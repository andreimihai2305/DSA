#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"



int main(void)
{
    printf("Hello From Queue!\n");
    int *ptr = NULL;
    int size = 10;


    printf("%p\n", ptr);

    ptr = (int*)malloc(size*sizeof(int));

    if (ptr == NULL)
    {
        printf("Error could not allocate ptr.\n");
        return 1;
    }
    printf("Pointers after allocation: %p\n", ptr);

    for (size_t i = 0; i < size; i++)
    {
        int *temp = ptr + i;
        *temp= i;
        printf("%p: %d\n", ptr+i, ptr[i]);
    }

    printf("Value of ptr: %p, Value at address ptr: %d\n", ptr, *ptr);

    ptr += 1;
    printf("Value of ptr: %p, Value at address ptr: %d\n", ptr, *ptr);


    printf("\n");
    ptr -= 1;
    free(ptr);
    return 0;
}
