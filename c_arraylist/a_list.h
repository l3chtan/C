#ifndef ARRAY_LIST
#define ARRAY_LIST

struct arraylist {
	int size;
	char *list;
};

extern struct arraylist al_init();
extern int al_size(struct arraylist *a);
extern void al_resize(struct arraylist *a, int new_size);
extern void al_add(struct arraylist *a, char c);
extern void al_remove(struct arraylist *a);
extern int al_get_size(struct arraylist *a);
extern char al_get_elem(struct arraylist *a, int num);

#endif
