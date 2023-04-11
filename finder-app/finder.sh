#!/bin/sh

if [ $# -ne 2 ]
then
    echo "The arguments should be ./finder.sh [filesdir] [searchstr]"
    return 1
fi

if [ ! -d $1 ]
then
    echo "$1 is not a directory"
    return 1
fi

FILESDIR=$1
SEARCHSTR=$2

NUMFILES=`find $FILESDIR -type f 2> /dev/null | wc -l`
NUMHIT=`grep $SEARCHSTR -r $FILESDIR | wc -l`

echo "The number of files are $NUMFILES and the number of matching lines are $NUMHIT"
