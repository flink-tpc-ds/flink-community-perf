#!/bin/sh
#######################################
# PLATFORMS: All *nix Systems with given pre-reqs
# PREREQS: ps , grep , wc
# Waits for processes to disappear before proceeding further
# DEPENDANCY: Names and keywords to identify test processes
#  Refer watchCPUMem.txt for more details
# TIMELINE:
# Kunal Khatua [Jun 9, 2013] - Checking in for the 1st time
# Kunal Khatua [Dec 3, 2014] - Providing Pure blocking capabilities
#######################################

if [ $# -lt 1 ]; then
		echo Insufficient Arguments!  
		echo "Usage: $0 <filter> [ThreadCountTrigger]"
	    exit 127
fi

filter=$1
trigger=$2
threadCount=$(($(ps -ef | grep $filter | grep -v 'grep $filter' | grep -v $0 | wc -l) - 1))

if [ $# -lt 2 ]; then
        echo "$filter has $threadCount threads"
        exit 127
fi

# Running in Infinite Loop
while [ $threadCount -gt $trigger ]
do 
	# Sleeping
	sleep 1
	threadCount=$(($(ps -ef | grep $filter | grep -v 'grep $filter' | grep -v $0 | wc -l) - 1))
	#echo "$filter has $threadCount threads"
done

echo "$filter done"

