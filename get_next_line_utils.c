/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:08:17 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/24 11:09:52 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*val;

	i = 0;
	val = (char *)s;
	while ((char )c != s[i] && s[i] != '\0')
		i++;
	if ((char )c == s[i])
		return (val + i);
	else if (!s[i])
		return (NULL);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while ((dstsize - 1) != i && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*re;
	size_t	size;

	size = ft_strlen(s1);
	re = (char *)malloc(size + 1);
	if (!re)
		return (NULL);
	ft_strlcpy(re, s1, (size + 1));
	return (re);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	a;
	char	*re;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	re = (char *)malloc(len + 1);
	if (!re)
		return (NULL);
	while (i <= len && s1[i])
	{
		re[i] = s1[i];
		i++;
	}
	a = 0;
	while (s2[a])
		re[i++] = s2[a++];
	re[i] = '\0';
	free(s1);
	free(s2);
	return (re);
}
