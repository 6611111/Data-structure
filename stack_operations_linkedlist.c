#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node node;
node *head=NULL;
void insert(int val)
{
	node *nn,*temp;
	nn=(node *)malloc(sizeof(node));
	nn->data=val;
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=nn;
	}
}
int delet()
{
	int val;
	node *temp;
	if(head==NULL)
	{
		return -1;
	}
	else if(head->next==NULL)
	{
		val=head->data;
		head=NULL;
		return val;
	}
	else
	{
		temp=head;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		val=temp->next->data;
		temp->next=NULL;
		return val;
	}
}
void display()
{
	node *temp;
	if(head==NULL)
	{
		printf("NO\n");
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit : ");
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
			val=delet();
			if(val==-1)
			{
				printf("NO\n");
			}
			else
			{
				printf("%d ",val);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
