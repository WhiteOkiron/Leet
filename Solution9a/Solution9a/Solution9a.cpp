//TODO: Example 1:
//TODO: Input: 121
//TODO: 	Output : true

//TODO: 	Example 2 :
//TODO: 	Input : -121
//TODO: 	Output : false
//TODO: 	Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.

//TODO: 	Example 3 :
//TODO: 	Input : 10
//TODO: 	Output : false
//TODO: 	Explanation : Reads 01 from right to left.Therefore it is not a palindrome.

    
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) { cout << "false" << endl; return false; }  //! FILTER: false if negative number
		if (x < 10) { cout << "true" << endl; return true; }  //! Filter: 1 digit is Palindrome
		int xTemp1 = x;
		int digitCount = 1;
		int firstDigit = 0;
		int lastDigit = 0;
		while (xTemp1 >= 10) { xTemp1 = xTemp1 / 10; digitCount++; }  //! CALCULATION: find digitCount

		string value = to_string(x);

		int LeftIndex = 0;
		int RightIndex = digitCount - 1;
		firstDigit = value[LeftIndex];
		lastDigit = value[RightIndex];

		//? 1 0 0 0 0 2 1
		while (firstDigit == lastDigit)
		{

			if (RightIndex - LeftIndex == 0 || RightIndex - LeftIndex == 1)
			{
				cout << "true" << endl;
				return true;
			}
			LeftIndex++;
			RightIndex--;
			firstDigit = value[LeftIndex];
			lastDigit = value[RightIndex];
		}
		cout << "false" << endl;
		return false;
	}
};

int main()
{
	Solution solution;
	solution.isPalindrome(11);
	system("PAUSE");
}
