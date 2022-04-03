#include<stdio.h>

typedef int ElemType;
typedef struct{
    ElemType data[50];
    int length;
}SqList;

bool List_Insert(SqList &L,int i,ElemType e)
{
    if(i<1 || i>L.length+1)
        return false;
    if(L.length >= 50)
        return false;
    for(int j = L.length; j >= i; j--)
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;
    L.length++;
    return true;
}

bool List_Delete(SqList &L,int i,ElemType &e)
{
    if(i<1 || i>L.length)
        return false;
    if(L.length == 0)
        return false;
    e = L.data[i-1];
    for(int j = i;j<L.length;j++)
        L.data[j-1] = L.data[j];
    L.length--;
    return true;
}

int Locate_Elem(SqList L,ElemType e)
{
    for(int i = 0; i < L.length;i++)
        if(L.data[i] ==e)
            return i+1;
    return 0;    
}

void print_List(SqList &L)
{
    for(int i = 0;i < L.length ;i++)
        printf("%-4d",L.data[i]);
    printf("\n");
}

int main()
{
    SqList L;
    bool ret;
    ElemType del; 
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.length = 3;
    ret = List_Insert(L,2,60);
    if (ret ==  true)
    {
        printf("插入成功！\n");
        print_List(L);
    }
    else
        printf("插入失败！\n");
    ret = List_Delete(L,1,del);
    if(ret)
    {
        printf("删除成功！删除的元素为%d\n",del);
        print_List(L);
    }
    else
        printf("删除失败！\n");
    int elem_pos;
    elem_pos = Locate_Elem(L,60);
    if(elem_pos)
    {
        printf("查找成功！元素位置为%d\n",elem_pos);
    }
    else{
        printf("查找失败!");
    }
    return 0;
}
