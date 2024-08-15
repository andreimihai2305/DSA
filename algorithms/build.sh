#!/bin/sh

set -xe

if [ ! -d "./build" ]; then

    mkdir ./build
fi

clang -o ./build/bubble_sort ./bubble_sort.c
clang -o ./build/binary_search ./binary_search.c
