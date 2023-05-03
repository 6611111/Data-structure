#include<stdio.h>
#include<stdlib.h>
struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN,*res;
void insert_at_head(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		NN->next=head;
		head->prev=NN;
		head=NN;
	}
}
void insert_at_end(NODE *NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
	}
	else
	{
		tail->next=NN;
		NN->prev=tail;
		tail=NN;
	}
}
void insert_by_pos(NODE *NN,int pos)
{
	int p;
	temp=head;
	for(p=1;p<pos-1;p++)
	{
		if(temp==NULL)
		{
			printf("Not possible\n");
			return;
		}
	temp=temp->next;
	}
	NN->next=temp->next;
	NN->prev=temp;
	temp->next=NN;
	NN->next->prev=NN;
	/*res=temp->next;
	temp->next=NN;
	res->prev=NN;
	NN->prev=temp;
	NN->next=res;*/
}
void display_from_head()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes here\n");
	}
	temp=head;
	while(temp)
	{
		printf("%d  %d  %d  %d\n",temp,temp->prev,temp->data,temp->next);
		temp=temp->next;
	}
}
void display_from_tail()
{
	if(head==NULL && tail==NULL)
	{
		printf("No Nodes here\n");
	}
	temp=tail;
	while(temp)
	{
		printf("%d %d %d %d\n",temp,temp->prev,temp->data,temp->next);
		temp=temp->prev;
	}
}
NODE * delete_at_head()
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
	res=head;
	head=head->next;
	head->prev=NULL;
	res->next=NULL;
	return res;
}
NODE * delete_at_tail()
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
	res=tail;
	tail=tail->prev;
	tail->next=NULL;
	res->prev=NULL;
	return res;
}
NODE * delete_by_pos(int pos)
{
	
}
int main()
{
	int val,ch,pos;
	while(1)
	{
		printf("1.insert at head\n2.insert at end\n3.insert by position\n4.display from head to tail\n5.display from tail to head\n6.delete at head\n7.delete at tail\n8.delete by position\n9.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..insert at head
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->prev=NULL;
			NN->next=NULL;
			insert_at_head(NN);
		}
		else if(ch==2)
		{
			//..insert at end
		    scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->prev=NULL;
			NN->next=NULL;
			insert_at_end(NN);	
		}
		else if(ch==3)
		{
			//..insert by position
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->prev=NULL;
			NN->next=NULL;
			insert_by_pos(NN,pos);
		}
		else if(ch==4)
		{
			//..display
			display_from_head();
		}
		else if(ch==5)
		{
			//display
			display_from_tail();
		}
		else if(ch==6)
		{
			//..delete at head
			res=delete_at_head();
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
		else if(ch==7)
		{
			//..delete at tail
			res=delete_at_tail();
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
		else if(ch==8)
		{
			//.delete by position
			scanf("%d",&pos);
			res=delete_by_pos(pos);
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
		else
		{
			break;
		}
	}
}
