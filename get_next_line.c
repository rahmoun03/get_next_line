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

char	*ft_line(char *ptr)
{
	static char *sv;
	char *re;
	int i;

	i = 0;
	if(sv)
		ptr = ft_strjoin(sv, ptr);
	while (ptr[i] != '\n' && ptr[i] != '\0')
		i++;
	re = (char *)malloc(i + 1);
	ft_strlcpy(re, ptr, i + 2);
	sv = (char *)malloc(ft_strlen(ptr) - i + 1);
	ft_strlcpy(sv, ptr + i + 1, ft_strlen(ptr) - i + 1);
	return (re);
}

char	*get_next_line(int fd)
{
	ssize_t a;
	char *dst;
	char *ptr;

	a = 1;
	ptr = (char *)malloc(1);
	while (a != 0 && !ft_strchr(ptr, '\n'))
	{
		dst = (char *)malloc(BUFFER_SIZE + 1);
		if(!dst || !ptr)
			return NULL;
		a = read(fd, dst, BUFFER_SIZE);
		dst[a] = '\0';
		ptr = ft_strjoin(ptr, dst);
	}
	return (ft_line(ptr));
}

// int main()
// {
// 	int fd = open("test.txt", O_CREAT | O_RDWR);

// 	printf("%s%s", "1->", get_next_line(fd));//1
// 	printf("%s%s", "2->", get_next_line(fd));//2
// 	printf("%s%s", "3->", get_next_line(fd));//3
// 	printf("%s%s", "4->", get_next_line(fd));//4
// 	printf("%s%s", "5->", get_next_line(fd));//5
// 	printf("%s%s", "6->", get_next_line(fd));//6
// 	// printf("%s\n\n\n\n\n", get_next_line(fd));//7
// }
/*
				< I Love get_next_line >
					-----------------
						^__^
						(oo)|_______
						(__)|       )\
							||---ww |
							||     ||    */
