# 天池Flink TPC-DS性能大赛赛题说明

## 1.说明：

Flink团队提供用于比赛的[Flink分支](https://github.com/flink-tcp-ds/flink/tree/tpcds-master)，选手进行Flink 代码优化以提升Flink SQL执行效率，
组委会提供[Benchmark工具](https://github.com/flink-tcp-ds/flink-community-perf) 供选手自行测试，
比赛阶段，选手将最终优化后的Flink代码打包，通过天池平台提交，天池平台会使用相同的性能测评工具，进行评测、排名。


## 2.具体赛题

1.比赛使用的测试数据集为100G，用户自行用Benchmark工具生成，生成数据集的随机因子组委会不公开。

2.比赛使用SQL query为TPC-DS工具生成的99个SQL(含变种SQL)，共计103个，组委会从中选择20条SQL进行评测。

3.选手可以进行SQL优化，执行Plan算子优化，引擎优化，调度优化，数据传输优化等，以便让SQL作业执行更快速。

4.选手每天有三次提交作业的机会，每个自然日提供5次代码运行机会。

5.组委会保留对赛题修改的权利。

## 3.比赛流程
1.选手从[Benchmark工具](https://github.com/flink-tcp-ds/flink-community-perf) 获取query。

2.选手通过[Benchmark工具](https://github.com/flink-tcp-ds/flink-community-perf) 生成测试数据，建议利用将数据转换成parquet格式以获取更好的性能。

3.选手从[Flink分支](https://github.com/flink-tcp-ds/flink/tree/tpcds-master)拉取Flink代码进行优化。

4.本地利用[Benchmark工具](https://github.com/flink-tcp-ds/flink-community-perf)评测优化效果。

5.选手将优化后的代码打包提交天池平台。


## 4.详细说明
       
### 4.1工程结构
一共两个工程，建议工程组织：
```
    +--/home
       +--/hadoop
         +--/flink
            +--/flink-dist
            +--/flink-core
            +--...
         +--/flink-community-perf  
            +--/src
            +--/bin
            +--/resource    
```
flink工程目录不做细讲，flink-community-perf 工程目录结构如下：
```
   +--/src
      +--/main
         +--/java
         +--/scala      
   +--/bin
      +--/params.conf
      +--/runBenchMark.sh
      +--/runParquetCnnvertTool.sh
   +--/resource
      +--/tpcds
         +--/compileTpcds.sh
         +--/compileTpcdsMac.sh
         +--/datagen
         +--/querygen
         +--/tpc-ds-tool  
         +--/tpc-ds-tool-mac             
```

## 4.2.工程代码：
[Flink比赛使用分支](https://github.com/flink-tcp-ds/flink/tree/tpcds-master)：Flink代码是从社区[apache/flink](https://github.com/apache/flink)代码拉取分支，并根据比赛需要新增了一些feature和bug修复，请所有选手基于这份代码进行优化
[Benchmark工具](https://github.com/flink-tcp-ds/flink-community-perf): Flink 用来做TPC-DS性能测试的工具，提供生成数据集、生成测试query，同时提供了数据集从CSV转parquet的功能，Benchmark工具中有TPC-DS全量99个SQL。

    
       
## 5 详细说明

### 1.生成数据集和query
(1) 编译最新的tpc-ds tools(v2.11.0), 命令:
```
cd flink-community-perf/resource/tpcds
sh compileTpcds.sh
```
tpc-ds tools对Mac系统支持不好，Mac用户可以使用下面命令，这个工具源自[tpcds-kit](https://github.com/databricks/tpcds-kit.git) ，命令:
```
cd flink-community-perf/resource/tpcds
sh compileTpcdsMac.sh
```


(2) 指定 scaleFactor(GB) 和 RNGSEED (随机种子) 生成测试数据,默认:
```
cd flink-community-perf/resource/tpcds/datagen
sh generateTpcdsData.sh 1 0  
```
测试数据集可以适当小些，数据位于flink-community-perf/resource/tpcds/datagen/data下

(3) 生成query,提供了全量99个query位于 flink-community-perf/resource/tpcds/querygen/queries下，其中
SF1包含两个测试SQL,SF100包含全量99个SQL


### 2.优化FlinK代码
(1) 拉取比赛使用的Flink代码[tpcds-master](https://github.com/flink-tcp-ds/flink),commands:
```
    cd /home/hadoop/flink
    git remote add flink-tpc-ds git@github.com:flink-tcp-ds/flink.git
    git fetch flink-tpc-ds
    git checkout tpcds-master
```

(2) 优化
也是比赛最主要的部分， 优化Flink代码和配置，包含但不限于以下模块：
    SQL 优化，优化出更合理的SQL执行Plan。
    算子优化， 优化出更高效的SQL执行算子。
    引擎优化， 优化调度，数据传输等等，可以让作业执行更快速。

(3) 将优化后的Flink代码打包上传，并将压缩包上传至[天池](https://tianchi.aliyun.com/competition/entrance/231742/information):

```
    cd /home/hadoop/flink
    mvn clean install -DskipTests=true -Dfast 
    # optional, compiling parallel to speed up
    mvn clean install -DskipTests=true -Dfast -T 2C -Dmaven.compile.fork=true 
    
```

### 3.性能评测
选手可以在本地IDE中进行测试，也可以在选手自己的集群上进行测试：

####  3.1 本地 Intellij 测试:
(1) 找到主类: 
```
src/main/scala/com.alibaba/flink/benchmark/QueryBenchmark
```
(2)修改 pom.xml 依赖.
```
<dependency.scope>compile</dependency.scope>
```

(3) 设置运行参数:

运行一个 sql 作业(如query1.sql),设置数据集大小为 1G, 执行次数为 3，测试数据格式为csv,运行参数如下:
```
--sqlQueries query1.sql
--numIters 3
--scaleFactor 1
--dataLocation /home/hadoop/flink-community-perf/resource/tpcds/datagen/data/SF1
--sqlLocation  /home/hadoop/flink-community-perf/resource/tpcds/querygen/queries/SF1 
--sqlType tpcds 
--sourceType csv
--optimizedPlanCollect true 
--dumpFileOfOptimizedPlan /tmp/plan/tpcds
--operatorMetricCollect false
--dumpFileOfPlanWithMetrics /tmp/metrics
--analyzeTable false
```
Intellij 截图:
![Intellij](./resource/img/run_intelij.jpg)


运行所有 sql 作业,设置数据集大小为 1G, 执行次数为 3，测试数据格式为parquet,运行参数如下:
```
--sqlQueries all
--numIters 1
--scaleFactor 1
--dataLocation /home/hadoop/flink-community-perf/resource/tpcds/datagen/data/SF1
--sqlLocation  /home/hadoop/flink-community-perf/resource/tpcds/querygen/queries/SF1  
--sqlType tpcds 
--sourceType parquet
--optimizedPlanCollect true 
--dumpFileOfOptimizedPlan /tmp/plan/tpcds
--operatorMetricCollect false
--dumpFileOfPlanWithMetrics /tmp/metrics
--analyzeTable false
```
选手可以根据自己的需求进行修改，其中analyzeTable表示在运行SQL前是否对所有数据集进行信息统计。


####  3.2 集群运行:

(1) 比赛使用standalone集群,命令如下:
```
cd /home/hadoop/flink/flink-dist/target/flink-1.9-tpcds-master-bin/flink-1.9-tpcds-master/bin 
sh start-cluster.sh
```
你可以在[http:localhost:8081](http:localhost:8081) 管理作业，在拉起集群前，你可以修改flink配置文件以获得更好的性能

(2)设置运行参数:
```
cd  /home/hadoop/flink-community-perf/bin
vim param.conf
```
关键的参数有:
````
### flink binaries package directory
export FLINK_DIR=/home/hadoop/flink/flink-dist/target/flink-1.9-tpcds-master-bin

### file directory stores tpc raw data
export DATA_LOCATION=/home/hadoop/flink-community-perf/resource/tpcds/datagen/data/SF${SF}

### sql queries local directory
export SQL_LOCATION=/home/hadoop/flink-community-perf/resource/tpcds/querygen/queries/SF${SF}

### flink-perf jar local file
export JAR_FILE=/home/hadoop/flink-community-perf/target/flink-community-perf-1.0-SNAPSHOT-jar-with-dependencies.jar
````

(3)打包
Modify the dependencies scope in pom.xml for run in cluster.
```
       <dependency.scope>provided</dependency.scope>
```
Build the jar 
```
 cd /home/hadoop/flink-community-perf/
 mvn assembly:assembly

```

(4)提交 tpc-ds benchmark 作业
```
cd /home/hadoop/flink-community-perf/bin

```

运行一个sql, 设置数据集大小为 10G, 执行次数为 3, 运行参数如下:

```
sh runBenchmark.sh query1.sql 3 SF=10 
```

运行所有 sql, 设置数据集大小为 100G, 执行次数为 1, 运行参数如下:
```
sh runBenchmark.sh all 1 SF=100 
```

选手可以根据自己的需求进行修改param.conf文件，其中analyzeTable表示在运行SQL前是否对所有数据集进行信息统计。


### 4.提交作业至天池平台
(1) 代码优化完成后，打包提交到天池平台，打包命令如下：
```  
    cd /home/hadoop/flink/flink-target/flink-dist/target/flink-1.9-tpcds-master-bin 
    tar --exclude=flink-1.9-tpcds-master/opt/ -zcvf flink-1.9-tpcds-master.tar.gz   flink-1.9-tpcds-master/  
    upload your flink-1.10-SNAPSHOT.tar.gz to Tanchi 
```

### 5.格式转换工具

parquet在大量数据的的读取和查询上有更好的性能，Flink也支持该格式，tpc-ds工具生成的数据集格式是csv的，benchmark提供了工具进行换。

####  5.1 本地Intellij中转换:
(1) 找到主类: 
```
src/main/scala/com.alibaba/flink/benchmark/tools/CsvToParquet
```
(2) 修改 pom.xml：
```
<dependency.scope>compile</dependency.scope>
```

(3) 设置主类运行参数:

进行数据规模为1G的csv数据转为parquet数据： 
```
--scaleFactor 1 
--sqlType tpcds 
--dataLocation  /home/hadoop/flink-community-perf/resource/tpcds/datagen/data/SF1
--compressionCodec snappy
```

你可以根据自己需求进行参数设置

####  5.2 集群上转换:

(1) 拉起flink集群,命令:
```
cd /home/hadoop/flink/flink-dist/target/flink-1.9-tpcds-master-bin/flink-1.9-tpcds-master/bin 
sh start-cluster.sh
```
(2)设置参数:
```
cd  /home/hadoop/flink-community-perf/bin
vim param.conf

```
关键参数有：

````
### flink parquet compression type,parquet format has better performance than csv format
export COMPRESSION_TYPE=snappy

### flink binaries package directory
export FLINK_DIR=/home/hadoop/flink/flink-dist/target/flink-1.9-tpcds-master-bin

### file directory stores tpc raw data
export DATA_LOCATION=/home/hadoop/flink-community-perf/resource/tpcds/datagen/data/SF${SF}

### flink-perf jar local file
export JAR_FILE=/home/hadoop/flink-community-perf/target/flink-community-perf-1.0-SNAPSHOT-jar-with-dependencies.jar
````

(3)打包：
修改依赖scope
```
       <dependency.scope>provided</dependency.scope>
```

编译打包
```
 cd /home/hadoop/flink-community-perf/
 mvn assembly:assembly

```

(4)提交作业
```
cd /home/hadoop/flink-community-perf/bin
```
执行格式转换作业
```
sh runParquetConvertTool.sh SF=10
```

## 5.联系我们

如有任何关于[Flink TPC-DS 比赛](https://tianchi.aliyun.com/competition/entrance/231742/introduction?spm=5176.12281949.1003.9.55e44c2aUc3y76)的疑问，请联系我们。
钉钉群号：21950145
![dingTalk](./resource/img/dingTalk_group.png)
   