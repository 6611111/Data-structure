#include<stdio.h>
#include<stdlib.h>
struct Node {
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root,*NN,*temp;
void insert(int val)
{
	temp=root;
	if(root==NULL)
	{
		root=NN;
		return;
	}
	else
	{
		if(temp->data==NN->data)
		{
			printf("Element already in the tree\n");
			return;
		}
		else if(temp->data>NN->data)
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else if(temp->left==NULL)
			{
				temp->left=NN;
			}
		}
		else if(temp->data<NN->data)
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else if(temp->right==NULL)
			{
				temp->right=NN;
			}
		}
	}
}
int searching(int key)
{
	temp=root;
	if(temp==NULL)
	{
		return 0;
	}
	while(temp)
	{
		if(temp->data==key)
		{
			return 1;
		}
		else if(temp->data>key)
		{
			temp=temp->left;
		}
		else if(temp->data<key)
		{
			temp=temp->right;
		}
	}
}
int main()
{
	int n,i,ch,val,key;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(1)
	{
		printf("1.Insert  2.Searching 3.Exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			// insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->left=NULL;
			NN->right=NULL;
		    insert(val);
		}
		else if(ch==2)
		{
			scanf("%d",&key);
			if(searching(key))
			{
				printf("Element found\n");
			}
			else
			{
				printf("Element not found\n");
			}
		}
	}
}
