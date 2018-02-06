#include <linux/list.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/limits.h>

struct birthday {
	char name[100];
	int day;
	int month;
	int year;
	struct list_head list;
};

// we'll set bucket size as 2 
struct bucket {
	struct hlist_head * in_head;
	int max_len = 2;
};
typedef struct bucket bucket;

struct HashTable {
	unsigned int size;
	bucket *head; // head of the doubly linked list
};

typedef struct HashTable HT;
typedef struct birthday entry;


HT * create_HT (unsigned int size) {
	
	HT * ht = NULL;
	if ((ht=kmalloc(sizeof(HT), GFP_KERNEL)) == NULL ) {
		return NULL;
	}
	if ((ht->table = kmalloc(sizeof(list)*size, GFP_KERNEL)) == NULL) {
		return NULL;
	}
	int i;
	for (i=0; i < size; i ++ ) {
		ht->table[i] = NULL;
	}
	ht->size = size;
	
	return ht;
}

int hash(HT * ht, char * name) {
	unsigned long int hashval;
	int i = 0;
	while (hashval < ULONG_MAX && i < strlen(name)) {
		hashval =  hashval << 8;
		hashval += name[i];
		i ++;
	}
	return hashval % ht-> size;
}

int set_HT(HT * ht, entry * bday) { 
	int ind = hash(ht, bday->name);
	
}

//char * HT_get(HT * table, char * key) { }

int main(void) {
	HT * ht = create_HT(5);
	
	entry * entry1;
	entry1 = kmalloc(sizeof(*entry1), GFP_KERNEL);
	entry1->name = "Tsunade";
	entry1->day = 19;
	entry1->month = 6;
	entry1->year = 1995;
	set_HT(ht, &entry1);
	
	entry * entry2;
	entry2 = kmalloc(sizeof(*entry2), GFP_KERNEL);
	entry2->name = "Dignis";
	entry2->day = 19;
	entry2->month = 6;
	entry2->year = 1992;
	
	entry * entry3;
	entry3 = kmalloc(sizeof(*entry3), GFP_KERNEL);
	entry3->name = "Ramu";
	entry3->day = 23;
	entry3->month = 2;
	entry3->year = 1993;
	
	entry * entry4;
	entry4 = kmalloc(sizeof(*entry4), GFP_KERNEL);
	entry4->name = "Sita";
	entry4->day = 12;
	entry4->month = 5;
	entry4->year = 1988;

	entry * entry5;
	entry5 = kmalloc(sizeof(*entry5), GFP_KERNEL);
	entry5->name = "Solti";
	entry5->day = 13;
	entry5->month = 12;
	entry5->year = 1993;
}








