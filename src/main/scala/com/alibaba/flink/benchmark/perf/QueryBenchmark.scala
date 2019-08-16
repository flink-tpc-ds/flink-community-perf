package com.alibaba.flink.benchmark.perf

import org.apache.flink.api.java.tuple.Tuple2
import org.apache.flink.table.plan.stats.TableStats
import org.apache.flink.table.sources.CsvTableSource2
import org.apache.flink.streaming.api.transformations.ShuffleMode
import org.apache.flink.table.api.{EnvironmentSettings, TableEnvironment, TableSchema}
import org.apache.flink.table.api.config.{ExecutionConfigOptions, OptimizerConfigOptions}
import org.apache.flink.table.api.internal.TableEnvironmentImpl
import com.alibaba.flink.benchmark.perf.QueryBenchmark.SOURCE_TYPE.SOURCE_TYPE
import com.alibaba.flink.benchmark.perf.QueryBenchmark.SQL_TYPE.SQL_TYPE
import scopt.OptionParser
import java.io.File
import java.lang.{Long => JLong, String => JString}
import java.sql.Date
import java.util.{ArrayList => JArrayList}

import com.alibaba.flink.benchmark.perf.QueryBenchmark.printStats
import org.apache.flink.core.fs.Path
import org.apache.flink.table.catalog.ObjectPath
import org.apache.flink.table.planner.plan.stats.StatisticGenerator
import org.apache.flink.table.planner.sources.ParquetTableSource
import org.apache.flink.table.planner.utils.TableStatsConverter
import org.apache.flink.table.types.DataType

import _root_.scala.collection.JavaConversions._

object QueryBenchmark {

  val tpchTables = Seq("region", "nation", "supplier", "customer",
    "part", "partsupp", "orders", "lineitem")

  val tpcdsTables = Seq("catalog_sales", "catalog_returns", "inventory",
    "store_sales", "store_returns", "web_sales", "web_returns", "call_center",
    "catalog_page", "customer", "customer_address", "customer_demographics", "date_dim",
    "household_demographics", "income_band", "item", "promotion", "reason",
    "ship_mode", "store", "time_dim", "warehouse", "web_page", "web_site")

  object SQL_TYPE extends Enumeration {
    type SQL_TYPE = Value
    val TPCH, TPCDS = Value
  }

  object SOURCE_TYPE extends Enumeration {
    type SOURCE_TYPE = Value
    val CSV, PARQUET, ORC = Value
  }

  case class Params(
                     dataLocation: String = null,
                     sqlLocation: String = null,
                     sqlQueries: String = "",
                     numIters: Int = 1,
                     scaleFactor: Int = 1000,
                     sqlType: SQL_TYPE = SQL_TYPE.TPCH,
                     sourceType: SOURCE_TYPE = SOURCE_TYPE.CSV,
                     optimizedPlanCollect: Boolean = false,
                     dumpFileOfOptimizedPlan: String = "",
                     operatorMetricCollect: Boolean = false,
                     dumpFileOfPlanWithMetrics: String = "",
                     analyzeTable: Boolean = false)

  var tableStatsMap: Map[String, TableStats] = Map()
  var analyzed: Boolean = false
  val analyzeCostArray = new JArrayList[Tuple2[JString, JLong]]()

