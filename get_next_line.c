//#include "get_next_line.h"
#include <stdlib.h>

//ssize_t read(int fd, void *buf, size_t count);

char    *ft_readandsave(int fd, char *save)
{
    char    *buffer;
    int     *bytes;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (0);
    //bytes = 1;

}

char	*get_next_line(int fd)
{
    char    *line;
    static char    *save;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    save = ft_readandsave(fd ,save);
    if (!save)
        return (0);
    return (line);
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    char    *line;
    int     i;
    int     fd1;
    fd1 = open("test1.txt", O_RDONLY);
    printf("fd = %d\n", fd1);
    i = 1;
    while (i < 5)
    {
        line = get_next_line(fd1);
        printf("Line %d : %s", i, line);
        free(line);
        i++;
    }
    close(fd1);
    return (0);
}