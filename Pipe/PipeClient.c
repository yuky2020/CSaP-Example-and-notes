#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "halfduplex.h"

int main(int argc, char *argv[])
{
    int fd;
    char *p;

    /* Check if an argument was specified. */
    if (argc != 2) {
        printf("Usage : %s <string to be sent to the server>\n", argv[0]);
        exit (1);
    }
    p=argv[1];

    /* Open the pipe for writing */
    fd = open(HALF_DUPLEX, O_WRONLY);

    /* Write string down the pipe */
    write(fd, p, strlen(p)+1);
}
