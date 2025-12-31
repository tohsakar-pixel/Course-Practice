#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next, *prev;
} node;

node *initList() // 初始化链表
{
    node *head = (node *)malloc(sizeof(node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void insertHead(node *L, ElemType e) // 头插法
{
    node *p = (node *)malloc(sizeof(node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if (L->next != NULL)
    {
        L->next->prev = p;
    }
    L->next = p;
}

void listNode(node *L) // 遍历链表
{
    node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

node *get_tail(node *L) // 获取尾部
{
    node *p = L;
    while (p != NULL)
    {
        p = p->next;
    }
    return p;
}

node *insertTail(node *tail, ElemType e) // 尾插法
{
    node *p = (node *)malloc(sizeof(node));
    p->data = e;
    p->next = NULL;
    p->prev = tail;
    tail->next = p;
    return p;
}

void insertNode(node *L, int pos, ElemType e) // 指定位置插入
{
    node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }

    node *n = (node *)malloc(sizeof(node));
    n->data = e;
    n->next = p->next;
    n->prev = p;
    p->next->prev = n;
    p->next = n;
}

void delete(node *L, int pos) // 删除指定位置元素
{
    node *p = L;
    int i = 0;
    while (i < pos - 1)
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }

    node *del = p->next;
    p->next = del->next;
    del->next->prev = p;
    free(del);
}

void freeList(node *L) // 释放链表
{
    node *p = L;
    node *q;
    while (p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;
}

int main()
{
    node *list = initList();
    return 0;
}