/*#include<stdio.h>
int linear_search(int *a,int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int i,n,key,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	r=linear_search(a,n,key);
	printf("Result is %d",r);
}*/
/*#include<stdio.h>
int binary_search(int *a,int n,int key)
{
	int l,h,m;
	l=0,h=(n-1);
	while(l<=h)
	{
		m=(l+h)/2;
		if(a[m]==key)
		{
		   return m;	
		}
		else if(a[m]>key)
		{
			h=(m-1);
		}
		else if(a[m]<key)
		{
			l=(m+1);
		}
	}
}
int main()
{
	int n,i,key,r;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&key);
	r=binary_search(a,n,key);
	printf("Result is %d",r);
}
*/
/*#include<stdio.h>
void bubble_sort(int *a,int n)
{
    int i,j,temp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
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
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}*/
/*#include<stdio+.h>
void insertion_sort(int *a,int n)
{
    int i,j,key;
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
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	insertion_sort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}*/
/*#include<stdio.h>
void selection_sort(int *a,int n)
{
	int i,j,min,temp=0;
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
/*#include<stdio.h>
void swap(int *a,int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int partiation(int *a,int l,int h)
{
	int p=h,i,j;
	for(i=l,j=l;i<p;i++)
	{
		if(a[i]<a[p])
		{
			swap(a,i,j);
			j++;
		}
	}
	swap(a,j,p);
	return j;
}
void quicksort(int *a,int l,int h)
{
	if(l<h)
	{
	    int par;
	    par=partiation(a,l,h);
	    quicksort(a,l,par-1);
	    quicksort(a,par+1,h);
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
	quicksort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}*/
