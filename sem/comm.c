#include"head.h"
static int Com_creat_sem(int nums,int flags)
{
   key_t key=ftok(PATHNAME,PRO_ID);
   if(key<0)
   {
      perror("ftok()");
	  exit(-1); 
   } 
   int semid=semget(key,nums,flags);
   if(semid<0)
   {
      perror("semget");
	  exit(-1); 
   } 
   return semid;
} 

int Creat_sem(int nums)
{
   return Com_creat_sem(nums,IPC_CREAT | IPC_EXCL | 0666); 
} 

int Get_sem(int nums)
{
  return Com_creat_sem(nums,IPC_CREAT); 
} 
int Init_sem(int semid,int nums,int inival)
{
    union semun _un;
	_un.val=inival;
   if(semctl(semid,nums,SETVAL,_un)<0)
   {
     perror("ftok()");
	 exit(-1); 
   } 
  return 0;
} 
static int ComPV(int semid,int who,int op)
{
    struct sembuf _sf;
	_sf.sem_num=who;
    _sf.sem_op=op;
	_sf.sem_flg=0;
	if(semop(semid,&_sf,1)<0)
	{
	   perror("semop");
	   exit(-1); 
	} 
	return 0;
} 
int P(int semid,int who)
{
   return ComPV(semid,who,-1); 
} 
int V(int semid,int who)
{
   return ComPV(semid,who,1);
}
int DestorySemSet(int semid)
{
   if(semctl(semid,0,IPC_RMID)<0)
   {
     perror("semctl");
	 exit(1); 
   } 
   return 0;
} 

