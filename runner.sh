#!/bin/bash

rm -fr "comparison.txt"
touch "comparison.txt" ## create the output results
## run python
python3 python/change.py -c >> "comparison.txt"

sleep 2

# ## run julia
julia julia/change.jl -c >> "comparison.txt"

sleep 2
## run c 
cd ./c 
make clean 
make all
cd ../ ## go back to the MakeChange directory
./c/change -c >> "comparison.txt"
cd c 
make clean
cd ../

sleep 1
## run c++
cd cpp
make clean
make all
cd ../
./cpp/change.exe -c >> "comparison.txt"
cd cpp 
make clean
cd ../
sleep 1

## run rust
./rust/target/debug/change -c >> "comparison.txt"

echo "All programs have been executed and logged in comparison.txt"


