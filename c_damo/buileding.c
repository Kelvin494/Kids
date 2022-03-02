#include <stdio.h>
#include "windows.h"
int main(int argc, char **argv) 
{
DWORD dwFreq = 200;
DWORD dwDuration = 1000;
    Beep(dwFreq, dwDuration);
    return 0;
}