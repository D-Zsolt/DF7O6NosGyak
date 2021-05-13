#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void Handler(int sig);

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: ./DF7O6N_gyak9_3 PID\n");
        return 1;
    }

    pid_t pid = (pid_t)atoi(argv[1]); 
    kill(pid, SIGALRM);


    if (signal(SIGALRM, Handler) == SIG_ERR)
    {
        printf("Signal handler creation failed. Exiting with error.\n");
        exit(EXIT_FAILURE);
    }

    pause();
    return 0;
}

void Handler(int sig)
{
    printf("DF7O6N\n");
	printf("From now on I'm not blocked!\n");
    exit(1);
}


