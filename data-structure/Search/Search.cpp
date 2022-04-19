#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;//存储动态数组里面元素的个数
}SSTable;

void ST_Init(SSTable &ST, int len)
{
    ST.TableLen = len + 1;
    ST.elem = (ElemType*)malloc(sizeof(ElemType)*ST.TableLen);
    srand(time(NULL));
    for(int i = 0; i < ST.TableLen; i++)
        ST.elem[i] = rand() % 100;
}

void ST_print(SSTable ST)
{
    for(int i=0;i<ST.TableLen;i++)
	{
		printf("%d ",ST.elem[i]);
	}
	printf("\n");
}

int Search_Seq(SSTable ST, ElemType key)
{
    ST.elem[0] = key;
    int i;
    for(i = ST.TableLen-1; ST.elem[i] != key; i--);
    return i;
}

int compare(const void *left, const void *right)
{
    return *(ElemType*)left - *(ElemType*)right;
}

int Binary_Search(SSTable ST, ElemType key)
{
    int low=0,high=ST.TableLen-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ST.elem[mid]==key)
			return mid;//等于就找到了
		else if(ST.elem[mid]>key)
			high=mid-1;
		else
			low=mid+1;
	}
	return -1;
}

int main()
{
    SSTable ST;
    ST_Init(ST,10);
    ST_print(ST);
    ElemType key;
    int pos;
    printf("请输入要搜索的key值：");
    scanf("%d",&key);
    pos = Search_Seq(ST,key);
    if(pos)
        printf("查找成功,位置为 %d\n",pos);
    else
        printf("查找失败！\n");
    qsort(ST.elem, ST.TableLen,sizeof(ElemType),compare);
    ST_print(ST);
    system("pause");
}
