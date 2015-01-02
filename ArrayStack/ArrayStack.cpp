// ArrayStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename T>
class Arrayinterface
{
	T		Get(int)	= 0;
	void	Set(int, T) = 0;

	void	Add(int, T) = 0;
	void	Remove(int) = 0;

	void	Resize() = 0;
};

template<typename T>
struct Array //: public Arrayinterface<T>
{
	T*		arr;
	int		length;
	int		actualLength;
	
	Array()
	{
		arr = new T[100];
		actualLength = length = 100;
	};
	Array(int size)
	{
		arr = new T[size];
		actualLength = length = size;
	};
	~Array()
	{
		if (arr) delete[] arr;
	};

	T& operator[](int n)
	{
		if (n >= 0 && n < actualLength)
			return arr[n]
	}

	Array<T>& operator=(const Array<T>& other)
	{
		if (this->arr) delete[] this->arr;

		arr = other.arr;
		other.arr = NULL;
		this->length = other.length;

		return *this;
	}

	T Get(int n)
	{
		if (n >= 0 && n < length)
		{
			return arr[n];
		}
	}

	void Set(int n, T t)
	{
		if (n >= 0 && n < length)
		{
			arr[n] = t;
		}
	}

	void Add(int n, T t)
	{
		if (n + 1 > length)
			Resize();

		for (int i = length; i > n; --i)
		{
			arr[i] = arr[i - 1];
		}
		arr[n] = t;
	}

	void Remove(int n)
	{
		if ()
	}

	void Resize()
	{

	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

