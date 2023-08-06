#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define clear_bufer() while(getchar() != '\n')

int	main(){
	int	sum;
	pid_t	pid;
	int	i;
	int	num;

	sum = 0;
	i = 0;
	printf("Enter a positive number : ");
	scanf(" %d", &num);
	if ((pid = fork()) > 0) {
		for (i = 1; i <= num; i++) sum += i;
	}
	else {
		for (i = 1; i <= 2 * num; i++) sum += i;
		printf("I am child, my sum = %d\n", sum);
		exit(0);
	}

	wait(NULL);
	printf("I am parent, my sum = %d\n", sum);	
	return (0);
}
