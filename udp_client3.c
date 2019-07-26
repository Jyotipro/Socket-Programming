


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<time.h>
#include<pthread.h>

struct inf 
{
struct sockaddr_in sd;
int cs;
char b[256];
}; 
void timer(unsigned int s)
{
unsigned int st=time(0)+s;
while(time(0)<st);
}
void *fl2(void *arg)
{
struct inf *r=arg;
FILE *f1;
char c1[512];
int g1;
f1=fopen("/home/jyotiprakash/client1","r");
while((fgets(c1,sizeof(c1),f1)) != NULL)
{
        sscanf(c1,"%d",&g1);
        sendto(r->cs,&g1,sizeof(g1), 0,(struct sockaddr *) &(r->sd),sizeof(r->sd));
        timer(1);
        
}
} 
void main()
{
struct inf fc;
//creating a socket
 fc.cs=socket(AF_INET,SOCK_DGRAM,0);

//Specifying server address
fc.sd.sin_family=AF_INET;
fc.sd.sin_port=htons(8080);
fc.sd.sin_addr.s_addr=INADDR_ANY;

FILE *f;
char c[512];
int g;
f=fopen("/home/jyotiprakash/client2","r");
pthread_t tid;

pthread_create(&tid,NULL,fl2,&fc);
while((fgets(c,sizeof(c),f)) != NULL) 
{
        sscanf(c,"%d",&g);
	
	sendto(fc.cs,&g,sizeof(g), 0,(struct sockaddr *) &fc.sd,sizeof(fc.sd));
        timer(1);
	

}
pthread_join(tid,NULL);

close(fc.cs);
}
