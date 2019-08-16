#include "get_string.h"

char* get_string(void)
{
    char* buffer = NULL;

    unsigned short int capacity = 0;
    unsigned short int n = 0;

    int c;

    while((c = fgetc(stdin)) != '\n' && c != EOF)
    {
        if (n + 1 > capacity)
        {
            if (capacity + 128 < USHRT_MAX)
            {
                capacity += 128;
            }
            else
            {
                free(buffer);
                return NULL;
            }

            char* tmp = realloc(buffer, capacity * sizeof(char));
            if (tmp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = tmp;
        }

        buffer[n++] = (char)c;
    }

    if (n == 0 && c == EOF)
    {
        return NULL;
    }

    char* string = malloc((n + 1) * sizeof(char));
    strncpy(string, buffer, n);
    free(buffer);

    string[n] = '\0';

    return string;
}
