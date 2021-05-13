#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int child;

    
    mkfifo("df7o6n", S_IRUSR | S_IWUSR);

    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        
        fd = open("df7o6n", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);

        
        close(fd);
        unlink("df7o6n");
    } else if(child == 0){
        int fd;

        
        fd = open("df7o6n", O_WRONLY);
        write(fd, "Darago Zsolt DF7O6N!\n", 13);
        close(fd);
    }

    return 0;
}