/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:36:28 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/16 19:54:37 by alycgaut         ###   ########.fr       */
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
char	*ft_read(int fd, char *buffer, char *prev_read);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);

#endif
