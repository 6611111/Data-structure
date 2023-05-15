#include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque_rear(int val)
{
	if(front==0 && front==size-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==-1 && front==-1)
	{
		rear=0;
		front=0;
		queue[rear]=val;
	}
	else
	{
		rear=(rear+1)%size;
		queue[rear]=val;
	}
}
void enque_front(int val)
{
	if(front==size-1 && front==0)
	{
		printf("Queue is full\n");
	}
	else if(rear==front-1)
	{
		printf("Queue is full\n");
	}
	else if(rear==-1 && front==-1)
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
int deque_front()
{
	int val;
	if(front==-1 && rear==-1)
	{
		printf("queue is empty\n");
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
int deque_rear()
{
	int val;
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty\n");
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
void display()
{
	int i;
	i=front;
	if(rear==-1 && front==-1)
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
		printf("1.enque at rear \n 2.deque at front\n 3.display \n 4.enque at front \n 5.deque at rear \n 6.exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..enque at rear
			scanf("%d",&val);
			enque_rear(val);
		}
		else if(ch==2)
		{
			//..deque at front
			val=deque_front();
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
			enque_front(val);
		}
		else if(ch==5)
		{
			//...deque at rear
			val=deque_rear();
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
}
