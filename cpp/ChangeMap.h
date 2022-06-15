#include <map>
#include <iostream>
using namespace std;
namespace change 
{
	class ChangeMap
	{
		public:
			map<string,int> values;

		ChangeMap(bool empty)
		{
			if (empty) 
			{
				values.insert({"Penny",0});
				values.insert({"Nickel",0});
				values.insert({"Dime",0});
				values.insert({"Quarter",0});
				values.insert({"Dollar1",0});
				values.insert({"Dollar5",0});
				values.insert({"Dollar10",0});
				values.insert({"Dollar20",0});
				values.insert({"Dollar50",0});
				values.insert({"Dollar100",0});
			}
			else 
			{
				values.insert({"Penny",1});
				values.insert({"Nickel",5});
				values.insert({"Dime",10});
				values.insert({"Quarter",25});
				values.insert({"Dollar1",100});
				values.insert({"Dollar5",500});
				values.insert({"Dollar10",1000});
				values.insert({"Dollar20",2000});
				values.insert({"Dollar50",5000});
				values.insert({"Dollar100",10000});
			}
		}

		void printMap () 
		{
			/**
			 * Helper function to print the contents of the map to the screen
			 * 
			 */
			for (auto B= values.begin(), E = values.end(); B != E; ++B)
			{
				string key = B->first;
				int val = B->second;
				if (val != 0)
				{
					cout << '\t' << key << " : " << val << endl;

				}
			}
		}


	}; // end class

	map<string,int> filterMap(float amount,ChangeMap changeMap)
	{
		/**
		 * Helper function to return a map with values that are greater than the amount argument
		 * 
		 */
		map<string,int> retmap;
		for (auto B = changeMap.values.begin(),E = changeMap.values.end(); B!=E; ++B)
		{
			string coin =  B->first;
			int val = B->second;
			if (val < amount)
			{
				retmap[coin] = val;
			}
		}
		return retmap;
	}

	// Overload function to accept an int as well
	map<string,int> filterMap(int amount, ChangeMap changeMap)
	{
		map<string,int> retmap;
		for (auto B = changeMap.values.begin(),E = changeMap.values.end(); B!=E; ++B)
		{
			string coin =  B->first;
			int val = B->second;
			if (val <= amount)
			{
				retmap[coin] = val;
			}
		}
		return retmap;

	}

	map<string,int> selectMax(map<string,int> values)
	{
		/**
		 * Helper function to select the max value from the change map
		 */
		int max_val = 0;
		string max_key; 

		for (auto B = values.begin(), E = values.end(); B != E; ++B)
		{
			int temp_val = B->second;
			if (temp_val > max_val)
			{
				string temp_string = B->first;
				max_val = temp_val;
				max_key = temp_string;
			}
		}
		map<string,int> ret_map;
		ret_map[max_key] = max_val;
		return ret_map;
	}

	void make_change(ChangeMap valueMap, ChangeMap *changeCounter,double amount)
	{
		int changeRemaining = 0;
		int cent_value = (int)(amount*100); // convert to cents
		while (true)
		{
			int delta = cent_value - changeRemaining; // keep a running tally
			// if (delta == 0 || changeRemaining > cent_value)
			if (delta == 0)
				break;
			auto filtered = filterMap(delta,valueMap); 
			auto max_val = selectMax(filtered);
			for (auto B = max_val.begin(), E = max_val.end(); B != E; ++B)
			{
				string s = B->first;
				int v =  B-> second;
				changeCounter->values[s]++; // incremenet the change counter for the given key
				changeRemaining += v;
			}
		}
	};
}; // end namespace