/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:27:27 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/16 20:37:47 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *prev_read)
{
	char	*buffer;
	size_t	i;
	
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
    if (ft_strchr(buffer, '\n') != 0)
	{
		prev_read = ft_substr(buffer, i, (BUFFER_SIZE - i));
        buffer = ft_substr(buffer, 0, ft_strchr(buffer, '\n'));
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;
	static char	*prev_read;

	line = NULL;
	//if (prev_read)
	//	line = find_next_line(prev_read);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd, prev_read);
	return (line);
}


