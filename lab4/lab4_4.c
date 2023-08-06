#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define clear_bufer() while(getchar() != '\n')

int	main(){
	pid_t pid[3], w;
	int num, sum = 0;
	int i, status;

	printf("Enter a positive number ");
	num = getchar() - 48; 
	// Same as scanf(%d, &num);
	clear_buffer();
	// ignore if (num <= 0)
	for (i = 0; i < 3; i++) {
		if ((pid[i] = fork()) == 0) {
			printf("I am child no %d. my copy of num %d\n", i, num);
			exit(i);:
		}
	}
	return (0);
}
