#include<bluetooth/bluetooth.h>
#include<bluetooth/rfcomm.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

//#include <sys/types.h>          /* See NOTES */
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>


void main()
{
struct sockaddr_rc sadr,cadr;
int sfd,cfd,checks;
socklen_t addrlen;

//********Clear allocated memories

memset(&sadr,'\0',sizeof(sadr));
memset(&cadr,'\0',sizeof(cadr));



//********Server Properties
	sadr.rc_family=AF_BLUETOOTH;
	str2ba("00:06:66:03:1F:61",&sadr.rc_bdaddr);
    	/*	if(checks==-1)
    		{
    		perror("str2ba failure\n");
    		
    		}
    	*/sadr.rc_channel = (uint8_t) 1;

//********Socket Defination,Discriptor

	sfd=socket(AF_BLUETOOTH,SOCK_STREAM,BTPROTO_RFCOMM);
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
			int ret=write(cfd,"Hello fucker",sizeof("Hello "));
			printf("%d",ret);
			
			read(cfd,buff,1024);
			if(buff[0]=='.')
				if(buff[1]=='c')
					{
						shutdown(sfd,SHUT_RDWR);
						shutdown(cfd,SHUT_RDWR);
		
					}
					
			puts(buff);
			sleep(5);						
		}

}
