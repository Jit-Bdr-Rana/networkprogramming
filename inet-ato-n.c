#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdio.h>
#include<sys/select.h>
#include<sys/poll.h>
#include<sys/types.h>
#include<unistd.h>
#define SA struct sockaddr
void main(){
    int child=fork();
    if(child==0){
        printf("from child \n");
        printf("i am child procee and my id is %d \n",getpid());
        printf("i am parent process my id id %d \n",getppid());
        printf("\n");
    }else{
        printf("from parent \n");
        printf("i am parent process and my id is %d \n",getpid());
        printf("i am child process my id id %d\n",child);
        printf("\n");]
        wait();
        
    }

}