/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maaz <ael-maaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:49:46 by ael-maaz          #+#    #+#             */
/*   Updated: 2024/01/07 18:03:34 by ael-maaz         ###   ########.fr       */
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
    if(str[sum] == '\0')
    {
      line = malloc(sizeof(char) * i + 1);
      line[i]='\0';
    }
    else
    {
    	line = malloc(sizeof(char) * i + 2);
    	line[i++] = '\n';
    	line[i]='\0';
    	sum++;
    }
    i = 0;
    while(str[cpy] != '\n' && str[cpy] != '\0')
    {
        line[i] = str[cpy++];
        i++;
    }
    return (line);
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
		line = get_line(str);
	else
	{
		while((i = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[i] = '\0';
			temp = str;
			str = ft_strjoin(str, buffer);
			if(str == NULL)
				return (NULL);
			if(temp != NULL)
				free(temp);
		}
		done = 1;
		line = get_line(str);
	}
	return (line);
}

/* char	*get_next_line(int fd)
{
	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static int done = 0;
	int i = 0;
	static int sum = 0;
	char buffer[BUFFER_SIZE + 1];
	static char *str = "";
	char *line = NULL;
	if(done == 1)
		line = get_line(str,&sum);
	else
	{
		while((i = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[i] = '\0';
			str = ft_strjoin(str, buffer);
		}
		done = 1;
		line = get_line(str,&sum);
	}
	return (line);
} */
/* int main()
{
	int fd = open("file.txt", O_RDWR | O_CREAT, 0777);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
} */