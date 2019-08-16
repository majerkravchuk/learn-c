#include <stdio.h>
#include "../_shared/get_string.h"

int main()
{
    printf("What is your name?\n");
    char* string = get_string();

    printf("Hello, %s!\n", string);
    return 0;
}
