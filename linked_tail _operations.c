#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;
void insert(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		tail->next=NN;
		tail=NN;
	}
}
void insertathead(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		NN->next=head;
		head=NN;
	}
}
NODE * delet()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	else
	{
		temp=head;
		while(temp->next->next)
		{
			temp=temp->next;
		}
		res=tail;
		temp->next=NULL;
		tail=temp;
		return res;
	}
}
NODE * deleteathead()
{
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		res=head;
		head=NULL;
		tail=NULL;
		return res;
	}
	else
	{
		/*temp=head;
		temp=head->next;
		head->next=NULL;
		return temp;*/
		temp=head;
		temp=temp->next;
		res=head;
		head->next=NULL;
		head=temp;
		return res;
	}
}
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes here\n");
	}
	else
	{
		temp=head;
		while(temp)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void reverse()
{
	NODE *cur,*prev,*next;
	if(head==NULL && tail==NULL)
	{
		printf("NO Nodes here\n");
	}
	else if(head==tail)
	{
		printf("NO need or list contains single node\n");
	}
	else
	{
		tail=head;
		cur=head;
		prev=NULL;
		next=NULL;
		while(cur)
		{
			next=cur->next;
			cur->next=prev;
			prev=cur;
			cur=next;
		}
		head=prev;
	}
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.Insert at tail \n 2.Delete at tail \n 3.Display \n  4. Insert at head \n 5.Delete at head \n 6.reverse \n 7.Exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//...insert
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert(NN);
		}
		else if(ch==2)
		{
			//..delete
			res=delet();
			if(res==NULL)
			{
				printf("No Nodes here\n");
			}
			else
			{
				printf("%d \n",res->data);
				free(res);
			}
		}
		else if(ch==3)
		{
			//...display
			display();
		}
		else if(ch==4)
		{
		    //..insert at head
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insertathead(NN);
		}
		else if(ch==5)
		{
			//..delete at head
			res=deleteathead();
			if(res==NULL)
			{
				printf("NO Nodes here\n");
			}
			else
			{
				printf("%d \n",res->data);
				free(res);
			}
		}
		else if(ch==6)
		{
			reverse();
		}
		else
		{
			break;
		}
	}
}
