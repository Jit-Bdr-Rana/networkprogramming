#include<stdio.h>
#include<unistd.h>


void main(){
    int fd[2];
    char buffer[80];
    char buffer2[70];
    int p;
    p=pipe(fd);
   int i=0;
   while((buffer[i++]=getchar())!='\n');
    write(fd[1],buffer,sizeof(buffer));

   
    read(fd[0],buffer2,sizeof(buffer2));
    printf("buffer messsage:%s",buffer2);


}