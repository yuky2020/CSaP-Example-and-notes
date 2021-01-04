/* Semaphore example program a (sema.c) */
/* We have two programs, sema and semb. Semb may be initiated at any 
   time, but will be forced to wait until sema is executed. Sema and
   semb do not have to be executed by the same user! */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define KEY (1492)
/* This is the external name by which the semaphore is known to any
   program that wishes to access it. */

int main(int argc, char *argv[])
{
    int id;  /* Internal identifier of the semaphore. */
    struct sembuf operations[1];
    /* An "array" of one operation to perform on the semaphore. */

    int retval; /* Return value from semop() */

    /* Get the index for the semaphore with external name KEY. */
    id = semget(KEY, 1, 0666);
    if(id < 0)
	/* Semaphore does not exist. */
    {
	fprintf(stderr, "Program sema cannot find semaphore, exiting.\n");
	exit(0);
    }

    /* Do a semaphore V-operation. */
    printf("Program semv about to do a V-operation. \n");

    /* Set up the sembuf structure. */
    /* Which semaphore in the semaphore array : */
    operations[0].sem_num = 0;
    /* Which operation? Add 1 to semaphore value : */
    operations[0].sem_op = 1;
    /* Set the flag so we will UNDO */   
    if (argc!=1) {
	operations[0].sem_flg = SEM_UNDO;
    }
    else {
	operations[0].sem_flg = 0;
    }

    /* So do the operation! */
    retval = semop(id, operations, 1);

    if(retval == 0)
    {
	printf("Successful V-operation by program semv.\n");
    }
    else
    {
	printf("sema: V-operation did not succeed.\n");
	perror("REASON");
    }
}
