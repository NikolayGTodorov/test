#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
    char buff[1024];
    int readed = 0;
    while((readed = read(0,buff,1024)) > 0 || buff[0] != EOF){
        write(1, buff, readed);
    }
}