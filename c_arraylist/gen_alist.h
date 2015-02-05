#ifndef ARRAY_LIST
#define ARRAY_LIST

typedef struct arraylist_s {
	int size;
	void **list; /* Can hold any type of pointer */
} arraylist;

extern arraylist al_init();
extern void ** list_alloc(int n);
extern int al_size(arraylist *a);
extern void al_resize(arraylist *a, int new_size);
extern void al_add(arraylist *a, void *c);
extern void al_remove(arraylist *a);
extern int al_get_size(arraylist *a);
extern void * al_get_elem(arraylist *a, int num);

#endif