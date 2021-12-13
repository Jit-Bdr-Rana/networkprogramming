#include<stdio.h>
#include<netdb.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int sockfd){
char buff[MAX];
int n;
for(;;){
  bzero(buff,MAX);
  read(sockfd,buff,sizeof(buff));
  printf("\nclient:%s ",buff);
  bzero(buff,MAX);
  n=0;
  printf("\nserver:");
  while((buff[n++]=getchar())!='\n');
  write(sockfd,buff,sizeof(buff));
  if(strncmp("exit",buff,4)==0){
    printf("server exit...\n");
    break;
  }
}
}
int main()
{
int sockfd,confd,len;
struct sockaddr_in servaddr ,cli;

sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1){
  printf("socket creation has beenfailled");
  exit(0);
  }else{
  printf("socket had been successfully created");
  }

bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(PORT);

/*binding*/
if((bind(sockfd,(SA*)&servaddr,sizeof(servaddr)))!=0)
{
  printf("failed in binding");
  exit(0);
}else{
   printf("binding successfully");
}
/** listening**/
if((listen(sockfd,5))!=0){
printf("fail in listening");
}else{
 printf("success in listening ");
}
//accept
int lenth=sizeof(cli);
confd=accept(sockfd,(SA*)&cli,&lenth);
if(confd<0){
 printf("server accept fail");
 exit(0);
}else{
 printf("seraver accepted successfully");
}
func(confd);
close(sockfd);
}

