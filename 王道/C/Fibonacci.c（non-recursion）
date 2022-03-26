#include<stdio.h>
int Fibo(int n)
{
	int pre = 0;
	int current = 1;
	int result = 1;
	if(n<0)
	{
		printf("input error");
		return -1;
	}
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
	{
		for(int i = 2; i<=n ;i++)
		{
			result = pre + current;
			pre = current;
			current = result;
		}
		return result;
	}
}
int main()
{
	int n=0;
	scanf("%d",&n);
	int result = Fibo(n);
	if(result > 0)
		printf("%d",result);
	return 0;
}
