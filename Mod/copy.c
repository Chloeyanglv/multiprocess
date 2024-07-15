#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <process_copy.h>

int main(int arg, char** argv)
{
	// 校验参数
	if(arg < 4)
	{
		perror("参数不足");
		exit(0);
	}
	// 打开文件
	int srcfd = open(argv[1], O_RDONLY);
	if(srcfd == -1)
	{
		perror("open srcfd failed.");
		exit(0);
	}
	int destfd = open(argv[2], O_WRONLY|O_CREAT, 0664);
	if(destfd == -1)
	{
		perror("open destfd failed");
		exit(0);
	}
	// 移动指针
	int pos = atoi(argv[3]);
	lseek(srcfd, pos, SEEK_SET);
	lseek(destfd, pos, SEEK_SET);
	// 读取文件内容并写入
	int buffersize = atoi(argv[4]);
	char sbuf[buffersize];
	int len = read(srcfd, sbuf,buffersize);
	if(len == -1)
	{
		perror("read file failed");
		exit(0);
	}
	write(destfd, sbuf, len);
	// 关闭文件
	close(srcfd);
	close(destfd);
	return 0;
}
