#ifndef _HEAD_H__
#define _HEAD_H__
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

#define PATHNAME "../"
#define PRO_ID 0x38

int Creat_shm(int size);
int Destory(int shmid);
int Getshm(int size);

#endif
