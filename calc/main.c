#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../_shared/stack.h"

#define NUMBER '0'
#define MAX_STACK_SIZE 99
#define MAX_OPERATOR_SIZE 9

int get_operator(char* string);

int main()
{
    struct stack* s = new_stack(MAX_STACK_SIZE);

    char* operator = (char*)malloc(sizeof(char) * MAX_OPERATOR_SIZE);
    int type;

    double l_operand;
    double r_operand;

    while ((type = get_operator(operator)) != EOF)
    {
        if (type == NUMBER)
        {
            push(s, strtod(operator, NULL));
        }
        else if (type == '+' || type == '-' || type == '*' || type == '/')
        {
            r_operand = pop(s);
            l_operand = pop(s);

            switch (type)
            {
                case '+':
                    push(s, l_operand + r_operand);
                    break;
                case '-':
                    push(s, l_operand - r_operand);
                    break;
                case '*':
                    push(s, l_operand * r_operand);
                    break;
                case '/':
                    push(s, l_operand / r_operand);
                    break;
                default:
                    break;
            }
        }
        else if (type == '\n' || type == EOF)
        {
            printf("%.8g\n", pop(s));
        }
        else
        {
            printf("error: what? %s\n", operator);
        }
    }

    return 0;
}

int get_operator(char* string)
{
    int i = 0;
    int c;

    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (!isdigit(c))
    {
        return c;
    }

    if (isdigit(c))
    {
        string[0] = (char)c;
        while (isdigit(string[++i] = (char)(c = getchar())))
            ;
    }

    if (c == '.')
        while (isdigit(string[++i] = (char)(c = getchar())))
            ;

    string[i] = '\0';

    if (c != EOF)
    {
        ungetc((char)c, stdin);

    }

    return NUMBER;
}
