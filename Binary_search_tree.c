#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL,*temp,*NN,*par;
NODE * newnode(int val)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->data=val;
	NN->left=NULL;
	NN->right=NULL;
	return NN;
}
void insert(int val)
{
	NN=newnode(val);
	temp=root;
	if(root==NULL)
	{
		root=NN;
		return;
	}
	while(1)
	{
		if(temp->data==NN->data)
		{
			printf("Element is already in tree\n");
			return;
		}
		else if(temp->data>NN->data)
		{
			if(temp->left!=NULL)
			{
				temp=temp->left;
			}
			else
			{
				temp->left=NN;
				return;
			}
		}
		else if(temp->data<NN->data)
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else
			{
				temp->right=NN;
				return;
			}
		}
	}
}
int search(int key)
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
void inorder(NODE *root)
{
	if(root!=NULL)
	{
	  inorder(root->left);
	  printf("%d ",root->data);
	  inorder(root->right);
    }
}
void preorder(NODE *root)
{
	if(root!=NULL)
	{
	  printf("%d ",root->data);
	  preorder(root->left);
	  preorder(root->right);
   }
}
void postorder(NODE *root)
{
	if(root!=NULL)
	{
	  postorder(root->left);
	  postorder(root->right);
	  printf("%d ",root->data);
   }
}
int main()
{
	int ch,val,key;
	while(1)
	{
		printf("1.insert\n2.delete\n3.search\n4.inorder\n5.preorder\n6.postorder\n7.levelorder\n8.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
			//insert
			scanf("%d",&val);
			insert(val);
		}
		else if(ch==2)
		{
			//delete
			
		}
		else if(ch==3)
		{
			//search
			scanf("%d",&key);
            if(search(key))
			{
				printf("Element found\n");
			}
			else
			{
				printf("Not found\n");
			}
		}
		else if(ch==4)
		{
			//inorder
			inorder(root);
		}
		else if(ch==5)
		{
			//preorder
			preorder(root);
		}
		else if(ch==6)
		{
			//postorder
			postorder(root);
		}
		else if(ch==7)
		{
			//levelorder
			
		}
		else
		{
			break;
		}
	}
}
