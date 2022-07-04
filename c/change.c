#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include "HashTable.h"
#include<unistd.h>
#include<time.h>


#define BUFFER 16

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("Error: Please enter at least 1 amount\n");
		return 1;
	}

	bool read_flag = false;
	char opt;
	// Parse the command line args
	// if there is a -c then the program should read from the file
	while ((opt = getopt(argc,argv,"c")) != EOF)  // if the arg was c: then it would expect an argument after -c
	{
		switch(opt)
		{
			case 'c':
				read_flag = true;
				break;
			default:
				printf("No argument entered\n");
				break;
		}	
	}

	if (read_flag)
	{
		double time_spent = 0.0;
		clock_t start = clock();
		FILE *fp;
		char line[BUFFER];
		fp = fopen("args.txt","r");
		while (fgets(line,sizeof(line),fp))
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

			money** ht = create_hashtable();

			insert(&penny,ht);
			insert(&nickel,ht);
			insert(&dime,ht);
			insert(&quarter,ht);
			insert(&d1,ht);
			insert(&d5,ht);
			insert(&d10,ht);
			insert(&d20,ht);
			insert(&d50,ht);
			insert(&d100,ht);

			// char* arg =  argv[i];
			char temp[BUFFER];
			float arg_dub;
			arg_dub = strtof(line,&temp);
			sprintf(temp,"%0.2f",arg_dub); // format the string to a float with two decimals
			float arg_float;
			sscanf(temp,"%f",&arg_float); // store the formated string as a float 
			make_change(arg_dub,ht);
			free(ht); // free up the hashtable
			memset(temp,'0',BUFFER); // reset the temp variable otherwise the original value will persist
			memset(line,'0',BUFFER);

		}
		clock_t end = clock();
		time_spent += (double)(end - start)/CLOCKS_PER_SEC; // this will be represented in seconds
		printf("C took %f seconds to run\n",time_spent);
		return 0;
	}

	else 
	{
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

			money** ht = create_hashtable();

			insert(&penny,ht);
			insert(&nickel,ht);
			insert(&dime,ht);
			insert(&quarter,ht);
			insert(&d1,ht);
			insert(&d5,ht);
			insert(&d10,ht);
			insert(&d20,ht);
			insert(&d50,ht);
			insert(&d100,ht);

			char* arg =  argv[i];
			char temp[BUFFER];
			float arg_dub;
			arg_dub = strtof(arg,&temp);
			sprintf(temp,"%0.2f",arg_dub); // format the string to a float with two decimals
			float arg_float;
			sscanf(temp,"%f",&arg_float); // store the formated string as a float 
			make_change(arg_dub,ht);
			printf("For $%0.2f:\n",arg_dub);
			print_hashtable(ht);
			printf("====================================\n");
			free(ht); // free up the hashtable
			memset(temp,'0',BUFFER); // reset the temp variable otherwise the original value will persist

		}
		return 0;
	}
}
