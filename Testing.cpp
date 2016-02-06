#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main()
{
    char randChar[53], charCheck;
    bool once=true;
    int cnt, arrCnt,pos=0;

    srand(time(NULL));

    while(1)
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
            while(cnt<4 || arrCnt<52)
            {
                if(charCheck==randChar[arrCnt])
                {
                    cnt++;
                }
                arrCnt++;
            }
            if(cnt<4)
                pos++;
            if(pos>52)
                break;
        }
    }
    cout<<randChar[0]<<endl;
    cout<<charCheck;
}
