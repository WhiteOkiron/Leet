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

int getMinLetterCount(vector<string>& strs)
{
	if (strs.size() != 0)
	{
		minimum = strs[0].length();
		for (int i = 0; i < strs.size(); i++)
		{
			if (strs[i].length() < minimum)
			{
				minimum = strs[i].length();
			}
		}
	}
	return minimum;
}


class Solution {

public:
	string longestCommonPrefix(vector<string>& strs) {  //?  Empty Vector results in error when passed to a function
		int stringSizeMinusOne = ((int)strs.size() - 1);
		int minLetterCount = getMinLetterCount(strs);

		string result = "";

		int prefixCount = 0;
		bool match = true;
		string currentLetter = "";
		string nextLetter = "";

		int letterCount = 0; //! created when switching from a for loop to a while loop to accommodate match == true
		while (letterCount < minLetterCount && match == true)
		{
			match = true;

			for (int word = 0; word < strs.size(); word++)
			{
				//?  if number of word < strs.size()
				if (word != strs.size()-1 && match)                     //! Account for overflowing vector
				{

					currentLetter = strs[word][letterCount];
					nextLetter = strs[word + 1][letterCount];
					//cout << currentLetter << " vs " << nextLetter << endl;


					(currentLetter == nextLetter) ? match = true : match = false;
					//cout << match << endl;
				}
			}
			if (match == true) { prefixCount++; }
			//cout << "prefixCount++: " << prefixCount << endl;
			letterCount++;
		}


		if (stringSizeMinusOne != -1)
		{
			for (int i = 0; i < prefixCount; i++)  //!  Recreate the cut out string
			{
				result.push_back(strs[0][i]);
			}
		}
		return result;
	}
};




int main()
{
	//! Find the length of the shortest word
	//! Loop through each letters in all the words using that length
	vector<string>words = { "twodf", "two", "twoee", "twour", "twoves" };
	vector<string>empty = {  };
	Solution solution;
	cout << solution.longestCommonPrefix(words) << endl;
	system("PAUSE");
	return 0;

}


