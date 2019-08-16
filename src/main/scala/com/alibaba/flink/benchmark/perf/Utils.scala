package com.alibaba.flink.benchmark.perf

import org.apache.commons.lang3.SystemUtils

import java.io._

import scala.collection.Map
import scala.io.Source
import scala.util.Try

object Utils {
  /**
    * This should return a user helpful processor information. Getting at this depends on the OS.
    * This should return something like "Intel(R) Core(TM) i7-4870HQ CPU @ 2.50GHz"
    */
  def getProcessorName: String = {
    val cpu = if (SystemUtils.IS_OS_MAC_OSX) {
      executeAndGetOutput(Seq("/usr/sbin/sysctl", "-n", "machdep.cpu.brand_string"))
    } else if (SystemUtils.IS_OS_LINUX) {
      Try {
        val grepPath = executeAndGetOutput(Seq("which", "grep")).stripLineEnd
        executeAndGetOutput(Seq(grepPath, "-m", "1", "model name", "/proc/cpuinfo"))
          .stripLineEnd.replaceFirst("model name[\\s*]:[\\s*]", "")
      }.getOrElse("Unknown processor")
    } else {
      System.getenv("PROCESSOR_IDENTIFIER")
    }
    cpu
  }

  /**
    * This should return a user helpful JVM & OS information.
    * This should return something like
    * "OpenJDK 64-Bit Server VM 1.8.0_65-b17 on Linux 4.1.13-100.fc21.x86_64"
    */
  def getJVMOSInfo: String = {
    val vmName = System.getProperty("java.vm.name")
    val runtimeVersion = System.getProperty("java.runtime.version")
    val osName = System.getProperty("os.name")
    val osVersion = System.getProperty("os.version")
    s"$vmName $runtimeVersion on $osName $osVersion"
  }

  /**
    * Execute a command and get its output, throwing an exception if it yields a code other than 0.
    */
  def executeAndGetOutput(
      command: Seq[String],
      workingDir: File = new File("."),
      extraEnvironment: Map[String, String] = Map.empty,
      redirectStderr: Boolean = true): String = {
    val process = executeCommand(command, workingDir, extraEnvironment, redirectStderr)
    val output = new StringBuilder
    val threadName = "read stdout for " + command.head

    def appendToOutput(s: String): Unit = output.append(s).append("\n")

    val stdoutThread = processStreamByLine(threadName, process.getInputStream, appendToOutput)
    val exitCode = process.waitFor()
    stdoutThread.join() // Wait for it to finish reading output
    if (exitCode != 0) {
      System.err.println(s"Process $command exited with code $exitCode: $output")
      throw new RuntimeException(s"Process $command exited with code $exitCode")
    }
    output.toString
  }

  /**
    * Execute a command and return the process running the command.
    */
  def executeCommand(
      command: Seq[String],
      workingDir: File = new File("."),
      extraEnvironment: Map[String, String] = Map.empty,
      redirectStderr: Boolean = true): Process = {
    val builder = new ProcessBuilder(command: _*).directory(workingDir)
    val environment = builder.environment()
    for ((key, value) <- extraEnvironment) {
      environment.put(key, value)
    }
    val process = builder.start()
    if (redirectStderr) {
      val threadName = "redirect stderr for command " + command(0)

      def log(s: String): Unit = println(s)

      processStreamByLine(threadName, process.getErrorStream, log)
    }
    process
  }

  /**
    * Return and start a daemon thread that processes the content of the input stream line by line.
    */
  def processStreamByLine(
      threadName: String,
      inputStream: InputStream,
      processLine: String => Unit): Thread = {
    val t = new Thread(threadName) {
      override def run() {
        for (line <- Source.fromInputStream(inputStream).getLines()) {
          processLine(line)
        }
      }
    }
    t.setDaemon(true)
    t.start()
    t
  }

  def fileToString(file: File, encoding: String = "UTF-8"): String = {
    val inStream = new FileInputStream(file)
    val outStream = new ByteArrayOutputStream
    try {
      var reading = true
      while (reading) {
        inStream.read() match {
          case -1 => reading = false
          case c => outStream.write(c)
        }
      }
      outStream.flush()
    }
    finally {
      inStream.close()
    }
    new String(outStream.toByteArray, encoding)
  }

  def writeContent(file: File, content: String): Unit = {
    val path = file.getParentFile
    if (!path.exists()) {
      path.mkdirs()
    }

    var out: FileWriter = null
    try {
      out = new FileWriter(file, false)
      out.write(content)
      out.flush()
    } finally {
      if (out != null) {
        out.close()
      }
    }
  }
}
