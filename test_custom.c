/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_custom.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 10:30:06 by jkoopman       #+#    #+#                */
/*   Updated: 2019/12/05 14:58:06 by jkoopman      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/*
** Usage: ./a.out
** Now you can type in the terminal and check the stdin & stdout
*/

int			main(void)
{
	char	*line;
	int		cnt = 0;
	int		fd = 0;
	int		res;

	printf("BUFFER: %d\n", BUFFER_SIZE);
	printf("FD: %d\n", fd);
	printf("==== START ====\n");
	while ((res = get_next_line(fd, &line)) > 0)
	{
		printf("LINE %d, OUT %d: |%s|\n", cnt++, res, line);
		if (line)
			free(line);
	}
	printf("LINE %d, OUT %d: |%s|\n", cnt++, res, line);
	if (line)
		free(line);
	printf("==== ENDED ====\n");
	return (0);
}
