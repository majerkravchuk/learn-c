#include "bubble_sort.h"

void bubble_sort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int* a, int* b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
