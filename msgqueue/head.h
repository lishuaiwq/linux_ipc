#ifndef _HEAD_H__
#define _HEAD_H__
#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdlib.h>
#define PATHNAME "."
#define PRO_ID 0X9527

#define CLIENT_TYPE 1
#define SERVE_TYPE 2

struct msgbuf
{ 
     long mtype;
	 char mtext[1024]; 
}; 

int Creat_msgque();//创建消息队列
int Get_msgque();//获取消息队列的标识号
int Destory_msgque(int  msgid);//删除消息队列
int Send_msgque(int msgid,int who,char *msg);//发送消息
int Recv_msgque(int msgid,int who,char out[]);//接收消息 


#endif
