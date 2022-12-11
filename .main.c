
#include "get_next_line.h"

int main()
{
	int fd = open("test.txt", O_RDWR);

	char *a = get_next_line(fd);
	printf("%s%s", "1->", a);//1
	free(a);


	a = get_next_line(fd);
	printf("%s%s", "2->", a);//2
	free(a);


	a = get_next_line(fd);
	printf("%s%s", "3->", a);//3
	free(a);


	a = get_next_line(fd);
	printf("%s%s", "4->", a);//4
	free(a);


	// a = get_next_line(fd);
	// printf("%s%s", "5->", a);//5
	// free(a);


	// a = get_next_line(fd);
	// printf("%s%s", "6->", a);//6
	// free(a);


	// a = get_next_line(fd);
	// printf("%s%s", "7->", a);//7
	// free(a);


	// a = get_next_line(fd);
	// printf("%s%s", "8->", a);//8
	// free(a);

	// system("leaks a.out");
	// // printf("%s\n\n\n\n\n", );//7
}
/*
				< I Love get_next_line >
					-----------------
						^__^
						(oo)|_______
						(__)|       )\
							||---ww |
							||     ||    */