#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MSGSIZE 16

char *msg1 = "hello #1";
char *msg2 = "hello #2";
char *msg3 = "hello #3";

void main()
{  char inbuf[MSGSIZE];

  int p[2], j;
  pid_t pid;

  /* open pipe */

  if(pipe(p) == -1) {    
    perror("pipe call error");
    exit(1);
  }

  switch(pid = fork())
    {
    case -1: perror("error: fork call");
      exit(2);

    case 0:  /* if child then write down pipe */
      close(p[0]);  /* first close the read end of the pipe */
      strcpy(inbuf,msg1);
      write(p[1], inbuf, sizeof(inbuf));
      strcpy(inbuf,msg2);
      write(p[1], inbuf, sizeof(inbuf));
      strcpy(inbuf,msg3);
      write(p[1], inbuf, sizeof(inbuf));
      break;
    default:   /* parent reads pipe */
      close(p[1]);  /* first close the write end of the pipe */
      for(j=0; j<3; j++) {   
	read(p[0], inbuf, MSGSIZE);
	printf("Parent: %s\n", inbuf);
      }
      wait(NULL);
    }
  exit(0);
}

