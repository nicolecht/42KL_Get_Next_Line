/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchee <nchee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:41:00 by nchee             #+#    #+#             */
/*   Updated: 2022/08/08 13:04:07 by nchee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *str)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (0);
		}
		buf[bytes_read] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_line(char *str)
{
	char	*edited_line;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	edited_line = malloc(sizeof(char) * (i + 2)); // 2 for \n and '\0'
	if (!edited_line)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n') // separating the lines by '\0' or \n
	{
		edited_line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		edited_line[i] = str[i];
		i++;
	}
	edited_line[i] = '\0';
	return (edited_line);
}

char	*update_line(char *str)
{
	char	*updated;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	updated = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!updated)
		return (0);
	i++; // skip the \n
	j = 0;
	while (str[i])
	{
		updated[j++] = str[i++];
	}
	updated[j] = '\0';
	free(str);
	return (updated);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (0);
	str[fd] = read_line (fd, str[fd]);
	if (!str[fd])
		return (0);
	line = get_line(str[fd]);
	str[fd] = update_line(str[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	fd1 = open("test1.txt", O_RDONLY);
// 	fd2 = open("test2.txt", O_RDONLY);
// 	fd3 = open("test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 6)
// 	{
// 		line = get_next_line(fd1);
// 		printf("fd [%d] | line [%02d]: %s", fd1, i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("fd [%d] | line [%02d]: %s", fd2, i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		printf("fd [%d] | line [%02d]: %s", fd3, i, line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	close(fd3);
// 	return (0);
// }