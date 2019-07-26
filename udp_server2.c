#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

void main()
{
//creating server socket
int ss=socket(AF_INET,SOCK_DGRAM,0);

//defining server address
struct sockaddr_in sd,from;
sd.sin_family=AF_INET;
sd.sin_port=htons(8080);
sd.sin_addr.s_addr=INADDR_ANY;
bind(ss,(struct sockaddr *) &sd,sizeof(sd));

int fromlen=sizeof(struct sockaddr_in);

//sending the integer
FILE *f;
f=fopen("/home/jyotiprakash/server","w");
fclose(f);

int s;
char b[256]="Message Received";
while(1)
{
recvfrom(ss,&s,sizeof(s),0,(struct sockaddr *)&from,&fromlen);
printf("%d\n",s);
FILE *f;
f=fopen("/home/jyotiprakash/server1","a");
fprintf(f,"%d\n",s);
fclose(f);
sendto(ss,b,sizeof(b),0,(struct sockaddr *) &from,fromlen); 
}

close(ss);
}
