#include<stdio.h>
#include<netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define SA struct sockaddr
#define PORT 8080
#define MAXLINE 1024
void main(){
    int fd;
    struct sockaddr_in servaddr,cliaddr;
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd<0){
        printf("socket creation failed...");
        exit(0);
    }else{
        printf("successfully created socket....\n");
    }
    memset(&servaddr,0,sizeof(servaddr));
    memset(&cliaddr,0,sizeof(cliaddr));
   
    servaddr.sin_addr.s_addr=INADDR_ANY;
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT);
    
    if(bind(fd,(SA *)&servaddr,sizeof(servaddr))<0){
        printf("server binding failed...\n");
        exit(0);
    }else{
        printf("server bind successfully");
    }
   //chatting start here
   for(;;){
    int len,n;
    len=sizeof(cliaddr);
    char buffer[MAXLINE];

   n=recvfrom(fd,(char *)buffer,MAXLINE,MSG_WAITALL,(SA *)&cliaddr,&len);
   buffer[n]='\0';
   printf("\nclient says:%s",buffer);


   printf("\nserver:");
   memset(buffer,0,MAXLINE);
   int i=0;
   while((buffer[i++]=getchar())!='\n');
   sendto(fd,(const char *)buffer,strlen(buffer),MSG_CONFIRM,(SA *)&cliaddr,len);
   if(strncmp("exit",buffer,4)==0){
       break;
   }
   }
  printf("\nexiting from client....");
  close(fd);
}