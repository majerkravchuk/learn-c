#include <stdio.h>
#include <stdlib.h>
#include "binary_search.h"

int main(int argc, char **argv)
{
    int size = 100;
    int array[size];

    for(int i = 0; i < size; i++) {
        array[i] = i * 2;
    }

    int index;

    index = binary_search(array, size, 4);
    printf("search: 24; index: %d\n", index);

    index = binary_search(array, size, 92);
    printf("search: 92; index: %d\n", index);

    index = binary_search(array, size, 424);
    printf("search: 424; index: %d\n", index);

    return 0;
}
