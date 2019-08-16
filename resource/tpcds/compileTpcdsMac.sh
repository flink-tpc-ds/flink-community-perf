#!/bin/bash

workDir=`dirname $0`
cd $workDir
workDir=`pwd`

dbgenCodeDir=$workDir/tpc-ds-tool-mac/tools
cd $dbgenCodeDir

### clear old program
rm -f ./dsdgen
rm -f ./dsqgen

### compile for mac os
make OS=MACOS

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


