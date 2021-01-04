#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


#define SIG1 SIGUSR1

#define UNBLOCK 

int sigreceived=0;

void handler1(int sig)
{
    sigreceived++;
}

void main(int argc, char *argv[])
{
    int i;
    int t,m;
    sigset_t omask,nmask;

    sigemptyset(&nmask);
    if (sigaddset(&nmask,SIG1)) {
	perror("sigaddset");
	exit(1);
    }
    signal(SIG1,handler1);

    if (argc>1 && sigprocmask(SIG_BLOCK,&nmask,&omask)) {
	perror("sigprocmask");
	exit(1);
    }

    for (i=0;i<10;i++) { 
	kill(getpid(),SIG1);
    }
    sleep(1);

    if (argc>1 && sigprocmask(SIG_SETMASK,&omask,&nmask)) {
	perror("sigprocmask");
	exit(1);
    }
    printf("%d\n",sigreceived);
}
