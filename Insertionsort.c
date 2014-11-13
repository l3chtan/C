#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

int A[atoi(argv[1])];
int i = 0, tmp = 0, index = 0, len_A = 0;

len_A = sizeof(A)/sizeof(int);

for(i=0;i<len_A;i++){
	A[i] = 0;
}

printf("Enter the row of numbers you want sorted.\n");

for(i=0;i<len_A;i++){
	scanf("%1d", &A[i]);
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


return 0;
}
