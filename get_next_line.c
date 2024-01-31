/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:08:58 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/31 19:12:43 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer, int index)
{
	char	*tmp;
	char	*frees;

	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), buffer = NULL, NULL);
	while (index > 0)
	{
		index = read(fd, tmp, BUFFER_SIZE);
		if (index == -1)
			return (free(buffer), free(tmp), NULL);
		if (index != 0)
		{
			tmp[index] = '\0';
			frees = buffer;
			buffer = ft_strjoin(buffer, tmp);
			if (!buffer)
				return (free(frees), free(tmp), NULL);
			free(frees);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	return (free(tmp), buffer);
}

char	*getline(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	ft_memfunc(line, "", 0, i + 1);
	line[i] = '\0';
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	i = 0;
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (free(s), NULL);
	while (i < start && i[s])
		i++;
	ft_memfunc(&p[0], &s[i], 1, len);
	p[len] = 0;
	free(s);
	return (p);
}

char	*rest(char *buffer)
{
	char	*rest;
	int		i;

	i = 0;
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			if (buffer[i + 1] == '\0')
				return (free(buffer), buffer = NULL, NULL);
			rest = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
			return (rest);
		}
		i++;
	}
	free (buffer);
	buffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_read(fd, buffer, 1);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = getline(buffer);
	if (!line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = rest(buffer);
	return (line);
}
