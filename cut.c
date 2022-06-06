#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fileDesc = open(argv[1], O_RDONLY);
    if (fileDesc == -1)
    {
        return -1;
    }
    int m, n;
    scanf("%d %d", &m, &n);
    if (m > n)
    {
        perror("Cant be like that mate :)\n");
    }
    char buff[1];
    int readed = 0;
    int currPos = 0;
    char lastCh = ' ';
    while ((readed = read(fileDesc, buff, 1)) > 0)
    {

        currPos++;
        if (currPos >= m && currPos <= n)
        {
            write(1, buff, readed);
            lastCh = buff[0];
        }
        if (buff[0] == '\n')
        {
            currPos = 0;
            if(lastCh != '\n')
                write(1, buff, readed);
        }
    }
    close(fileDesc);
}