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

char	*ft_read(int fd, char *buffer)
{
	char	buf[1];
	size_t	i;
	int	count;

    read(fd, buf, 1);
    if (buf[0] == '\n' || buf[0] == 0)
        return (free(buffer), NULL);
    count = 0;
	i = 0;
	while (buf[0] != '\n' && count <= BUFFER_SIZE)
	{
		read(fd, buf, 1);
        buffer[i++] = buf[0];
		count ++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer = ft_read(fd, buffer);
	return (buffer);
}

/*int	main(void)
{
	int	fd;
	char *gnlReturn;

	fd = open("empty", O_RDWR);
	gnlReturn = get_next_line(fd);
	if ( gnlReturn == NULL)
		printf("Sucess\n");
	else 
		printf("%s", gnlReturn);
	return (0);
}*/
