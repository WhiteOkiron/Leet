

#include <iostream>
#include <vector>

using namespace std;
 


vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result = {};
	int rowCount = 0;
	int previousNumber = 0;
	int currentNumber = 0;
	int leftIndex = 0;
	int rightIndex = 0;
	int count = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		previousNumber = nums[i];
		leftIndex = i;

		for (int j = 1 + count; j < nums.size(); j++)
		{
			currentNumber = nums[j];
			rightIndex = j;

			if (previousNumber + currentNumber == target)
			{
				result.push_back(leftIndex);
				result.push_back(rightIndex);
				return result;
			}
		}
		count++;
	}
	return result;
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