  def main(args: Array[String]) {
    val defaultParams = Params()

    val parser = new OptionParser[Params]("Blink QueryBenchmark") {
      opt[String]("dataLocation")
        .text("data path")
        .required()
        .action((x, c) => c.copy(dataLocation = x))
      opt[String]("sqlLocation")
        .text("sql query path")
        .required()
        .action((x, c) => c.copy(sqlLocation = x))
      opt[String]("sqlQueries")
        .text("sql query names. " +
          "If the value of sqlQueries is 'all', all queries will be executed")
        .required()
        .action((x, c) => c.copy(sqlQueries = x))
      opt[Int]("numIters")
        .text(s"The number of iterations that will be run per case, " +
          s"default: ${defaultParams.numIters}")
        .action((x, c) => c.copy(numIters = x))
      opt[Int]("scaleFactor")
        .text(s"the size of raw data produced by dsdgen, " +
          s"default: ${defaultParams.scaleFactor}")
        .action((x, c) => c.copy(scaleFactor = x))
      opt[String]("sqlType")
        .text(s"the type of sql case, " +
          s"default: ${defaultParams.sqlType}")
        .action((x, c) => c.copy(sqlType = SQL_TYPE.withName(x.toUpperCase)))
      opt[String]("sourceType")
        .text(s"the type of file source, " +
          s"default: ${defaultParams.sourceType}")
        .action((x, c) => c.copy(sourceType = SOURCE_TYPE.withName(x.toUpperCase)))
      opt[Boolean]("optimizedPlanCollect")
        .text(s"whether collect optimized plan, " +
          s"default: ${defaultParams.optimizedPlanCollect}")
        .action((x, c) => c.copy(optimizedPlanCollect = x))
      opt[String]("dumpFileOfOptimizedPlan")
        .text(s"the dump file of optimized plan, " +
          s"default: ${defaultParams.dumpFileOfOptimizedPlan}")
        .action((x, c) => c.copy(dumpFileOfOptimizedPlan = x))
      opt[Boolean]("operatorMetricCollect")
        .text(s"whether collect operator metric, " +
          s"default: ${defaultParams.operatorMetricCollect}")
        .action((x, c) => c.copy(operatorMetricCollect = x))
      opt[String]("dumpFileOfPlanWithMetrics")
        .text(s"the dump file of plan metrics, " +
          s"default: ${defaultParams.dumpFileOfPlanWithMetrics}")
        .action((x, c) => c.copy(dumpFileOfPlanWithMetrics = x))
      opt[Boolean]("analyzeTable")
        .text(s"Whether to analyze table, default: ${defaultParams.analyzeTable}")
        .action((x, c) => c.copy(analyzeTable = x))
    }

    args.foreach(iterm => System.out.println(iterm))
    val params = parser.parse(args, defaultParams).get
    run(params)
  }

  private def setUpEnv(params: Params): TableEnvironment = {
    val settings = EnvironmentSettings.newInstance().useBlinkPlanner().inBatchMode().build()
    val tEnv = TableEnvironmentImpl.create(settings)
    tEnv.getConfig.getConfiguration.setBoolean(
      OptimizerConfigOptions.TABLE_OPTIMIZER_JOIN_REORDER_ENABLED, true)
    tEnv.getConfig.getConfiguration.setBoolean(
      OptimizerConfigOptions.TABLE_OPTIMIZER_REUSE_SUB_PLAN_ENABLED, true)
    tEnv.getConfig.getConfiguration.setBoolean(
      OptimizerConfigOptions.TABLE_OPTIMIZER_REUSE_SOURCE_ENABLED, false)
    tEnv.getConfig.getConfiguration.setString(ExecutionConfigOptions.TABLE_EXEC_SHUFFLE_MODE,
      ShuffleMode.BATCH.toString)

    setUpTables(tEnv, params)
    tEnv
  }

  private def setUpTables(tEnv: TableEnvironment, params: Params): Unit = {
    val sqlType = params.sqlType
    val sourceType = params.sourceType
    val dataLocation = params.dataLocation

    val tableNames = tpcdsTables

    tableNames.foreach { tableName =>
      println(s"register tableName=$tableName")

      val schema = TpcDsSchemaProvider.getSchema(tableName)
      val tableSource = sourceType match {
        case SOURCE_TYPE.CSV =>
          val builder = CsvTableSource2.builder()
          builder.path(s"$dataLocation/$tableName/")
          for (i <- schema.getFieldNames.indices) {
            builder.field(schema.getFieldNames(i), schema.getFieldTypes(i))
          }
          builder.fieldDelimiter("|")
          builder.lineDelimiter("\n")
          builder.build()
        case SOURCE_TYPE.PARQUET =>
          val schemaBuilder = TableSchema.builder()
          for (i <- schema.getFieldNames.indices) {
            schemaBuilder.field(schema.getFieldNames(i), schema.getFieldTypes(i))
          }
          val tableSchema = schemaBuilder.build()
          new ParquetTableSource(tableSchema,
            new Path(s"${dataLocation}_parquet/$tableName"),
            true
          )
        case _ =>
          throw new UnsupportedOperationException(s"Unsupported sourceType: $sourceType")
      }

      tEnv.registerTableSource(tableName, tableSource)

      val fieldName2DataTypes = schema.getFieldNames.toList.zip(schema.getFieldTypes.toList).toMap
      val tableStats = params.analyzeTable match {
        case true => {
          val start = System.currentTimeMillis()
          val stats = StatisticGenerator.generateTableStats(tEnv, Array(tableName), Some(schema.getFieldNames))
          tableStatsMap += (tableName -> stats)
          val end = System.currentTimeMillis()
          analyzeCostArray.add(new Tuple2[JString, JLong](tableName, end - start))
          stats
        }
        case _ => {
          System.out.println("do not existed tableStats:")
          null
        }
      }
      if (tableStats != null) {
        printStats(tableStats, tableName, params.scaleFactor, fieldName2DataTypes)
        val tableStatistics = TableStatsConverter.convertToCatalogTableStatistics(tableStats)
        val columnStatistics = TableStatsConverter.convertToCatalogColumnStatistics(tableStats)
        tEnv.getCurrentCatalog
        tEnv.getCatalog(tEnv.getCurrentCatalog).get().alterTableStatistics(new ObjectPath(tEnv.getCurrentDatabase, tableName), tableStatistics, false)
        tEnv.getCatalog(tEnv.getCurrentCatalog).get().alterTableColumnStatistics(new ObjectPath(tEnv.getCurrentDatabase, tableName), columnStatistics, false)
      }
    }
  }

