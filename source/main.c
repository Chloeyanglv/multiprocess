#include <process_copy.h>

int main(int argc, char ** argv)
{
	//./process_copy 1.png 2.png
	int pronum;
	int blocksize;
	if(argv[3]==0)
			pronum = 5;
	else
			pronum = atoi(argv[3]);
	check_pram(argc, argv[1], pronum);
	blocksize = blocksize_cur(argv[1],pronum);
	process_create(argv[1], argv[2], pronum, blocksize);
	return 0;	
}
