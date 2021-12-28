#include "pcpy.h"
//每个进程的任务量
int block(const char* SFile,int pronum)
{
	int Filesize;//文件大小
	int fd=open(SFile,O_RDONLY);
	Filesize=lseek(fd,0,SEEK_END);//获取文件大小

	if(Filesize % pronum == 0)
	{
		return Filesize/pronum;
	}
	else
	{
		return Filesize/pronum +1 ;//每个进程多分一个字节，用来处理余数
	}
}

