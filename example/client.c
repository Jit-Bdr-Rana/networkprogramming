#include<sys/socket.h>
#include <netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SA struct sockaddr 
#define PORT 8080
#define MAX 80
void main(){
  int len, fd;
  struct sockaddr_in servaddr,cliaddr;
  
  fd=socket(AF_INET,SOCK_DGRAM,0);
  if(fd==-1){
      printf("socket creation failed...\n");
  }else{
      printf("socket creation succcessful...\n");
  }
  servaddr.sin_family=AF_INET;
  servaddr.sin_addr.s_addr=INADDR_ANY;
  servaddr.sin_port=htons(PORT);

  for(;;){
      int len,n=0;
      char buffer[MAX];
       memset(&buffer,0,MAX);
      printf("\nclient:");
      while((buffer[n++]=getchar())!='\n');
      size_t sen=sendto(fd,(const char *)buffer,sizeof(buffer),MSG_CONFIRM,(SA *)&servaddr,sizeof(servaddr));

     memset(&buffer,0,MAX);
     len=sizeof(servaddr);
     n=recvfrom(fd,(char *)buffer,MAX,MSG_WAITALL,(SA *)&servaddr,&len);
     buffer[n]='\0';
     printf("\nserver:%s",buffer);
     printf("\nrecvfrom return:%d",n);
     printf("\nsendTo retrun:%ld",sen);

     if(strncmp("exit",buffer,4)==0){
         break;
     }
  }
  close(fd);

}