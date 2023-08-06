#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int	main(){
	pid_t	pid;
	int	i;
	int	sum;

	i = 0;
	sum = 3;
	pid = fork();
	
	if (pid > 0) {
		i = 1;
		sum += 1;
		printf("my copy of i is %d\n", i);
	}
	else {
		i = 2;
		sum += i;
		printf("my copy of i is %d\n", i);

	}

	printf("my sum = %d\n", sum);
	wait(NULL);
	return (0);
}
