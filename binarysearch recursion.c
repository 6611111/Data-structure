#include<stdio.h>
int binary_search_rec(int *a,int l,int h,int key)
{
	if(l>h)
	{
		return -1;
	}
	int m;
	m=(l+h)/2;
	if(a[m]==key)
		{
			return m;
		}
	else if(a[m]>key)
		{
		  h=(m-1);	
		}
	else if(a[m]<key)
		{
			l=(m+1);
		}
}
int main()
{
	int n,i,key,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	r=binary_search_rec(a,0,n-1,key);
	printf("Result is %d",r);
}
