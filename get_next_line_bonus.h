/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-all <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:00 by oait-all          #+#    #+#             */
/*   Updated: 2025/11/26 13:29:18 by oait-all         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif 

size_t length(char *str);
int found_newline(char *str);
char *extract_line(char *stash);
char *save_reset(char *stash);
char *append(char *stash , char *buffer);
char *get_next_line(int fd);