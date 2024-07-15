#include <process_copy.h>

int process_wait()
{
	pid_t zid;
	while((zid = waitpid(-1, 0, WNOHANG)) != -1)
	{
		if(zid > 0)
		{
			printf("zombie processs id[%d].\n", zid);
		}
	}
	return 0;
}
