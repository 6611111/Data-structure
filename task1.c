/*include<stdio.h>
int queue[100],front=-1,rear=-1,size;
void enque(int val)
{
	if(rear==size-1)
	{
		printf("Queue is full\n");
		return ;
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
		printf("Queue is empty\n");
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
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque\n2.Deque\n3.Display\n4.Exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			//..enque
			scanf("%d",&val);
			enque(val);
		}
		else if(ch==2)
		{
			//..deque
			val=deque();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d \n",val);
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
	if(front==rear)
	{
		val=queue[front];
		front=-1;
		rear=-1;
		return val;
	}
	val=queue[front];
	front=(front+1)%size;
	return val;
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty\n");
	}
	while(i!=rear)
	{
		printf("%d \n",queue[i]);
		i=(i+1)%size;
	}
	printf("%d \n",queue[i]);
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque 2.Deque 3.Display 4.Exit: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d",&val);
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
#include<stdio.h>
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
	else if(rear==front-1)
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
		front=(front+1)%size;
		val=queue[front];
		return val;
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
		return val;
	}
	else
	{
		rear--;
		val=queue[front];
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
	while(i!=rear)
	{
		printf("%d \n",queue[i]);
		i=(i+1)%size;
	}
	printf("%d \n",queue[i]);
}
int main()
{
	int ch,val;
	scanf("%d",&size);
	while(1)
	{
		printf("1.Enque at rear\n2.Enque at front\n3.Deque at front\n4.Deque at rear\n5.Display\n6.Exit: ");
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
			//..deque at front
			val=deque_at_front();
			if(val==-1)
			{
				printf("Queue is empty\n");
			}
			else
			{
				printf("%d\n",val);
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
				printf("%d\n",val);
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
}
