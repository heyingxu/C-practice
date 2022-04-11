#include<stdio.h>
#include<stdlib.h>
#define MaxSize 50
//typedef char ElemType;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *next;
}tag_t,*ptag_t;

typedef BiTree ElemType;

typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

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

//前序遍历-----非递归 dfs
void PreOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            putchar(p->data);
            Push(S,p);
            p = p->lchild;
        }
        else{
            Pop(S,p);
            p = p->rchild;
        }
    }
}

//中序遍历-----非递归
void InOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p = p->lchild;
        }
        else{
            Pop(S,p);
            putchar(p->data);
            p = p->rchild;
        }
    }
}

//后序遍历-----非递归
void PostOrder2(BiTree T)
{
    SqStack S;
    InitStack(S);
    BiTree p = T, r = NULL;
    while(p || !StackEmpty(S))
    {
        if(p)
        {
            Push(S,p);
            p = p->lchild;
        }
        else{
            GetTop(S,p);
            if(p->rchild && p->rchild != r)
                p = p->rchild;
            else{
                Pop(S,p);
                putchar(p->data);
                r = p;
                p = NULL;
            }
        }
    }
}

//层次遍历  bfs
void LevelOrder(BiTree T)
{
    LinkQueue Q;//辅助队列
    InitQueue(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!isEmpty(Q))
    {
        DeQueue(Q,p);
        putchar(p->data);
        if(p->lchild != NULL)
            EnQueue(Q,p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q,p->rchild);
    }
}

int main()
{
    BiTree pnew;
    char c;
    BiTree tree = NULL;
    ptag_t phead = NULL,ptail = NULL,listpnew,pcur;//辅助队列
    //层次建树
    while(scanf("%c",&c)!=EOF)
    {
        if(c == '\n')
            break;
        //calloc申请空间后里面都会指向0，而malloc不会
        pnew = (BiTree)calloc(1,sizeof(BiTNode));
        pnew->data = c;
        listpnew = (ptag_t)calloc(1,sizeof(tag_t));
        listpnew->p = pnew;
        if(tree == NULL)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;//
            continue;
        }
        else{
            ptail->next = listpnew;
            ptail = listpnew;
        }
        if(pcur->p->lchild == NULL)
            pcur->p->lchild = pnew;
        else if(pcur->p->rchild == NULL)
        {
            pcur->p->rchild = pnew;
            pcur = pcur->next;
        }         
    }
    PreOrder2(tree);
    printf("\n");
    InOrder2(tree);
    printf("\n");
    PostOrder2(tree);
    printf("\n");
    LevelOrder(tree);
    printf("\n");
    return 0;
}
