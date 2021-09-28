/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvanden- <jvanden-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:03:57 by eperaita          #+#    #+#             */
/*   Updated: 2021/09/28 13:11:51 by jvanden-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *find_line_break(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while(str[i])
	{
		if(str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char *ft_join(char *temp, char *buff)
{
	char *new;
	int i;
	
	i = 0;
	if (!temp || !buff)
		return(NULL);
	new = malloc((ft_strlen(temp) + ft_strlen(buff) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (*temp)
		new[i++] = *temp++;
	while (*buff)
		new[i++] = *buff++;
	new[i] = '\0';
	return (new);
}

char *ft_substr(char *str, int start, size_t len)
{
	char *new;
	int i;

	i = 0;
	if (!str || len <= 0)
		return (NULL);
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (len)
	{
		new[i++] = str[start++];
		len--;
	}
	new[i] = '\0';
	return (new);
}

char *purge_line_from_temp(char *temp, char *line)
{
	char *new_temp;
	int	len;
	int	start;

	if (!find_line_break(temp))
	{
		free (temp);
		return (NULL);
	}
	len = ft_strlen(temp) - ft_strlen(line);
	start = ft_strlen(line);
	new_temp = ft_substr(temp, start, len); 
	free (temp);
	return (new_temp);
}

char *extract_line_from_temp(char *line, char *temp)
{
	size_t	len;

	len = 0;
	if(find_line_break(temp))
		line = ft_substr(temp, 0, ft_strlen(temp) - ft_strlen(find_line_break(temp)) + 1);
	else
		line = ft_substr(temp, 0, ft_strlen(temp));
	return (line);
}

char *update_temp(char *temp, char *buff)
{
	char *new;
	int i;

	i = 0;
	if (!temp)
	{
		temp = malloc (1);
		temp[0] = '\0';
	}
	new = ft_join(temp, buff);
	free (temp);
	return (new);	
}

char *read_to_temp(int fd, char *temp)
{
	char *buff;
	int bytes;

	bytes = 1;
	while (!find_line_break(temp) && bytes > 0)
	{
		buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buff)
			return (0);
		bytes = read(fd, buff, BUFFER_SIZE);
		if ((bytes == 0 && !temp) || bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		temp = update_temp(temp, buff);
		free (buff);
	}
	return (temp);
}

char *get_next_line(int fd)
{
	char *line;
	static char *temp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp = read_to_temp(fd, temp);
	line = extract_line_from_temp(line, temp);
	temp = purge_line_from_temp(temp, line);
	return (line);
}

