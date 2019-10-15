#include "quick_sort.h"

void quick_sort(int arr[], int low, int high)
{
    int left = low, right = high, pivot = arr[(left + right) / 2];
    while (left < right)
    {
        while (arr[left] < pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left <= right)
        {
            if (arr[left] > arr[right])
                swap(&arr[left], &arr[right]);

            left++;
            right--;
        }
    }

    if (low < right)
        quick_sort(arr, low, right);

    if (left < high)
        quick_sort(arr, left, high);
}
