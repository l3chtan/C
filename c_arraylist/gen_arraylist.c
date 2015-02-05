#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "gen_alist.h"


 arraylist al_init(){
 	arraylist a;
 	a.size = -1;
 	a.list = list_alloc(1);
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

 int al_size(arraylist *a){
	return sizeof(a->list)/sizeof(void*);
 }

 void al_resize(arraylist *a, int new_size){
 	arraylist n;	
 	int i=0;

 	n.size = a->size;
 	n.list = list_alloc(new_size);
 	for(i=0;i<a->size;i++){
 		n.list[i]  = a->list[i];
 	}
 	/*
 	int num = sizeof(a->list);
 	memcpy(n.list,a->list,num);
 	*/
 	if(NULL == n.list){
 		exit(EXIT_FAILURE);
 	}
 	free(a->list);
 	a = &n;
 }

 void al_add(arraylist *a, void *c){

	if(a->size == INT_MAX-1){
		fprintf(stderr, "You cannot add more elements to your arraylist\n");
		return;
	}

	if(a->size == al_size(a)){
		al_resize(a,2*sizeof(a->size));
	}	
	a->list[a->size+1] = c;
 }

void al_remove(arraylist *a){
	if(--(a->size) < al_size(a)/2){
		al_resize(a,sizeof(a->list)/2);
	}
}

int al_get_size(arraylist *a){
	return a->size;
}

void * al_get_elem(arraylist *a, int num){
	return a->list[num];
}
