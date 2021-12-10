#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    char hostbuffer[256];
    char *IPbuffer;
    struct hostent *host_entry;
    int hostname;
  
    // To retrieve hostname
    hostname = gethostname(hostbuffer, sizeof(hostbuffer));
    if (hostname == -1)
    {
        printf("gethostname");
        exit(1);
    }
    // To retrieve host information
    host_entry = gethostbyname("www.facebook.com");
    if (host_entry == NULL)
    {
        printf("gethostbyname");
        exit(1);
    }
  
    // To convert an Internet network
    // address into ASCII string
    IPbuffer = inet_ntoa(*((struct in_addr*)
                           host_entry->h_addr_list[0]));
    printf("Hostname: %s\n", host_entry->h_name);
    printf("Host IP: %s", IPbuffer);
  
    return 0;
}