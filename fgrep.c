#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fileDesc = open(argv[2], O_RDONLY);
    if (fileDesc == -1)
    {
        perror("Couldn't open file\n");
    }
    int readed;
    char buff[90];
    while ((readed = read(fileDesc, buff, 81)) > 0)
    {
        char *pointers;
        pointers = strtok(buff, " \n");
        while (pointers)
        {
            if (strcmp(pointers, argv[1]) == 0)
            {
                close(fileDesc);
                return 0;
            }
            pointers = strtok(NULL, " ,./-");
        }
    }
    close(fileDesc);
    return -1;
}