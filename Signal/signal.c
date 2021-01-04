#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


void handler(int sig)
{
    sleep(1);
//    signal(SIGINT,handler); // Reinstall handler - Archaic Unixes required this
    printf("Ouch\n");
}

void main()
{
    
    signal(SIGINT,handler);
    for (;;) ;
}
