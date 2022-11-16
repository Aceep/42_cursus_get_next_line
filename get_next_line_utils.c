/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alycgaut <alycgaut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:27:27 by alycgaut          #+#    #+#             */
/*   Updated: 2022/11/14 16:27:58 by alycgaut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

size_t	ft_strchr(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i ++;
	if (s[i] == c)
		return (i);
	return (0);
}

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
        char    *dst;
        size_t  size;
        size_t  i;

        if (!s)
                return (NULL);
        size = ft_strlen(s) - start;
        if (start > ft_strlen(s))
                size = 0;
        else if (len > size)
                len = size;
        else if (len < size)
                size = len;
        dst = (char *)(malloc(sizeof(char) * (size + 1)));
        if (!dst)
                return (NULL);
        i = 0;
        while (i < size && s[start])
        {
                dst[i] = s[start];
                i ++;
                start ++;
        }
        dst[i] = '\0';
        return (dst);
}

