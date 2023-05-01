#include<stdio.h>
int binary_search(int *a,int n,int key)
{
	int l,h,m;
	l=0,h=(n-1);
	while(l<=h)
	{
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
	r=binary_search(a,n,key);
	printf("Result is %d",r);
}
