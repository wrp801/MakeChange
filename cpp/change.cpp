#include "ChangeMap.h"
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
using namespace change;
int main(int argc, char *argv[])
{
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
				cout << "No flag entered" << endl;
				break;
		}	
	}
	if (read_flag)
	{
		auto start = high_resolution_clock::now();
		string arg_val;
		ifstream arg_file("args.txt");
		while (getline(arg_file,arg_val))
		{
			ChangeMap cm = ChangeMap(false);
			ChangeMap counter = ChangeMap(true);
			double amount_to_change =  std::stod(arg_val); // convert the command line arg to a float
			make_change(cm,&counter,amount_to_change);
		}
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		double secs = (double)duration.count();
		double seconds = secs / 1000000.00;
		// cout << "C++ took " << duration.count() << " to run" << endl;
		cout << "C++ took " << seconds << " to run" << endl;

		return 0;
	}	
	else 
	{
		if (argc == 1) // check to make sure there is an amount entered
		{
			cout << "Error: Please input an amount as an argument" << endl;
			exit(EXIT_FAILURE);
		}

		for (int i = 1; i < argc;i++)
		{
			ChangeMap cm = ChangeMap(false);
			ChangeMap counter = ChangeMap(true);
			double amount_to_change =  std::stod(argv[i]); // convert the command line arg to a float
			cout << "For " << "$" << amount_to_change << ":" << endl;
			make_change(cm,&counter,amount_to_change);
			counter.printMap();
			cout << "====================================" << endl;
		}
		return 0;
	}
}