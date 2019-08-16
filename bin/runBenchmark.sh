#!/bin/bash
##############################################################################
# run flink benchmark
##############################################################################

curDir=`dirname $0`
curDir=`cd $curDir ; pwd`
cd $curDir

index=0
for i in $@
do
    if [[ $i =~ "="  ]]
    then
	key=`echo $i | awk -F= '{print $1}'  `
        value=`echo $i | awk -F= '{print $2}' `
        export $key=$value
    else
        if [ $index == 0 ]
        then
          sqlQueries=$i
        elif [ $index == 1 ]
        then
          numIters=$i
        fi
        index=`expr $index + 1`
    fi
done


if [[ -e $curDir/params.conf ]]; then
    source $curDir/params.conf
fi

if [ $# -lt 1 ]; then
    echo "[ERROR] Insufficient # of params"
    echo "USAGE: `dirname $0`/$0 <sqlQueries> [numIters]"
    exit 127
fi

if [[ $numIters > 0 ]]; then
    numItersArgs="--numIters $numIters"
fi

mainClass=com.alibaba.flink.benchmark.perf.QueryBenchmark

${FLINK_DIR}/bin/flink run -c $mainClass $JAR_FILE --scaleFactor $SF --dataLocation $DATA_LOCATION  --sqlLocation $SQL_LOCATION  --sqlQueries $1 $numItersArgs --sqlType $SQL_TYPE --sourceType $SOURCE_TYPE --optimizedPlanCollect $OPTIMIZED_PLAN_COLLECT --dumpFileOfOptimizedPlan $DUMP_FILE_OF_OPTIMIZED_PLAN --operatorMetricCollect $OPERATOR_METRIC_COLLECT --dumpFileOfPlanWithMetrics $DUMP_FILE_OF_PLAN_WITH_METRICS --analyzeTable $ANALYZE_TABLE
