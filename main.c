/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:36:11 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/22 18:49:00 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	check_error(int fd)
{
	char	*gnlreturn;

	gnlreturn = get_next_line(fd);
	if (gnlreturn == NULL)
		printf("OK\n");
	else
		printf("Erreur\n");
}

void	with_files(void)
{
	int		i;
	int		fd;
	char	*gnlreturn;

	i = 1;
	/*fd = open("bible.txt", O_RDONLY);
	gnlreturn = get_next_line(fd);
	while (gnlreturn)
	{
		printf("line %d = %s", i, gnlreturn);
		gnlreturn = get_next_line(fd);
		i ++;
	}
	i = 1;*/
	fd = open("test", O_RDONLY);
	gnlreturn = get_next_line(fd);
	while (gnlreturn)
	{
		printf("line %d = %s", i, gnlreturn);
		gnlreturn = get_next_line(fd);
		i ++;
	}
	return ;
}

int	main(void)
{
	int		fd;
	char	*gnlreturn;

	fd = 0;
	if (BUFFER_SIZE <= 0)
	{
		printf("Incorrect size of buffer : ");
		check_error(fd);
		return (0);
	}
	fd = open("empty", O_RDWR);
	printf("Fichier vide : ");
	check_error(fd);
	fd = 42;
	printf("Incorrect fd : ");
	check_error(fd);
	fd = 0;
	gnlreturn = get_next_line(fd);
	printf("line = %s", gnlreturn);
	with_files();
	return (0);
}
