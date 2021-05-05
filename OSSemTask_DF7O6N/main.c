#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int main()
{
        char ch,Input[50];
        int i;
        do
        {
            printf("Adjon meg egy parancsot: ");

            i=0;
            while(i< 49 && (ch=getchar()) != '\n')
            {
                Input[i++]= ch;
            }
            Input[i]= '\0';
            system(Input);
            printf("\n");
            memset(Input, 0, 50);

        }while(true);

        return 0;

}
