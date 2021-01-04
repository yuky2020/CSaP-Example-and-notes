#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>

#define MSGSIZE    16

char *msg1 = "hello #1";
char *msg2 = "hello #2";
char *msg3 = "hello #3";

int main()
{
  char inbuf[MSGSIZE];

  int   fd[2], j;
  pid_t pid;
  struct timeval now;

  /* open pipe */

  if (pipe(fd) == -1) {
    perror("pipe call error");
    exit(1);
  }
  switch (pid = fork()) {
  case -1: perror("Fork failed\n");
    return(1);

  case 0:         /* if child write down the pipe */
    close(fd[0]); /* close the read first */
    gettimeofday(&now, NULL);
    printf("Child\t@%ld: Writing Pipe\n",(long)(now.tv_sec*1E6+now.tv_usec));
    /* write the messages in the pipe */
    write(fd[1], msg1, MSGSIZE);
    write(fd[1], msg2, MSGSIZE);
    write(fd[1], msg3, MSGSIZE);
    gettimeofday(&now, NULL);
    printf("Child\t@%ld: Exiting\n",(long)(now.tv_sec*1E6+now.tv_usec));

    break;

  default:        /* if parent read the pipe */
    close(fd[1]); /* close the write first */
    /* read the messages in the pipe */
    gettimeofday(&now, NULL);
    printf("Parent\t@%ld: Reading Pipe\n",(long)(now.tv_sec*1E6+now.tv_usec));
    for (j = 0; j < 3; j++) {
      read(fd[0], inbuf, MSGSIZE);   /* read from the pipe */
      gettimeofday(&now, NULL);
      printf("Parent\t@%ld: %s\n",(long)(now.tv_sec*1E6+now.tv_usec), inbuf); /* print the content of the pipe */
    }
    wait(NULL);
    gettimeofday(&now, NULL);
    printf("Parent\t@%ld: Exiting\n",(long)(now.tv_sec*1E6+now.tv_usec));
  }
  exit(0);
}
