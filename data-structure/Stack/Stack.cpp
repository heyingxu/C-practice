#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50

typedef int ElemType;
//用顺序表形式实现栈
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;
}

bool StackEmpty(SqStack S)
{
    if(S.top == -1)
        return true;
    return false;
}

bool Push(SqStack &S, ElemType x)
{
    if(S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}

bool GetTop(SqStack S,ElemType &m)
{
    if(StackEmpty(S))
        return false;
    m = S.data[S.top];
    return true;
}

bool Pop(SqStack &S, ElemType &x)
{
    if(StackEmpty(S))
        return false;
    x = S.data[S.top--];
    return true;
}

int main()
{
    SqStack S;//FILO
    InitStack(S);//初始化
    bool flag = StackEmpty(S);
    if(flag)
        printf("初始化成功！\n");
    else
        printf("初始化失败！\n");
    Push(S,3);
    Push(S,4);
    Push(S,5);
    ElemType m;//存储取出的栈内元素
    flag = GetTop(S,m);
    if(flag)
    {
        printf("获取成功，栈顶元素为:%d\n",m);
    }
    else
        printf("获取失败\n");
    flag = Pop(S,m);
    if(flag)
        printf("弹出成功，弹出元素为:%d\n",m);
    flag = Pop(S,m);
    if(flag)
        printf("弹出成功，弹出元素为:%d\n",m);
    flag = Pop(S,m);
    if(flag)
        printf("弹出成功，弹出元素为:%d\n",m);
    flag = Pop(S,m);
    if(flag)
        printf("弹出成功，弹出元素为:%d\n",m);
    else
        printf("弹出失败\n");
    return 0;
}
