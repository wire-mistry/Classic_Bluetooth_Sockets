#include<bluetooth/bluetooth.h>
#include<bluetooth/rfcomm.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void main()
{
struct sockaddr_in sadr,cadr;
int sfd,cfd,checks;
socklen_t addrlen;

//********Clear allocated memories

memset(&sadr,'\0',sizeof(sadr));
memset(&cadr,'\0',sizeof(cadr));



//********Server Properties

	sadr.sin_family=AF_INET;
	sadr.sin_port=htons(5555);
	checks=inet_aton("127.0.0.1", (struct in_addr *)&sadr.sin_addr);
		if(!checks)
		{
			perror("Error:	IP String conversion\n");
			exit(-1);
		}
//********Socket Defination,Discriptor

	sfd=socket(AF_INET,SOCK_STREAM,0);
		if(sfd==-1)
		{
			perror("Error in Creating Server socket file discriptor\n");
			exit(-1);
		}
		
//********Socket Binding with server properties

	checks=bind(sfd,(struct sockaddr *)&sadr,sizeof(sadr));
		if(checks==-1)
		{
			perror("Error:	Bind Failure\n");
			exit(-1);
		}
		
//********Listing properties
	checks=listen(sfd,20);
		if(checks==-1)
		{
			perror("Error:	Listen Failure\n");
			exit(-1);
		}
			
//********Accpting
	addrlen=sizeof(cadr);
	cfd=accept(sfd,(struct sockaddr *)&cadr,&addrlen);		
		if(sfd==-1)
		{
			perror("Error in Creating Client socket file discriptor\n");
			exit(-1);
		}
//logic as soon as a sock is accepted create a fork i.e parallel process to follow communication logic and keep waiting for other sockets here		
//********Communication logic
char buff[1024];
	while(1){
			memset(buff,'\0',1024);
			send(cfd,"Hello",sizeof("Hello"),0);
			recv(cfd,buff,1024,0);
			if(buff[0]=='.')
				if(buff[1]=='c')
					{
						shutdown(sfd,SHUT_RDWR);
						shutdown(cfd,SHUT_RDWR);
		
					}
					
			puts(buff);						
		}

}
