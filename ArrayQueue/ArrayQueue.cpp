// ArrayQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
struct Array
{
	T*		arr;
	int		length;
	Array()
	{
		arr = new T[10];
		length = 10;
	}
	Array(int size)
	{
		arr = new T[size];
		length = size;
	}
	~Array()
	{
		if (arr) delete[] arr;
	}

	T& operator[](int x)
	{
		if (x >= 0 && x < length)
			return arr[x];
	}
	
	Array<T>& operator=(Array<T>& other)
	{
		if (arr) delete[] arr;

		arr = other.arr; length = other.length;
		other.arr = NULL; other.length = 0;

		return *this;
	}
};

template<typename T>
struct ArrayQueue // implementing queue as a infinite dynamic array
{
	Array<T>	a; 
	int			n; // end index of the queue
	int			j; // start index of the queue

	ArrayQueue() :n(0), j(0) {};
	ArrayQueue(int x) : n(0), j(0), a(x) {};

	void add(T x)
	{
		if (n + 1 > a.length) resize();

		a[(j + n) % a.length] = x;
		n++;
	}

	void remove()
	{
		j = (j+1) % a.length;
		n--;
		if (a.length >= 3 * n) resize();
	}

	void resize()
	{
		Array<T> b(max(2*n,1));
		for (int i = 0; i < n; i++)
			b[i] = a[(j + i) % a.length];
		a = b;
		j = 0;
	}

	T&	get(int i=0)
	{
		return a[(j + i) % a.length];
	}

	void  set(int i,T x)
	{
		a[(j + i) % a.length] = x;
	}

public:

	bool empty(){ return n > 0 ? false : true; }
	int	 size(){ return (j+n); }

	T&	back()
	{
		return get(n);
	}
	T&	front()
	{
		return get(0);
	}

	void pop()
	{
		remove();
	}

	void push(T x)
	{
		add(x);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	fstream				fs;
	string				str;
	ArrayQueue<string>	myQueue;

	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs, str);
			myQueue.push(str);
		}

		while (!myQueue.empty())
		{
			string item = myQueue.front();
			cout << item << endl;
			myQueue.pop();
		}
	}

	cout << "Press enter to exit..." << endl;
	getchar();
	return 0;
}

