#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
void main(){
    char *args[]={"./wait",NULL};
    execvp(args[0],args);
    printf("ending....");
}