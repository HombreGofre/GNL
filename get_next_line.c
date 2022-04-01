/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:29:00 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/01 12:39:45 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd > 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(ft_strchr(mem, '\n')))
	{
		mem	= get_bite(*mem);
	}
	line = take_bite(&mem);
	mem = save_bite(mem);
	return (line);
}

char	*get_bite(char *mem)
{
	char	buff[BUFFER_SIZE + 1]
	char	*new_line;
	size_t	cont;

	cont = read (fd, &buff, BUFFER_SIZE);
	while (cont > 0)
	{
		new_line[cont] = '\0';
		new_line = ft_strjoin(mem, buff);
		if (ft_strchr(mem, '\n'))
			return ;
		cont = read (fd, &buff, BUFFER_SIZE);
	}
	return (new_line);
}

char	*take_bite(char *mem)
{
	char	*rtn_str;
	size_t	i;
	size_t	start;
	size_t	len;

	cont = 0;
	while (*mem[i] && *mem[i] != '\n')
		i++;
	rtn_str = ft_substr(*mem, 0, i + 1);
	rtn_str[i + 1] = '\0';
	return (rtn_str);
}
