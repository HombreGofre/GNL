/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnunez-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:23:03 by cnunez-s          #+#    #+#             */
/*   Updated: 2022/04/07 13:30:51 by cnunez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

int main()
{
	int 	fd;
	char	*str;

	fd = open ("mi_fichero.txt", O_RDONLY);
	str = get_next_line(fd);
	while(str != NULL)
	{
		printf("|%s|\n", str);
		free(str);
		str = get_next_line(fd);
	}
}
