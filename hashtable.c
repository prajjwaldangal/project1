#include <linux/list.h>

struct birthday {
	char name[100];
	int day;
	int month;
	int year;
	struct list head list;
}

struct HashTable {
	int size;
	struct 
};

typedef struct HashTable HT;

HashTable * create_HT (int size) {
	
	HT * ht = NULL;
	if (ht=kmalloc(sizeof( 
}

char * HT_get(HT * table, char * key) {
	
}
