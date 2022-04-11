#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

void EnQueue(LinkQueue &Q,ElemType x)
{
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q,ElemType &e)
{
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(p == Q.rear)
        Q.rear = Q.front;
    free(p);
    return true;
}

bool isEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}

int main()
{
    LinkQueue Q;
    bool ret;
    ElemType element;
    InitQueue(Q);
    EnQueue(Q,3);
    EnQueue(Q,4);
    EnQueue(Q,5);
    EnQueue(Q,6);
    EnQueue(Q,7);
    for(int i = 0; i < 6; i++)
    {
        ret = DeQueue(Q,element);
        if(ret)
            printf("出队成功！出队元素为：%d\n",element);
        else
            printf("出队失败！\n");
    }
    return 0;
}
