#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#define SA struct sockaddr
#define PORT 8080
#define MAX 80
void main(){
    int fd;
    struct sockaddr_in servaddr,cliaddr;
    
    fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd==-1){
        printf("socket creation failed...");
        exit(0);
    }else{
        printf("socket creation successfull..\n");
    }
    memset(&servaddr,0,sizeof(servaddr));
    memset(&cliaddr,0,sizeof(cliaddr));
    servaddr.sin_addr.s_addr=INADDR_ANY;
    servaddr.sin_port=htons(PORT);
    servaddr.sin_family=AF_INET;

    if(bind(fd,(SA *)&servaddr,sizeof(servaddr))==-1){
      printf("binding failed....\n");
      exit(0);
    }else{
        printf("binding successful...\n");
    }

    
     for(;;){
    int len,n;
    len=sizeof(cliaddr);
    char buffer[MAX];

   n=recvfrom(fd,(char *)buffer,MAX,MSG_WAITALL,(SA *)&cliaddr,&len);
   buffer[n]='\0';
   printf("\nclient says:%s",buffer);


   printf("\nserver:");
   memset(buffer,0,MAX);
   int i=0;
   while((buffer[i++]=getchar())!='\n');
   sendto(fd,(const char *)buffer,strlen(buffer),MSG_CONFIRM,(SA *)&cliaddr,len);
   if(strncmp("exit",buffer,4)==0){
       break;
   }
   
}
    close(fd);

}