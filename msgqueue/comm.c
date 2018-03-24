#include"head.h"

static int Commo_creat_msgqueuw(int flags)
{
      key_t key=ftok(PATHNAME,PRO_ID);
	  if(key<0)
	  {
	     perror("ftok");
		 exit(-1); 
	  } 
    int msgid=msgget(key,flags);
	if(msgid<0)
	{
	   perror("msgid");
	   exit(-1); 
	} 
	return msgid;
} 

int Creat_msgque()
{
   return Commo_creat_msgqueuw(IPC_CREAT | IPC_EXCL | 0666); 
} 

int Destory_msgque(int msgid)
{
    if(msgctl(msgid,IPC_RMID,NULL)<0)
	{
	   perror("msgid");
	   exit(-1); 
	} 
   return 0;//成功返回0
} 
int Get_msgque()
{
   return Commo_creat_msgqueuw(IPC_CREAT); 

} 
int Send_msgque(int msgid,int who,char* msg)
{
     struct msgbuf buf;
	 buf.mtype=who;//消息类型
     strcpy(buf.mtext,msg);
	 //将消息放到消息队列
	 if(msgsnd(msgid,(void*)&buf,sizeof(buf.mtext),0)<0)
	 {
	    perror("use msgid");
				exit(-1); 
	 } 
	 return 0;
} 
int Recv_msgque(int msgid,int who,char out[])
  {
    struct msgbuf buf;
	if(msgrcv(msgid,(void*)&buf,sizeof(buf.mtext),who,0)<0) 
	{
	   perror("msgid"); 
	  exit(-1); 
	} 		
    strcpy(out,buf.mtext); 
   return 0;
  } 
