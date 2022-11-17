/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:27:27 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/17 19:54:42 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_read(int fd, char *buffer, char **prev_read)
{
	char	*line;
	int	r;

	//printf("prev_read at start = %s\n", *prev_read);
	if (ft_strchr(*prev_read, '\n') != -1)
	{
		line = ft_substr(*prev_read, 0, (ft_strchr(*prev_read, '\n') + 1));
		*prev_read = ft_substr(*prev_read, (ft_strchr(*prev_read, '\n') + 1), BUFFER_SIZE);
		//printf("line = %s et prev_read =%s\n", line, *prev_read);
		return (line);
	}
	else if (prev_read)
		line = ft_strdup(*prev_read);
	//printf("i = %d", ft_strchr(buffer, '\n'));
	r = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", r);
	while (r > 0)
	{
		while (ft_strchr(buffer, '\n') == -1)
		{
			printf("line = %s et buffer = %s et i = %d\n", line, buffer, ft_strchr(buffer, '\n'));
			line = ft_strjoin(line, buffer);
			r = read(fd, buffer, BUFFER_SIZE);
		}
		*prev_read = ft_substr(buffer, (ft_strchr(buffer, '\n') + 1), BUFFER_SIZE);
		line = ft_strjoin(line, ft_substr(buffer, 0, (ft_strchr(buffer, '\n') + 1)));
		//printf("line = %s et prev_read =%s\n", line, *prev_read);
		len = ft_strlen(line);
		line[len] = '\0';
		return (line);
	}
	//free(*prev_read);
	return (NULL);
}*/

char	*ft_read(int fd, char *buffer, char **prev_read)
{
	char	*line;
	int	len;
	int	r;

	if (*prev_read)
	{
		if (ft_strchr(*prev_read, '\n') != -1)
		{
			line = ft_substr(*prev_read, 0, ft_strchr(*prev_read, '\n' + 1));
			*prev_read = ft_substr(*prev_read, ft_strchr(*prev_read, '\n' + 1), BUFFER_SIZE);
			return (line);
		}
		else if (ft_strchr(*prev_read, '\0') != -1)
		{
			line = ft_strdup(*prev_read);
			free(*prev_read);
			return (line);
		}
		line = ft_strdup(*prev_read);
	}
	r = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n", r);
	if (!*prev_read && r <= 0)
		return (NULL);
	while (ft_strchr(buffer, '\n') == -1)
	{
		line = ft_strjoin(line, buffer);
		r = read(fd, buffer, BUFFER_SIZE);
	}
	*prev_read = ft_substr(buffer, (ft_strchr(buffer, '\n') + 1), BUFFER_SIZE);
	line = ft_strjoin(line, ft_substr(buffer, 0, (ft_strchr(buffer, '\n') + 1)));
	len = ft_strlen(line);
	line[len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*prev_read;
	char	*buffer;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) <= 0)
		return (printf("here");NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!prev_read)
		prev_read = ft_strdup("");
	printf("prev_read = %s\n", prev_read);
	return (ft_read(fd, buffer, &prev_read));
}


