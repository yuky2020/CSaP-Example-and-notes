#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>


void handler(int sig)
{
    signal(SIGINT,handler);
    printf(">>>>>>>>>> Ouch\n");
}

void main()
{
    
    signal(SIGINT,handler);
    for (;;) {
	printf("Sending Signal..\n");
	kill(getpid(),SIGINT);
	printf("Sleeping\n");
	sleep(5);
    }
}
