// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	int arr[] = {1,2,3};
	std::for_each(&arr[0], &arr[0]+sizeof(arr)/sizeof(arr[0]), [](int n) {std::cout << n << std::endl;});

	auto is_odd = [](int n) {return n%2==1;};
	auto begin = &arr[0];
	auto end = &arr[0]+sizeof(arr)/sizeof(arr[0]);
	auto pos = std::find_if(begin, end, is_odd);
	if(pos != end)
		std::cout << *pos << std::endl;

	return 0;
}

