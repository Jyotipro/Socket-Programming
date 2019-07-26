


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
void timer(unsigned int s)
{
unsigned int st=time(0)+s;
while(time(0)<st);
}
void main()
{
//creating a socket
int cs=socket(AF_INET,SOCK_DGRAM,0);

//Specifying an address for the socket or server address
struct sockaddr_in sd,from;
sd.sin_family=AF_INET;
sd.sin_port=htons(8080);
sd.sin_addr.s_addr=INADDR_ANY;
int fromlen;
char b[256];

FILE *f;
char c[512];
int g;
f=fopen("/home/jyotiprakash/client1","r");
while((fgets(c,sizeof(c),f)) != NULL) 
{
        sscanf(c,"%d",&g);
	sendto(cs,&g,sizeof(g), 0,(struct sockaddr *) &sd,sizeof(sd));
        recvfrom(cs,b,sizeof(b),0,NULL,0);
	printf("%s\n",b);
        timer(1);

}
close(cs);
}
