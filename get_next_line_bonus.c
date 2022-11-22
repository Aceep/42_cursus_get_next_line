#include "get_next_line.h"

int	ft_end_file(char *prev_read)
{
	int i;
	i =0;
	while (prev_read[i] != '\n' && prev_read[i] != '\0')
		i ++;
	if (prev_read[i] == '\n')
		return (1);
	return (0);
}

char	*get_line(char **prev_read)
{
	char	*line;
	int	i;

	if (!prev_read)
		return (NULL);
	i = ft_strchr(*prev_read);
	line = ft_substr(*prev_read, 0, (i + ft_end_file(*prev_read)));
	if (!line)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

char	*get_end(char **prev_read)
{
	char	*p_read;
	int	i;

	if (!prev_read)
		return (NULL);
	i = ft_strchr(*prev_read);
	if (ft_end_file(*prev_read) == 0)
	{
		free (*prev_read);
		return (NULL);
	}
	p_read = ft_substr(*prev_read, i + 1, ft_strlen(*prev_read) - i);
	if (!p_read)
	{
		free (p_read);
		return (NULL);
	}
	free (*prev_read);
	return (p_read);
}

int	ft_read(int fd, char **buffer, char **line, char **prev_read)
{
		int	b_read;

		b_read = 1;
		while (ft_strchr(*prev_read) == -1 && b_read > 0)
		{
			b_read = read(fd, *buffer, BUFFER_SIZE);
			if (b_read < 0)
				return ( 0);
			(*buffer)[b_read] = '\0';
			*prev_read = ft_strjoin(*prev_read, *buffer);
		}
		free (*buffer);
		*line = get_line(prev_read);
		if (**line == '\0')
		{
			free (*line);
			*line = NULL;
		}
		*prev_read = get_end(prev_read);
		return (b_read);
}

char	*get_next_line(int fd)
{
	static char	*prev_read[10];
	char	*buffer;
	int	b_read;
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || read(fd, buffer, 0) < 0)
		return (free(buffer), free(*prev_read), NULL);
	if (!prev_read[fd])
		prev_read[fd] = ft_strdup("");
	b_read = ft_read(fd, &buffer, &line, &prev_read[fd]);
	if (b_read == 0 && !line)
		return (NULL);
	return (line);
}
