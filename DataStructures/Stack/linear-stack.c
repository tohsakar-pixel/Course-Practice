#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int Elemtype;
typedef struct
{
    Elemtype *data;
    int top;
} stack;

stack *initStack() // 初始化栈
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = (Elemtype *)malloc(sizeof(Elemtype) * MAXSIZE);
    s->top = -1;
    return s;
}

int push(stack *s, Elemtype e) // 压栈
{
    if (s->top >= MAXSIZE - 1)
    {
        printf("满了");
        return 0;
    }

    s->top++;
    s->data = e;
    return 1;
}

int pop(stack *s, Elemtype *e) // 出栈
{
    if (s->top == -1)
    {
        printf("空的");
        return 0;
    }

    *e = s->data[s->top];
    s->top--;
    return 1;
}

int getTop(stack *s, Elemtype *e) // 获取栈顶元素
{
    if (s->top == NULL)
    {
        printf("空的\n");
        return 0;
    }

    *e = s->data[s->top];
    return 1;
}

void freeStack(stack *s)//释放栈
{
    stack *p = s;
    while(p!=NULL)
    {
        stack *temp = p;
        p = p->next;
        free(temp);
    }
}

int main()
{
    stack *s = initStack();
    push(s, 10);
    Elemtype e;
    freeStack(s);
    return 0;
}
