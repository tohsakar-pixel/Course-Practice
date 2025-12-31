#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;
typedef struct Stack
{
    Elemtype data;
    struct Stack *next;
} stack;

stack *initStack() // 初始化
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->data = 0;
    s->next = NULL;
    return s;
}

int push(stack *s, Elemtype e) // 压栈
{
    stack *p = (stack *)malloc(sizeof(stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

int pop(stack *s, Elemtype *e) // 出栈
{
    if (s->next == NULL)
    {
        printf("empty\n");
        return 0;
    }

    *e = s->next->data;
    stack *del = s->next;
    s->next = del->next;
    free(del);
    return 1;
}

int getTop(stack *s, Elemtype *e) // 获取栈顶元素
{
    if (s->next == NULL)
    {
        printf("empty\n");
        return 0;
    }

    *e = s->next->data;
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
    push(s, 20);
    push(s, 30);

    Elemtype e;
    pop(s, &e);
    printf("%d", e);

    freeStack(s);
    return 0;
}