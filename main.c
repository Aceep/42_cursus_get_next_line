/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:36:11 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/30 17:10:31 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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
	}*/
	i = 1;
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

void	bonus(void)
{
	int		i;
	int		fd1;
	char	*gnlreturn1;
	int		fd2;
	char	*gnlreturn2;

	i = 1;
	fd1 = open("test", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	gnlreturn1 = get_next_line(fd1);
	gnlreturn2 = get_next_line(fd2);
	while (gnlreturn1 || gnlreturn2)
	{
		if (gnlreturn1)
			printf("line %d du fichier 1= %s\n", i, gnlreturn1);
		else
			printf("\n");
		if (gnlreturn2)
			printf("line %d du fichier 2= %s\n", i, gnlreturn2);
		else
			printf("\n");
		gnlreturn1 = get_next_line(fd1);
		gnlreturn2 = get_next_line(fd2);
		i ++;
	}
}

int	main(void)
{
	int		fd;
	//char	*gnlreturn;

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
	close(fd);
	fd = 42;
	printf("Incorrect fd : ");
	check_error(fd);
	close(fd);
	// fd = 0;
	// gnlreturn = get_next_line(fd);
	// printf("line = %s", gnlreturn);
	//with_files();
	//bonus();
	return (/*free(gnlreturn),*/ 0);
}
