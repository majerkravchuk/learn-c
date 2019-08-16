#include "stack.h"

struct stack* new_stack(int capacity)
{
    struct stack* pt = (struct stack*)malloc(sizeof(struct stack));

    pt->size = 0;
    pt->capacity = capacity;
    pt->items = (double*)malloc(sizeof(double) * capacity);

    return pt;
}

int is_full(struct stack* s)
{
    return (s->size >= s->capacity);
}

int is_empty(struct stack* s)
{
    return (s->size <= 0);
}

void push(struct stack* s, double x)
{
    if (s->size < s->capacity)
    {
        s->items[s->size++] = x;
    }
    else
    {
        printf("error: stack overflow");
        exit(EXIT_FAILURE);
    }
}

double pop(struct stack* s)
{
    if (s->size > 0)
    {
        return s->items[--s->size];
    }
    else
    {
        printf("error: stack is empry");
        exit(EXIT_FAILURE);
    }
}
