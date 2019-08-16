#!/bin/bash

workDir=`dirname $0`
cd $workDir
workDir=`pwd`

dbgenCodeDir=$workDir/tpc-ds-tool/tools
cd $dbgenCodeDir

### NAME OF ANSI COMPILER HERE
CC=gcc

### Current values for DATABASE are: INFORMIX, DB2, TDAT (Teradata) SQLSERVER, SYBASE, ORACLE, VECTORWISE
DATABASE=SQLSERVER

### Current values for MACHINE are:  ATT, DOS, HP, IBM, ICL, MVS, SGI, SUN, U2200, VMS, LINUX, WIN32
MACHINE=LINUX

### Current values for WORKLOAD are:  TPCH、TPC-DS
WORKLOAD=TPC-DS


cp Makefile.suite makefile

sed -i "s/CC      =/CC=$CC/" makefile

sed -i "s/DATABASE= /DATABASE=$DATABASE/" makefile

sed -i "s/MACHINE = /MACHINE=$MACHINE/" makefile

sed -i "s/WORKLOAD = /WORKLOAD=$WORKLOAD/" makefile

### clear old program
rm -f ./dsdgen
rm -f ./dsqgen

make

### test whether dbgen working
./dsdgen -RELEASE
./dsqgen -RELEASE

### copy to target directory
cp $dbgenCodeDir/dsdgen $workDir/datagen/dsdgen
cp $dbgenCodeDir/tpcds.idx $workDir/datagen/tpcds.idx

cp $dbgenCodeDir/dsqgen $workDir/querygen/
cp $dbgenCodeDir/tpcds.idx $workDir/querygen/tpcds.idx

chmod +x $workDir/datagen/dsdgen
chmod +x $workDir/querygen/dsqgen

# set templates save path
templatesPath=$workDir/querygen/templates/

# import templeates
rm -rf ${templatesPath}
mkdir -p ${templatesPath}

cp -r $workDir/tpc-ds-tool-mac/query_templates/query*.tpl ${templatesPath}
cp -r $workDir/tpc-ds-tool-mac/query_variants/query*.tpl ${templatesPath}
cp -r $workDir/tpc-ds-tool-mac/query_templates/netezza.tpl  ${templatesPath}


echo "Compile SUCCESS..."


