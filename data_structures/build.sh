#!/bin/sh

set -xe


if [ ! -d "./build" ]; then

    mkdir ./build
fi
cc -o ./build/dynamic_array ./dynamic-array/dynamic_array.c
cc -o ./build/linked_list ./linked-list/linked_list.c
cc -o ./build/queue -I./dynamic-array/ ./queue/queue.c
cc -o ./build/main -I./dynamic-array/ ./main.c
cc -o ./build/stack ./stack/stack.c
cc -o ./build/hash_table ./hash-table/hash_table.c
cc -o ./build/binary_tree ./binary-tree/binary_tree.c

