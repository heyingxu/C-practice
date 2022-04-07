#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;
//头插法新建链表
DLinkList DList_head_insert(DLinkList &DL)
{
    DNode *s;
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));
    DL->prior = NULL;
    DL->next = NULL;
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        s->next = DL->next;
        if(DL->next!=NULL)
            DL->next->prior = s;
        s->prior = DL;
        DL->next = s;
        scanf("%d",&x);
    }
    return DL;
}
//尾插法新建链表
DLinkList DList_tail_insert(DLinkList &DL)
{
    int x;
    DL = (DLinkList)malloc(sizeof(DNode));
    DNode *s ,*r = DL;
    DL->prior = NULL;
    scanf("%d",&x);
    while(x!=9999)
    {
        s = (DLinkList)malloc(sizeof(DNode));
        s->data = x;
        r->next = s;
        s->prior = r;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return DL;
}
//打印链表
void PrintDList(DLinkList DL)
{
    DL = DL->next;
    while(DL!=NULL)
    {
        printf("%3d",DL->data);
        DL = DL->next;
    }
    printf("\n");
}
//按位查找
DLinkList GetElem(DLinkList DL,int i)
{
    int j = 1;
    DLinkList p = DL->next;
    if(i==0)
        return DL;
    if(i < 1)
        return NULL;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//插入第i个新节点
bool InsertDList(DLinkList DL,int i,ElemType e)
{
    DLinkList p = GetElem(DL,i-1);
    if(p==NULL)
        return false;
    DLinkList s = (DLinkList)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}
//输出第i个新节点
bool DeleteDList(DLinkList DL,int i)
{
    DLinkList p = GetElem(DL,i-1);
    if(p==NULL)
        return false;
    DLinkList q;
    q = p->next;
    if(q==NULL)
        return false;
    p->next = q->next;
    if(q->next!=NULL)
        q->next->prior = p;
    free(q);
    q = NULL;
    return true;
}
int main()
{
    DLinkList DL;
    //DList_head_insert(DL);
    DList_tail_insert(DL);
    PrintDList(DL);
    return 0;
}
