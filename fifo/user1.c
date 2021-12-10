#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
    int fd1;

    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo,0666);

    char str1[80],str2[80];
    while(1){
        fd1=open(myfifo,O_WRONLY);
        
        fgets(str1,80,stdin);
        write(fd1,str1,sizeof(str1));
       close(fd1);

       fd1=open(myfifo,O_RDONLY);
       read(fd1,str2,sizeof(str2));
       printf("user2:%s\n",str2);
       close(fd1);

    }
}