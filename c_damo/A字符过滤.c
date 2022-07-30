#include<stdio.h>
#include<string.h>

void Next(char *T, int *next);

int KMP(char *S, char *T);

int main(int argv, char *argc[])
{
int i=KMP(argc[1],argc[2]);
printf("%d\n",i);
printf("%s",argc[1]);
printf("\n");
while(--i){
printf("-");}
printf("%s",argc[2]);
return 0;}

void Next(char *T, int *next){
int i=1;
next[1]=0;
int j=0;
while(i<strlen(T)){
if(j==0 || T[i-1]==T[j-1]){
++i;++j;
next[i]=j;
}else{
j=next[j];
}
}
}

int KMP(char *S, char *T){
int next[64];
Next(T, next);
int i=1;
int j=1;
while(i<=strlen(S)&&j<=strlen(T)){
if(j==0||S[i-1]==T[j-1]){
i++;
j++;
}else{
j=next[j];
}
}
if(j>strlen(T)){
return (i-(int)strlen(T));
}
return -1;
}
