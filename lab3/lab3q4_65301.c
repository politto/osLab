#include <stdio.h>

int	main(){
	int	num;
	int	cnt;
	int	sum;
	
	sum = 0;
	cnt = 0;
	printf("enter a positive number : \n");
	while (1){
		scanf("%d", &num);
		if (num <= 0) break;
		sum += num;
		cnt += 1;
	}

	printf("summation is : %d \n", sum);
	printf("mean is      : %.2f \n", (float)(sum / cnt));
	return (0);


}
