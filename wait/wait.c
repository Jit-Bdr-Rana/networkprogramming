
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
 int stat;
 pid_t pid[5];

 for(int i=0;i<5;i++){
     if((pid[i]=fork())==0){
         sleep(0);
         exit(100+i);
     }
 }
 for(int j=0;j<5;j++){
   pid_t cpid=waitpid(pid[j],&stat,0) ;
   if(WIFEXITED(stat)){
       printf("child %d terminate with status code %d \n",cpid,WEXITSTATUS(stat));
   }    
 }



}