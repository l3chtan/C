#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>

int main(void){

	int i = 0, j = 0, k = 2, m = 0, l = 0, t = 1;

	for(i=2;i<1000;i++){
		for(j=i;j<1000;j++){
			m = pow(i,2) + pow(j,2);
			t = 1, l = 0;
			while(pow(l,2)< INT_MAX && l < m){
				t++;
				l = pow(t,2);
				if(l == m){
					printf("%d^%d + %d^%d = %d\n",i,k,j,k,m);
					printf("##############################################\n");
				}			
			}
		}
	}

	return 0;
}
