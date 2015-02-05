#include <stdio.h>

#include "gen_alist.h"

int main(void){
	
	arraylist a = al_init();
	
	int i = 0;
	char *b, *c, d;
	d = 'a';
	b = &d;
	for(i = 0; i<100000;i++){
		al_add(&a, b);
		c = (char*) al_elem(&a, i);
		printf("elem %d: %c\n",i, *c);
//		printf("elem %d: %c\n",i, *(al_elem(&a,i));
		printf("elem %d: %c\n",i, *((char*) a.list[i]));
	}
	/*
	char *h; d = 'b'; h = &d;
	al_add(&a,(int *)4);
	printf("number %d: %d\n",i,al_elem(&a,a.size));	
*/	
	b= al_elem(&a, a.size);
	printf("mele %d: %c\n",a.size, *b);
	al_remove(&a);
	b = al_elem(&a, a.size);
	printf("mele %d: %c\n",a.size, *b);
	b = al_elem(&a, 10);
	printf("elem at 10 (aka 11th element): %c\n", *b);

	return 0;
}