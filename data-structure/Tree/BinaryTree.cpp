#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

typedef struct tag{
    BiTree p;//树的某一个结点的地址值
    struct tag *next;
}tag_t,*ptag_t;

//前序遍历-----递归
void PreOrder(BiTree p)
{
    if(p != NULL)
    {
        putchar(p->data);
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

//中序遍历-----递归
void InOrder(BiTree p)
{
    if(p != NULL)
    {
        InOrder(p->lchild);
        putchar(p->data);
        InOrder(p->rchild);
    }
}

//后序遍历-----递归
void PostOrder(BiTree p)
{
    if(p != NULL)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        putchar(p->data);
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
    PreOrder(tree);
    printf("\n");
    InOrder(tree);
    printf("\n");
    PostOrder(tree);
    printf("\n");
    return 0;
}
