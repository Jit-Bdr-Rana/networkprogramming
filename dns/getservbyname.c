#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include<stdio.h>
void main(){
    struct servent *appl_name;
char name[4] = "FTP";
char proto[4] = "TCP";
int port;

appl_name = getservbyname(name, proto);

 if (!appl_name)
   printf("unknown application %s\n", name);
 else
 {
   port = appl_name->s_port;
   printf("getservbyname was successful\n");
 } 
}
