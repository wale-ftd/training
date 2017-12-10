#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int data = 10;

int child_process()
{
	sleep(1);
	printf("Child process %d, data %d\n",getpid(), data);
	_exit(0);
}

int main(int argc, char* argv[])
{
	int pid;
	
	printf("main process %d, data %d\n",getpid(), data);
	
	pid = fork();

	if(pid==0) {
		child_process();
	}
	else{
		printf("Parent process %d, data %d\n",getpid(), data);
		data = 20;
		printf("Parent process %d, data %d\n",getpid(), data);

		int wc = wait(NULL);
		printf("hello, I am parent of %d (wc:%d) (pid:%d)\n", pid, wc, (int) getpid());

		exit(0);
	}
}

/*
 * main process 69447, data 10
 * Parent process 69447, data 10
 * Parent process 69447, data 20
 * Child process 69448, data 10
 * hello, I am parent of 69448 (wc:69448) (pid:69447)
 */

