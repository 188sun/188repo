#include "pcpy.h"
//进程创建
int procreate(const char* SFile,const char* DFile,int pronum,int blocksize)
{
	pid_t pid;
	int flag;
	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));

	for(flag=0;flag<pronum;flag++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	if(pid>0)
	{
		printf("parent process pid=%d,非阻塞回收\n",getpid());
		pid_t zpid;
		while((zpid=waitpid(-1,NULL,WNOHANG))!=-1 )
		{
			if(zpid>0)
			{
				printf("parent wait success:zombie pid=%d\n",zpid);
			}
		}
	}
	else if(pid==0)
	{
		//偏移量
		pos=flag*blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		//重载
		execl("/home/colin/0322/four/1228/12-28/copy","copy",SFile,DFile,cblock,cpos,NULL);
		
	}
	else
	{
		perror("fork call failed");
		exit(0);
	}


	return 0;
}

