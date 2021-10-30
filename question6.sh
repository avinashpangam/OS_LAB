#!/bin/bash

echo "Enter the file path."
read filePath


if [ -f "$filePath" ]
then
	printf '\n'
	#Checking write permissions
	[ -w $filePath ] && W="Write = Yes" || W="Write = No"
	
	#Checking excute permissions
	[ -x $filePath ] && X="Execute=Yes" || X="Execute=NO"

	#Checking read permissions
	[ -r $filePath ] && R="Read=Yes" || R="Read=No"
	echo "Current file permissions are"
	echo $W $X $R
	
	printf '\n'
	echo "File's path is ${filePath}"
	fileType=$( file  --mime-type  <"$filePath" )
	echo "$fileType"

	echo "Files present in directory are:- "
	count=$1
	for items in "$filePath"/*
	do
		echo "$items"
		count=$((count + 1))
	done
	echo "There are ${count} files in your directory"

else
	echo "Given file path doesn't exist."
fi
