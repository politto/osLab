#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int	main(){
	pid_t	pid;
	int	i;
	int	sum;

	i = 0;
	sum = 3;

	for (i = 0; i < 3; i++) {
		pid = fork();
		if (pid == 0) {
			printf("my copy of i is %d\n", i);
			exit(0);
			printf("Shoud not be executed\n");
		}
	}

	while (wait(NULL) != -1);
	printf("bye from main \n");
	return (0);
}
