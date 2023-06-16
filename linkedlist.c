#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *NN,*res,*head,*tail;
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
		head=NN;
	}
}
void insert_at_tail(NODE *NN)
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

int main()
{
	int val,ch,pos;
	while(1)
	{
		printf("1.Insert at head 2.Insert at tail 3.Insert by position 4.Delete at head 5.Delete at tail 6.Delete by position 7.Display:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..insert at head
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_at_head(NN);
		}
		else if(ch==2)
		{
			//..insert at tail
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_at_tail(NN);
		}
		else if(ch==3)
		{
			//.insert by position
			scanf("%d",&val);
			scanf("%d",&pos);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_by_pos(NN,pos);
		}
		else if(ch==4)
		{
			//.delete at head
		   res=delete_at_head();
		   if(res==NULL)
		   {
		   	  printf("NO Nodes\n");
		   }	
		   else
		   {
		   	  printf("%d",res->data);
		   	  free(res);
		   }
		}
		else if(ch==5)
		{
		    //..delete at tail
			res=delete_at_tail();
		   if(res==NULL)
		   {
		   	  printf("NO Nodes\n");
		   }	
		   else
		   {
		   	  printf("%d",res->data);
		   	  free(res);
		   }	
		}
		else if(ch==6)
		{
			//..delete by position
			res=delete_by_pos();
		   if(res==NULL)
		   {
		   	  printf("NO Nodes\n");
		   }	
		   else
		   {
		   	  printf("%d",res->data);
		   	  free(res);
		   }
		}
		else if(ch==7)
		{
			display();
		}
		else
		{
			break;
		}
	}
}
