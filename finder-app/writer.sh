#!/bin/sh

if [ $# -lt 2 ]
then
	exit 1
fi

echo "$2" > "$1"
exit 0