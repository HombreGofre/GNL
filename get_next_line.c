/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:29:00 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/01 14:34:10 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	if (fd > 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!(ft_strchr(mem, '\n')))
	{
		mem	= get_bite(mem, fd);
	}
	line = take_bite(&mem);
	mem = save_mem(mem);
	return (line);
}

char	*get_bite(char *mem, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*new_line;
	int		cont;

	cont = read (fd, &buff, BUFFER_SIZE);
	while (cont > 0)
	{
		new_line[cont] = '\0';
		new_line = ft_strjoin(mem, buff);
		if (ft_strchr(mem, '\n'))
			break;
		cont = read (fd, &buff, BUFFER_SIZE);
	}
	return (new_line);
}

char	*take_bite(char **mem)
{
	char	*rtn_str;
	size_t	i;

	i = 0;
	while (*mem[i] && *mem[i] != '\n')
		i++;
	rtn_str = ft_substr(*mem, 0, i + 1);
	rtn_str[i + 1] = '\0';
	return (rtn_str);
}

char	*save_mem(char *mem)
{
	char	*sv_str;
	size_t	cont;

	if (mem == NULL || ft_strchr(mem, '\0') == 0)
		return (NULL);
	cont = ft_strchr(mem, '\n');
	if (cont < 0)
		return (NULL);
	else
	{
		sv_str = malloc(sizeof(char) * (ft_strlen(mem) - cont + 1));
		free(mem);
	}
	return (sv_str);
}
