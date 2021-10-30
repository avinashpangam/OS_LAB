#!/bin/bash

echo "Enter the number of elements required"
read n

a=0
b=1

echo "Required Series is : "
for (( i=0; i<n; i++ ))
do
	echo -n "$a "
	temp=$((a + b))
	a=$b
	b=$temp
done

