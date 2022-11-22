#include "get_next_line.h"

void	check_error(int fd)
{
	char	*gnlReturn;

	gnlReturn = get_next_line(fd);
	if (gnlReturn == NULL)
		printf("OK\n");
	else
		printf("Erreur\n");
}

int	main(void)
{
	int	fd;

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
	int i = 1;
	char	*gnlReturn;
	fd = open("bible.txt", O_RDONLY);
	gnlReturn = get_next_line(fd);
	while (gnlReturn)
	{
		printf("line %d = %s", i, gnlReturn);
		gnlReturn = get_next_line(fd);
		i ++;
	}
	fd = open("test", O_RDONLY);
	gnlReturn = get_next_line(fd);
	while (gnlReturn)
	{
		printf("line %d = %s", i, gnlReturn);
		gnlReturn = get_next_line(fd);
		i ++;
	}
	fd = 0;
	gnlReturn = get_next_line(fd);
	while (gnlReturn)
	{
		printf("line %d = %s", i, gnlReturn);
		gnlReturn = get_next_line(fd);
		i ++;
	}
	
	return (0);
}