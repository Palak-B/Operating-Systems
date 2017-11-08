#!/bin/sh
read basics
read TA
ten=10
x=$(bc <<< "$TA/$ten")
echo $x
gs=$(bc <<< "$basics+$TA+$x")
echo $gs
echo $basics + $TA*1.1 | bc
