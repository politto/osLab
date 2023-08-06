#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int	main(void){
	pid_t	pid;
	int	i;

	pid = fork();
	if (pid > 0) {
		i = 1;
		sleep(5);
		printf("I am parent my pid = %d, i = %d\n", getpid(), i);
	}
	else {
		i = 2;
		printf("I am child my pid = %d, i = %d\n", getpid(), i);
	}

	return (0);
}

