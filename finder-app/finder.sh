#!/bin/sh

if [ $# -lt 2 ]
then
	exit 1
fi

if [ ! -d "$1" ]; then
    exit 2
fi

count=`find "$1" -type f | wc -l`
found=`grep -Rl "$2" "$1" | wc -l`
echo "The number of files are $count and the number of matching lines are $found"
exit 0