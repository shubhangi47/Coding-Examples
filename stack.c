#include <stdio.h>

typedef struct stack
{
    char data[64];
    int top;
} stack;
int empty(stack *p)
{
    return (p->data == -1);
}
int top(stack *p)
{
    return (p->data[p->top]);
}
void push(stack *p, char a)
{
    p->data[++(p->top)] = a;
    return;
}
void pop(stack *p)
{
    if (!empty(&p))
    {
        p->top--;
    }
    return;
}
int main()
{
    stack s;
    s.top = -1;
    char str[10] = "ABCDE";
    int i, len;
    len = sizeof(str);
    for (i = 0; i < len; i++)
    {
        push(&s, str[i]);
    }
    printf(" string\n ");
    for (i = 0; i < len; i++)
    {
        printf("%c", s.data[i]);
    }
    printf("\n");
    printf(" reverse string\n ");
    for (i = 0; i < len; i++)
    {
        printf("%c", top(&s));
        pop(&s);
    }
    printf("\n");

    return 0;
}