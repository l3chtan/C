#include <stdio.h>
#include <stdlib.h>

int A(int a, int b){
	/*printf("a: %d, b: %d\n",a,b);*/

	if(a == 0){
		return b+1;
	} else if(b == 0){
		return A(a-1,1);
	} else {
		return A(a-1,A(a,b-1));
	}
}

int main(int argc, char **argv){

	char buf[11];
	int i = 0;
	int a[] = {0,0};

	printf("Enter two non-negative integers. Default values are 0 for both integers.\n");

	for(i=0;i<2;i++){
		printf("> ");
		if(fgets(buf, 10, stdin) == NULL){
			fprintf(stderr, "Could not read input\n");
		}
		a[i] = atoi(buf);
	}

	(a[0] ==0&& a[1]==0) ? printf("> 1\n") : printf("> %d\n",A(a[0],a[1]));

	return 0;
}