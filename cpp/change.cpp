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
	ChangeMap cm = ChangeMap(false);
	ChangeMap counter = ChangeMap(true);
	// float amount_to_change = 12.32;
	float amount_to_change =  std::stof(argv[1]); // convert the command line arg to a float
	make_change(cm,&counter,amount_to_change);
	counter.printMap();
	return 0;
}