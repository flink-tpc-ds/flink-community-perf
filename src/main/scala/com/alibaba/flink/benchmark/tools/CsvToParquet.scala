package com.alibaba.flink.benchmark.tools


import com.alibaba.flink.benchmark.perf.QueryBenchmark.{SQL_TYPE, tpcdsTables, tpchTables}
import com.alibaba.flink.benchmark.perf.QueryBenchmark.SQL_TYPE.SQL_TYPE
import org.apache.flink.table.api.{EnvironmentSettings, TableEnvironment}
import org.apache.flink.table.sources.CsvTableSource2
import com.alibaba.flink.benchmark.perf.TpcDsSchemaProvider
import org.apache.flink.core.fs.FileSystem.WriteMode
import org.apache.flink.streaming.api.transformations.ShuffleMode
import org.apache.flink.table.api.config.{ExecutionConfigOptions, OptimizerConfigOptions}
import org.apache.flink.table.api.internal.TableEnvironmentImpl
import org.apache.flink.table.planner.sinks.ParquetTableSink
import org.apache.parquet.hadoop.metadata.CompressionCodecName
import scopt.OptionParser

/**
  * flink tpch&tpcds data convert tool, currently spark data
  * not available in blink parquet table source.
  */
object CsvToParquet {
  val map = Map("snappy" -> CompressionCodecName.SNAPPY,
    "gzip" -> CompressionCodecName.GZIP,
    "lzo" -> CompressionCodecName.LZO)

  def convert(tEnv: TableEnvironment,
      dataPath: String, tableName: String, realCompressionAlgorithm: CompressionCodecName) {

    val table = tEnv.sqlQuery(s"SELECT * FROM $tableName")
    val sink = new ParquetTableSink(table.getSchema,s"${dataPath}_parquet/$tableName", Some(WriteMode.OVERWRITE),
      realCompressionAlgorithm,32 * 1024 * 1024,true)
    tEnv.registerTableSink(s"${tableName}_to_parquet",sink)
    table.insertInto(s"${tableName}_to_parquet")
    tEnv.execute(s"${tableName}_to_parquet")

  }

  case class Params(
      dataLocation: String = null,
      sqlType: SQL_TYPE = SQL_TYPE.TPCH,
      scaleFactor: Int = 100,
      compressionCodec: String = "snappy"
  )

  def main(args: Array[String]) {
    val defaultParams = Params()

    val parser = new OptionParser[Params]("Blink dataConvertTool") {
      opt[String]("dataLocation")
        .text("Benchmark data path")
        .required()
        .action((x, c) => c.copy(dataLocation = x))
      opt[String]("sqlType")
        .text(s"the type of sql case, " +
          s"default: ${defaultParams.sqlType}")
        .action((x, c) => c.copy(sqlType = SQL_TYPE.withName(x.toUpperCase)))
      opt[Int]("scaleFactor")
        .text(s"the size of raw data produced by dsdgen, " +
          s"default: ${defaultParams.scaleFactor}")
        .action((x, c) => c.copy(scaleFactor = x))
      opt[String]("compressionCodec")
        .text(s"specify the compression algo, " +
          s"default: ${defaultParams.compressionCodec}")
        .action((x, c) => c.copy(compressionCodec = x))
    }

    parser.parse(args, defaultParams) match {
      case Some(params) => run(params)
      case _ => sys.exit(1)
    }
  }

  private def run(params: Params): Unit = {
    printAndCheckParams(params)

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


    val realCompressionAlgorithm = map(params.compressionCodec)

    val sqlType = params.sqlType
    val tableNames = sqlType match {
      case SQL_TYPE.TPCDS => tpcdsTables
      case _ => throw new UnsupportedOperationException(s"Unsupported sqlType: $sqlType")
    }

    tableNames.foreach { tableName =>
      val schema = sqlType match {
        case SQL_TYPE.TPCDS => TpcDsSchemaProvider.getSchema(tableName)
      }
      val builder = CsvTableSource2.builder()
      builder.path(s"${params.dataLocation}/$tableName/")
      for (i <- schema.getFieldNames.indices) {
        builder.field(schema.getFieldNames(i), schema.getFieldTypes(i))
      }
      builder.fieldDelimiter("|")
      builder.lineDelimiter("\n")
      builder.build()
      tEnv.registerTableSource(tableName, builder.build())
      convert(tEnv, params.dataLocation, tableName, realCompressionAlgorithm)
    }
  }

  private def printAndCheckParams(params: Params): Unit = {
    println("-" * 15 + " params " + "-" * 15)
    println(s"dataLocation=${params.dataLocation}")
    println(s"sqlType=${params.sqlType}")
    println(s"scaleFactor=${params.scaleFactor}")
    println(s"compressionCodec=${params.compressionCodec}")

    require(params.dataLocation.nonEmpty,
      "please modify the value of dataLocation to point to your hdfs data")

    require(params.compressionCodec.nonEmpty,
      "please modify the value of compressionCodec to point to your compress algorithm")
  }

}
