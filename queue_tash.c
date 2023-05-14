#include<stdio.h>
int queue[100],rear=-1,front=-1,size;
void enque(int val)
{
	if(rear==size-1)
	{
		printf("Queue is full\n");
		return;
	}
	else if(rear==-1 && front==-1)
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
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty\n");
	}
	if(rear==front)
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
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty\n");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d",queue[i]);
		}
		printf("\n");
	}
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	printf("1.enque 2.deque 3.display 4.exit:");
	scanf("%d",&ch);
	while(1)
	{
		if(ch==1)
		{
			printf("%d",val);
			enque(val);
		}
		else if(ch==2)
		{
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
}
