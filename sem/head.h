#ifndef _HEAD_H__
#define _HEAD_H__
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>

#define PATHNAME "../"
#define PRO_ID 0x3838

union semun
{
   int val;
   struct semid_ds* buf;
   unsigned short *array;
   struct seminfo* __buf; 
}; 
int Creat_sem(int nums);//信号量集中的信号量个数
int Init_sem(int semid,int nums,int initval); //标识符，对应的信号量序号，初始化的值
int Get_sem(int nums);//信号量集中的信号量的个数
int P(int semid,int who);//标识符，哪个信号量
int V(int semid,int who);
int DestorySemSet(int semid);

#endif
