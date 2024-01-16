/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:18:48 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/10 17:27:15 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

/* size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i]; 
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char **s1, char *s2)
{
	size_t	length;
	char	*p;
	
	if(*s1 == NULL && s2 == NULL)
        return NULL;
    else if(*s1 == NULL)
        return ft_strdup(s2);
    else if(s2 == NULL)
        return ft_strdup(*s1);
	length = ft_strlen(*s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (length + 1));
	if (!p)
		return (NULL);
	ft_memcpy(&p[0], *s1, ft_strlen(*s1));
	ft_memcpy(&p[ft_strlen(*s1)], s2, ft_strlen(s2));
	p[length] = '\0';
	free(*s1);
	*s1 = NULL;
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	int	i;

	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i++] = (unsigned char) c; 
	}
	return (b);
}
 */


static char *get_line(char *str)
{
    int i = 0;
	if(str== 0)
		return (NULL);
    static int sum = 0;
    char *line;
	int cpy = sum;
	if (str[sum] == '\0')
		return (NULL);
    while(str[sum] != '\n' && str[sum])
    {
      sum++;
      i++;
    }
	if(str[sum] == '\n')
	{
		i++;
		sum++;
	}
	line = malloc(sizeof(char) * i + 1);
	if(!line)
		return(NULL);
	ft_memset(line, '\n', i + 1);
	line[i] = '\0';
	i = 0;
    while(str[cpy] != '\n' && str[cpy] != '\0')
        line[i++] = str[cpy++];
	return(line);
}


char	*get_next_line(int fd)
{
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	static int done = 0;
	int i = 0;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	static char *str = NULL;
	char *temp;
	char *line;
	if(done == 1)
	{
		line = get_line(str);
		if (line == NULL && str != NULL) 
        {
            free(str); 
            str = NULL;  
        }
	}
	else
	{
		while((i = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[i] = '\0';
			temp = ft_strjoin(&str, &buffer);
			if (str)
				free(temp);
			str = temp;
			free(buffer);
			buffer = NULL;
		}
		if (i == -1)
		{
			free(str);
			free(temp);
			temp = NULL;
			str = NULL;
			return (NULL);
		}
		done = 1;
		line = get_line(str);
	}
	return (line);
}
