#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max 5
int s[max],top=-1,item;
int isfull()
{
	if (top>=max)
	{
		return 1;
	}
	return 0;
}
int isempty()
{
	if (top==-1)
	{
		return 1;
	}
	return 0;
}
void push(int item)
{
	top++;
	s[top]=item;
}
void pop()
{
	item=s[top];
	top--;
}
void display()
{
int i;
printf("\n the elements of the stack");
for (i=top;i>=0;i--)
{
	printf("\n %d",s[i]);
}
}
void check_pal()
{
	int i=0,digit,renum=0,num=0,k=0;
	if (top==-1)
	{
		printf("\n the stack is empty");
		return;
	}
	else
	{
	while(top!=-1)
	{
		pop();
		num=num*10+item;
		renum=item*pow(10,k)+renum;
		k=k+1;
	}
	printf("\n the reverse number of %d is%d",num ,renum);
	if (num==renum)
	{
		printf("the stack contains a palendrome");
	}
	else
	{
		printf("\n the stack is not a palendrome");
	}
}
}
void main()
{
int ch;
do
{
printf("\n 1.push \n2.pop \n 3.display \n4.palendrome \n5.exit\n");
printf("\n enter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the elemnet to be inserted");
scanf("%d",&item);
if(isfull())
{
printf("stack overflow");
}
else
{
push(item);
}
break;
case 2:
if (isempty())
{
printf("\n stack under flow");
}
else
{
pop();
printf("the item deleted is %d\n",item);
}
break;
case 3:
if(isempty())
{
printf("stack is empty");
}
else{
display();
}
break;
case 4:
check_pal();
break;
case 5:
printf("process terminated\n");
exit(0);
default:
printf("invaild input\n");
}
}while(ch!=5);
}
