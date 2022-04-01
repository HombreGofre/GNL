/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:30:28 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/01 12:10:26 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <limits.h>

int		*get_next_line(int fd);
char	*get_bite(char *mem); 

size_t	ft_strlen(char str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *mem, int c);

#endif

