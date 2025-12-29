#include <math.h>
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

Node *initListWithElem(ElemType e) // 初始化节点
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = NULL;
    return node;
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

void findFromEnd(Node *L, int pos) // 快慢指针查找倒数第几个元素
{
    if (!L || !L->next || !L->next->next)
        return NULL;

    Node *slow = L, *fast = L;

    // 快指针先走pos步
    for (int i = 0; i < pos; i++)
    {
        fast = fast->next;
    }

    // 两指针同步前进
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    printf("倒数第%d个节点值为%d\n", pos, slow->data);
}

int lengthList(Node *L) // 链表长度
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

void freeList(Node *L) // 释放链表
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

// 查找两个链表的共同起始位置
Node *findIntersectionNode(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    Node *p = headA;
    int lenA = 0;
    int lenB = 0;

    while (p != NULL) // 获取链表A的长度
    {
        p = p->next;
        lenA++;
    }

    p = headB;
    while (p != NULL) // 获取链表B的长度
    {
        p = p->next;
        lenB++;
    }

    Node *fast; // 快指针
    Node *slow; // 慢指针
    int step;   // 两个单词之间差值
    if (lenA > lenB)
    {
        step = lenA - lenB;
        fast = headA;
        slow = headB;
    }
    else
    {
        step = lenB - lenA;
        fast = headB;
        slow = headA;
    }

    for (int i = 0; i < step; i++) // 快指针先走step步
    {
        fast = fast->next;
    }

    while (fast != NULL) // 快慢指针同步走，直到指向同一个节点
    {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

// 删除绝对值相同的节点

/*  引入一个数组，将链表data里的数字对应数组下标。
    如果出现data数字，则数组对应下标的值变为1。
    若出现的data值对应的下标已经为1了，则删掉那个重复节点。 */

void delSameNode(Node *L, int n)
{
    Node *p = L;
    int index;                                    // 作为数组下标
    int *arr = (int *)calloc(n + 1, sizeof(int)); // 初始化为0

    while (p->next != NULL)
    {
        index = abs(p->next->data); // abs获取绝对值
        if (arr[index] == 0)
        {
            arr[index] = 1;
            p = p->next;
        }
        else
        {
            Node *temp = p->next;
            p->next = temp->next;
            free(temp);
        }
    }
    free(arr);
}

// 反转链表

/*  first指向空，用于将第一个节点指向空、新建的头节点指向原来的尾节点
    second用于将自己所在的指针反转方向、确定遍历结束
    third用于连接反转完的部分和未反转的部分  */

Node *reserveList(Node *head)
{
    Node *first = NULL;
    Node *second = head->next;
    Node *third;

    while (second != 0)
    {
        third = second->next;
        second->next = first;
        first = second;
        second = third;
    }

    Node *hd = initList();
    hd->next = first;

    return hd;
}

//删除中间节点

/*  快慢指针。快指针一次走两步，慢指针一次一步
    快指针永远是慢指针的2倍
    如果快指针的当前节点或者下一节点是空，则说明慢指针是中间节点的前置节点  */

void delMiddleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;

    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *q = slow->next;
    slow->next = q->next;
    free(q);
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

    findFromEnd(list, 3);
    freeList(list);
    return 0;
}
