#!/bin/sh
read -a arr
base=${arr[0]}
echo $base
size=${#arr[@]}
echo $size
declare -a res
for((i=1;i<$size;i++));do
	k=0
	x=${arr[i]}
	while(($x>0));do
		res[k]=$(bc <<< "$x%$base")
		x=$(bc <<< "$x/$base")
		((k++))
done
for((j=k-1;j>=0;j--));do
	echo ${res[j]}
done
echo " "
done
