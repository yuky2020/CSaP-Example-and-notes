#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <math.h>

struct timeval t;
double now,later;

int s;
void handler(int sig)
{
    if (alarm(s)<0) {
	perror("alarm");
	exit(1);
    }
    if (gettimeofday(&t,NULL)) {
	perror("gettimeofday");
	exit(1);
    }
    later=t.tv_sec+t.tv_usec/1E9;
    printf("Awakened (after %d secs.)\n",(int)round((later-now)));
}

int main(int argc, char *argv[])
{

    if (argc!=2 || (s=atoi(argv[1]))<0) {
	fprintf(stderr,"Usage:\n\t%s <secs>\n",argv[0]);
	exit(1);
    }

    signal(SIGALRM,handler);
    s=atoi(argv[1]);
    
    if (gettimeofday(&t,NULL)) {
	perror("gettimeofday");
	exit(1);
    }
    now=t.tv_sec+t.tv_usec/1E9;

    if (alarm(s)<0) {
	perror("alarm");
	exit(1);
    }
    for(;;) { printf("Hi\n"); sleep(1); } 
}
