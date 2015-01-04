// std-copy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool fun(string s)
{
	int x = stoi(s);
	return (x % 2 == 1);
}

string fun2(string s)
{
	int x = stoi(s);
	if (x % 2 == 1)
		return s;
	else
		return "";
}
int _tmain(int argc, _TCHAR* argv[])
{
	string	numbers[]	= {"0","1","2","3","4","5","6","7","8","9"};
	string	numbers2[]	= {"0","0","0","0","0","0","0","0","0","0"};

	// uncomment any of the following
	// std::copy , std::copy_backward
	
	//copy(numbers, numbers + 4, numbers2 + 1);
	
	// in copy_backeards copy starts from *(result-1) :S which is stragne and by standard
	//copy_backward(numbers, numbers + 4, numbers2 + 5);

	//auto newLast = copy_if(numbers, numbers + 10, numbers2, fun);

	// copy_n(numbers, 7, numbers2);

	//auto it = find_if(numbers, numbers+9, fun);
	//std::cout << "The first Even value is " << *it << '\n';

	//move(numbers, numbers + 4, numbers2 + 1);

	//std::transform(numbers, numbers + 10, numbers2, fun2);

	for (string& x1 : numbers) cout << x1 << " ";
		cout << endl;
	for (string& x2 : numbers2) cout << x2 << " " ;
		cout << endl;

	cout << "Press enter to exit ... " << endl;
	getchar();
	return 0;
}

