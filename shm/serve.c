#include"head.h"

int main()
{
   int shmid=Creat_shm(4096);
   char *addr=shmat(shmid,NULL,0);
   sleep(2);
   int i=0;
   while(i++<26)
   {
      printf("client:%s\n",addr);//打印客户端
	  sleep(1); 
   } 
   shmdt(addr);
   sleep(2);
  Destory(shmid);
  return 0;
} 
