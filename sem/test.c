#include"head.h"
int main()
{
   int semid=Creat_sem(1);
   Init_sem(semid,0,1);//初始化计数器的值
   pid_t pid=fork();
   if(pid==0)
   {

      int _semid=Get_sem(0);
	  while(1)
	  {
	     		  
	      P(_semid,0);//申请信号量资源
		   printf("A");
		   fflush(stdout);
		   sleep(1);
		   printf("A "); 
		   fflush(stdout);
	  V(_semid,0); //释放资源
		  sleep(1); 
	  } 
   } else if(pid>0)
   {
   while(1)
   {
      P(semid,0);
		   printf("B");
		   fflush(stdout);
		   sleep(1);
		   printf("B "); 
		   fflush(stdout);
	 V(semid,0); 
   } 
   wait(NULL);//回收子进程 
   } 
   DestorySemSet(semid);
   return 0;
} 
