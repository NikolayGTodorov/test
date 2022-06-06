#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    int bytes = 0, words = 0, newLines = 0;
    int file = open(argv[1], O_RDONLY);
    char buff[1];
    if(file == -1){
        return -1;
    }
    char last = ' ';
    while(read(file, buff, 1) == 1){
        bytes++;
        if(buff[0] == ' ' || buff[0] == '\t'){
            last = ' ';
        }
        else if(buff[0] == '\n'){
            newLines++;
            last = ' ';
        }
        else{
            if(last == ' '){
                words++;
            }
            last = '_';
        }
    }
    printf("%d %d %d %s\n", newLines, words, bytes, argv[1]);
    close(file);
}