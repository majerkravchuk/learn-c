#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main(int argc, char **argv)
{
    int target;
    sscanf(argv[1], "%d", &target);

    int x = factorial(target);
    printf("%d! = %d\n", target, x);

    return 0;
}
