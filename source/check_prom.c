#include <process_copy.h>

int check_pram(int argc, const char * src, int pronum)
{
	if(argc != 3){
		perror("输入参数不足\n");
		exit(0);
	}
	if(access(src, F_OK) == -1){
		perror("file does not exist.\n");
		exit(0);
	}
	if(pronum <= 0 || pronum >= 100){
		perror("the number of processes ranges from 1 to 100.\n");
		exit(0);
	}
	return 0;
}
