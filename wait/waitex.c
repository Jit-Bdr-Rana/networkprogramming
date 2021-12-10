#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
void main(){

pid_t pid;
if((fork())==0){
 printf("\nchild id %d",getpid());
 printf("\nparent preocessid %d",getppid());
}else{
    pid=waitpid(4589,NULL,0);
    printf("\nchild processid %d",pid);
    printf("\nparent processid %d",getpid());
}



}