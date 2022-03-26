#include<stdio.h>
int main()
{
  int i=1,j=1,k=1;
  int count=0;
  for(i=1;i<7;i++)
    for(j=1;j<13;j++)
    {
      k = 60-9*i-4*j;
      if(k<37&&k>1)
        count++;
    }
  printf("%d",count);
  return 0;
}
