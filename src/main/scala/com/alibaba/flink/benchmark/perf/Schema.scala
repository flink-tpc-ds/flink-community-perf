package com.alibaba.flink.benchmark.perf

import java.util

import org.apache.flink.table.types.DataType


trait Schema {

  def getFieldNames: Array[String]

  def getFieldTypes: Array[DataType]

  def getUniqueKeys: util.Set[util.Set[String]] = null

}

