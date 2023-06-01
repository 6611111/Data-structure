/*// linear search
#include<stdio.h>
int linear_search(int *a,int n,int k)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n,k,r,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	r=linear_search(a,n,k);
	printf("Found at %d",r);
}*/
// Binary search
/*#include<stdio.h>
int binary_search(int *a,int n,int k)
{
	int i,l=0,h=n-1,m;
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==k)
		{
			return m;
		}
		else if(a[m]<k)
		{
			l=m+1;
		}
		else if(a[m]>k)
		{
			h=m-1;
		}
	}
	return -1;
}
int main()
{
	int n,i,k,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	r=binary_search(a,n,k);
	printf("Found at %d",r);
}*/
// bubble sort
/*#include<stdio.h>
void bubble_sort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{                     // i=0,j=0  j=1
			if(a[j]>a[j+1])   // 14>24    24>16
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];   //5
	for(i=0;i<n;i++)
	{                       // i= 0  1  2  3  4
		scanf("%d",&a[i]);   //   14 24 16 10 19
	}                        // j= 0  1  2  3  4
	bubble_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}*/
//insertion sort
/*#include<stdio.h>
void insertion_sort(int *a,int n)
{
	int i,key,j;
	for(i=1;i<n;i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}*/
// selection sort
/*#include<stdio.h>
void selection_sort(int *a,int n)
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	selection_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}*/
// implementation of stack using arrays
/*#include<stdio.h>
int st[100],top=-1,s;
void push(int val)
{
	if(top==s-1)
	{
		printf("You can not push the values\n");
	}
	else
	{
		st[++top]=val;
	}
}
int pop()
{
	int val;
	if(top==-1)
	{
		printf("You can not pop\n");
	}
	else
	{
		val=st[top];
		st[top--]=0;
		return val;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("You can not display\n");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d ",st[i]);
		}
		printf("\n");
	}
}
int main()
{
	int n,ch,val;
	scanf("%d",&s);
	while(1)
	{
		printf("1.push 2.pop 3.display 4.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			// push
			scanf("%d",&val);
			push(val);
		}
		else if(ch==2)
		{
			// pop
			val=pop();
			if(val==-1)
			{
				printf(" You can not pop\n");
			}
			else
			{
				printf("%d",val);
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
}*/
// infix to postfix
/*#include<stdio.h>
#include<string.h>
int pred(char ch)
{
	switch(ch)
	{
		case '^':return 3;
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
		default:return 0;
	}
}
char *infix_postfix(char *infix)
{
	int n,top=-1,i,j=0;
	n=strlen(infix);
	char st[n],op;
	static char postfix[100];
	for(i=0;i<n;i++)
	{
		if(pred(infix[i]))
		{
			// operator case
			if(top==-1)
			{
				st[++top]=infix[i];
			}
			else if(pred(infix[i])>pred(st[top]))
			{
				st[++top]=infix[i];
			}
			else
			{
				while(top!=-1 && pred(infix[i])<=pred(st[top]))
				{
					op=st[top--];
					postfix[j++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
			// operend case
			postfix[j]=infix[i];
			j++;
		}
	}
	for(i=top;i>=0;i--)
	{
		postfix[j++]=st[i];
	}
	return postfix;
}
int main()
{
	char infix[100],*postfix;
	scanf("%[^\n]s",infix);
	postfix=infix_postfix(infix);
	printf("%s",postfix);
	return 0;
}*/
// infix to postfix advanced
/*#include<stdio.h>
#include<string.h>
int pred(char ch)
{
	switch(ch)
	{
		case '^':return 3;
		case '*':return 2;
		case '/':return 2;
		case '+':return 1;
		case '-':return 1;
		case '(':return -1;
		case ')':return -1;
		default:return 0;
	}
}
char * infix_postfix(char *infix)
{
	int i,j=0,top=-1,n;
	n=strlen(infix);
	char st[n],op;
	static char postfix[100];
	for(i=0;i<n;i++)
	{
		if(pred(infix[i]))
		{
			// operator case
			if(top==-1)
			{
				st[++top]=infix[i];
			}
			else if(infix[i]=='(')
			{
				st[++top]=infix[i];
			}
			else if(pred(infix[i])>pred(st[top]))
			{
				st[++top]=infix[i];
			}
			else if(infix[i]==')')
			{
				while(st[top]!='(')
				{
					op=st[top--];
					postfix[j++]=op;
				}
				top--;
			}
			else
			{
				while(top!=-1 && pred(infix[i])<=pred(st[top]))
				{
					op=st[top--];
					postfix[j++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
			// operend case
			postfix[j]=infix[i];
			j++;
		}
	}
	for(i=top;i>=0;i--)
	{
		postfix[j++]=st[i];
	}
	return postfix;
}
int main()
{
	char infix[100],*postfix;
	scanf("%[^\n]s",infix);
	postfix=infix_postfix(infix);
	printf("%s",postfix);
	return 0;
}*/
// postfix evaluation
/*#include<stdio.h>
#include<string.h>
int is_oper(char ch)
{
	switch(ch)
	{
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':
			return 1;
		default:
		    return 0;
	}
}
int perform_oper(int op1,char ch,int op2)
{
	switch(ch)
	{
		case '^':return (op2^op1);
		case '*':return (op2*op1);
		case '/':return (op2/op1);
		case '+':return (op2+op1);
		case '-':return (op2-op1);
		default :return 0;
	}
}
int postfix_evaluation(char *postfix)
{
	int st[100],i,j=0,top=-1,op1,op2,res,val=0;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(is_oper(postfix[i]))
		{
			op1=st[top--];
			op2=st[top--];
			res=perform_oper(op1,postfix[i],op2);
			st[++top]=res;
		}
		else
		{
			if(postfix[i]>=48 && postfix[i]<=57)
			{
				val=val*10+postfix[i]-'0';
			}
			else if(postfix[i]==' ' && val!=0)
			{
				st[++top]=val;
				val=0;
			}
		}
	}
	return st[0];
}
int main()
{
	char postfix[100];
	int r;
	scanf("%[^\n]s",postfix);
	r=postfix_evaluation(postfix);
    printf("%d",r);
    return 0;
}*/
// queue
/*#include<stdio.h>
int front=-1,rear=-1,queue[100],size;
void enque(int val)
{
	if(rear==size-1)
	{
		printf("Enque not possible\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else
	{
		rear++;
		queue[rear]=val;
	}
}
int deque()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	else if(front==rear)
	{
		val=queue[front];
		front=-1;
		rear=-1;
		return val;
	}
	else
	{
		val=queue[front];
		front++;
		return val;
	}
}
void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("display not possible\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d ",queue[i]);
		}
		printf("\n");
	}
}
int main()
{
	int val,ch;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque 2.Deque 3.Display 4.exi: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			// enque
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			// deque
			val=deque();
			if(val==-1)
			{
				printf("Not possible\n");
			}
			else
			{
				printf("%d\n",val);
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
}*/
// circular queue
/*#include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque(int val)
{
	if(front==0 && rear==size-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==front-1)
	{
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[rear]=val;
	}
	else 
	{
		rear=(rear+1)%size;
		queue[rear]=val;
	}
}
int deque()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	else if(front==rear)
	{
		val=queue[front];
		front=-1;
		rear=-1;
		return val;
	}
	else
	{
		val=queue[front];
		front=(front+1)%size;
		return val;
	}
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		while(i!=rear)
		{
			printf("%d \n",queue[i]);
			i=(i+1)%size;
		}
		printf("%d \n",queue[i]);
	}
}
int main()
{
	int val,ch;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque 2.Deque 3.Diplay 4.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			// Enque
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			// Deque
			val=deque();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d",val);
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
}*/
// double ended queue
/*#include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque_at_rear(int val)
{
	if()
}
int main()
{
	int val,ch;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque at rear 2.Enque at front 3.Deque at front 4.Deque at rear 5.Display 6.exit: ");
	    scanf("%d",&ch);
		if(ch==1)
		{
			//..enque at rear
			scanf("%d",&val);
			enque_at_rear(val);
		}	
		else if(ch==2)
		{
			//..enque at front
			scanf("%d",&val);
			enque_at_front(val);
		}
		else if(ch==3)
		{
			//.deque at front
			val=deque_at_front();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d \n",val);
			}
		}
		else if(ch==4)
		{
			//..deque at rear
			val=deque_at_rear();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d \n",val);
			}
		}
		else if(ch==5)
		{
			display();
		}
		else
		{
			break;
		}
	}
}*/
// single linked  list
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node NODE;
NODE *head=NULL,*tail=NULL,*temp,*res,*NN;
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
NODE *delet()
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
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("NO nodes\n");
	}
	else
	{
		temp=head;
		while(temp)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
int main()
{
	int val,ch;
	while(1)
	{
		printf("1.Insert 2.Delete 3.Display 4.Exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..insert
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
				printf("Empty\n");
			}
			else
			{
				printf("%d \n",res->data);
				free(res);
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
