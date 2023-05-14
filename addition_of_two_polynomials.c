#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe,pow;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head1=NULL,*head2=NULL,*head3=NULL,*NN;
NODE *temp,*temp1,*temp2,*temp3;
NODE * newnode(int coe,int pow)
{
	NN=(NODE *)malloc(sizeof(NODE));
	NN->coe=coe;
	NN->pow=pow;
	NN->next=NULL;
	return NN;
}
NODE * createpol(NODE *head)
{
   int coe,pow;
   char ch='Y';
   while(ch!='N')
   {
   	scanf("%d%d",&coe,&pow);
   	NN=newnode(coe,pow);
   	if(head==NULL)
   	{
   		head=NN;
	}
	else
	{
	   	temp=head;
	   	while(temp->next)
		   {
		   temp=temp->next;
		   }
		   temp->next=NN;
	}
   	printf("do u want to enter(Y/N):");
   	scanf(" %c",&ch);
   }	
   return head;
}
void display(NODE *head)
{
	temp=head;
	while(temp)
	{
		printf("%d %d\t",temp->coe,temp->pow);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	head1=createpol(head1);
	head2=createpol(head2);
	//head3=addpol(head1,head2,head3);
	dispaly(head1);
	display(head2);
    //display(head3);
}

