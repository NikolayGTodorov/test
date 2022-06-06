#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv){
    int fileDesc = open(argv[1], O_CREAT | O_WRONLY | O_APPEND, 0744);
    if(fileDesc == -1){
        printf("oops");
        return -1;
    }
    char buff[1024];
    int readed = 0;
    while((readed = read(0, buff, 1024)) > 0 || buff[0] == EOF){
        write(fileDesc, buff, readed);
    }
    close(fileDesc);
    return 0;
}