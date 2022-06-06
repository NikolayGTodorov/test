#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char** argv)
{
    int firstFile = open(argv[1], O_RDONLY);
    int secondFile = open(argv[2], O_TRUNC | O_WRONLY | O_CREAT);
    if(firstFile == -1 || secondFile == -1){
        return -1;
    }
    char buff[1024] = "\0";
    int readed;
    while((readed = read(firstFile,buff, 1024)) > 0)
    {
        write(secondFile, buff, readed);
        strcpy("\0", buff);
    }
    close(firstFile);
    close(secondFile);
}