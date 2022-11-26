/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arahmoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:08:02 by arahmoun          #+#    #+#             */
/*   Updated: 2022/11/24 11:08:05 by arahmoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_set_line(char *str)
{
	int			i;
	char		*val;
	static char	*result;

	if (!result)
		result = (char *)malloc(1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	val = (char *)malloc(i + 1);
	ft_strlcpy(val, str, i + 2);
	result = (char *)malloc(ft_strlen(str) - i + 1);
	ft_strlcpy(result, str + i, ft_strlen(str) - i + 2);
	free(str);
	return (val);
}

char	*get_next_line(int fd)
{
	char	*p[3];
	ssize_t	a;

	a = 1;
	if (fd < 0)
		return (NULL);
	p[0] = (char *)malloc(1);
	p[1] = (char *)malloc(BUFFER_SIZE + 1);
	if (!p[1] || !p[0] || BUFFER_SIZE <= 0)
		return (NULL);
	while (a != 0 && !ft_strchr(p[0], '\n'))
	{
		a = read(fd, p[1], BUFFER_SIZE);
		p[1][a] = '\0';
		if (a != 0)
			p[0] = ft_strjoin(p[0], p[1]);
		if (a < 0 || p[1][0] == '\0')
		{
			free(p[0]);
			free(p[1]);
			return (NULL);
		}
	}
	free(p[1]);
	return (ft_set_line(p[0]));
}

// int main()
// {
// 	int fd = open("test.txt", O_CREAT | O_RDWR);

// 	printf("%s", get_next_line(fd));//1
// 	printf("%s", get_next_line(fd));//2
// 	printf("%s", get_next_line(fd));//3
// 	printf("%s", get_next_line(fd));//4
// 	printf("%s", get_next_line(fd));//5
// 	// printf("%s", get_next_line(fd));//6
// 	// printf("%s", get_next_line(fd));//7
// 	// printf("%s", get_next_line(fd));//8

// }
/*
				< I Love get_next_line >
					-----------------
						^__^
						(oo)|_______
						(__)|       )\
							||---ww |
							||     ||    */
