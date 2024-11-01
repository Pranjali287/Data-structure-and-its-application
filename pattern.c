#include<stdio.h>
void main()
{
char str[100],pat[100],rep[100],ans[100];
int i,j,c,m,k,flag=0;
printf("\n enter the main string:");
gets(str);
printf("\n enter the pattern :");
gets(pat);
printf("\n enter the repalce string:");
gets(rep);
i=j=m=c=0;
while(str[c]!='\0')
{
	if(str[m]==pat[i])
	{
	i++;
	m++;
	if(pat[i]=='\0')
	{
		flag=1;
		for(k=0;rep[k]!='\0';k++,j++)
        		ans[j]=rep[k];
			i=0;
			c=m;
	}
        }
	else
	{
		ans[j]=str[c];
		j++;
		c++;
		m=c;
		i=0;
	}
}
if(flag==0)
{
	printf("pattern doesnt exist\n");
}
else
{
	ans[j]='\0';
	printf("the resultant string is %s\n",ans);
}
}
