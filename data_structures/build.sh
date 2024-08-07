#!/bin/sh

set -xe

if [ ! -d "./build" ]; then

    mkdir ./build
fi
cc -o ./build/dynamic_array ./dynamic_array.c
cc -o ./build/linked_list ./linked_list.c
cc -o ./build/queue ./queue.c
cc -o ./build/main ./main.c
