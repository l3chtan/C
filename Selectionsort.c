#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	if(argc != 2){
		fprintf(stderr, "The program takes exactly one argument (the amount of numbers you want to be sorted)!\n");
		return 1;
	}

	char *buf;
	int A[atoi(argv[1])];
	int i = 0, tmp = 0, index = 0, len_A = 0;

	len_A = sizeof(A)/sizeof(int);

	for(i=0;i<len_A;i++){
		A[i] = 0;
	}
	buf = (char *)malloc(20*sizeof(char));

	printf("Enter the row of numbers you want sorted.\nAll extra digits will be omitted.\n");

	for(i=0;i<atoi(argv[1]);i++){
		buf[0] = '\0';		
		fgets(buf,20,stdin);
		/*TODO: Implement check for non-numbers*/
		A[i] = atoi(buf);
	}

	printf("Thank you!\n");

	for(i=1;i<len_A;i++){

		tmp = A[i];
		index = i;

		while(index > 0 && tmp < A[index-1]){
			A[index] = A[index-1];
			index--;
		}
		A[index] = tmp;

	}

	for(i=0;i<len_A;i++){
		printf("%d\n", A[i]);
	}


	return 42;
}
