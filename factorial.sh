#!/bin/sh
read a
fact=1
for ((i=1;i<=$a ;i++));do
	fact=$(bc <<< "$i*$fact")
done
echo $fact
