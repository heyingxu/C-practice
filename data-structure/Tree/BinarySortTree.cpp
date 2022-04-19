#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;
typedef struct BSTNode{
    KeyType key;
    struct BSTNode *lchild, *rchild;
}BSTNode, *BiTree;

int BST_Insert(BiTree &T, KeyType k)
{
    if(T == NULL)
    {
        T = (BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }
    else if(k == T->key)
        return 0;
    else if(k < T->key)
        return BST_Insert(T->lchild,k);
    else
        return BST_Insert(T->rchild,k);
}

void Create_BST(BiTree &T, KeyType str[], int n)
{
    T = NULL;
    int i = 0;
    while(i < n)
    {
        BST_Insert(T,str[i]);
        i++;
    }

}

BiTree Search_BST(BiTree T, KeyType key, BiTree &p)
{
    p = NULL;
    while(T != NULL && key != T->key)
    {
        p = T;
        if(key < T->key)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}
void InOrder(BiTree T)
{
    if(T != NULL)
    {
        InOrder(T->lchild);
        printf("%-3d",T->key);
        InOrder(T->rchild);
    }
}

void DeleteNode(BiTree &T, KeyType x)
{
    if(T == NULL)
        return;
    if(T->key > x)
        DeleteNode(T->lchild, x);
    else if(T->key < x)
        DeleteNode(T->rchild, x);
    else{
        if(T->lchild == NULL)
        {
            BiTree tempNode = T;
            T = T->rchild;
            free(tempNode);
        }
        else if(T->rchild == NULL)
        {
            BiTree tempNode = T;
            T = T->lchild;
            free(tempNode);
        }
        else{
            //一般替补的是左子树的最大数据或者右子树的最小数据
            BiTree tempNode = T->lchild;
            if(tempNode->rchild != NULL)
                tempNode = tempNode->rchild;
            T->key = tempNode->key;
            DeleteNode(T->lchild,tempNode->key);
        }
    }
}

int main()
{
    BiTree T;
    BiTree parent;
    BiTree Search;
    KeyType str[] = {54, 20, 66, 40, 28, 79, 58};
    Create_BST(T,str,7);
    InOrder(T);
    printf("\n");
    Search = Search_BST(T,40,parent);
    if(Search)
        printf("找到对应结点，值=%d\n",Search->key);
    else
        printf("未找到对应结点\n");
    DeleteNode(T,66);
    InOrder(T);
    return 0;
}
