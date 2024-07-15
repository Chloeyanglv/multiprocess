#include <process_copy.h>

int process_create(const char * src, const char * dest, int pronum, int blocksize)
{
	pid_t pid;
	int flags;
	for(flags = 0; flags < pronum; flags++){
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0)
	{
		printf("process_create success.\n");
	}
	else if(pid == 0)
	{
		int pos = flags * blocksize;
		char str_pos[10];
		char sblocksize[10];
		sprintf(str_pos, "%d", pos);
		sprintf(sblocksize, "%d", blocksize);
		printf("child process id[%d], file start pos[%d], blocksize[%d].\n", getpid(), pos, blocksize);
		execl("", "", src, dest, pos, sblocksize, NULL);
	}
	return 0;
}
