#!/bin/bash

## run python
python3 python/change.py -c

sleep 2

## run julia
julia julia/change.jl -c

sleep 2
## run c 
cd ./c 
make clean 
make all
cd ../ ## go back to the MakeChange directory
./c/change -c

sleep 1


