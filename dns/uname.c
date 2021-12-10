#include<stdio.h>
#include<sys/utsname.h>

void main(){
    int x;
    struct utsname uts;

    x=uname(&uts);

    if(x<0){
        printf("faile to uname");
    }
    printf("name of os is:%s",uts.sysname);
    printf("\nnode of os is:%s",uts.nodename);
    printf("\n version of os is:%s",uts.version);
    printf("\n release of os is:%s",uts.release);
    printf("\n machine of os is:%s",uts.machine);

}