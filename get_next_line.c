/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:29:00 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/07 15:46:04 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*mem;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	if (ft_strchr(mem, '\n'))
		mem = get_bite(mem, fd);
	line = take_bite(&mem);
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
		buff[cont] = '\0';
		new_line = mem; 
		mem = ft_strjoin(mem, buff);
		free(new_line);
		if (ft_strchr(mem, '\n') != -1)
		{
			break ;
		}
		cont = read (fd, &buff, BUFFER_SIZE);
	}
	return (mem);
}

char	*take_bite(char **mem)
{
	char	*rtn_str;
	char	*tmp;
	size_t	i;

	if(*mem == NULL)
		return (NULL);
	i = 0;
	while ((*mem)[i] && (*mem)[i] != '\n')
		i++;
	if ((*mem)[i] == '\n')
		rtn_str = ft_substr(*mem, 0, i + 1);
	else
		rtn_str = ft_substr(*mem, 0, i);

	tmp = NULL;
	if (ft_strlen(*mem) - i > 0 && ft_strlen(*mem) - i - 1 > 0 ) 
		tmp = ft_substr(*mem, i + 1, ft_strlen(*mem) - i - 1);
	free(*mem);
	*mem = tmp;
	return (rtn_str);
}

