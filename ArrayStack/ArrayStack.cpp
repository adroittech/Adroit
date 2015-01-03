// ArrayStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

#define max(a,b)	a>b?a:b

using namespace std;

template<typename T>
struct Array
{
	T*		arr;
	int		length;
	
	Array()
	{
		arr = new T[2];
		length = 2;
	};
	Array(int size)
	{
		arr = new T[size];
		length = size;
	};
	~Array()
	{
		//if (arr) delete[] arr;
	};

	T& operator[](int n)
	{
		if (n >= 0 && n < length)
			return arr[n];
	}
	Array<T>& operator=(Array<T>& other)
	{
		if (this->arr) delete[] this->arr;

		arr = other.arr;
		other.arr = NULL;
		this->length = other.length;

		return *this;
	}
};

template<typename T>
struct ArrayStack
{
	ArrayStack() :n(0) {}
	~ArrayStack()
	{
		//
	}

private:
	Array<T>		a;
	int				n;

	T Get(int i)
	{
		if (i >= 0 && i < n)
		{
			return a[i];
		}
	}
	void Set(int i, T t)
	{
		if (i >= 0 && i < n)
		{
			a[i] = t;
		}
	}
	void Add(int i, T t)
	{
		if (n + 1 > a.length)
			Resize();

		// Traditional Way : for loop
		//for (int j = n; j > i; --j)
		//	a[j] = a[j - 1];

		// Fase Way using std :: copy 
		//copy_backward(a.arr + i, a.arr + n, a.arr + n + 1);
		copy(a.arr + i, a.arr + n, a.arr + i - 1);

		a[i] = t;
		
		++n;
	}
	void Remove(int i)
	{
		for ( int j = i; j < n ; ++j )
		{
			a[j] = a[j + 1];
		}
		--n;

		if (a.length > 3*n)
			Resize();
	}
	void Resize()
	{
		Array<T> b(max(2 * n, 1));

		// Traditional Copy using for loop
		//for (int i = 0; i < n; ++i)
		//	b[i] = a[i];

		// fast copy using std::copy
		std::copy(a.arr, a.arr+n, b.arr);

		a = b;
	}

public:
	int Size(){ return n; }
	bool empty()
	{
		if (n == 0)
			return true;
		else
			return false;
	}
	void push(T t)
	{
		Add(n, t);
	}
	void pop()
	{
		Remove(n - 1);
	}
	T top()
	{
		return Get(n - 1);
	}
};

typedef struct
{
	int		id;
	float	idx;
	string	name;
}Node;


int _tmain(int argc, _TCHAR* argv[])
{
	/// Practice - 2
	fstream				fs;
	string				str;
	ArrayStack<string>	lines;
	
	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs, str);
			lines.push(str);
		}
	}

	while (!lines.empty())
	{
		string str = lines.top();
		cout << str << endl;
		lines.pop();
	}

	/// Practice - 2 - Custon DS
	ArrayStack<Node*>	nodes;

	for (int j = 0; j < 10; ++j)
	{
		nodes.push(new Node{j,(float)j, "<<<----->>>" });
	}

	while (!nodes.empty())
	{
		Node* node = nodes.top();
		cout << node->id << " - " << node->idx << " - " << node->name << endl;
		nodes.pop();
	}

	cout << "Press enter to exit..." << endl;
	getchar();

	return 0;
}

