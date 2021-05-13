#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>


int main() {
    int fd, ret;
    char buffer[128];

    buffer[0]=0;


    fd=open("DF7O6N.txt",O_RDWR);

    if (fd == -1){
        perror("open() hiba!");
        exit(-1);
    } else{
        printf("Sikeres a fajl megnyitas!\n");
    }

    ret=read(fd,buffer,128); 
    printf("read() olvasott %d byteot, ami a kovetkezo: %s\n", ret, buffer);
    strcpy(buffer,"Daragó Zsolt, DF7O6N, Mérnökinformatikus");

    ret=lseek(fd,0,SEEK_SET); 
    printf("lseek() mondja: %d\n", ret);

    ret=write(fd,buffer,6); 
    printf("file() mondja: %d\n", ret);

    close(fd);


    return 0;
}