package com.alibaba.flink.benchmark.perf

object STATS_MODE extends Enumeration {
  type STATS_MODE = Value
  val FULL, PART, ROW_COUNT = Value
}
