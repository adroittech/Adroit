// Set.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main(int argc, _TCHAR* argv[])
{
	typedef set<int> MySet;
	//typedef unordered_set<int> MySet;
	MySet mySet;

	for(int i =0;i<100;i+=10)
	{
		mySet.insert(i);
	}

	MySet::iterator itr;
	MySet::iterator end = mySet.end();
	for ( itr=mySet.begin()	; itr!=end ; ++itr )
		cout << *itr << " ";

	cout << endl;

	if(mySet.find(30) != mySet.end())
	{
		cout << "Item found " <<endl;
	}
	else
		cout << "Item Not found " <<endl;

	getchar();

	return 0;
}