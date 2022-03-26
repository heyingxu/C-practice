#include<stdio.h>
int Fibo(int n)
{
	if(n<0)
	{
		printf("input error");
		return -1;
	}
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	if(n > 1)
		return(Fibo(n-1)+Fibo(n-2));
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
