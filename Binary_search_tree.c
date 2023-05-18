#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *left;
	int data;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL,*temp,*NN,*par,*res;
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
NODE * delet(int key)
{
	if(root==NULL)
	{
	 	return NULL;	 
	}
	temp=root;
	par=NULL;
	while(temp && temp->data!=key)
	{
		printf("Hai\n");
		if(temp->data>key)
		{
			par=temp;
			temp=temp->left;
		}
		else if(temp->data<key)
		{
			par=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->right==NULL && temp->left==NULL)
	{
		//..zero child case
		if(par->right!=NULL && par->right->data==key)
		{
			par->right=NULL;
		}
		else if(par->left!=NULL && par->left->data==key)
		{
			par->left=NULL;
		}
		return res;
	}
	else if(temp->left==NULL)
	{
		// single child right
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->right;
		}
		else if(par->right!=NULL && par->right->data==key)
		{
			par->right=temp->right;
		}
		return res;
	}
	else if(temp->right==NULL)
	{
		//.single chilf left
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->left;
		}
		else if(par->right!=NULL && par->right->data==key)
		{
			par->right=temp->left;
		}
		return res;
	}
	else if(temp->left!=NULL && temp->right!=NULL)
	{
		//two children
		NODE *p,*t;
		int val;
		t=temp->right;
		p=NULL;
		while(t->left!=NULL)
		{
			p=t;
			t=t->left;
	    }
	    if(p!=NULL)
	    {
	    	res=t;
	    	val=t->data;
	    	t->data=temp->data;
	    	temp->data=val;
	    	p->left=t->right;
	    	return res;
		}
		else
		{
			res=t;
			val=t->data;
			t->data=temp->data;
			temp->data=val;
			temp->right=t->right;
			return res;
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
	int ch,val,key,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
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
			scanf("%d",&key);
			res=delet(key);
			if(res)
			{
			  printf("%d\n",res->data);
			  free(res);
		    }
		   else
		   {
		   	printf("Element not found\n");
		   }
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
