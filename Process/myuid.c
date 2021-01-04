#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void main()
{
    printf("UID:%d EUID:%d GID:%d EGID:%d\n",
	getuid(),geteuid(),getgid(),getegid());
}
