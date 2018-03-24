#include"head.h"
static int Creat_com_shm(int size,int flag)
{
     key_t key=ftok(PATHNAME,PRO_ID);
	 if(key<0)
	 {
	    perror("ftok()");
		exit(-1); 
	 } 
	 int shmid=0;
	 if((shmid=shmget(key,size,flag))<0) 
	 {
	   perror("shmget");
	   exit(-1); 
	 } 
	 return shmid;
} 
int Creat_shm(int size)
{
  return Creat_com_shm(size,IPC_CREAT | IPC_EXCL | 0666); 
} 

int Getshm(int size)
{
   return Creat_com_shm(size,IPC_CREAT); 
} 

int Destory(int shmid)
{
    if(shmctl(shmid,IPC_RMID,NULL)<0)
	{
	   perror("shmctl"); 
	   exit(-1); 
	} 
	return 0;
} 
