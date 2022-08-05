#include "get_next_line.h"

size_t ft_strlen(char *str)
{
    size_t i;
    
    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strchr(char *str, int c)
{
    int i;
    
    i = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == (char)c)
            return ((char *)(str + i));
        i++;
    }
    if (str[i] == (char)c)
        return ((char *)(str + i));
    return (0);
}

char    *ft_strjoin(char *str1, char *str2)
{
    char    *dest;
    size_t  i;
    size_t  j;

    if (!str1 || !str2)
        return (0);
    dest = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
    if (!dest)
        return (0);
    i = 0;
    while (str1[i])
    {
        dest[i] = str1[i];
        i++;
    }
    j = 0;
    while (str2[j])
    {
        dest[i + j] = str2[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}