/*#include<stdio.h>
void merge(int *a,int n,int *b,int v)
{
	int r[100]={0},i=0,j=0,k=0;
	while(i<n && j<v)
	{
		if(a[i]>b[j])
		{
			r[k]=b[j];
			j++;
			k++;
		}
		else
		{
			r[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<n)
	{
		r[k]=a[i];
		i++;
		k++;
	}
	while(j<v)
	{
		r[k]=b[j];
		j++;
		k++;
	}
	for(i=0;i<n+v;i++)
	{
		printf("%d ",r[i]);
	}
}
int main()
{
	int i,n,v,j,k;
	printf("enter the size of the arrays\n");
	scanf("%d%d",&n,&v);
	int a[n],b[v],r[k];
	printf("Enter elements in first array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the elements in second array\n");
	for(j=0;j<v;j++)
	{
		scanf("%d",&b[j]);
	}
	merge(a,n,b,v);
}*/
/*#include<stdio.h>
// merge in one array
void merge(int *a,int l,int h)
{
	int i,m,j,k=0,p[h-l+1];
	m=l+h/2;
	i=l;
	j=m+1;
	while(i<=m && j<=h)
	{
		if(a[i]>a[j])
		{
			p[k]=a[j];
			j++;
			k++;
		}
		else
		{
			p[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<=m)
	{
		p[k]=a[i];
		i++;
		k++;
	}
	while(j<=h)
	{
		p[k]=a[j];
		j++;
		k++;
	}
	k=0;
	for(i=l;i<=h;i++)
	{
		a[i]=p[k];
		k++;
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	merge(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}*/
/*#include<stdio.h>
#include<string.h>
int prec(char ch)
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
	int i,j=0,top=-1,n;
	n=strlen(infix);
	char st[n],op;
	static char postfix[100];
	for(i=0;i<n;i++)
	{
		if(prec(infix[i]))
		{
			if(top==-1)
			{
				st[++top]=infix[i];
			}
			else if(prec(infix[i])>prec(st[top]))
			{
				st[++top]=infix[i];
	        }
	        else
	        {
	        	while(top!=-1 && prec(infix[i])<=prec(st[top]))
	        	{
	        		op=st[top--];
	        		postfix[j++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
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
/*#include<stdio.h>
#include<string.h>
int prec(char ch)
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
char *infix_postfix(char *infix)
{
	int i,j,top=-1,n;
	n=strlen(infix);
	char st[n],op;
	static char postfix[100];
	for(i=0;i<n;i++)
	{
		if(prec(infix[i]))
		{
			if(top==-1)
			{
				st[++top]=infix[i];
			}
			else if(infix[i]=='(')
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
			else if(prec(infix[i])>prec(st[top]))
			{
				st[++top]=infix[i];
			}
			else
			{
				while(top!=-1 && prec(infix[i])<=prec(st[top]))
				{
					op=st[top--];
					postfix[j++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
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
/*#include<stdio.h>
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
int perform_oper(int op1,char op,int op2)
{
	switch(op)
	{
		case '^':return (op2^op1);
        case '*':return (op2*op1);
        case '/':return (op2/op1);
        case '+':return (op2+op1);
        case '-':return (op2-op1);
        default:return 0;

	}
}
int evaluation(char *postfix)
{
	int i,st[100],top=-1,op1,op2,res,val=0;
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
	int res;
	char postfix[10];
	scanf("%[^\n]s",postfix);
	res=evaluation(postfix);
	printf("Result is %d",res);
}*/
/*#include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque_at_rear(int val)
{
	if(front==0 && front==size-1)
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
		rear++;
		queue[rear]=val;
	}
}
int deque_at_front()
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
		printf("Queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.enque at rear\n2.deque at front\n3.display\n4.exit:");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..enque at rear
			scanf("%d",&val);
			enque_at_rear(val);
		}
		else if(ch==2)
		{
			//...deque at front
			val=deque_at_front();
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
/*#include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque_at_rear(int val)
{
	if(front==0 && front==size-1)
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
void enque_at_front(int val)
{
	if(front==0 && front==size-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==size-1)
	{
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
		queue[front]=val;
	}
	else if(front==0)
	{
		front=size-1;
		queue[front]=val;
	}
	else
	{
		front--;
		queue[front]=val;
	}
}
int deque_at_rear()
{
	int val;
	if(front==-1 && rear==-1)
	{
		return -1;
	}
	else if(front==rear)
	{
		val=queue[rear];
		front=-1;
		rear=-1;
		return val;
	}
	else if(rear==0)
	{
		rear=size-1;
		val=queue[rear];
	}
	else
	{
		rear--;
		val=queue[rear];
		return val;
	}
}
int deque_at_front()
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
	int i;
	i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	while(i!=rear)
	{
		printf("%d ",queue[i]);
		i=(i+1)%size;
	}
	printf("%d\n",queue[i]);
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.enque at rear\n2.deque at front\n3.display\n4.enque at front\n5.deque at rear\n6.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..enque at rear
			scanf("%d",&val);
			enque_at_rear(val);
		}
		else if(ch==2)
		{
			//...deque at front
			val=deque_at_front();
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
		else if(ch==4)
		{
			//..enque at front
			scanf("%d",&val);
			enque_at_front(val);
		}
		else if(ch==5)
		{
			//..deque at rear
			val=deque_at_rear();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d",val);
			}
		}
		else
		{
			break;
		}
	}
}*/
/*#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL,*tail=NULL,*NN,*res,*temp;
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
void display()
{
	if(head==NULL && tail==NULL)
	{
		printf("NO Nodes here\n");
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
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.insert\n2.delete\n3.display\n4.exit:");
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
			display();
		}
		else
		{
			break;
		}
	}
}*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *head=NULL,*tail=NULL,*temp,*res,*NN;
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
	else
	{
		temp=head;
		temp=temp->next;
		res=head;
		head=temp;
		head->next=NULL;
		
	}
}
void reverse()
{
	
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
int main()
{
	int ch,val;
	while(1)
	{
		printf("1.insert at tail\n2.delete at tail\n3.display\n4.insert at head\n5.delete at head\n6.reverse\n7.insert by position\n8.delete by position\n9.exit: ");
	    scanf("%d",&ch);
	    if(ch==1)
	    {
	    	//..insert at tail
	    	scanf("%d",&val);
	    	NN=(NODE *)malloc(sizeof(NODE));
	    	NN->data=val;
	    	NN->next=NULL;
	    	insert_at_tail(NN);
		}
		else if(ch==2)
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
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			//..insert at head
			scanf("%d",&val);
			NN=(NODE *)malloc(sizeof(NODE));
			NN->data=val;
			NN->next=NULL;
			insert_at_head(NN);
		}
		else if(ch==5)
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
		else if(ch==6)
		{
			reverse();
		}
		else if(ch==7)
		{
			
		}
		else if(ch==8)
		{
			
		}
		else
		{
			break;
		}
	}
}
