#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*
  交换排序：冒泡排序、快速排序（交换法、挖坑法）
  插入排序：直接插入排序、折半插入排序、希尔排序
  选择排序：简单选择排序、堆排序
  归并排序
*/

typedef int ElemType;
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

void ST_Init(SSTable &ST, int len)
{
    ST.TableLen = len;
    ST.elem = (ElemType*)malloc(sizeof(int)*ST.TableLen);
    int i;
    srand((unsigned)time(NULL));
    for(i = 0; i < ST.TableLen; i++)
        ST.elem[i] = rand() % 100;
}

void ST_print(SSTable ST)
{
    for(int i = 0; i < ST.TableLen; i++)
	{
		printf("%3d",ST.elem[i]);
	}
	printf("\n");
}

void swap(ElemType &a,ElemType &b)
{
	ElemType tmp;
	tmp=a;
	a=b;
	b=tmp;
}

//冒泡排序 O(n^2)
void BubbleSort(ElemType A[], int n)
{
    int i, j, flag;
    for(i = 0; i < n-1; i++)
    {
        flag = 0;
        for(j = n - 1; j > i; j--)
            if(A[j-1] > A[j])
            {
                swap(A[j-1], A[j]);
                flag = 1;
            }
        if(flag == 0)
            break;
    }
}

//快速排序 O(n*logn)
int Partition(int *arr, int left ,int right)
{
    int k, i;
    for(k = i = left; i < right; i++)
    {
        if(arr[i]<arr[right])
        {
            swap(arr[i], arr[k]);
            k++;
        }
    }
    swap(arr[k], arr[right]);
    return k;
}

void QuickSort(ElemType A[], int low, int high)
{
    if(low < high)
    {
        int pivotpos = Partition(A,low,high);
        QuickSort(A,low,pivotpos-1);
        QuickSort(A,pivotpos+1,high);
    }
}

//直接插入排序
void InsertSort(ElemType A[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        if(A[i-1] > A[i])
        {
            temp = A[i];
            for(j = i - 1; j > 0 && A[j] > temp; j--)
                A[j+1] = A[j];
            A[j+1] = temp;
        }
    }
}

//折半插入排序 O(n^2)
void MidInsertSort(ElemType A[],int n)
{
    int i, j, low, mid, high,temp;
    for(i = 1; i < n; i++)
    {
        temp = A[i];
        low = 0;
        high = n - 1;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(A[i] < mid)
                high = mid -1;
            else
                low = mid + 1;
        }
        for(j = i - 1; j >= low; j--)
            A[j+1] = A[j];
        A[j+1] = temp;
    }

}

//希尔排序 O(n^1.3)
void ShellSort(ElemType A[], int n)
{
    int i, j, temp, gap;
    for(gap = n / 2; gap > 0; gap /= 2)
        for(i = gap; i < n; i++)
        {
            temp = A[i];
            for(j = i - gap; j >= 0 && A[j] > temp ; j = j - gap)
                A[j+gap] = A[j];
            A[j+gap] = temp;
        }
}

//简单选择排序 O(n^2)
void SelectSort(ElemType A[],int n)
{
    int min, i, j;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
            if(A[j] < A[min])
                min = j;
        if(min != i)
            swap(A[i], A[min]);
    }
}

//堆排序 O(n*logn)
void AdjustDown(ElemType A[],int k,int n)
{
	int dad = k;
	int son = 2 * dad + 1;
	while(son < n)
    {
        if(son + 1 < n && A[son] < A[son+1])
            son++;
        if(A[son] > A[dad])
        {
            swap(A[son], A[dad]);
            dad = son;
            son = 2*dad + 1;
        }
        else
            break;
    }
}
//用数组去表示树----层次建树
void BuildMaxHeap(ElemType A[],int n)
{
	for(int i = n / 2 - 1; i >= 0; i--)
	{
		AdjustDown(A,i,n);
	}
}

void HeapSort(ElemType A[],int n)
{
	int i;
	BuildMaxHeap(A,n);//建立大顶堆
    //swap(A[0], A[n-1]);
	for(i = n; i > 1; i--)
	{
        swap(A[i-1],A[0]);
		AdjustDown(A, 0, i-1);
	}
}

//归并排序 O(n*logn)
void Merge(ElemType A[], int low, int mid, int high)
{
    ElemType B[10];
    int i, j, k;
    for(k = low; k <= high; k++)
        B[k] = A[k];
    for(i = low, j = mid + 1, k = i; i <= mid && j <= high; k++ )
    {
        if(B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
    while(i <= mid)
    {
        A[k++] = B[i++];
    }
    while(j <= high)
        A[k++] = B[j++];
}

void MergeSort(ElemType A[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

int main()
{
    SSTable ST,ST2;
	ST_Init(ST,10);//初始化
    printf("-----初始化数组-----\n");
	ST_print(ST);
	BubbleSort(ST.elem,10);//冒泡排序
    printf("-----冒泡排序-----\n");
	ST_print(ST);
    printf("-----快速排序-----\n");
    QuickSort(ST.elem,0,9);
    ST_print(ST);
    printf("-----直接插入排序-----\n");
    InsertSort(ST.elem,10);
    ST_print(ST);
    MidInsertSort(ST.elem,10);
    printf("-----折半插入排序-----\n");
    ST_print(ST);
    ShellSort(ST.elem,10);
    printf("-----希尔排序-----\n");
    ST_print(ST);
    SelectSort(ST.elem,10);
    printf("-----简单选择排序-----\n");
    ST_print(ST);
    HeapSort(ST.elem,10);
    printf("-----堆排序-----\n");
    ST_print(ST);
    MergeSort(ST.elem,0,9);
    printf("-----归并排序-----\n");
    ST_print(ST);
	//system("pause");
}
