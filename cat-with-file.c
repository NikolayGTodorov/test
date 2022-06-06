#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int fileDesc = open(argv[1], O_RDONLY);
    if (fileDesc == -1)
    {
        return -1;
    }
    char buff[1024];
    int readed = 0;
    while((readed = read(fileDesc, buff, 1024)) > 0){
        write(1,buff,readed);
    }
    close(fileDesc);
    return 0;
}