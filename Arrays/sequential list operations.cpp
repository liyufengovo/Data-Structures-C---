#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 10 // 定义最大长度

typedef struct
{
    int data[MAX_SIZE]; // 定义静态数组
    int length;         // 顺序表的当前长度
} SqList;               // 顺序表的类型定义

// 初始化顺序表
void InitList(SqList &L)
{
    L.length = 0; // 顺序表初始长度为 0
}

// 在 L 的位序 i 处插入元素 e
// 注意区分【位序】和【下标】，位序从1开始，下标从0开始
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) // 判断i的范围是否有效
        return false;
    if (L.length >= MAX_SIZE) // 当前存储的元素已达到最大值，不能插入
        return false;
    for (int j = L.length; j >= i; j--) // 将第i个元素及之后的元素后移
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e; // 在位置 i 处放入 e
    L.length++;        // 插入成功，表长加1
    return true;
}

// 删除顺序表 L 的位序 i，并使用 e 返回删除的值
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) // 判断 i 的范围是否有效
        return false;
    e = L.data[i - 1];                 // 将被删除的元素赋值给 e
    for (int j = i; j < L.length; j++) // 将第 i 个位置后的元素前移
        L.data[j - 1] = L.data[j];
    L.length--; // 删除成功，表长减1
    return true;
}

// 按位序查找，返回的为值
int ListGetElem(SqList L, int i)
{
    if (i < 1 || i > L.length) // 判断 i 的范围是否有效，-999 为约定的失败代表值可以为任意能代表失败的数
        return -999;
    return L.data[i - 1];
}

// 按值查找，返回的为位序
int ListLocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1; // 返回的为位序，所以是下标 + 1
    }
    return -1;
}

void ListPrint(SqList L)
{
    cout << "线性表为: ";
    for (int i = 0; i < L.length; i++)
        cout << L.data[i] << " ";
    cout << '\n';
}

// 在尾部插入
bool ListInsertTail(SqList &L, int e)
{
    if (L.length >= MAX_SIZE) // 当前存储的元素已达到最大值，不能插入
        return false;
    L.data[L.length] = e;
    L.length = L.length + 1;
    return true;
}

int main()
{
    SqList L;    // 声明一个顺序表
    InitList(L); // 初始化顺序表
    ListInsert(L, 1, 1);
    ListInsert(L, 1, 2);
    ListInsert(L, 1, 3);
    ListInsert(L, 1, 4);
    ListInsert(L, 8, 7); // 超出length，并没有插入成功
    ListPrint(L);
    int delValue; // 要删除的元素
    ListDelete(L, 1, delValue);
    ListPrint(L);
    return 0;
}