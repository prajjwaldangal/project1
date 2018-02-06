#include <linux/list.h>
#include <linux/slab.h>
#include <linux/kernel.h>

struct birthday {
	char name[100];
	int day;
	int month;
	int year;
	struct list_head list;
};

struct HashTable {
	int size;
	struct birthday ** table; 
};

typedef struct HashTable HT;
typedef struct birthday entry;

HT * create_HT (int size) {
	
	HT * ht = NULL;
	if ((ht=kmalloc(sizeof(HT), GFP_KERNEL)) == NULL ) {
		return NULL;
	}
	if ((ht->table = kmalloc(sizeof(entry), GFP_KERNEL)) == NULL) {
		return NULL;
	}
	int i;
	for (i=0; i < size; i ++ ) {
		ht->table[i] = NULL;
	}
	ht->size = size;
	return ht;
}

int set_HT(HT * table, entry * bday) { 
	char * key = bday->name;
	
}

//char * HT_get(HT * table, char * key) { }

int main(void) {
	HT * ht = create_HT(3);
	
}








