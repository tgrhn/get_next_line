/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkarakad <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:19:26 by tkarakad          #+#    #+#             */
/*   Updated: 2023/07/29 17:49:52 by tkarakad         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	subs = malloc(sizeof(char) * (len));
	if (!subs)
	{
		free(subs);
		return (NULL);
	}
	while (i < len && i < ft_strlen(s) && s[start + i])
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

char	*ft_getlin(char *s, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	subs = (char *) malloc(len);
	if (!subs)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		subs[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		subs[i] = s[i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *rd_line, char *buff)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!rd_line)
	{
		rd_line = (char *)malloc(1 * sizeof(char));
		rd_line[0] = '\0';
	}
	if (!rd_line || !buff)
		return (NULL);
	s = malloc(sizeof(char) * ((ft_strlen(rd_line) + ft_strlen(buff)) + 1));
	if (s == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (rd_line[++i] != '\0')
		s[i] = rd_line[i];
	while (buff[j] != '\0')
		s[i++] = buff[j++];
	s[ft_strlen(rd_line) + ft_strlen(buff)] = '\0';
	free(rd_line);
	return (s);
}
