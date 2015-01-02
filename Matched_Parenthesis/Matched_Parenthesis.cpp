// Matched_Parenthesis.cpp : Defines the entry point for the console application.
//

//	A matched string is a sequence of {, }, (, ), [, and] characters
//	that are properly matched.For example, “{{()[]}}” is a matched string, but
//	this “{{()]}” is not, since the second { is matched with a ].Show how to
//	use a stack so that, given a string of length n, you can determine if it is a
//	matched string in O(n) time.

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	(void)argc;
	(void)argv;

	string			inputString;
	stack<char>		stkParenthesis;
	map<char, int>	valueMap;

	valueMap.insert( std::pair<char, int>('[', 1) ); valueMap.insert( std::pair<char, int>('{', 2) ); valueMap.insert( std::pair<char, int>('(', 3) );
	valueMap.insert( std::pair<char, int>(']', -1) ); valueMap.insert( std::pair<char, int>('}', -2) ); valueMap.insert( std::pair<char, int>(')', -3) );

	/// Accept input string.
	getline(cin, inputString);

	//cout << inputString << endl;

	// prepare a stack from the the strings
	for (unsigned int i = 0; i < inputString.size();++i)
	{
		if (stkParenthesis.empty())
			stkParenthesis.push(inputString[i]);
		else
		{
			if ( valueMap[inputString[i]] > 0 )
				stkParenthesis.push(inputString[i]);
			else
			{ // Evaluate the correctness of parenthesis
				char top;

				top = stkParenthesis.top();
				
				if (valueMap[top] + valueMap[inputString[i]] == 0) // matching parenthesis
					stkParenthesis.pop();
				else
				{
					cout << "String contains non matching parenthesis" << endl;
					break;
				}
			}
		}
	}

	if (stkParenthesis.empty())
		cout << "String contains All matching parenthesis" << endl;

	cout << "Press any key to terminate..." << endl;
	getchar();
	return 0;
}

