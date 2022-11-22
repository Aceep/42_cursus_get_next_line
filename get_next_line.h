/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:36:28 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/22 16:40:36 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# include <stdio.h>


char	*get_next_line(int fd);
int ft_read(int fd, char **buffer, char **line, char **prev_read);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*get_end(char **prev_read);
char	*get_line(char **prev_read);

#endif
