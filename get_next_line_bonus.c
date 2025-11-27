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

static char *fffff(char **stash)
{
    char    *line ;
    line = extract_line(*stash);
    char *tmp = *stash;
    *stash = save_reset(*stash);
    free(tmp);
    return line ;
}



char *get_next_line(int fd)
{

    static *stash[1024];
    char    *BUFFER;
    ssize_t nbyte ;

    if (BUFFER_SIZE <= 0 || fd <= -1)
        return NULL;
    BUFFER = malloc( ((size_t)BUFFER_SIZE) + 1);
    if (BUFFER == NULL)
        return NULL ;
    while(1)
    {
        while ((nbyte = read(fd , BUFFER , BUFFER_SIZE)) > 0)
        {
            BUFFER[nbyte] = '\0';
            stash[fd] = append(stash[fd] , BUFFER);
            break;
        }
        if (nbyte == 0)
            break;
        if (nbyte == -1)
        {
            free(BUFFER);
            return NULL ;
        }
    }
    free(BUFFER);
    return (fffff(&stash[fd]));
}
