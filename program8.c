#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count=0;
struct node
{
    int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    struct node *next;
    struct node *prev;
}*first, *temp, *last;

void create()
{
    int ssn;
    long int phno;
    float sal;
    char name[20], dept[10], desg[20];
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter ssn, name, department, designation, salary and phno of employee: ");
    scanf("%d %s %s %s %f %ld", &ssn, name, dept, desg, &sal, &phno);
    temp->ssn = ssn;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->desg, desg);
    temp->sal = sal;
    temp->phno = phno;
    count++;
}

void display()
{
    temp = first;
    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("\n Linked list elements from beginning:\n");
    while (temp != NULL)
    {
        printf("%d %s %s %s %f %ld\n", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phno);
        temp = temp->next;
    }
    printf("No of employees = %d", count);
}


void insert_front()
{
    if (first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
}

void delete_front()
{
    struct node *cur=first;
    if(first == NULL) /* If the List is Empty */
    {
        printf("List is Empty\n");
        return;
    }
    if(first->next == NULL) /* If there is only one node in the List */
    {
        printf("%d %s %s %s %f %ld\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
        free(first);
        first = NULL;
    }
    else
    {
        first = first->next;
        printf("%d %s %s %s %f %ld", cur->ssn, cur->name, cur->dept, cur->desg, cur->sal, cur->phno);
        free(cur);
     }
count--;
}
void insert_rear()
{
    if(first == NULL)
    {
        create();
        first = temp;
        last = first;
    }
    else
    {
        create();
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
}

void delete_rear()
{
    if(first == NULL) /* If the list is Empty */
    {
        printf("List is Empty\n");
        return;
    }
    if(first->next == NULL) /* If there is only one node in the List */
    {
        printf("%d %s %s %s %f %ld\n", first->ssn, first->name, first->dept, first->desg, first->sal, first->phno);
        free(first);
        first = NULL;
    }
    else
    {
        temp = last->prev;
        temp->next = NULL;
        printf("%d %s %s %s %f %ld\n", last->ssn, last->name, last->dept, last->desg, last->sal, last->phno);
        free(last);
        last = temp;
    }
    count--;
}

void main()
{
	int ch, n, i;
	first=NULL;
	temp=last=NULL;
	printf("---------------MENU--------------");
	printf("\n 1.create a DLL of temp");
	printf("\n 2.Display from beganing");
	printf("\n 3.insert at front");
	printf("\n 4.delete at front");
	printf("\n 5.insert at rear");
	printf("\n 6.delete at rear");
	printf("\n 7.exit\n");
	while(1)
	{
	printf("\nEnter the choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\n enter the no mof employee");
		       scanf("%d",&n);
                       for(i=0;i<n;i++)
		       insert_rear();
		       break;
		case 2:	
display();
			break;
		case 3:
insert_rear();
			break;
		case 4:
delete_front();
			break;
		case 5:
insert_rear();
			break;
		case 6:
 delete_rear();
			break;
		case 7:
exit(0);
		default :printf("wrong choice\n");
	}
	}
}
