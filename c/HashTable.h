#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define TABLESIZE 101
#define MAXNAME 256


// struct nlist(
// 	struct nlist *next;
// 	char *name;
// 	char *defn;
// );
typedef struct {
	char* item; // the name of the money
	int value; // the value of money in cents
	int n; // the number of occurences
} money;

money *hashtable[TABLESIZE] ;


unsigned int hash(char *s)
{
	unsigned int hashval;
	for (hashval=0;*s != '\0';s++)
	{
		hashval = *s + 31 * hashval;
	}
	return hashval % TABLESIZE; 
}

void init_hashtable() 
{
	int i;
	for (i = 0; i < TABLESIZE; ++i)
	{
		hashtable[i] = NULL;
	}
}

bool insert(money *m)
{
	if (m == NULL)
		return false;
	int index = hash(m->item);
	if (hashtable[index] != NULL) // this means there is a collision
		return false;
	
	hashtable[index] = m;
	return true;
}

void print_hashtable() 
{
	for (int i = 0;i < TABLESIZE; i++)
	{
		if (hashtable[i] == NULL || hashtable[i]->n == 0) {
			continue;
		}
		else {
			printf("\t%s: %i \n",hashtable[i]->item,hashtable[i]->n);
		}
	}
}

/**
 * Retrieve the item from the hashmap 
 */
money* get(char* key)
{
	unsigned int hashcode = hash(key);
	return hashtable[hashcode];
}

int update_max(int amount) 
{
	int val = 0;
	char* key;
	for (int i = 0;i < TABLESIZE; i++)
	{
		if (hashtable[i] != NULL) {
			if (hashtable[i]->value > val && hashtable[i]->value <= amount) {
				val = hashtable[i]->value;
				key = hashtable[i]->item;
			}
		}
	}
	// now update the hashmap's n field to increase the frequency 
	money* m = get(key);
	if (m == NULL) {
		printf("The key %s does not exist in the hashtable\n",key);
		return;
	}
	m->n++;
	return m->value;
}

void make_change(float amount) 
{
	int amount_int = (int)(amount * 100);
	int change_amount = 0;
	int delta = amount_int - change_amount;
	// printf("The amount_int is %d and the change is %d and the delta is %d \n",amount_int,change_amount,delta);

	while (delta > 0)
	{
		int amt = update_max(delta);
		change_amount += amt;
		delta = amount_int - change_amount;
	}
	printf("For $%0.2f:\n",amount);
	print_hashtable();
	printf("====================================\n");
}
