#!/bin/bash
##############################################################################
# run flink benchmark data convert tool
##############################################################################

curDir=`dirname $0`
curDir=`cd $curDir ; pwd`
cd $curDir

if [[ -e $curDir/params.conf ]]; then
    source $curDir/params.conf
fi

index=0
for i in $@
do
    if [[ $i =~ "="  ]]; then
	key=`echo $i | awk -F= '{print $1}'  `
        value=`echo $i | awk -F= '{print $2}' `
        export $key=$value
    fi
done

jarFile=""
if [[ -z $jarFile ]]; then
    jarFile=$JAR_FILE
fi
if [[ -z $jarFile ]]; then
    echo "[ERROR] jarFile is empty. (flink-perf jar local file)"
    exit 127
fi

flinkDir=""
if [[ -z $flinkDir ]]; then
    flinkDir=$FLINK_DIR
fi
if [[ -z $flinkDir ]]; then
    echo "[ERROR] flinkDir is empty. (flink binaries package directory)"
    exit 127
fi

dataLocation=""
if [[ -z $dataLocation ]]; then
    dataLocation=$DATA_LOCATION
fi
if [[ -z $dataLocation ]]; then
    echo "[ERROR] dataLocation is empty. (hdfs directory stores tpch data, like: hdfs://namenode:8020/tpchRaw/SF100)"
    exit 127
fi

sqlType=$SQL_TYPE

scaleFactor=$SF
if [[ -z $scaleFactor ]]; then
    echo "[ERROR] scaleFactor is empty"
    exit 127
fi

compressionCodec=$COMPRESSION_TYPE

mainClass=com.alibaba.flink.benchmark.tools.CsvToParquet

echo $FLINK_CLASSPATH

${flinkDir}/bin/flink run -c $mainClass $jarFile --dataLocation $dataLocation  --scaleFactor $scaleFactor --sqlType $sqlType --compressionCodec $compressionCodec
