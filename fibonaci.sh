#!/bin/sh
read n
a=1
b=1
echo $a
echo $b
for ((i=1;i<=$n-2 ;i++));do
	c=$(bc <<< "$a+$b")
	echo $c
	a=$b
	b=$c
done
