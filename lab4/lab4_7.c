#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define clear_bufer() while(getchar() != '\n')

/*
7.1 3
7.2 pidsub = fork();
7.3 exit(0);
7.4  for (int ่j = 0; j < num_gc; j++){
	pidsub = fork();
		if (pid != 0) {
			printf("Child %d forked grandchild %d", j, i);
		}
	}
	while(wait(NULL) != -1)
7.5 int num_gc = 4;  
7.6 pidsub == 0
7.7 exit(0);
7.8 exit(0);
7.9 มันไป exit in if ไม่ก็ else condition อยู่แล้ยู่แล้ว
7.10 23 lines
7.11 22                        7.12 no
*/

int	main(){
	int	i, j;
	pid_t	pid, pidsub;

	printf("only parent before fork\n");
	
	for (i = 0; i < 5; i++) {
		pid = fork();
		
		if (pid == 0) {
			
			if ((i % 2) == 0) {
				printf("I am the child no %d\n", i);
				int num_gc = 3; //<<< 7.1

				for (j = 0; j < num_gc; j++) {
					pidsub = fork(); //<<< 7.2
					if (pidsub == 0) {
						printf("I am grandchild num %d of even child no %d\n", j, i);
						exit(0);//<<< 7.3
					}
				}
				//<<< 7.4
				for (int ่j = 0; j < num_gc; j++){
					pidsub = fork();
					if (pid != 0) {
						printf("Child %d forked grandchild %d", j, i);
					}
				}
				while(wait(NULL) != -1)
				// END 7.4
				exit(0);
			}
			else {
				printf("I am the child no %d\n", i);
				int num_gc = 4; //<<< 7.5
				for (j = 0; j < num_gc; j++) {
					pidsub = fork();
					if (pidsub == 0){ /// <<< 7.6
						printf ("I am grandchild num %d of odd child no %d\n", j, i);
						exit(0);// <<< 7.7
					}
				}

				while (wait(NULL) != -1);
				exit(0);//<<< 7.8
			}
			// <<< 7.9 why no exit(0) here

		}
	}
	while (wait(NULL) != -1);
	return (0);

}
