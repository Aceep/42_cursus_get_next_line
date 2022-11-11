/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:27:27 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/11 18:51:40 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char buffer)
{
	int	count;
	char	buf[1];
	int	i;

	while (read(fd, buf, 1) > 0 && buf[0] != '\n' && count <= BUFFER_SIZE)
	{
		i = 0;
		buffer[i ++] = buf[0];
		read(fd, buf, 1);
		if (buf[0] == '\n')
			return (buffer);
		count ++;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	buffer = ft_read(fd, buffer);
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("test", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
