#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
void main(){
    char j[80]={'J','I','T','U'};
    char n[80];
   for(int i=0;i<=sizeof(j);i++){
     n[i]=tolower(j[i]);
   }
   printf("before %s",j);
   printf("after %s",n);

}