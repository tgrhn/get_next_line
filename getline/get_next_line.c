/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:17:22 by tkarakad          #+#    #+#             */
/*   Updated: 2023/07/30 10:31:21 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *rd_line)
{
	char	*buffer;
	ssize_t	bytesread;

	buffer = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(rd_line, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			free(rd_line);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		rd_line = ft_strjoin(rd_line, buffer);
	}
	free(buffer);
	return (rd_line);
}

char	*ft_extract(char *rd_line)
{
	int		i;
	char	*str;

	i = 0;
	while (rd_line[i] && rd_line[i] != '\n')
		i++;
	if (!rd_line[i])
	{
		free(rd_line);
		return (NULL);
	}
	str = ft_substr(rd_line, i + 1, (ft_strlen(rd_line) - i));
	free(rd_line);
	return (str);
}

char	*ft_get_line(char *rd_line)
{
	int	i;

	i = 0;
	if (!rd_line[i])
		return (NULL);
	while (rd_line[i] && rd_line[i] != '\n')
		i++;
	return (ft_getlin(rd_line, i + 2));
}

char	*get_next_line(int fd)
{
	static char	*rd_line;
	char		*get_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_line = ft_read(fd, rd_line);
	if (!rd_line)
		return (NULL);
	get_line = ft_get_line(rd_line);
	rd_line = ft_extract(rd_line);
	return (get_line);
}
/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
	int fd = open("/dev/ttys001", O_RDONLY);
	char *next_line;

	while ((next_line = get_next_line(fd)))
	{
		printf("%s", next_line);
		free(next_line);
	}

	return (0);
}*/