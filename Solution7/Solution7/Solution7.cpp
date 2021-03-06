//TODO: Given a 32-bit signed integer, reverse digits of an integer.

//TODO: Input: 123
//TODO:	Output : 321
//TODO:	Example 2 :

//TODO:	Input : -123
//TODO:	Output : -321
//TODO:	Example 3 :

//TODO:	Input : 120
//TODO:	Output : 21
//TODO:	Note : Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range :
//TODO: [−2^31, 2^31−1].For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.


#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	Node* next;
	int data;
};

class LinkedList
{
public:
	void addNode(int num)
	{
		Node* n = new Node();
		n->next = nullptr;
		n->data = num;
		if (head == nullptr) { head = n; }
		else
		{
			curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = n;
		}
	}

	int32_t getReverseValue(LinkedList* passed_list)
	{
		double reversedValue = 0;
		int digitCount = 0;
		int count = 0;									                                          // input: 10, should be at 1
		passed_list->curr = passed_list->head;                                                    // assign curr to head
		cout << "passed_list->curr->data: " << passed_list->curr->data << endl;
		if (passed_list->curr->data == 0) { passed_list->curr = passed_list->curr->next; }        // skipped 0
		while (passed_list->curr != nullptr)
		{
			passed_list->curr = passed_list->curr->next;
			digitCount++;                                                                         // digitCount is 1
		}
		passed_list->curr = passed_list->head;                                                    // back to head
		if (passed_list->curr->data == 0) { passed_list->curr = passed_list->curr->next; }        // skipped 0
		while (passed_list->curr != nullptr)
		{
			// calculate reversedValues here
			reversedValue = reversedValue + passed_list->curr->data * pow(10, digitCount - 1);
			passed_list->curr = passed_list->curr->next;
			digitCount--;
		}
		cout << "reversedValue: " << reversedValue << endl;
		if (reversedValue < -pow(2, 31) || reversedValue > pow(2, 31) - 1)
		{
			reversedValue = 0;
		}
		return reversedValue;
	}

private:
	Node* curr = nullptr;
	Node* next = nullptr;
	Node* head = nullptr;
};
class Solution {
public:
	int reverse(int x) {
		if (x == std::numeric_limits<int>::min()) //! if the result is -2147483648, then number would overflow. this solves it somehow
		{                                         //! Visual studio compiler, however, doesnt tolerate that number passing as int
			return 0;
		}
		double _x = x;
		bool negative = false;
		if (_x < 0) { negative = true; _x = _x * -1; }  //!  Find out if x is negative 
		//?  Step 1: find the number of digits
		int digitCount = 1;
		int32_t tempX = _x;   //duplicate x for calculation
		int32_t tempX2 = _x;  //duplicate x for calculation
		int32_t tempX3 = _x;  //duplicate x for calculation

		while (tempX >= 10)   //! Find digitCount
		{
			tempX = tempX / 10;
			digitCount++;
		}
		//?  Step 2:  Find the first digit and add it to linked list
		int result = 0;
		LinkedList* list = new LinkedList();
		for (int i = 0; i < digitCount; i++)
		{
			int oneDigit = tempX3 % 10;


			list->addNode(oneDigit);

			tempX3 = tempX3 / 10;
			if (tempX3 < 1) { continue; }
		}
		result = list->getReverseValue(list);
		if (negative)
		{
			result = result * -1;
		}
		cout << "result: " << result << endl;
		if (result < -pow(2, 31) || result > pow(2, 31) - 1)
		{
			result = 0;
		}
		return result;
	}

};



int main()
{
	Solution solution;

	solution.reverse(-34563456);
	system("PAUSE");
}


