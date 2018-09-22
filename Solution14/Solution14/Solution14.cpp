//TODO: Write a function to find the longest common prefix string amongst an array of strings.

//TODO: If there is no common prefix, return an empty string "".

//TODO: Example 1:

//TODO: Input: ["flower", "flow", "flight"]
//TODO: 	Output : "fl"
//TODO: 	Example 2 :

//TODO: 	Input : ["dog", "racecar", "car"]
//TODO: 	Output : ""
//TODO: 	Explanation : There is no common prefix among the input strings.


#include <iostream>
#include <string>
#include <vector>
using namespace std;


int minimum = 0;
class Solution {

public:
	string longestCommonPrefix(vector<string>& strs) {

		int minSize = getMinSize(strs);
		for (int i = 0; i < minSize; i++)
		{

		}
	}

};

int getMinSize(vector<string>& strs)
{
	minimum = strs[0].length();
	for (int i = 0; i < strs.size(); i++)
	{
		if (strs[i].length() < minimum)
		{
			minimum = strs[i].length();
		}
	}
	return minimum;
}

int test()
{
	vector<string>word = { "onesdf", "two", "three", "four", "fives" };

	//cout << word[0] << endl;       //! one
	//cout << word[0][1] << endl;    //! n
	//int size = static_cast<int>(word.size());
	//cout << size << endl;
	//cout << word.size() << endl;
	int MinSize = getMinSize(word);






	return 0;
}

int main()
{
	//! Find the length of the shortest word
	//! Loop through each letters in all the words using that length

	test();
	return 0;

}


