


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


void main()
{
//creating server socket
int ss=socket(AF_INET,SOCK_DGRAM,0);
//defining server address
struct sockaddr_in sd,from;
sd.sin_family=AF_INET;
sd.sin_port=htons(9002);
sd.sin_addr.s_addr=INADDR_ANY;

bind(ss,(struct sockaddr *) &sd,sizeof(sd));
int fromlen=sizeof(struct sockaddr_in);

//receiving data
int s;
recvfrom(ss,&s,sizeof(s),0,(struct sockaddr *) &from, &fromlen);
printf("%d\n",s);
close(ss);
}

