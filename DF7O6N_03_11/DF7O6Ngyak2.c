#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){

	char input[50];
    printf("Adjon meg egy parancsot: ");
    scanf("%s", input);

	system(input);

	return 0;
}