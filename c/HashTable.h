#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define TABLESIZE 101
#define MAXNAME 256

typedef struct {
	char* item; // the name of the money
	int value; // the value of money in cents
	int n; // the number of occurences
} money;


/**
 * Hashcode which will serve as the index to insert something into the hashtable
 */
unsigned int hash(char *s)
{
	unsigned int hashval;
	for (hashval=0;*s != '\0';s++)
	{
		hashval = *s + 31 * hashval; // 31 was an arbitray number, any prime would work 
	}
	return hashval % TABLESIZE; 
}

/**
 * Allocates a hashtable on the heap, returns a pointer to it
 */
money** create_hashtable() 
{
	money** hashtable;
	hashtable = (money**)malloc(sizeof(money)*TABLESIZE);
	int i;
	for (i = 0; i < TABLESIZE; ++i)
	{
		hashtable[i] = NULL;
	}
	return hashtable;
}

/**
 * Insert an item into the hashtable based off of the hashcode 
 */
bool insert(money *m,money** hashtable)
{
	if (m == NULL)
		return false;
	int index = hash(m->item);
	if (hashtable[index] != NULL) // this means there is a collision
		return false;
	
	hashtable[index] = m;
	return true;
}

void print_hashtable(money** hashtable) 
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
money* get(char* key,money **hashtable)
{
	unsigned int hashcode = hash(key);
	return hashtable[hashcode];
}

/**
 * Select the maximum value from the hashtable that is less than the argument amount
 */
int update_max(int amount,money **hashtable) 
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
	money* m = get(key,hashtable);
	if (m == NULL) {
		printf("The key %s does not exist in the hashtable\n",key);
		// return -1;
		exit(1);
	}
	m->n++;
	return m->value;
}

/**
 * Find the optimal amount of change and print out the results
 */
void make_change(float amount, money **hashtable) 
{
	int amount_int = (int)(amount * 100);
	int change_amount = 0;
	int delta = amount_int - change_amount;

	while (delta > 0)
	{
		int amt = update_max(delta,hashtable);
		change_amount += amt;
		delta = amount_int - change_amount;
	}
}
