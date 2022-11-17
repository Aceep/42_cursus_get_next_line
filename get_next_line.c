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

char	*ft_read(int fd, char *buffer, char *prev_read)
{
	char	*line;
	int	i;

	i = 1;
	if (prev_read)
		line = ft_strdup(prev_read);
	//printf("i = %d", ft_strchr(buffer, '\n'));
	while (ft_strchr(buffer, '\n') == 0 && i == 1)
	{
		//printf("line = %s et buffer = %s et i = %d\n", line, buffer, ft_strchr(buffer, '\n'));
		line = ft_strjoin(line, buffer);
		i = read(fd, buffer, BUFFER_SIZE);
	}
	prev_read = ft_substr(buffer, (ft_strchr(buffer, '\n') + 1), BUFFER_SIZE);
	line = ft_strjoin(line, ft_substr(buffer, 0, (ft_strchr(buffer, '\n') + 1)));
	//printf("line = %s et prev_read =%s", line, prev_read);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*prev_read;
	char	*buffer;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	//printf("ok\n");
	if (!prev_read)
		prev_read = ft_strdup("");
	read(fd, buffer, BUFFER_SIZE);
	return (ft_read(fd, buffer, prev_read));
}


