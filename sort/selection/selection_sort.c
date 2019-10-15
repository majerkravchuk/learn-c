#include "selection_sort.h"

void selection_sort(int arr[], int size)
{
    int min, i, j;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;

        if (min != i)
            swap(&arr[i], &arr[min]);
    }
}
