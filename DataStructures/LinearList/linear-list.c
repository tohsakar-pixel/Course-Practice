#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct // 顺序表
{
    ElemType *data;
    int length;
} SqList;

SqList *InitList() // 初始化顺序表，使其返回指针
{
    SqList *L = (SqList *)malloc(sizeof(SqList));
    L->data = (ElemType *)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    return L;
}

int append(SqList *L, ElemType e) // 在顺序表末尾添加元素
{
    if (L->length == MAXSIZE)
    {
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

int insert(SqList *L, int pos, ElemType e) // 在顺序表指定位置插入元素
{
    if (L->length == MAXSIZE)
    {
        printf("顺序表已满\n");
        return 0;
    }

    if (pos < 1 || pos > L->length + 1)
    {
        printf("位置不合法\n");
        return 0;
    }

    if (pos < L->length)
    {
        for (int i = L->length - 1; i >= pos - 1; i--)
        {
            L->data[i + 1] = L->data[i];
        }
        L->data[pos - 1] = e;
        L->length++;
    }
    return 1;
}

int delete(SqList *L, int pos, ElemType *e) // 删除顺序表指定位置的元素
{
    if (L->length == 0)
    {
        printf("顺序表为空\n");
        return 0;
    }

    if (pos < 1 || pos > L->length)
    {
        printf("位置不合法\n");
        return 0;
    }

    *e = L->data[pos - 1];
    if (pos < L->length)
    {
        for (int i = pos; i < L->length; i++)
        {
            L->data[i - 1] = L->data[i];
        }
        L->length--;
    }
    return 1;
}

void printList(SqList *L) // 打印顺序表
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int find(SqList *L, ElemType e) // 查找顺序表中指定元素的位置
{
    if (L->length == 0)
    {
        printf("顺序表为空\n");
        return 0;
    }

    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    SqList *L = InitList();
    printf("Initialized list\n");
    printf("占用字节：%zu\n", sizeof(L->data));

    append(L, 1);
    append(L, 2);
    append(L, 3);

    insert(L, 2, 4);

    ElemType del; // 删除的元素
    delete(L, 3, &del);
    printf("删除的元素：%d\n", del);

    printList(&L);

    printf("元素4的位置: %d\n", find(L, 4));

    free(L->data);
    free(L);
    return 0;
}
