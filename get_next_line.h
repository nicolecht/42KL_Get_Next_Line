#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char    *read_line(int fd, char *str);
char    *get_line(char *str);
char    *update_line(char *str);
char    *ft_strchr(char *str, int c);
char    *ft_strjoin(char *s1, char *s2);
size_t  ft_strlen(char *str);

#endif