  private def getQueries(params: Params): Array[String] = {
    params.sqlQueries match {
      case "all" => new File(params.sqlLocation).list()
      case _ => params.sqlQueries.split(",")
    }
  }

  private def run(params: Params): Unit = {
    printAndCheckParams(params)

    val queries = getQueries(params)
    val tEnv = setUpEnv(params)

    val bestArray = new JArrayList[Tuple2[JString, JLong]]()

    params.sqlType match {
      case SQL_TYPE.TPCDS =>
        params.sqlQueries match {
          case "all" => {
            for (x <- 1 to 99) {
              runQuery(tEnv, "query" + x + ".sql", params.numIters, params, bestArray)
              runQuery(tEnv, "query" + x + "a.sql", params.numIters, params, bestArray)
            }
          }
          case _ => {
            queries.foreach { name =>
              runQuery(tEnv, name, params.numIters, params, bestArray)
            }
          }
        }
    }
    printSummary(params, bestArray)
  }

  private def printStats(tableStats: TableStats, tableName: String, scaleFactor: Int, fieldName2DataTypes: Map[String, DataType]): Unit = {
    System.out.println("----------------------------before--------------------------------------------------")
    val sb = new StringBuilder("val " + tableName.toUpperCase + "_" + scaleFactor + " = new TableStats(");
    sb.append(tableStats.getRowCount()).append("L, Map[String, ColumnStats](").append("\n")
    tableStats.getColumnStats.foreach {
      case (col, st) => sb.append("\"").append(col).append("\" -> new ColumnStats(")
        .append(st.getNdv).append("L, ")
        .append(st.getNullCount).append("L, ")
        .append(st.getAvgLen).append("D, ")
        .append(st.getMaxLen).append(", ")


        st.getMaxValue match {
          case _: Number => sb.append("convertToNumber(\"")
          case _: Date => sb.append("Date.valueOf(\"")
          case _ => Unit
        }
        sb.append(st.getMaxValue)
        st.getMaxValue match {
          case _: Number => sb.append("\",").append("DataTypes.").append(fieldName2DataTypes.get(col).get.toString).append(")")
          case _: Date => sb.append("\")")
          case _: java.lang.Long => sb.append("L")
          case _: java.lang.Double => sb.append("D")
          case _ => Unit
        }
        sb.append(", ")


        st.getMinValue match {
          case _: Number => sb.append("convertToNumber(\"")
          case _: Date => sb.append("Date.valueOf(\"")
          case _ => Unit
        }
        sb.append(st.getMinValue)
        st.getMinValue match {
          case _: Number => sb.append("\",").append("DataTypes.").append(fieldName2DataTypes.get(col).get.toString).append(")")
          case _: Date => sb.append("\")")
          case _: java.lang.Long => sb.append("L")
          case _: java.lang.Double => sb.append("D")
          case _ => Unit
        }
        sb.append("),\n")
    }
    sb.replace(sb.length - 2, sb.length, "")
    sb.append("))")
    System.out.println(sb.toString())
    System.out.println("-----------------------------after-------------------------------------------------")
  }

