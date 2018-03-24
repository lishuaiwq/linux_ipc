#include"head.h"

int main()
{
   int msgid=Get_msgque();
   char buf[1024];
   while(1)
   {
       buf[0]=0; 
     printf("client:");
	 fflush(stdout);
	 ssize_t s=read(0,buf,sizeof(buf));
	 if(s>0)
	 {
	    buf[s-1]=0;
	    Send_msgque(msgid,CLIENT_TYPE,buf);
		printf("send done..wait recive\n"); 
	 } 
	 Recv_msgque(msgid,SERVE_TYPE,buf);
	 printf("serve:%s\n",buf); 
   } 
    return 0;
} 
