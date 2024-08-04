#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<stdio.h>
#include<stdlib.h>


typedef struct {
    int size;
    int count;
    int* items;

} DynamicArray; 

int d_alloc(DynamicArray *arr, int size);
int dynamic_append(DynamicArray *arr, int item);
int pop_back(DynamicArray *arr);


int d_alloc(DynamicArray *arr, int size)
{   
    printf("Beginning allocation...\n");
    printf("Trying to set the size...\n");
    arr->size = size;
    printf("Size set succesfully: arr->size = %d\n", arr->size);
    arr->count = 0;
    printf("Count set succesfully: arr->count = %d\n", arr->count);
    arr->items = (int*) malloc(size * sizeof(int));
    if (arr->items == NULL) return -1;
    printf("Items set succesfully: arr->items = %p\n", arr->items);
    return 0;
};


int dynamic_append(DynamicArray *arr, int item)
{
    if (arr->count < arr->size)
    {
        arr->items[arr->count] = item;
    }
    else
    { 
        arr->size += 20;
        arr->items = (int*)realloc(arr->items, (arr->size)*sizeof(int));
        if(arr->items == NULL) return -1;
        arr->items[arr->count] = item;
    }
    arr->count++;
    return 0;
}

int pop_back(DynamicArray *arr)
{
    if (arr->count <= 0) return -1;
    arr->count--;
    return arr->items[arr->count];

}

#endif // DYNAMIC_ARRAY_H