  private def printSummary(
                            params: Params,
                            bestArray: JArrayList[Tuple2[JString, JLong]]): Unit = {
    if (bestArray.isEmpty) {
      return
    }
    val sqlType = params.sqlType
    System.err.println(String.format(s"--------------- $sqlType Results ---------------"))
    val itemMaxLength = 20
    System.err.println()
    var total: java.lang.Long = 0L
    var product: java.lang.Double = 1d
    printLine('-', "+", itemMaxLength, "", "")
    printLine(' ', "|", itemMaxLength, " " + s"$sqlType sql", " Time(ms)")
    printLine('-', "+", itemMaxLength, "", "")

    bestArray.foreach { x =>
      printLine(' ', "|", itemMaxLength, x.f0, String.valueOf(x.f1))
      total += x.f1
      product = product * x.f1 / 1000d
    }
    printLine(' ', "|", itemMaxLength, "Total", String.valueOf(total))
    printLine(' ', "|", itemMaxLength, "Average", String.valueOf(total / bestArray.size()))
    printLine(' ', "|", itemMaxLength, "GeoMean", String.valueOf((java.lang.Math.pow(product, 1d / bestArray.size()) * 1000).toInt))
    printLine('-', "+", itemMaxLength, "", "")

    if (!analyzeCostArray.isEmpty) {
      System.err.println()
      printLine('-', "+", itemMaxLength, "", "")
      printLine(' ', "|", itemMaxLength, " " + "analyze-Table", " Time(ms)")
      printLine('-', "+", itemMaxLength, "", "")

      total = 0L
      analyzeCostArray.foreach { x =>
        printLine(' ', "|", itemMaxLength, x.f0, String.valueOf(x.f1))
        total += x.f1
      }
      printLine(' ', "|", itemMaxLength, "analyze-Total", String.valueOf(total))
      printLine('-', "+", itemMaxLength, "", "")
    }

    System.err.println()
  }

  private def printLine(
                         charToFill: Char,
                         separator: String,
                         itemMaxLength: Int,
                         items: String*): Unit = {
    val builder = new StringBuilder
    for (item <- items) {
      builder.append(separator)
      builder.append(item)
      val left = itemMaxLength - item.length - separator.length
      builder.append(charToFill.toString * left)
    }
    builder.append(separator)
    System.err.println(builder.toString)
  }

  private def runQuery(
                        tEnv: TableEnvironment,
                        query: String,
                        iter: Int,
                        params: Params,
                        bestArray: JArrayList[Tuple2[JString, JLong]]): Unit = {
    val file = new File(s"${params.sqlLocation}/$query")
    if (!file.exists()) {
      return
    }

    val queryString = Utils.fileToString(file)
    val benchmark = new Benchmark(query, queryString, iter, tEnv)
    benchmark.run(bestArray)
  }

  private def printAndCheckParams(params: Params): Unit = {
    println("-" * 15 + " params " + "-" * 15)
    println(s"dataLocation=${params.dataLocation}")
    println(s"sqlLocation=${params.sqlLocation}")
    println(s"sqlQueries=${params.sqlQueries}")
    println(s"numIters=${params.numIters}")
    println(s"scaleFactor=${params.scaleFactor}")
    println(s"sqlType=${params.sqlType}")
    println(s"sourceType=${params.sourceType}")

    require(params.dataLocation.nonEmpty,
      s"please modify the value of dataLocation to point to your ${params.sqlType} data")

    require(params.sqlLocation.nonEmpty,
      s"please modify the value of sqlLocation to point to ${params.sqlType} queries directory")

    require(params.sqlQueries.nonEmpty,
      s"please modify the value of sqlQueries to point to ${params.sqlType} queries")

    if (params.sqlQueries.equals("all")) {
      val file = new File(s"${params.sqlLocation}")
      val content = file.list()
      require(content == null || content.nonEmpty, s"there is no query in ${params.sqlLocation}")
    } else {
      params.sqlQueries.split(",").foreach { name =>
        val file = new File(s"${params.sqlLocation}/$name")
        require(file.exists(), s"${file.toString} does not exist")
      }
    }

    require(params.numIters > 0, "numIters must be greater than 0")
  }

}
