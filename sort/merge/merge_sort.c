#include "merge_sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int ls = mid - left + 1;
    int rs = right - mid;

    int l_half[ls];
    int r_half[rs];

    int l = 0;
    int r = 0;
    int k = left;

    for (int i = 0; i < ls; i++)
        l_half[i] = arr[i + left];

    for (int i = 0; i < rs; i++)
        r_half[i] = arr[i + mid + 1];

    while (l < ls && r < rs)
    {
        if (l_half[l] <= r_half[r])
        {
            arr[k] = l_half[l];
            l++;
        }
        else
        {
            arr[k] = r_half[r];
            r++;
        }
        k++;
    }

    while (l < ls)
    {
        arr[k] = l_half[l];
        l++;
        k++;
    }

    while (r < rs)
    {
        arr[k] = r_half[r];
        r++;
        k++;
    }
}

