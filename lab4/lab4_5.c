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

	sum = 0;
	if ((pid = fork()) > 0) {
		i = 1;
		sum += i;
		printf("I am parent. My ID is %d\n", getpid());
	}
	else {

		i = 2;
		sum += i;
		printf("I am child. My ID is %d\n", getpid());
		printf("My parent id is %d\n", getppid());
		exit(0);
	}

	wait(NULL);
	printf("(parent) sum = %d\n", sum);
	return (0);
}
