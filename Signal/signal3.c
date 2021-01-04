#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int i=0;

#define SIG1 SIGUSR1
#define SIG2 SIGUSR2

// #define UNBLOCK

void handler1(int sig)
{
    printf("SIG1,%d\n",i);
}

void handler2(int sig)
{
    printf("SIG2,%d\n" ,i);
}

void main()
{
    
    signal(SIG1,handler1);
    signal(SIG2,handler2);
    for (;;) { 
	sigset_t omask,nmask;

	sigemptyset(&nmask);
	if (sigaddset(&nmask,SIG1) || sigaddset(&nmask,SIG2) ) {
	    perror("sigaddset");
	    exit(1);
	}

	if (sigprocmask(SIG_BLOCK,&nmask,&omask)) {
	    perror("sigprocmask");
	    exit(1);
	}

	kill(getpid(),SIG1);
	kill(getpid(),SIG2);
	kill(getpid(),SIG1);
//	kill(getpid(),SIG2);
	kill(getpid(),SIG1);
//	kill(getpid(),SIG2);
	i +=1;

#if defined(UNBLOCK)
	if (sigprocmask(SIG_SETMASK,&omask,&nmask)) {
	    perror("sigprocmask");
	    exit(1);
	}
#endif
	sleep(1);
    }
}
