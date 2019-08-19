#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

int main(int argc, char **argv)
{
    int size = argc - 1;
    int *numbers = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        sscanf(argv[i + 1], "%d", &numbers[i]);

    bubble_sort(numbers, size);

    for (int i = 0; i < size; i++)
        printf("%u ", numbers[i]);

    printf("\n");
}
