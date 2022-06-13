#include "ChangeMap.h"
using namespace std;
using namespace change;
int main(int argc, char const *argv[])
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
	}
	return 0;
}