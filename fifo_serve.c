#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
    int fd=open("fifo",O_RDONLY);
	if(fd==-1)
	{
	   perror("use open");
	   exit(-1); 
	} 
	printf("this is servic\n"); 
	while(1)
	{
		char buf[20]={0};  	
	    int n=read(fd,buf,sizeof(buf)-1);//
		if(n>0) 
		{
				buf[n-1]=0; 
				printf("cilent:%s\n",buf);  
				//fflush(stdout); 
        }else if(n==0)
		{
		    printf("client quit..\n");
            exit(-1); 
		} else
		{
		  perror("use read");
		  exit(1); 
		} 
	}
	return 0;
} 
