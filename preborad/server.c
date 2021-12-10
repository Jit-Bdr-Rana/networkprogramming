#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdio.h>
#include<netdb.h>
#include<string.h>
#define SA struct sockaddr
#define PORT 8080
void func(int fd){
    char buff[80];
    char newbuff[80];
    read(fd,buff,sizeof(buff));
    printf("from client %s",buff);

    for(int i=0;i<sizeof(buff);i++){
        newbuff[i]=tolower(buff[i]);
    }
    write(fd,newbuff,sizeof(newbuff));
}
void main(){
    int sockfd,connfd,len;
    struct sockaddr_in servaddr,cliaddr;
  /* socket creation */
     sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd==-1){
        printf("socket creation fail");
        exit(0);
    }else{
        printf("socket has been created successfully....\n");
    }
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(PORT);
    
   
   if(bind(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0){
       printf("socket binding failed..");
   }else{
       printf("successfully binding...\n ");
   }
   if(listen(sockfd,6)!=0){
       printf("listening failed");
   }else{
       printf("successfully listen to the port....\n");
   }
   
   len=sizeof(cliaddr);
  connfd=accept(sockfd,(SA *)&cliaddr,&len);
   if(connfd<0){
    printf("accept is not ready ..,.");
   }else{
       printf("accept is ready....\n");
   }
   func(connfd);
   close(sockfd);

}