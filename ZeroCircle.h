#ifndef ZEROCIRCLE_H_INCLUDED
#define ZEROCIRCLE_H_INCLUDED

#include <time.h>
#include <Windows.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NL printf("\n")
void banner(char ban_Name[]);
void stars(int numStar,int ifSpace1,int numSpace);
int str2int(char *,int, int *adres);
void errorMS();
void wait(int sec,int dots,char sign);

void stars(int numStar, int choice, int numSpace)
{
    int i;

    if(choice==1)
    {
        for(i=0;i<numSpace;i++)
            printf(" ");
    }

    for(i=0;i<numStar;i++)
        printf("*");
}
void errorMS()
{
    printf("   **I N C O R R E C T   I N P U T...\a");
    wait(1,0,'.');
    printf("P L E A S E   \a");
    wait(1,0,'.');
    printf("C H O O S E   \a");
    wait(1,0,'.');
    printf("A G A I N**\t\a");
    wait(1,0,'.');
}
void wait(int sec, int dots, char sign)
{
	clock_t end;

    end = clock () + sec * CLK_TCK;
    while (clock() < end){}

  	while(dots>0)
  	{
        printf(" %c ",sign);
        wait(sec,dots-1,sign);
        dots=dots*0;
    }
}
void LOGO_SCREEN()
{
    int i;

    char strWORDS[][15]={"WELCOME-","---TO---","-ONE OF-","-RICKY'S","-AWESOME","PROGRAMS"};
    for(i=0;i<6;i++)
    {
        system("cls");
        NL;NL;NL;NL;NL;NL;NL;NL;NL;
        stars(49,1,17);NL;
        stars(0,1,17);
        printf("****----------------%s-----------------****",strWORDS[i]);NL;
        stars(49,1,17);NL;
        wait(1,0,'/');
    }
    NL;NL;printf("\t\t\tENTER IN >>>");
    for(i=1;i<=3;i++)
    {
        if(i==3)
            printf(" %i",i);

        else
        {
            printf(" %i >",i);
            wait(1,0,'>');
        }
    }
    wait(1,0,'0');
    printf(" >>> GO...");
    system("cls");
}
void banner(char ban_Name[])
{
    system("cls");
    stars(80,2,0);
    printf("\t\t\t\t*%s*\n",ban_Name);
    stars(80,2,0);
}
int str2int(char *temp,int SIZE, int *adres)
{
    int i=0;

    while(i<SIZE)
    {
        if(isdigit(*temp)==0)
        {
            return 1;
        }
        temp++;
        i++;
    }
    temp-=SIZE;
    *adres=atoi(temp);
    return 0;
}
#endif // ZEROCIRCLE_H_INCLUDED
