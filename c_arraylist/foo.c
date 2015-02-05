#include <stdio.h>

#include "gen_alist.h"

int main(void){
	
	arraylist a = al_init();
	
	int i = 0;
	char *b, *c, d;
	d = 'a';
	b = &d;
	for(i = 0; i<100000;i++){
		al_add(&a, (char*)b);
		c = al_get_elem(&a, i);
		printf("elem %d: %c\n",i, *c);
//		printf("elem %d: %c\n",i, *(al_get_elem(&a,i));
		printf("elem %d: %c\n",i, *((char*) a.list[i]));
	}
	
/*	al_get_elem(&a, a.size, b);
	printf("mele %d: %c\n",a.size, *b);
	al_remove(&a);
	al_get_elem(&a, a.size, b);
	printf("mele %d: %c\n",a.size, *b);
	al_get_elem(&a, 10, b);
	printf("elem at 10 (aka 11th element): %c\n", *b);
*/
	return 0;
}