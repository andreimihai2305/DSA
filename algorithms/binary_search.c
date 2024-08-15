#include <stdio.h>

int binary_search(int arr[], int size, int item)
{
    int low = 0;
    int high = size - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == item) return mid;
        else if (arr[mid] < item) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    printf("Hello from Binary Search!\n");
    int size = 10;
    int arr[10] = {1, 2, 5, 7, 9, 12, 67, 78, 98, 100};
    int item = binary_search(arr, 10, 98);
    printf("%d: %d\n", arr[item], item);
    return 0;
}
