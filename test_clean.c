/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:29:36 by jkoopman       #+#    #+#                */
/*   Updated: 2019/12/03 15:32:59 by jkoopman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** Usage: ./a.out file1.txt
** This will EXACTLY copy the file to the terminal.
** Usefull to combine with a diff.
*/

int		main(int argc, char *argv[])
{
	int		fd;
	char	*line;
	int		res;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	res = 1;
	while (res > 0)
	{
		if (res > 0)
		{
			res = get_next_line(fd, &line);
			if (res == 0)
				printf("%s", line);
			else
				printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
