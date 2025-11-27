/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:28:02 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/26 13:55:30 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	length(char *str)
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

int	found_newline(char *str)
{
	int	i;

	i = 0;
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

char	*extract_line(char *stash)
{
	char	*matrix;
	int		i;
	int		newline;
	int		k;

	if (stash == NULL)
		return (NULL);
	i = 0 ;
	while (stash[i] != '\n' && stash[i])
		i++;
	newline = found_newline(stash);
	matrix = malloc(i + newline + 1);
	if (matrix == NULL)
		return (NULL);
	k = 0 ;
	while (k < i)
	{
		matrix[k] = stash[k];
		k++;
	}
	if (newline)
		matrix[k++] = '\n';
	matrix[k] = '\0';
	return (matrix);
}

char	*save_reset(char *stash)
{
	char	*matrix;
	int		i;
	int		len;
	int		k;

	if (stash == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\0')
		return (NULL);
	if (stash[i] == '\n')
		i++;
	len = length(stash + i);
	matrix = malloc(len + 1);
	if (matrix == NULL)
		return (NULL);
	k = 0 ;
	while (k < len)
		matrix[k++] = stash[i++];
	matrix[k] = '\0';
	return (matrix);
}

char	*append(char *stash, char *buffer)
{
	char	*matrix;
	int		len_stash;
	int		len_buf;
	int		i;
    int     k;

	if (buffer == NULL)
		return (stash);
	len_stash = length(stash);
	len_buf = length(buffer);
	matrix = malloc(len_stash + len_buf + 1);
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < len_stash)
	{
		matrix[i] = stash[i];
		i++;
	}
	k = 0 ;
	while (k < len_buf)
		matrix[i++] = buffer[k++];
	matrix[i] = '\0';
	free(stash);
	return (matrix);
}
                                                                                                                                    