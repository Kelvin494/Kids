#include<stdio.h>
#include<conio.h>
int main()
{
    int x = 1;
    char keyvelue;
    int i=0;
    while(x)
        {
            if(_kbhit()) //问题是不连续输入也可以
            {
                keyvelue = getche();
                if(keyvelue=='e'&&i==0) {i++;continue;} //
                
                if(keyvelue=='x'&&i==1) {i++;continue;} //
                
                if(keyvelue=='i'&&i==2) {i++;continue;} //
                
                if(keyvelue=='t'&&i==3) {i=x=0;continue;} //
                

                i=0;
                
               
            }
        }


return 0;
}
int estimate()
{



    return 1;
}
/*
winsocket2 gcc
-lwin32socket
鏌ョ湅dll,lib
Visual studio 2015 Command Prompt
dumpbin /exports 鈥淐:\Windows\System32\user32.dll鈥�
dumpbin /LINKERMEMBER aa.lib
*/



