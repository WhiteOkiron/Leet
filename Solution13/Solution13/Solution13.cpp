//TODO: I             1
//TODO: V             5
//TODO: X             10
//TODO: L             50
//TODO: C             100
//TODO: D             500
//TODO: M             1000

//TODO:  Example 4:
//TODO:  Input: "LVIII"
//TODO: 	Output : 58
//TODO: 	Explanation : C = 100, L = 50, XXX = 30 and III = 3.

//TODO: 	Example 5 :
//TODO: 	Input : "MCMXCIV"
//TODO: 	Output : 1994
//TODO: 	Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.


#include <iostream>
#include <string>

using namespace std;


//?                       I = 1    II = 2    III = 3     IV = 4    V = 5   VI = 6      VII = 7     VIII = 8     IX = 9      X = 10

//!  If larger number is on the right hand, then minus it with previous number;  Add the 2 digits together to become one.
//!  If Left and Right number is the same, then it counts as its own digit.
class Solution {

	const int I = 1;
	const int V = 5;
	const int X = 10;
	const int L = 50;
	const int C = 100;
	const int D = 500;
	const int M = 1000;

public:
	int romanToInt(string s) {
		int total = 0;
		int current = 0;
		int next = 0;
		for (int i = 0; i < s.length(); i++)  //? have the knowledge of current and next letter for comparison
		{
			cout << "s[" << i << "]: " << s[i] << endl;
			switch (s[i])
			{
			case 'I':
				current = 1;
				break;
			case 'V':
				current = 5;
				break;
			case 'X':
				current = 10;
				break;
			case 'L':
				current = 50;
				break;
			case 'C':
				current = 100;
				break;
			case 'D':
				current = 500;
				break;
			case 'M':
				current = 1000;
				break;
			}
			switch (s[i + 1])
			{
			case 'I':
				next = 1;
				break;
			case 'V':
				next = 5;
				break;
			case 'X':
				next = 10;
				break;
			case 'L':
				next = 50;
				break;
			case 'C':
				next = 100;
				break;
			case 'D':
				next = 500;
				break;
			case 'M':
				next = 1000;
				break;
			}

			if (current == next || current > next)
			{
				total = total + current;
				cout << "current:" << current << " == / > " << "next:" << next << endl;
				cout << "Total: " << total << endl;
			}
			if (s.length() == i)
			{
				total = total + next;
				cout << "s.length() == i" << endl;
				cout << "Total: " << total << endl;
				return total;
			}
			if (current < next)
			{
				total = total + (next - current);
				i++;
				cout << "current:" << current << " < " << "next:" << next << endl;
				cout << "Total: " << total << endl;
			}

			current = 0;
			next = 0;
			//! if 1 standalone digit, then let it loop without changing i

			//! if 2 digits added together, then i++
		}
		return total;
	}
};


int main()																						//! got	     1785
{																									     //! 1695   (1000)+(500)+(100-10)+(100+5)
	string testModule[12] = { "I", "III", "IV", "VI", "VIII", "IX", "XI", "XX", "XVI", "XXI", "MCMXCIV", "MDCXCV" };
	int result = 0;
	Solution solution;

	result = solution.romanToInt("MDCXCV");
	cout << "MDCXCV" << ": " << result << endl;

}

