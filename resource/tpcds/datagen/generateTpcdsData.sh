#!/bin/bash
##############################################################################
# TPC-DS data Generation
##############################################################################

export JAVA_HOME=/home/hadoop/java

# set data save path
targetPath=./data/

# set work threads ,initial value is 0
workThreads=0

# set data scale
if [ $# -lt 1 ]; then
	echo "[ERROR] Insufficient # of params"
	echo "USAGE: `dirname $0`/$0 <scaleFactor>"
	exit 127
fi
scaleFactor=$1

# random seed to build data,default value is 0
rngSeed=0
if [ $# -ge 2 ]; then
    rngSeed=$2
fi


### Check for target path
if [ -z $targetPath ]; then
	echo "[ERROR] HDFS target path was not configured"
	exit 127
fi

### Init
### in workload.lst, dimension table was configured parallel value 1,and fact table  was configured bigger parallel
workFile=workloads/tpcds.workload.${scaleFactor}.lst

if [ ! -e $workFile ]; then

	echo "[INFO] generating Workload file: "$workFile
	echo "a call_center	$((scaleFactor))" >>$workFile
	echo "b catalog_page	$((scaleFactor))" >>$workFile
	echo "d catalog_sales	$((scaleFactor))" >>$workFile
	echo "e customer_address	$((scaleFactor))" >>$workFile
	echo "f customer	$((scaleFactor))" >>$workFile
    echo "g customer_demographics	$((scaleFactor))" >>$workFile
	echo "h date_dim	$((scaleFactor))" >>$workFile
    echo "i household_demographics $((scaleFactor))" >>$workFile
    echo "j income_band    $((scaleFactor))" >>$workFile
    echo "k inventory    $((scaleFactor))" >>$workFile
    echo "l item    $((scaleFactor))" >>$workFile
    echo "m promotion    $((scaleFactor))" >>$workFile
    echo "n reason    $((scaleFactor))" >>$workFile
    echo "o ship_mode    $((scaleFactor))" >>$workFile
    echo "p store    $((scaleFactor))" >>$workFile
    echo "r store_sales    $((scaleFactor))" >>$workFile
    echo "s time_dim    $((scaleFactor))" >>$workFile
    echo "t warehouse    $((scaleFactor))" >>$workFile
    echo "u web_page    $((scaleFactor))" >>$workFile
    echo "w web_sales    $((scaleFactor))" >>$workFile
    echo "x web_site    $((scaleFactor))" >>$workFile
fi

### Basic Params
echo "[INFO] Data will be generated locally on each node at a named pipe ./<tblName.tbl.<chunk#>"
echo "[INFO] Generated data will be streamingly copied to the cluster at "$targetHSDFPath
echo "[INFO] e.g. lineitem.tbl.10 --> /disk/1/tpcds/data/SF100/lineitem/lineitem.10.tbl"

#Clear existing workloads
rm -rf writeData.sh

#Check Dir on disk
targetPath=${targetPath}/SF${scaleFactor}

rm -rf ${targetPath}
mkdir -p ${targetPath}

### Init Workloads

fileName=writeData.sh
echo "#!/bin/bash" >> $fileName
echo "  "  >> $fileName
echo "ps -efww|grep dsdgen |grep -v grep|cut -c 9-15|xargs kill -9" >> $fileName
echo "ps -efww|grep FsShell |grep -v grep|cut -c 9-15|xargs kill -9" >> $fileName
echo "ps -efww|grep wait4process.sh |grep -v grep|cut -c 9-15|xargs kill -9" >> $fileName
echo "rm -rf *.dat" >> $fileName
echo "  "  >> $fileName

mkdir -p ${targetPath}/catalog_returns
mkdir -p ${targetPath}/store_returns
mkdir -p ${targetPath}/web_returns

### Generate Workloads
while read line; do
	params=( $line )
	#Extracting Parameters
	#echo ${params[*]}
	tblCode=${params[0]}
	tblName=${params[1]}
	tblParts=${params[2]}
	echo "====$tblName==="
	mkdir -p ${targetPath}/$tblName
	# Assigning workload in round-robin fashion
	partsDone=1
	while [ $partsDone -le $tblParts ]; do
		if [ $tblParts -gt 1 ]; then
			echo "rm -rf ./${tblName}_${partsDone}_${tblParts}.dat" >> writeData.sh
			echo "mkfifo ./${tblName}_${partsDone}_${tblParts}.dat" >> writeData.sh
            if [ "$tblName" = "catalog_sales" ]; then
                echo "rm -rf ./catalog_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
                echo "mkfifo ./catalog_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
            fi
            if [ "$tblName" = "store_sales" ]; then
                echo "rm -rf ./store_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
                echo "mkfifo ./store_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
            fi
            if [ "$tblName" = "web_sales" ]; then
                echo "rm -rf ./web_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
                echo "mkfifo ./web_returns_${partsDone}_${tblParts}.dat" >> writeData.sh
            fi
			echo "./dsdgen -SCALE $scaleFactor -TABLE $tblName -CHILD $partsDone -PARALLEL $tblParts -FORCE Y -RNGSEED $rngSeed  &" >> writeData.sh
			echo "./copyAndDelete.sh ./${tblName}_${partsDone}_${tblParts}.dat ${targetPath}/$tblName  &" >> writeData.sh
            if [ "$tblName" = "catalog_sales" ]; then
                echo "./copyAndDelete.sh ./catalog_returns_${partsDone}_${tblParts}.dat ${targetPath}/catalog_returns  &" >> writeData.sh
            fi
            if [ "$tblName" = "store_sales" ]; then
                echo "./copyAndDelete.sh ./store_returns_${partsDone}_${tblParts}.dat ${targetPath}/store_returns &" >> writeData.sh
            fi
            if [ "$tblName" = "web_sales" ]; then
                echo "./copyAndDelete.sh ./web_returns_${partsDone}_${tblParts}.dat ${targetPath}/web_returns &" >> writeData.sh
            fi
		else
			echo "rm -rf ./${tblName}.dat" >> writeData.sh
			echo "mkfifo ./${tblName}.dat" >> writeData.sh

			if [ "$tblName" = "catalog_sales" ]; then
                echo "rm -rf ./catalog_returns.dat" >> writeData.sh
                echo "mkfifo ./catalog_returns.dat" >> writeData.sh
            fi
            if [ "$tblName" = "store_sales" ]; then
                echo "rm -rf ./store_returns.dat" >> writeData.sh
                echo "mkfifo ./store_returns.dat" >> writeData.sh
            fi
            if [ "$tblName" = "web_sales" ]; then
                echo "rm -rf ./web_returns.dat" >> writeData.sh
                echo "mkfifo ./web_returns.dat" >> writeData.sh
            fi

			echo "./dsdgen -SCALE $scaleFactor -TABLE $tblName -FORCE Y -RNGSEED $rngSeed &" >> writeData.sh
			echo "./copyAndDelete.sh ./${tblName}.dat ${targetPath}/$tblName &" >> writeData.sh

			if [ "$tblName" = "catalog_sales" ]; then
                echo "./copyAndDelete.sh ./catalog_returns.dat ${targetPath}/catalog_returns &" >> writeData.sh
            fi
            if [ "$tblName" = "store_sales" ]; then
                echo "./copyAndDelete.sh ./store_returns.dat ${targetPath}/store_returns  &" >> writeData.sh
            fi
            if [ "$tblName" = "web_sales" ]; then
                echo "./copyAndDelete.sh ./web_returns.dat ${targetPath}/web_returns &" >> writeData.sh
            fi

		fi

		let partsDone=1+$partsDone
		let workThreads=1+workThreads
	done
done <$workFile;
echo "echo \"[INFO] this machine has ${workThreads} dsden thread\" ">> writeData.sh
echo "echo \"[INFO] Waiting until completion...\" ">> writeData.sh
echo "./wait4process.sh dsdgen 0 " >> writeData.sh
echo "   " >> writeData.sh


echo "[INFO] Started Generation @ "`date +%H:%M:%S`
startTime=`date +%s`

echo "[INFO] Executing writeData.sh on "${worker}
chmod 755 writeData.sh
sh writeData.sh


endTime=`date +%s`
echo "[INFO] Completed Generation @ "`date +%H:%M:%S`
echo "[INFO] Generated and loaded SF"${scaleFactor}" in "`echo $endTime - $startTime |bc`" sec"
