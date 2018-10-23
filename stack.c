#include<stdio.h>
int stack[50],choice,n,top=0,x;
void push(void);
void pop(void);
void display(void);
int main()
{
	top=-1;
	printf("enter the size of the stack");
	scanf("%d",&n);
	printf("\t stack operation using array");
	printf("\n\t");
	printf("\n 1. push\n 2. pop\n 3.display");
	do
	{
		printf("\nenter the choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				push();
				break;
			}
			case 2:
			{
				pop();
				break;
			}
			case 3:
			{
				display();
				break;
			}
			case 4 :
			{
				printf("\n\texit point");
			}
			default :
			{
				printf("\t please enter  valid choice ");
				break;
			}
		}
	}
	while(choice!=4);
	{
		return 0;
	}
}
void push()
{
	if(top>=n-1)
	{
		printf("\n stack is overflow");
	}
	else
	{
		printf("enter the value to pushed");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}
void pop()
{
	if(top<=-1)
	{
		printf("stack is underflow");
	}
	else
	{
		printf("\n\t the popped element is %d ",stack[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top>=0)
	{
		printf("\nthe element in stack\n");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",stack[i]);
		}
		printf("\n press next choice");
	}
	else
	{
		printf("\n stack is empty");
	}
}
		

