#include<stdio.h>
#include<stdlib.h>
struct Day
{
char *dayname;
int date;
char *activity;
};
struct Day*Creat_calendar();
void readcalender (struct Day*calendar);
void displaycalendar (struct Day*calendar);
void freecalendar (struct Day*calender);
int main()
{
struct Day*calendar = Creat_calendar();
readcalendar (calendar);
displaycalendar (calendar);
freecalendar (calendar);
 return 0;
}
struct Day*Creat_calendar()
{
return ((struct Day*)malloc(7*sizeof(struct Day)));
}
void readcalendar(struct Day*calendar)
{
for(int i=0;i<7;i++)
{
printf("Enter the name of the Day %d",i+1);
scanf("%ms",&calendar[i].dayname);
printf("Enter the date for calendar%s",calendar[i].dayname);
scanf("%d",&calendar[i].date);
printf("Enter the activity for %s",calendar[i].dayname);
scanf("%ms",&calendar[i].activity);
}
}
void displaycalendar (struct Day*calendar)
{
for (int i=0;i<7;i++)
{
printf("day:%s\n,date:%d\n,activity%s\n",calendar[i].dayname,calendar[i].date,calendar[i].activity);
}
}
void freecalendar (struct Day*calendar)
{
for(int i=0;i<7;i++)
{
free(calendar[i].dayname);
free(calendar[i].activity);
}
free(calendar);
}
}
