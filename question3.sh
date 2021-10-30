
#!bin/bash

echo "Enter number :"
read n

echo "Enter digit you want to find"
read x
f=0
while [ $n -gt 0 ]
do 
	digit=$((n%10))
	if [ $digit == $x ]
	then
		f=1
	fi
	n=$((n/10))
done

if [ $f == 1 ]
then 
	echo "Digit present"
else
	echo "Digit not present"

fi