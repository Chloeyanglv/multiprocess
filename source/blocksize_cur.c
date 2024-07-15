#include <process_copy.h>

int blocksize_cur(const char * src, int pronum)
{
	// 获取文件大小
	int fd = open(src, O_RDWR|O_CREAT, 0664);
	//int len = read(fd, buffer, sizeof(buffer));
	int fsize = lseek(fd, 0, SEEK_END);
	if(fsize % pronum == 0)
			return fsize / pronum;
	else
			return fsize / pronum + 1;
}
