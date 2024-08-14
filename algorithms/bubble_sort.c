#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arr[], int size)
{
    bool sorted;
    do
    {
        sorted = true;
        for (int i = 0; i < size - 1; i++)
        {
            // printf("%d\n", arr[i]);
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i+1] = arr[i];
                arr[i] = temp;
                sorted = false;
            }
        }

    } while (!sorted);
}

int main(void)
{
    static int size = 10;
    int arry[10] = {10, 3, 6, 1, 9, 34, 21, 2, 6, 11};
    printf("Before Sort: \n");
    for(int i = 0; i < size; i++) printf("%d ", arry[i]);
    printf("\n");

    printf("After Sort: \n");
    bubble_sort(arry, size);

    for(int i = 0; i < size; i++) printf("%d ", arry[i]);
    printf("\n");


    return 0;
}
