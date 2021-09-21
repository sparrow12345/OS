# !/bin/bash

N=$1

for i in `seq 1 $N`
do

a=0

for j in `cat file.txt`
do
    a=$j
done

a=$(($a+1))

echo $a >> file.txt

done
