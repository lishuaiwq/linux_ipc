#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main() 
{
  pid_t pid;
  int fd[2]={0};
  char buf[BUFSIZ];
  char wri[BUFSIZ]; 
  int ret=pipe(fd);
    if(ret!=0)
	{
	   exit(-1); 
	} 
  if((pid=fork())>0)//父进程,我们来写数据
  {
			 close(fd[0]);//关闭读端
	  read(STDIN_FILENO,wri,sizeof(wri));  
	  write(fd[1],wri,sizeof(wri)); 
	 close(fd[1]);
	 sleep(1); 
  } else if(pid==0)//子进程来读数据
  {
   close(fd[1]);
   read(fd[0],buf,sizeof(buf));
   close(fd[0]); 
   printf("i am child i read:%s\n",buf);
  } else
  {
    perror("use fork");
	 exit(-1); 
  } 
  return 0;
} 
