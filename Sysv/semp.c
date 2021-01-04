#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

#define KEY (1492)
/* This is the external name by which the semaphore is known to any
   program that wishes to access it. */

int main(int argc, char * argv[])
{
    int id;  /* Internal identifier of the semaphore. */
    struct sembuf operations[1];
    /* An "array" of one operation to perform on the semaphore. */

    int retval; /* Return value from semop() */

    /* Get the index for the semaphore with external name KEY. */
    id = semget(KEY, 1, 0666);
    if(id < 0) {
	/* Semaphore does not exist. */
	fprintf(stderr, "Program semb cannot find semaphore, exiting.\n");
	exit(0);
    }

    /* Do a semaphore P-operation. */
    printf("Program semp about to do a P-operation. \n");
    printf("Process id is %d\n", getpid());

    /* Set up the sembuf structure. */
    /* Which semaphore in the semaphore array : */
    operations[0].sem_num = 0;
    /* Which operation? Subtract 1 from semaphore value : */
    operations[0].sem_op = -1;
    if (argc==1) {
	/* Set the flag so we will wait : */   
	operations[0].sem_flg = 0;
    }
    else {
	/* Set the flag so we DO NOT wait : */   
	operations[0].sem_flg = IPC_NOWAIT;
    }

    /* So do the operation! */
    retval = semop(id, operations, 1);

    if(retval == 0) {
	printf("Successful P-operation by program semp.\n");
	printf("Process id is %d\n", getpid());
    }
    else {
	if (operations[0].sem_flg && errno==EAGAIN) {
	    printf("semb: P-operation could not complete.\n");
	}
	else {
	    printf("semb: P-operation did not succeed.\n");
	}
    }
}
