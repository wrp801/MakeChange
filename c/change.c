#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include "HashTable.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("Error: Please enter at least 1 amount\n");
		return 1;
	}

	for (int i = 1; i < argc;i++)
	{
		money penny = {.item = "Penny",.value=1,.n = 0};
		money nickel = {.item = "Nickel",.value=5,.n=0};
		money dime = {.item = "Dime", .value = 10,.n = 0};
		money quarter = {.item = "Quarter",.value = 25,.n = 0};
		money d1 = {.item = "Dollar1",.value = 100,.n = 0};
		money d5 = {.item = "Dollar5",.value = 500,.n = 0};
		money d10 = {.item = "Dollar10",.value = 1000,.n = 0};
		money d20 = {.item = "Dollar20",.value = 2000,.n = 0};
		money d50 = {.item = "Dollar50",.value = 5000,.n = 0};
		money d100 = {.item = "Dollar100",.value = 10000,.n = 0};


		insert(&penny);
		insert(&nickel);
		insert(&dime);
		insert(&quarter);
		insert(&d1);
		insert(&d5);
		insert(&d10);
		insert(&d20);
		insert(&d50);
		insert(&d100);

		char* arg =  argv[i];
		char* temp;
		// printf("The arg is %s\n",arg);
		float arg_dub;
		arg_dub = strtof(arg,&temp);
		sprintf(temp,"%0.2f",arg_dub);
		// printf("New string is %s\n",temp);
		float arg_float;
		sscanf(temp,"%f",&arg_float);
		// printf("The double is %0.2f\n",arg_float);
		make_change(arg_dub);
	}
	return 0;
}
