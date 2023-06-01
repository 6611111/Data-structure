#include<stdio.h>
#include<stdlib.h>
struct NodeLL{
	int data;
	struct NodeLL *next;
};
typedef struct NodeLL NODELL;
NODELL *head=NULL,*temp,*NNLL;
struct NodeT{
	struct NodeT *left;
	int data;
	struct NodeT *right;
};
typedef struct NodeT NODET;
NODET *root=NULL,*NNT,*queue[100];

NODELL * newnodeLL(int val)
{
	NNLL=(NODELL *)malloc(sizeof(NODELL));
	NNLL->data=val;
	NNLL->next=NULL;
	return NNLL;
}
/*
f=0 and r=0
                     f                            r
  1000              2000          3000          4000         5000            6000
  
2000 10 3000        N 20 N       N 30 N         L D R       L D R           L D R
10                    20           30            40          50              60
head                                            temp

*/
NODET * newnodeTree(int val)
{
	NNT=(NODET *)malloc(sizeof(NODET));
	NNT->data=val;
	NNT->left=NULL;
	NNT->right=NULL;
	return NNT;
}
NODET * constructTree(NODELL *head)
{
	int f=0,r=0;
	temp=head;
	NNT=newnodeTree(temp->data);
	queue[r]=NNT;
	while(1)
	{
		if(temp->next!=NULL)
		{
			NNT=newnodeTree(temp->next->data);
			queue[++r]=NNT;
			queue[f]->left=NNT;
			temp=temp->next;
		}
		else
		{
			return queue[0];
		}
		if(temp->next)
		{
			NNT=newnodeTree(temp->next->data);
			queue[++r]=NNT;
			queue[f]->right=NNT;
			temp=temp->next;
		}
		else
		{
		  return queue[0];
		}
		f++;
	}
}
void inorder(NODET *root)
{
	if(!root)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void createLL(int val)
{
	NNLL=newnodeLL(val);
	if(head==NULL)
	{
		head=NNLL;
	}
	else
	{
		temp=head;
		while(temp->next)
        {
        	temp=temp->next;
		}
		temp->next=NNLL;
	}	
}
/*void display()
{
	temp=head;
	while(temp)
	{
		
		printf("%d %d %d\n",temp,temp->data,temp->next);
		temp=temp->next;
	}
}*/
int main()
{
	int n,i,val;
	scanf("%d",&n);  // no of values 5
	for(i=1;i<=n;i++)
	{
		scanf("%d",&val);  // 10 20 30 40  50
		createLL(val);  //createLL(10)
	}
	//display();
	root=constructTree(head);    // first node of 
	inorder(root);
}
