#include<stdio.h>
int linear_search_rec(int *a,int n,int i,int key)
{
	if(i>n)
	{
		return -1;
	}
	else
	{
		if(a[i]==key)
		{
			return i;
		}
		else
		{
			return linear_search_rec(a,n,i+1,key);
		}
	}
}
int main()
{
	int n,i,r,key;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	r=linear_search_rec(a,n,0,key);
	printf("Resut is %d",r);
}
