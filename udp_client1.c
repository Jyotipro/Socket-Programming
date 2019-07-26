



#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
//creating a socket
int cs=socket(AF_INET,SOCK_DGRAM,0);

//Specifying an address for the socket or server address
struct sockaddr_in sd;
sd.sin_family=AF_INET;
sd.sin_port=htons(9002);
sd.sin_addr.s_addr=INADDR_ANY;
//sending  data to server
int n=320;
sendto(cs,&n, sizeof(n), 0,(struct sockaddr *) &sd,sizeof(sd));
close(cs);
}

