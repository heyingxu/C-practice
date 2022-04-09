#include<stdio.h>
#define MaxSize 5

typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}

bool EnQueue(SqQueue &Q,ElemType x)
{
    if((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x)
{
    if(Q.front == Q.rear)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    SqQueue Q;
    InitQueue(Q);
    bool flag = isEmpty(Q);
    if(flag)
        printf("初始化成功！\n");
    else
        printf("初始化失败！\n");
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    flag = EnQueue(Q,6);
    if(flag)
        printf("入队成功！\n");
    else
        printf("入队失败！\n");
    flag = EnQueue(Q,7);
    if(flag)
        printf("入队成功！\n");
    else
        printf("入队失败！\n");
    ElemType x;
    flag = DeQueue(Q,x);
    if(flag)
        printf("出队成功！出队元素为：%d\n",x);
    else
        printf("出队失败！\n");
    flag = DeQueue(Q,x);
    if(flag)
        printf("出队成功！出队元素为：%d\n",x);
    else
        printf("出队失败！\n");
    flag = DeQueue(Q,x);
    if(flag)
        printf("出队成功！出队元素为：%d\n",x);
    else
        printf("出队失败！\n");
    flag = DeQueue(Q,x);
    if(flag)
        printf("出队成功！出队元素为：%d\n",x);
    else
        printf("出队失败！\n");
    flag = DeQueue(Q,x);
    if(flag)
        printf("出队成功！出队元素为：%d\n",x);
    else
        printf("出队失败！\n");
    flag = DeQueue(Q,x);
}
