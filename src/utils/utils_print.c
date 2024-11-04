#include <unistd.h>

void    putstr_fd(char *line, int fd)
{
    ssize_t i;

    i = -1;
    write(1, "\t> ", 3);
    while(line[++i])
    {
        if (line[i] != '\n')
            write(fd, &line[i], 1);
    }
    // write(fd, "\n", 1);
}