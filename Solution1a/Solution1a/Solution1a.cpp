

#include <iostream>
#include <vector>
#include <map>
using namespace std;
 


vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> r;
	map<int, int> map;
	for (auto it = nums.begin(); it != nums.end(); it++)  //! Create a [value/index] map using the passed in vector
	{
		//cout << *it << endl;
		int key = it - nums.begin(); //! 1 - 0    2 - 9   3 - 0       'it' itself isn't int typed, but somehow when subtracted to nums.begin() it becomes an int
									 //! purpose: Shortcut way to find index of it
		//cout << "key: " << key << endl;
		map[*it] = key;            //?  Map =  *it | Index of it
	}
	for (auto it = nums.begin(); it != nums.end(); it++)
	{
		auto matchingValue = target - *it;                                          //! target = *index1 + *index2,   matchingValue = target - *index1
																					//? *it - is now the IndexLeft's value.
		auto foundIt = map.find(matchingValue);                                      //! find the index of matchingValue, assign it to "foundIt"... which is an iterator type
		if (foundIt != map.end() && it - nums.begin() != foundIt->second)        //! if search is available (not null) && foundIt isn't the IndexLeft
		{
			r.push_back(it - nums.begin());        //?  "it - nums.begin()" is IndexLeft
			r.push_back(foundIt->second);          //?  "foundIt->second" is IndexRight
			return r;
		}
	}
	return r;
}

void main()
{

	int targetNumber = 26;
	vector<int> nums{ 2, 7, 11, 15 };
	vector<int> nums2{ 23,12,0,123,35,2,1232,4,43,542,53,5,435,345,345,345,3524,54 };
	vector<int> nums3{ 3,2,4 };

	vector<int> resultIndex = {};
	resultIndex = twoSum(nums, targetNumber);


	for (int i = 0; i < resultIndex.size(); i++)
	{
		cout << resultIndex[i] << endl;
	}

	system("PAUSE");
}
