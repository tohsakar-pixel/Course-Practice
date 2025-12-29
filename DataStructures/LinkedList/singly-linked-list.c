#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct node // 链表
{
    ElemType data;
    struct node *next;
} Node;

Node *initList() // 初始化链表
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

void insertHead(Node *L, ElemType e) // 头插法
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    p->next = L->next;
    L->next = p;
}

void listNode(Node *L) // 遍历
{
    Node *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Node *get_tail(Node *L) // 获取尾部
{
    Node *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    return p;
}

Node *insertTail(Node *tail, ElemType e) // 尾插法
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = e;
    tail->next = p;
    p->next = NULL;
    return p;
}

int insertNode(Node *L, int pos, ElemType e) // 指定位置插入
{
    Node *p = L;
    int i = 0;
    while (i < pos - 1) // 定位前驱
    {
        p = p->next;
        i++;
        if (p == NULL)
        {
            return 0;
        }
    }

    Node *new = (Node *)malloc(sizeof(Node));
    new->data = e;
    new->next = p->next;
    p->next = new;
    return 1;
}

int deleteNode(Node *L, int pos) // 删除指定位置元素
{
    Node *p = L;
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

    if (p->next == NULL)
    {
        printf("要删除的位置错误\n");
        return 0;
    }

    Node *del = p->next;
    p->next = del->next;
    free(del);
    return 1;
}

int lengthList(Node *L)
{
    Node *p = L;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

void freeList(Node *L)
{
    Node *p = L;
    Node *q;
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
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    listNode(list);

    Node *tail = get_tail(list); // 获取尾节点
    tail = insertTail(tail, 30);
    tail = insertTail(tail, 40);
    listNode(list);

    insertNode(list, 2, 15);
    listNode(list);

    deleteNode(list, 2);
    listNode(list);

    int len = lengthList(list); // 长度包含头节点
    printf("%d", len);

    freeList(list);
    return 0;
}
