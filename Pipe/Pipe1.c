#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MSGSIZE  16

char *msg1 = "hello #1";
char *msg2 = "hello #2";
char *msg3 = "hello #3";

void main()
{  
  char inbuf[MSGSIZE];

  int p[2], j;

  /* open pipe */

  if(pipe(p) == -1) {    
    perror("pipe call error");
    exit(1);
  }
  
  /* write down pipe */
  strcpy(inbuf,msg1);
  write(p[1], inbuf, sizeof(inbuf));
  strcpy(inbuf,msg2);
  write(p[1], inbuf, sizeof(inbuf));
  strcpy(inbuf,msg3);
  write(p[1], inbuf, sizeof(inbuf));

  /* read pipe */
  for(j=0; j<3; j++) {   
    read(p[0], inbuf, sizeof(inbuf));
    printf("%s\n", inbuf);
  }

  exit(0);
}

