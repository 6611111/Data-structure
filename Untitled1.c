#include<stdio.h>
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
			default :return 0;
		}
}
char *infix_postfix(char *infix)
{
	int i,j=0,n,top=-1;
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
	int i;
	scanf("%[^\n]s]",infix);
	postfix=infix_postfix(infix);
	printf("%s",postfix);
	return 0;
}
