/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:27:15 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/26 13:27:50 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t length(char *str)
{
	int	i;
	if (str == NULL)
		return (0);
	i = 0 ;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int check_new_line(char *str)
{
	int i ;
	if (str == NULL)
		return (0);
	i = 0 ;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *save_reset(char *stash)
{
	if (stash == NULL)
		return NULL ;
	char *matrix;
	int i;
	int k ;
	int len;
	i = 0 ;
	while (stash[i] != '\n' && stash[i])
		i++;
				if (stash[i] == '\0')
					return NULL ;
	i++;
	len = length(stash + i);
	matrix = malloc(len + 1);
	if (matrix == NULL)
		return NULL ;
		k = 0 ;
		while (k < len)
			matrix[k++] = stash[i++];
		matrix[k] = '\0';
		return matrix;
}

char *extract_line(char *stash)
{
	if (stash == NULL)
	{
		return NULL ;
	}
		char *matrix ;
		int found_line ;
		int i ;
		int k ;

		i = 0 ;
		while (stash[i] != '\n' && stash[i])
		{
			i++;
		}
			found_line = check_new_line(stash);
			matrix = malloc(i + found_line + 1);
		if (matrix == NULL)
			return NULL ;
		k = 0 ;
		while (k < i)
		{
			matrix[k] = stash[k];
			k++;
		}
		if (found_line)
		{
			matrix[k++] = '\n';
		}
		matrix[k] = '\0';
		return matrix;
}


char *join(char *stash , char *buffer)
{
	int k ;
	int i ;
	char *matrix;
	int len_stash ;
	int len_buffer;

	if(buffer == NULL)
		return stash ;

	len_buffer = length(buffer);
	len_stash = length(stash);
	matrix = malloc(len_buffer + len_stash + 1);
	if (matrix == NULL)
		return NULL ;
	i = 0 ;
	while (i < len_stash)
	{
		matrix[i] = stash[i];
		i++;
	}
	k = 0 ;
	while (k < len_buffer)
		matrix[i++] = buffer[k++];
	matrix[i] = '\0';
	free(stash);
	return matrix;
}

static char *clean_stash(char **stash)
{
	char *line ;
	line = extract_line(*stash);
	char *tmp = *stash ;
	*stash = save_reset(*stash);
	free(tmp);
	return line ;
}

char *get_next_line(int fd)
{
	static char *stash ;
	size_t nbyte;
	char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
    return NULL;
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return NULL;
	while ((nbyte = read(fd , buffer , BUFFER_SIZE)) > 0)
	{
		buffer[nbyte] = '\0';
		stash = join(stash , buffer);
		if (check_new_line(stash))
			break;
	}
	if (nbyte == -1)
	{
		free(buffer);
		return NULL ;
	}
	free(buffer);
	    if (!stash)
        return NULL;
	return (clean_stash(&stash));
}

int main ()
{
	int fd = open("file2.txt" , O_CREAT | O_RDWR, 0777 );
	char *line ;
	// char *buffer = "hello\nworld\nhow?";
	// printf("%s" , get_next_line(fd) );
	while ((line = get_next_line(fd)) != NULL)
	{
			printf("%s" , line);
			free(line);
	}
	free(line);

		
}
