#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//with the head node

//头插法新建链表
LinkList CreateList1(LinkList &L)
{
    int x;LNode *s;
    L=(LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}
//尾插法新建链表
LinkList CreateList2(LinkList &L)
{
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d",&x);
    while(x != 9999)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}
//打印链表
void PrintList(LinkList L)
{
    L = L->next;
    while(L != NULL)
    {
        printf("%d ",L->data);
        L = L->next;
    }
    printf("\n");
}
//按位查找
LinkList GetElem(LinkList L,int i)
{
    int j = 1;
    LinkList p = L->next;
    if(i==0)
        return L;
    if(i < 1)
        return NULL;
    while(p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//按值查找
LinkList LocateElem(LinkList L,ElemType e)
{
    LinkList p = L->next;
    while(p != NULL && p->data !=e)
        p = p->next;
    return p;
}
//新节点插入第i个位置
bool InsertList(LinkList L,int i,ElemType e)
{
    LinkList p = GetElem(L,i-1);
    if(p==NULL)
        return false;
    LinkList s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
//删除链表中的第i个节点
bool DeleteList(LinkList L,int i)
{
    LinkList p = GetElem(L,i-1);
    if(p == NULL)
        return false;
    LinkList q = p->next;
    if(q == NULL)
        return false;
    p->next = q->next;
    free(q);
    q=NULL;
    return true;
}
int main()
{
    LinkList L;
    CreateList2(L);
    PrintList(L);
    LinkList p = GetElem(L,2);
    if(p!=NULL)
        printf("第2个位置上的元素为%d\n",p->data);
    p = LocateElem(L,5);
    if(p)
        printf("5存在在链表中\n");
    else
        printf("5不存在在链表中\n");
    bool flag = InsertList(L,4,20);
    if(flag)
    {
        printf("插入20成功，此时链表为：\n");
        PrintList(L);
    }
    else
        printf("插入失败!\n");
    flag = DeleteList(L,3);
    if(flag)
    {
        printf("删除成功，此时的链表为：\n");
        PrintList(L);
    }
    else
        printf("删除失败");
    return 0;
}
