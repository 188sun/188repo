#include "pcpy.h"
//输入参数的校验
int checkarg(const char* SFile,int argnum,int pronum)
{
	//判断源文件是否存在
	if( (access(SFile,F_OK))!=0 )
	{
		perror("checkarg error");
		exit(-1);
	}
	//检查参数数量是否小于3
	if(argnum<3)
	{
		printf("checkarg error:参数数量异常.\n");
		exit(-1);
	}
	//判断进程数量是否溢出
	if(pronum<=0 || pronum>=100)
	{
		printf("checkarg error:进程数量需要大于0,小于100.\n");
		exit(-1);
	}

	return 0;
}

