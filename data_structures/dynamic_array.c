#include <stdio.h>
#include "./dynamic_array.h"

int main(void)
{
    DynamicArray arr = {0};
    if (d_alloc(&arr, 10) != 0)
    {
        printf("ERROR: Something went wrong during allocation\n");
    }

    free(&arr);

    return 0;

}
