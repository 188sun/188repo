#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

//每个进程任务量
int block(const char* SFile,int pronum);
//参数校验函数
int checkarg(const char* SFile,int argnum,int pronum);
//进程创建函数
int procreate(const char* SFile,const char* DFile,int pronum,int block);

