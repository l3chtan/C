#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "gen_alist.h"


 arraylist al_init(){
 	arraylist a;
 	a.size = -1;
 	a.capacity = 10;
 	a.list = list_alloc(a.capacity);
 	return a;
 }

 void ** list_alloc(int n){
 	void **v;
 	int i=0;

 	v = (void **) malloc(n*sizeof(void *));
 	if(v){
 		for(i=0;i<n;i++){
 			v[i] = (void*) malloc(sizeof(void *));
 			if(v[i] == NULL){
 				fprintf(stderr, "memory allocation failed.\n");
 				exit(1);
 			}
 		}
 	}
 	return v;
 }

 void al_resize(arraylist *a, int new_size){
 	arraylist n = al_init();	
 	int i=0;

 	n.size = a->size;
 	n.capacity = new_size;
 	n.list = list_alloc(new_size);
 	for(i=0;i<a->size;i++){
 		n.list[i]  = a->list[i];
 	}

 	if(NULL == n.list){
 		exit(EXIT_FAILURE);
 	}
 	free(a->list);
 	a->size = n.size;
 	a->capacity = n.capacity;
 	a->list = n.list;
 }

 void al_add(arraylist *a, void *c){

	if(a->size == INT_MAX-1){
		fprintf(stderr, "You cannot add more elements to your arraylist\n");
		return -1;
	}

	if(a->size >= a->capacity){
		al_resize(a,2*a->capacity);
	}	
	a->size = a->size+1;
	a->list[a->size] = c;
	return 0;
 }

void al_remove(arraylist *a){
	if(--(a->size) < a->capacity/2){
		al_resize(a,a->capacity/2);
	}
}

int al_get_size(arraylist *a){
	return a->size;
}

void * al_elem(arraylist *a, int num){
	return a->list[num];
}
