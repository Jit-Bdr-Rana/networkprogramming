#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main(){
  int fd;
  char * myfifo = "/tmp/myfifo";

  mkfifo(myfifo,0666);
char str1[80],str2[80];
while(1){
   
   fd=open(myfifo,O_RDONLY);
   read(fd,str1,sizeof(str1));
   printf("user one says:%s\n",str1);
   close(fd);

   fd=open(myfifo,O_WRONLY);
   fgets(str2,80,stdin);
   write(fd,str2,strlen(str2)+1);
   close(fd);

}

}