
#include<stdio.h>
void selection_sort(int *a,int n)
{
	int i,p,max,index,temp;
	for(p=0;p<n-1;p++)
	{
		max=a[0];
		index=0;
		for(i=0;i<n-p;i++)
		{
		   	if(a[i]>max)
		   	{
		   		max=a[i];
		   		index=i;
			}
		}
		temp=a[index];
		a[index]=a[i-1];
		a[i-1]=temp;
	}
}
int main()
{
	int i,n,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
