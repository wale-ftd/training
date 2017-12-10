#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int data = 10;

int child_process()
{
	printf("Child process %d, data %d\n",getpid(),data);
	data = 20;
	printf("Child process %d, data %d\n",getpid(),data);
	_exit(0);
}

/*
 * main process 15338, data 10
 * Child process 15339, data 10
 * Child process 15339, data 20
 * Parent process 15338, data 10
 */
int main(int argc, char* argv[])
{
	int pid;
	
	printf("main process %d, data %d\n",getpid(),data);
	
	pid = fork();

	if(pid==0) {
		child_process();
	}
	else{
		sleep(1);
		printf("Parent process %d, data %d\n",getpid(), data);
		exit(0);
	}
}



