/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:29:00 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/06 17:43:10 by cnunez-s         ###   ########.fr       */
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
	mem = save_mem(mem);
	return (line);
}

/*char	*empty_mem(void)
{
	char	*empty;
	empty = malloc(sizeof(char));
	if (!empty)
		return (NULL);
	*empty = '\0';
	return (empty);
}*/

char	*get_bite(char *mem, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*new_line;
	int		cont;

	cont = read (fd, &buff, BUFFER_SIZE);
	//if (cont == 0)
	//	mem = empty_mem();
	while (cont > 0) //Preguntar
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

	//printf("Mem take [%s]\n", *mem);
	if(*mem == NULL)
		return (NULL);
	i = 0;
	while ((*mem)[i] && (*mem)[i] != '\n')
		i++;
	rtn_str = ft_substr(*mem, 0, i + 1);
	if (ft_strlen(*mem) - i == 0)
		tmp = NULL;
	else
		tmp = ft_substr(*mem, i, ft_strlen(*mem) - i);
	free(*mem);
	*mem = tmp;
	return (rtn_str);
}

char	*save_mem(char *mem)
{
	char	*sv_str;
	size_t	cont;

	if (mem == NULL) {
		return (NULL);
	}
	else if (ft_strchr(mem, '\0'))
	{
		free(mem);
		//printf("Valor ------ [%s]\n", mem);
		return NULL;
	}
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
