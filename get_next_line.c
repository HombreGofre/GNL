/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:29:00 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/03/31 14:10:14 by cnunez-s         ###   ########.fr       */
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
		line = get_bite(*mem);
	}
	
}

char	*get_bite(char *mem)
{
	char	buff[BUFFER_SIZE + 1]
	char	*new_line;
	size_t	cont;

	cont = ft_strchr(mem, '\n');
	while (cont > 0)
	{
		new_line = ft_strjoin(
	}

}
