#include<stdio.h>
#include<stdlib.h>
struct Node 
{
	int coe;
	int pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*NN;
NODE * newnode(int coe,int pow)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->coe=coe;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
}
void insert(NODE * NN)
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
void display()
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
		insert(NN);
		printf("DO u want to enter Y/N: ");
		scanf(" %c",&ch);
	}
	display();
}
