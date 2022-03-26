/*
问题描述：
  假如有n个台阶，一次只能上1个台阶或2个台阶，请问走到第n个台阶有几种走法？
  为便于读者理解题意，这里举例说明如下：假如有3个台阶，那么总计就有3种走法：
  第一种为每次上1个台阶，上3次；第二种为先上2个台阶，再上1个台阶；第三种为先上1个台阶，再上2个台阶。
  输入为n，输出为走到第n个台阶有几种走法？
思路：
  可以分最后一步是一个台阶还是两个台阶两种情况，将两种情况的总数相加即可，递归下去为斐波那契数列。
*/
#include<stdio.h>
int Fibo(int n)
{
  int result;
  if(n==1)
    result = 1;
  else if(n==2)
      result = 2;
  else result = Fibo(n-1) + Fibo(n-2);
  return result;
}  
int main()
{
  int n=0;
  scanf("%d",&n);
  if(n <= 0)
    return 0;
  int result = Fibo(n);
  printf("%d",result);
  return 0;
}
