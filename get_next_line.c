#include "get_next_line.h"

int line = 0;
char	*ft_set_line(char *str)
{
	int i;
	char *re;

	i = line;
	while (str[i] && str[i] != '\n')
	{
		printf("%c | ", str[i]);
		i++;
	}
	str = str + line;
	line = i + 1;
	str[i + 1] = '\0';
	re = ft_strdup(str);
	return (re);
}

char	*get_next_line(int fd)
{
	char *p;
	char *re;
	ssize_t a[1];

	a[0] = 1;
	re = (char *)malloc(1);
	while (a[0] != 0)
	{
		p = (char *)malloc(BUFFER_SIZE + 1);
		a[0] = read(fd, p, BUFFER_SIZE);
		p[a[0]] = '\0';
		if(a[0] != 0)
			re = ft_strjoin(re, p);
		free(p);
	}
	re = ft_set_line(re);
	return (re);
}

int main()
{
	int fd = open("test.txt", O_CREAT | O_RDWR);

	printf(">>%s", get_next_line(fd));
	printf("%d.\n", line);
	printf(">>%s", get_next_line(fd));
	printf("%d.\n", line);
	printf(">>%s", get_next_line(fd));
	printf("%d.\n", line);
	//  printf("%s", get_next_line(fd));
}
/*
				< I Love get_next_line >
					-----------------
						^__^
						(oo)|_______
						(__)|       )\
							||----w |
							||     ||          */
