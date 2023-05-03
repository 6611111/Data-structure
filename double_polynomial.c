#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int coe;
	int pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head1=NULL,*tail1=NULL,*temp,*NN;
NODE *head2=NULL,*tail2=NULL;
NODE * newnode(int coe,int pow)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->coe=coe;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
}
void insert1(NODE * NN)
{
	if(head1==NULL && tail1==NULL)
	{
		head1=NN;
		tail1=NN;
	}
	else
	{
		tail1->next=NN;
		tail1=NN;
	}
}
void insert2(NODE * NN)
{
	if(head2==NULL && tail2==NULL)
	{
		head2=NN;
		tail2=NN;
	}
	else
	{
		tail2->next=NN;
		tail2=NN;
	}
}
void display(NODE *head)
{
	temp=head;
	if(temp==NULL)
	{
		printf("No Nodes here\n");
	}
	else
	{
		while(temp)
		{
			printf("%dx%d ",temp->coe,temp->pow);
            temp=temp->next;
		}
	}
}
int main()
{
	int coe,pow;
	char ch='a';
	while(ch!='N')
	{
		scanf("%d%d",&coe,&pow);
		NN=newnode(coe,pow);
		insert1(NN);
		printf("DO u want to enter Y/N: ");
		scanf(" %c",&ch);
	}
	display(head1);
	ch='a';
	while(ch!='N')
	{
		scanf("%d%d",&coe,&pow);
		NN=newnode(coe,pow);
		insert2(NN);
		printf("DO u want to enter Y/N: ");
		scanf(" %c",&ch);
	}
	display(head2);
}
