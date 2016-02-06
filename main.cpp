#include <string>
#include <time.h>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include "ZeroCircle.h"
template<typename T>

std::string to_string(T n)
{
     std::ostringstream os;
     os << n;
     return os.str();
}

typedef struct
{
    int dealer,player,draws;
}gameScore;

using namespace std;

void cardPrinter(string [],int,string tabs = "");
void cardPrinter(string, int numCards=1,string tabs = "",string playerInfo="",string dealerInfo="",string info = "");
void cardGenerator(string []);
void interFace(gameScore,string [],string [],string [],int,int,int,int,bool,bool,bool,int,int,int,int deckAmt,char userInput=' ');
int dealerCnt(string, int);
int playerCnt(string,int,bool);
void endStats(string [], string [], int,int,int,int,int,gameScore,bool noEnter,bool ext=false);
void scoreBoard(gameScore);

int main()
{
    string cards[52], playerCards[21], dealerCards[21];
    gameScore pnts;
    static int once=0;
    if(once==0)
    {
        LOGO_SCREEN();
        once++;
    }
    srand(time(NULL));
    cardGenerator(cards);
    interFace(pnts,cards,playerCards,dealerCards,0,0,0,0,false,false,true,0,0,0,52);
    return 0;
}
void cardPrinter(string card[], int numCards,string tabs)
{
    int i;
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<" ---  ";
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
    {   if(card[i]=="10")
            cout<<"| 1 | ";
        else
            cout<<"|   | ";
    }
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
    {
        if(card[i]=="10")
            cout<<"|   | ";
        else
            cout<<"| "<<card[i]<<" | ";
    }
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
    {   if(card[i]=="10")
            cout<<"| 0 | ";
        else
            cout<<"|   | ";
    }
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<" ---  ";
    cout<<"\n"<<tabs;
}
void cardPrinter(string card, int numCards,string tabs,string playerInfo,string dealerInfo,string info)
{
    int i;
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<" ---  ";
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<"| "<<card<<" | "<<playerInfo;
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<"| "<<card<<" | "<<info;
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<"| "<<card<<" | "<<dealerInfo;
    cout<<"\n"<<tabs;
    for(i=0;i<numCards;i++)
        cout<<" ---  ";
    cout<<"\n"<<tabs;
}
void cardGenerator(string cards[])
{
    char charCheck,randChar[52];
    bool once=true,ext=false;
    int cnt, arrCnt,pos=0;

    srand(time(NULL));

    while(ext==false)
    {
        cnt=0;
        arrCnt=0;

        charCheck=rand()%(77-65+1)+65;
        if(once==true)
        {
            randChar[pos]=charCheck;
            pos++;
            once=false;
        }
        else
        {
            while(arrCnt<51)
            {
                if(charCheck==randChar[arrCnt])
                    cnt++;
                arrCnt++;
            }
            if(cnt<4)
            {
                randChar[pos]=charCheck;
                pos++;
            }
            if(pos>51)
                ext=true;
        }
    }
    for(unsigned int i=0;i<sizeof(randChar);i++)
    {
        if(randChar[i]=='A')
            cards[i]="2";
        if(randChar[i]=='B')
            cards[i]="3";
        if(randChar[i]=='C')
            cards[i]="4";
        if(randChar[i]=='D')
            cards[i]="5";
        if(randChar[i]=='E')
            cards[i]="6";
        if(randChar[i]=='F')
            cards[i]="7";
        if(randChar[i]=='G')
            cards[i]="8";
        if(randChar[i]=='H')
            cards[i]="9";
        if(randChar[i]=='I')
            cards[i]="10";
        if(randChar[i]=='J')
            cards[i]="J";
        if(randChar[i]=='K')
            cards[i]="K";
        if(randChar[i]=='L')
            cards[i]="Q";
        if(randChar[i]=='M')
            cards[i]="A";
    }
}
void interFace(gameScore pnts,string cards[],string playerCards[],string dealerCards[],int p,int PnumCards,int deckPos,int playerTotal,bool ace11,bool burst,bool swtch,int DnumCards, int dealerTotal,int d,int deckAmt,char userInput)
{
    int deckDraw=0;
    char aceChoice;
    char test[1000]={0};

    if(swtch==true)
    {
        playerCards[p]=cards[deckPos];
        PnumCards++;
        deckDraw++;
        deckPos++;
    }
    if(burst==false)
    {
        int numTemp1=0,numTemp2=0;

            numTemp1=dealerTotal;
            dealerCards[d]=cards[deckPos];
            if(dealerCards[d]=="A" && dealerTotal<11)
                dealerTotal=dealerTotal+11;
            else if(dealerCards[d]=="A" && dealerTotal>10)
                dealerTotal=dealerTotal+1;
            if(dealerCards[d]!="A")
                dealerTotal=dealerCnt(dealerCards[d],dealerTotal);
            DnumCards++;
            deckPos++;
            numTemp2=dealerTotal;
            if(dealerTotal>21)
            {
                numTemp1=numTemp2-numTemp1;
                dealerTotal=dealerTotal-numTemp1;
                DnumCards--;
                burst=true;
            }
            else
                deckDraw++;
    }
    deckAmt=deckAmt-deckDraw;
    string info="DECK AMOUNT: " + to_string(deckAmt);
    do
    {
        system("cls");
        cout<<"\t\t\t B  L  A  C  K      J  A  C  K\n";
        cout<<"\t\t\t\tDEALER'S CARDS";
        cardPrinter("X",DnumCards,"\t\t","");
        cardPrinter("X",1,"   ","","",info);
        cardPrinter(playerCards,PnumCards,"\t\t");
        cout<<"\t\tPLAYER'S CARDS\n";
        if(playerCards[p]=="A" && ace11==false)
        {
            cout<<"\tPress '1' To Count This 'Ace' as 11 Or Any Key To Count As 1: ";
            cin.getline(test,999);
            int k=0;
            for(unsigned int i=0;test[i]!='\0';i++)
            {
                if(isspace(test[i])==0)
                {
                    test[k]=test[i];
                    k++;
                    continue;
                }
                test[i]='\0';
            }
            aceChoice=test[0];
            cin.clear();
            if(aceChoice=='1' && k==1)
            {
                playerTotal=playerTotal+11;
                ace11=true;
            }
        }
        if(swtch==true && userInput!='1')
            playerTotal=playerCnt(playerCards[p],playerTotal,ace11);

        if(playerTotal>=21 || (burst==true && swtch==false))
        {
            cout<<"Press Any Key To Continue...";
            getch();
            endStats(playerCards,dealerCards,deckAmt,PnumCards,DnumCards,playerTotal,dealerTotal,pnts,false);
        }
        if(swtch!=false)
        {
            cout<<"\t\tPress 'H' For HIT\t";
            cout<<"Press 'S' For STAY\n";
            cout<<"\t\t\t   Press 'X' To Exit Game\n";
            cout<<"CHOICE: ";
            cin.getline(test,999);
            int k=0;
            for(unsigned int i=0;test[i]!='\0';i++)
            {
                if(isspace(test[i])==0)
                {
                    test[k]=test[i];
                    k++;
                    continue;
                }
                test[i]='\0';
            }
            userInput=test[0];
            if(k>1)
                userInput='1';
            cin.clear();
        }
        switch(userInput)
        {
            case 'H':
            case 'h':   interFace(pnts,cards,playerCards,dealerCards,p+1,PnumCards,deckPos,playerTotal,ace11,burst,swtch,DnumCards,dealerTotal,d+1,deckAmt);
                        break;
            case 'S':
            case 's':   swtch=false;
                        wait(1,0,'.');
                        interFace(pnts,cards,playerCards,dealerCards,p,PnumCards,deckPos,playerTotal,ace11,burst,swtch,DnumCards,dealerTotal,d+1,deckAmt,userInput);
                        break;

            case 'X':
            case 'x':   endStats(playerCards,dealerCards,deckAmt,PnumCards,DnumCards,playerTotal,dealerTotal,pnts,false,true);

            default:    cout<<"\n\t\t\t  WRONG INPUT...ENTER AGAIN";
                        wait(1,0,'0');
                        userInput='1';
        }
    }while(userInput=='1');
}
void endStats(string playerCards[], string dealerCards[], int deckAmt, int PnumCards, int DnumCards,int playerTotal,int dealerTotal,gameScore pnts,bool noEnter,bool ext)
{
    char input;
    char test[1000]={0};
    static int pScore;
    static int dScore;
    static int draws;
    if(ext==true)
    {
        pnts.player=pScore;
        pnts.dealer=dScore;
        pnts.draws=draws;
        scoreBoard(pnts);
    }

    string winner;
    if(playerTotal>dealerTotal && playerTotal<=21)
        winner="PLAYER  WIN!!!";
    else if(playerTotal<dealerTotal || playerTotal>21)
        winner="DEALER WIN!!!";
    else if(playerTotal==dealerTotal)
        winner="DRAW!!!";
    if(noEnter==false)
    {
        if(playerTotal>dealerTotal && playerTotal<=21 && noEnter==false)
            pScore++;
        else if(playerTotal<dealerTotal || (playerTotal>21 && noEnter==false))
            dScore++;
        else if(playerTotal==dealerTotal && noEnter==false)
            draws++;
    }

    string info="DECK AMOUNT: " + to_string(deckAmt) + "\t"+winner;
    string playerInfo="\t\t\t\t\t\tPlayer Count: " + to_string(playerTotal);
    string dealerInfo="\t\t\t\t\t\tDealer Count: " + to_string(dealerTotal);

    system("cls");
    cout<<"\t\t\t B  L  A  C  K      J  A  C  K\n\n";
    cout<<"\t\t\t\tDEALER'S CARDS";
    cardPrinter(dealerCards,DnumCards,"\t\t");
    cardPrinter("X",1,"   ",playerInfo,dealerInfo,info);
    cardPrinter(playerCards,PnumCards,"\t\t");
    cout<<"\t\tPLAYER'S CARDS\n\n";
    cout<<"\t\t\t      Want To Play Again\n\t    Press 'C' To Continue\t\tPress 'X' For Exit: ";
    cin.getline(test,999);
    int k=0;
    for(unsigned int i=0;test[i]!='\0';i++)
    {
        if(isspace(test[i])==0)
        {
            test[k]=test[i];
            k++;
            continue;
        }
        test[i]='\0';
    }
    input=test[0];
    if(k>1)
        input='1';
    cin.clear();
    switch(input)
    {
        case 'c':
        case 'C':   main();

        case 'X':
        case 'x':   endStats(playerCards,dealerCards,deckAmt,PnumCards,DnumCards,playerTotal,dealerTotal,pnts,false,true);

        default:    cout<<"\t\t\t   WRONG INPUT...ENTER AGAIN";
                    noEnter=true;
                    wait(1,0,'0');
                    endStats(playerCards,dealerCards,deckAmt,PnumCards,DnumCards,playerTotal,dealerTotal,pnts,noEnter);
    }
}
int playerCnt(string playerCards,int playerTotal,bool ace11)
{
    if(playerCards=="J" || playerCards=="Q" || playerCards=="K" || playerCards=="10")
        playerTotal = playerTotal + 10;
    else if(ace11==false && playerCards=="A")
        playerTotal=playerTotal+1;
    else
        playerTotal = playerTotal + atoi(playerCards.c_str());

    return playerTotal;
}
int dealerCnt(string dealerCards, int dealerTotal)
{
    if(dealerCards=="J" || dealerCards=="Q" || dealerCards=="K" || dealerCards=="10")
        dealerTotal = dealerTotal + 10;
    else
        dealerTotal = dealerTotal + atoi(dealerCards.c_str());

    return dealerTotal;
}
void scoreBoard(gameScore pnts)
{
    char ban[] = "S C O R E B O A R D";
    banner(ban);
    stars(640,0,0);
    cout<<"\n\t\t  *PLAYER*\t   *DEALER*\t    *DRAWS*\n";
    cout<<"\t\t     "<<pnts.player<<"\t\t      "<<pnts.dealer<<"\t\t       "<<pnts.draws<<"\n\n";
    stars(799,0,0);
    cout<<"\010";
    wait(9,0,'0');
    exit(0);
}
