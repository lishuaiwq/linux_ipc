#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
void fun(int sign)
{
   printf("%d\n",sign);
   exit(-1); 
} 
int main() 
{
    signal(SIGPIPE,fun); 		
	extern int errno;
    int fd=open("fifo",O_WRONLY);
	if(fd==-1)
	{
	   // perror("use open");
	   printf("use open:%d\n",errno); 
		exit(-1); 
	} 
	printf("This is client\n"); 
	while(1)
	{
		char buf[20]={0};  	
		printf("client:");
		fflush(stdout);//print缓冲区未满，则不刷新到屏幕上面去 
		int n=read(STDIN_FILENO,buf,sizeof(buf)-1);   
		if(n>0)
		{
		    buf[n]=0;
	    write(fd,buf,strlen(buf));//
		} else if(n<=0)
		{
		   perror("use read");
				   exit(-1); 
		} 
    }
	return 0;
} 
