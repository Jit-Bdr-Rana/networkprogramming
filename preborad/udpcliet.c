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
int fd,n;
char buffer[MAXLINE];
struct sockaddr_in servaddr;
if((fd=socket(AF_INET,SOCK_DGRAM,0))<0){
    printf("socket creation failed ....\n");
    exit(0);
}else{
 printf("socket creation successful...\n");
}
memset(&servaddr,0,sizeof(servaddr));
servaddr.sin_port=htons(PORT);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;

for(;;){
int len,i;
len=sizeof(servaddr);
printf("Client:");
while((buffer[i++]=getchar())!='\n');
sendto(fd,buffer,strlen(buffer),MSG_CONFIRM,(SA *)&servaddr,sizeof(servaddr));  
memset(buffer,0,MAXLINE);
 

n=recvfrom(fd,(const char*)buffer,MAXLINE,MSG_WAITALL,(SA *)&servaddr,&len);
buffer[n]='\0';
printf("\nserver says:%s",buffer);
 if(strncmp("exit",buffer,4)==0){
       break;
   }
}
close(fd);
}