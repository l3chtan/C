#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "a_list.h"


struct arraylist al_init(){
	struct arraylist a;

	a.size = -1;
	a.list = (char*) malloc(32*sizeof(char));
	return a; 
}

int al_size(struct arraylist *a){

	return sizeof(a->list)/sizeof(char);
}

void al_resize(struct arraylist *a, int new_size){
	struct arraylist n;

	n.size = a->size; 
	n.list = (char*)malloc(new_size);
	int num = sizeof(a->list);
	memcpy(n.list,a->list,num);
	if(NULL == n.list){
		exit(EXIT_FAILURE);
	}
	free(a->list);
	a = &n;
}

void al_add(struct arraylist *a, char c){

	if(a->size == INT_MAX-1){
		fprintf(stderr, "You cannot add more elements to your arraylist\n");
		return;
	}

	if(a->size == al_size(a)){
		al_resize(a,2*sizeof(a->list));
	}	
	a->list[++a->size] = c;
}

void al_remove(struct arraylist *a){
	if(--(a->size) < al_size(a)/2){
		al_resize(a,sizeof(a->list)/2);
	}
}

int al_get_size(struct arraylist *a){
	return a->size;
}

char al_get_elem(struct arraylist *a, int num){
	return (a->list)[num];
}
