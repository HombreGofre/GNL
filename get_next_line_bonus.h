/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:20:19 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/11 14:39:08 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*get_bite(char *mem, int fd);
char	*take_bite(char **mem);

size_t	ft_strlen(char const *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *mem, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *s1);

#endif
