#include<ctype.h>
#include<netdb.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#define SA struct sockaddr
#define PORT 8080

void func(int fd){
char newbuff[80];
char buf[80]={'P','U','R','B','A','N','C','H','A','L'};
write(fd,buf,sizeof(buf));
 read(fd,newbuff,sizeof(buf));
 printf("from server:%s ",newbuff);
}
void main(){
  struct sockaddr_in servaddr;
  int sockfd;

  sockfd=socket(AF_INET,SOCK_STREAM,0);

  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  servaddr.sin_port=htons(PORT);
  servaddr.sin_family=AF_INET;

  if(sockfd==-1){
      printf("socket creation failed..");
  }else{
      printf("socket creation successful..\n");
  }

  if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0){
      printf("connection fail..");
      exit(0);
  }else{
      printf("conneciton successful..\n");
  }
  func(sockfd);
  close(sockfd);
 
}