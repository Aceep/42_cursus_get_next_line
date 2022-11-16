/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:27:27 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/14 16:27:58 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd)
{
	char	*buffer;
	size_t	i;
	int	count;
 
	count == 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(char * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	count = ft_strchr(buffer, '/n');
    if (count != 0)
	{
		prev_read = ft_strdup(buffer, i, (BUFFER_SIZE - i));
        buffer = ft_strdup(buffer, 0, count);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*prev_read;

	line = NULL;
	if (prev_read)
		line = find_next_line(prev_read);
	else
		line = ft_strjoin(ft_read(fd));
	return (line);
}

int	main(void)
{
	int	fd;
	char *gnlReturn;

	fd = /*open("test", O_RDWR)*/42;
	gnlReturn = get_next_line(fd);
	if ((BUFFER_SIZE <= 0 && gnlReturn == NULL) || (fd < 0 && gnlReturn == NULL))
		printf("Sucess for buffer size or wrong fd !");
	while (gnlReturn)
	{
		printf("%s", gnlReturn);
		gnlReturn = get_next_line(fd);
	}
	return (0);
}
