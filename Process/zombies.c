#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void main()
{
    int pid, mypid;

    pid=fork();
    if (pid==0) {
	mypid=getpid();
	if (fork()) {
	    printf("Child :%d (parent:%d) \n",mypid, getppid());
	    sleep(2);
	    kill(mypid,SIGKILL);
	}
	else {
	    printf("Nephew :%d (parent:%d)\n",getpid(),getppid());
	    sleep(5);
	    printf("Nephew :%d (parent:%d)\n",getpid(),getppid());
	    sleep(100);
	}

    }
    else {
	printf("Parent: %d\n",getpid());
	sleep(100);
    }
    exit(0);
}
