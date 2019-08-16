#ifndef LEARN_C_STACK_H
#define LEARN_C_STACK_H

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int capacity;
    int size;
    double* items;
};

struct stack* new_stack(int capacity);

int is_full(struct stack* s);
int is_empty(struct stack* s);

void push(struct stack* s, double x);
double pop(struct stack* s);

#endif
