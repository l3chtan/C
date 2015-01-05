#include <stdio.h>

#include "a_list.h"

int main(void){
	
	struct arraylist a = al_init();
	int i = 0;
	for(i = 0; i<100000;i++){
		al_add(&a, 'a');
		printf("elem %d: %c\n",i, a.list[i]);
	}
	printf("mele %d: %c\n",a.size, a.list[a.size]);
	al_remove(&a);
	printf("mele %d: %c\n",a.size, a.list[a.size]);

	printf("elem at 10 (aka 11th element): %c\n", al_get_elem(&a, 10));

	return 0;
}