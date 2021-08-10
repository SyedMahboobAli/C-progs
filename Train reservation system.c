/*III SEM MINI PROJECT
TRAIN RESERVATION SYSTEM
DONE BY:
SYED MAHBOOB ALI , TASSAIN RASOOL MALIK
1602-18-733-055,1602-18-733-035
CSE-A
II YEAR
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 120
void insert();
void delete();
int queue_array[MAX];
int rear = - 1;
int front = - 1;

typedef struct{
char name[50];
int train_num;
int num_of_seats;
}pd;

void reservation(void);
void cancel(void);
void printticket(char name[],int,int,float);
void specifictrain(int);
float charge(int,int);

int main()
{
printf("\t\t=================================================\n");
printf("\t\t|                                               |\n");
printf("\t\t|        --------------------------------       |\n");
printf("\t\t|        TRAIN TICKET RERSERVATION SYSTEM       |\n");
printf("\t\t|        --------------------------------       |\n");
    printf("\t\t|                                               |\n");
printf("\t\t=================================================\n\n\n");
int menu_choice,choice_return;
printf("\n=================================\n");
printf("    TRAIN RESERVATION SYSTEM");
printf("\n=================================");
printf("\n1>> Reserve A Ticket");
printf("\n------------------------");
printf("\n2>> View All Available Trains");
printf("\n------------------------");
printf("\n3>> Cancel Reservation");
printf("\n------------------------");
printf("\n4>> Exit");
printf("\n------------------------");
printf("\n\n-->");
scanf("%d",&menu_choice);
switch(menu_choice)
{
case 1:
reservation();
break;
case 2:
viewdetails();
break;
case 3:
cancel();
break;
case 4:
return(0);
default:
printf("\nInvalid choice");
}
return(0);
}


void insert()
{
    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
            front = 0;
        rear = rear + 1;
    }
}


void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        front = front + 1;
    }
}
void viewdetails()
{
printf("\n--------------------------------------------------------------------------------------------------------");
printf("\nTr.No\tName\t\t\t\tDestinations\t\t\t\t\tCharges\t\tTime\n");
printf("--------------------------------------------------------------------------------------------------------");
printf("\n1001\tGoa Express\t\tVasco da Gama (Goa) to Londa (Karnataka)\t\tRs.5000\t\t9am");
printf("\n1002\tRajdhani Express\tNew Jalpaiguri (West Bengal), Tinsukia , Ledo(Assam)\tRs.5000\t\t12pm");
printf("\n1003\tNizamuddin Express\tPune (Maharashtra) to New Delhi\t\t\t\tRs.4500\t\t8am");
printf("\n1004\tMandovi Express\t\tMadgaon (Goa) to Mumbai\t\t\t\t\tRs.4500\t\t11am");
printf("\n1005\tIndian Express\t\tMumbai to Delhi\t\t\t\t\t\tRs.4000\t\t7am");
printf("\n1006\tIsland Express\t\tKanyakumari (Tamil Nadu) to Trivandrum(Kerala)\t\tRs.4000\t\t9.30am");
    printf("\n1007\tHimalayan Queen\t\tKalka (Haryana) to Shimla (Himachal Pradesh)\t\tRs.3500\t\t1pm");
    printf("\n1008\tJammu Mail\t\tJammu to Udhampur (Jammu state)\t\t\t\tRs.3500\t\t4pm");
    printf("\n1009\tGolden Chariot\t\tBangalore (Karnataka) to Goa\t\t\t\tRs.6000\t\t3.35pm");
    printf("\n1010\tThe Toy Train\t\tNew Jalpaiguri to Darjeeling (West Bengal)\t\tRs.6000\t\t4.15pm");

}


void reservation()
{
char confirm;
int i=0;
float charges;
pd passdetails;
    printf("\nEnter Your Name:> ");
    scanf("%s",&passdetails.name);
    printf("\nEnter Number of seats:> ");
    scanf("%d",&passdetails.num_of_seats);
printf("\n\n");
if(passdetails.num_of_seats>120)
    {
        printf("Only 120 seats are available:");
    }
    else
    {

    viewdetails();
printf("\n\nEnter train number:> ");
start1:
scanf("%d",&passdetails.train_num);
if(passdetails.train_num>=1001 && passdetails.train_num<=1010)
{
charges=charge(passdetails.train_num,passdetails.num_of_seats);
printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
}
else
{
printf("\nInvalid train Number! Enter again--> ");
goto start1;
}

printf("\n\nConfirm Ticket (y/n):>");
start:
scanf(" %c",&confirm);
if(confirm == 'y')
{
printf("==================");
printf("\n Reservation Done\n");
printf("==================");
printf("\n");
}
else
{
if(confirm=='n'){
printf("\nReservation Not Done!\nj");
}
else
{
printf("\nInvalid choice entered! Enter again-----> ");
goto start;
}
}
    }
}


float charge(int train_num,int num_of_seats)
{
if (train_num==1001)
{
return(5000.0*num_of_seats);
}
if (train_num==1002)
{
return(5000.0*num_of_seats);
}
if (train_num==1003)
{
return(4500.0*num_of_seats);
}
if (train_num==1004)
{
return(4500.0*num_of_seats);
}
if (train_num==1005)
{
return(4000.0*num_of_seats);
}
if (train_num==1006)
{
return(4000.0*num_of_seats);
}
if (train_num==1007)
{
return(3500.0*num_of_seats);
}
if (train_num==1008)
{
return(3500.0*num_of_seats);
}
if (train_num==1009)
{
return(6000.0*num_of_seats);
}
if (train_num==1010)
{
return(6000.0*num_of_seats);
}
}

void printticket(char name[],int num_of_seats,int train_num,float charges)
{
printf("-------------------\n");
printf("\tTICKET\n");
printf("-------------------\n\n");
printf("Name:\t\t\t%s",name);
printf("\nNumber Of Seats:\t%d",num_of_seats);
printf("\nTrain Number:\t\t%d",train_num);
specifictrain(train_num);
printf("\nCharges:\t\t%.2f",charges);
}



void specifictrain(int train_num)
{

if (train_num==1001)
{
printf("\nTrain:\t\t\tGoa Express");
printf("\nDestination:\t\tVasco da Gama (Goa) to Londa (Karnataka)");
printf("\nDeparture:\t\t9am ");
}
if (train_num==1002)
{
printf("\nTrain:\t\t\tDibrugarh Rajdhani Express");
printf("\nDestination:\t\tNew Jalpaiguri (West Bengal), Tinsukia , Ledo(Assam)");
printf("\nDeparture:\t\t12pm");
}
if (train_num==1003)
{
printf("\nTrain:\t\t\tNizamuddin Duronto Express");
printf("\nDestination:\t\tPune (Maharashtra) to New Delhi");
printf("\nDeparture:\t\t8am");
}
if (train_num==1004)
{
printf("\nTrain:\t\t\tMandovi Express");
printf("\nDestination:\t\tMadgaon (Goa) to Mumbai");
printf("\nDeparture:\t\t11am ");
}
if (train_num==1005)
{
printf("\nTrain:\t\t\tIndian Maharaja Deccan Odyssey");
printf("\nDestination:\t\tMumbai to Delhi");
printf("\nDeparture:\t\t7am");
}
if (train_num==1006)
{
printf("\ntrain:\t\t\tIsland Express");
printf("\nDestination:\t\tKanyakumari (Tamil Nadu) to Trivandrum (Kerala)");
printf("\nDeparture:\t\t9.30am ");
}
if (train_num==1007)
{
printf("\ntrain:\t\t\tHimalayan Queen");
printf("\nDestination:\t\tKalka (Haryana) to Shimla (Himachal Pradesh)");
printf("\nDeparture:\t\t1pm ");
}
if (train_num==1008)
{
printf("\ntrain:\t\t\tJammu Mail");
printf("\n Destination:\t\tJammu to Udhampur (Jammu state)");
printf("\nDeparture:\t\t4pm ");
}
if (train_num==1009)
{
printf("\ntrain:\t\t\tGolden Chariot");
printf("\nDestination:\t\tBangalore (Karnataka) to Goa");
printf("\nDeparture:\t\t3.35pm ");
}
if (train_num==1010)
{
printf("\ntrain:\t\t\tThe Toy Train");
printf("\nDestination:\t\tNew Jalpaiguri to Darjeeling (West Bengal)");
printf("\nDeparture:\t\t1.15 ");
}
}


void cancel(void)
{
int i=0;
int trainnum;
    printf("-----------------------\n");
    printf("Enter the train number: \n");
printf("-----------------------\n");
    scanf("%i",&trainnum);
    delete();
    printf("\n\nCancelled");
}





