#include<stdio.h>
#include<string.h>
int perform_oper(int op1,char op,int op2)
{
	switch(op)
	{
		case '+': return op2+op1;
	    case '-': return op2-op1;
	    case '*': return op2*op1;
	    case '/': return op2/op1;
	    case '^': return op2^op1;
	    default: return 0;
	}
}
int isoper(char ch)
{
	switch(ch)
	{
		case '+':
	    case '-':
	    case '*':
	    case '/':
	    case '^':
	    	return 1;
	    default:
	    	return 0;
	}
}
int postfix_eval(char *postfix)
{
	int i,val=0,st[100],top=-1,op1,op2,res;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isoper(postfix[i]))
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
	char postfix[10];
	int res;
	scanf("%[^\n]s",postfix);
	res=postfix_eval(postfix);
	printf("%d ",res);
}
