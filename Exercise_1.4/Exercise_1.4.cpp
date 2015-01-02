//	Exercise_1.4.cpp : Defines the entry point for the console application.
//

//	Suppose you have a Stack, s, that supports only the push(x) and pop() operations.
//	Show how, using only a FIFO Queue, q, you can reverse the order of all elements in s.


#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

typedef struct
{
public:
	int		id;
	char*	name;
	string	address;
}Node;

int _tmain(int argc, _TCHAR* argv[])
{
	stack<Node*> nodes;
	queue<Node*> nodeQueue;

	////////// Prepare stack of 10 nodes ///////////
	cout << "Stack --> ";
	for (int i = 0; i < 10; ++i)
	{
		nodes.push(new Node{ i, "Dummy", "Address" });
		cout << nodes.top()->id;
	}
	cout << endl;

	/////////// Iterate and fill in a queue /////////
	while (!nodes.empty())
	{
		nodeQueue.push(nodes.top());
		nodes.pop();
	}

	//////////// Make a new stack from this queus //////
	cout << "Stack --> ";
	while (!nodeQueue.empty())
	{
		nodes.push(nodeQueue.front());
		cout << nodes.top()->id;
		nodeQueue.pop();
	}
	cout << endl;

	cout << "Press Enter to exit..." << endl;
	getchar();
	return 0;
}

