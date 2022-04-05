/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:30:28 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/05 15:24:48 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*get_bite(char *mem, int fd);
char	*take_bite(char **mem);
char	*save_mem(char *mem);

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *mem, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *s1);

#endif

