/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:49:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/10 13:27:51 by ael-maaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

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
	char buffer[BUFFER_SIZE + 1];
	static char *str = NULL;
	char *temp;
	char *line;
	if(done == 1)
	{
		line = get_line(str);
		if (line == NULL && str != NULL) // If there's no more lines and str is not NULL
        {
            free(str); // Free str
            str = NULL; // Set str to NULL to avoid dangling pointer
        }
	}
	else
	{
		while((i = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[i] = '\0';
			temp = ft_strjoin(&str, buffer);
			if (str)
				free(temp);
			str = temp;
		}
		done = 1;
		line = get_line(str);
		if (i == -1)
		{
			free(str);
			str = NULL;
			ft_memset(buffer, 0, BUFFER_SIZE + 1);	
			return (NULL);
		}
	}
	return (line);
}
