#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 123W  /* kulcs */

	int semid,nsems,rtn;
	unsigned nsops;	/* ezzel adjuk meg, hany semaphore strukturaval foglakozzon */
	int semflg;
	struct sembuf sembuf, *sop;


int main()
{


	nsems = 1;	
	semflg = 00666 | IPC_CREAT;
	semid = semget (SEMKEY, nsems, semflg);
	if (semid < 0 ) {perror(" semget hiba"); exit(0);}
	else printf("\n Azonosito: %d ",semid);
	printf ("\n");
	
	nsops = 1;		/* Egy muvelet van */
	sembuf.sem_num = 0;	/* A 0-ik semaphor-ral foglalkozunk */
	sembuf.sem_op = 1;	/* Noveles */
	sembuf.sem_flg = 0666;	/* Flag beallitas */
	sop = &sembuf;		/* Argumentum kerese */
	rtn = semop(semid, sop, nsops); /* 0-val visszatero semop sikeres. */
	printf("\n Visszateresi ertek: %d ",rtn);
	printf("\n");

}