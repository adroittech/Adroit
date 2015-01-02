// Exercise_1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

#define LINES 5000

void OpenAFile(FILE * handle)
{
	// Put dummy data into the file
	// FILE* handle= NULL;
	handle = fopen("../Data/FileReadTest.data","a");
	if (handle)
		cout <<"File opened successfully" << endl;
	else
		cout <<"File opened Failed" << endl;

	fclose(handle);
}

void PutDataIntoFile()
{
	fstream fs;

	fs.open("../Data/FileReadTest.data", fstream::in | fstream::out | fstream::app);

	string str;
	str = "This is line number : ";
	for(int i=0 ; i<LINES ; ++i)
	{
		string finalstr;
		finalstr = str + to_string(i+1) + "\n" ;
		//cout << str.c_str() << endl;
		if(fs.good())
			fs.write( finalstr.c_str() ,finalstr.size());
	}

	fs.close();
}

void ReadDataFromFileAndPrintForwards()
{
	fstream fs;
	string str;

	fs.open("../Data/FileReadTest.data", fstream::in);
	if(fs)
	{
		while(fs.good())
		{
			getline(fs,str);
			cout << str;
		}
	}

	fs.close();
}

const char* ReadNextLine(fstream& fs)
{
	if(fs)
	{
		if(fs.good())
		{
			string str;
			getline(fs,str);
			return str.c_str();
		}
	}
	return "";
}

void printStackTopAndPop(stack<string>& stk)
{
	while (!stk.empty())
	{
		cout << stk.top() << endl;
		stk.pop();
	}
}

void ReadDataFromFileAndPrintBackwards()
{
	fstream fs;
	stack<string> stkFileLines;

	fs.open("../Data/FileReadTest.data", fstream::in);
	if(fs)
	{
		while (fs.good())
		{
			string str;
			getline(fs,str);
			//cout << str ; //ReadNextLine(fs);
			stkFileLines.push(str);
		}
	}

	/// Pop stack and print lines
	//while (!stkFileLines.empty())
	//{
	//	cout << stkFileLines.top() << endl;
	//	stkFileLines.pop();
	//}
	printStackTopAndPop(stkFileLines);
}

void ReadDataFromFileAndPrintBackwards50()
{
	fstream fs;
	stack<string> stkFileLines50;

	fs.open("../Data/FileReadTest.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			if (stkFileLines50.size() >= 50)
				printStackTopAndPop(stkFileLines50);

			string str;
			getline(fs, str);
			stkFileLines50.push(str);
		}

		printStackTopAndPop(stkFileLines50);
	}
}

void ReadDataFromFileAndPrintWithQueue42()
{
	fstream fs;
	queue<string> qList;

	fs.open("../Data/FileReadTestBlankLines.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			string str;

			getline(fs, str);

			qList.push(str);
			if (qList.size() > 43)
				qList.pop();

			if (str == "")
				cout << qList.front() << endl;
			else
				cout << str << endl;
		}
	}
}

void ReadDataFromFileAndPrintWithoutDuplicates()
{
	fstream fs;
	string str;

	set<string> setList;
	pair< set<string>::iterator , bool >	validator;

	fs.open("../Data/FileReadTestDup.data", fstream::in);
	if (fs)
	{
		// Approach 1 - order is not maintained
		//while (fs.good())
		//{
		//	getline(fs, str);
		//	setList.insert(str);
		//}

		//set<string>::iterator itr;
		//set<string>::iterator end = setList.end();

		//for (itr = setList.begin(); itr != end; ++itr)
		//{
		//	cout << *itr << endl;
		//}

		// Approach 2 - in the order it was added
		while (fs.good())
		{
			getline(fs, str);
			validator = setList.insert(str);

			if (validator.second)
				cout << *validator.first << endl;
		}
	}
}

void ReadDataFromFileAndPrintOnlyDuplicates()
{
	fstream fs;
	string str;
	
	unordered_set<string>						uSetList;
	pair<unordered_set<string>::iterator,bool>	validator;

	fs.open("../Data/FileReadTestDup.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs, str);
			validator = uSetList.insert(str);
			if (!validator.second)
			{
				cout << *validator.first << endl;
			}
		}
	}
}

struct cusrom_comparator
{
	bool operator()(const string& left, const string& right)
	{
		if (left.length() < right.length())
			return true;
		else if (left.length() > right.length())
			return false;
		else
		{
			if (left.compare(right) < 0)
				return true;
			else
				return false;
		}
	}
};

void ReadDataFromFileAndPrintLengthWiseWithoutDuplicates()
{
	fstream fs;
	string str;

	set<string, cusrom_comparator> sSetLines;
	//pair<set<string>::iterator, bool> validator;

	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs, str);
			sSetLines.insert(str);
		}
		set<string>::iterator end = sSetLines.end();
		for (set<string>::iterator itr = sSetLines.begin(); itr != end; ++itr)
		{
			cout << *itr << endl;
		}
	}
}

void ReadDataFromFileAndPrintLengthWiseWithDuplicates()
{
	fstream fs;
	string str;

	multiset< string , cusrom_comparator > mSetList;

	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs, str);
			mSetList.insert(str);
		}

		multiset<string>::iterator end = mSetList.end();
		for (multiset<string>::iterator itr = mSetList.begin(); itr != end; ++itr)
		{
			cout << *itr << endl;
		}
	}
}

void ReadDataAndPrintOddEven()
{
	fstream fs;
	string str;
	vector<string> odd, even;

	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		int i = 0;
		while (fs.good())
		{
			getline(fs, str);
			
			if (i % 2 == 0)
				even.push_back(str);
			else
				odd.push_back(str);
			++i;
		}

		for (unsigned int j = 0; j < even.size(); j++)
			cout << even[j] << endl;

		for (unsigned int k = 0; k < odd.size(); k++)
			cout << odd[k] << endl;
	}
}

void ReadDataAndPrintInRandomOrder()
{
	fstream						fs;
	string						str;
	unordered_multiset<string>			mSetList;
	unordered_multiset<string>::iterator	itr;

	fs.open("../Data/FileReadTestLengthWiseSort.data", fstream::in);
	if (fs)
	{
		while (fs.good())
		{
			getline(fs,str);
			mSetList.insert(str);
		}

		unordered_multiset<string>::iterator end = mSetList.end();
		for (itr = mSetList.begin(); itr != end; ++itr)
		{
			cout << *itr << endl;
		}
	}
}

int main(int argc, _TCHAR* argv[])
{
	cout << "Please Uncomment section in code to run an example" << endl;
	// Create file and put some data
	//FILE * handle=NULL;

	// OpenAFile(handle);

	// getchar();

	//if(handle)
	{
		//PutDataIntoFile();
	}
	// getchar();
	/// read that data in sequential order
	{
		// ReadDataFromFileAndPrintForwards();
	}
	// getchar();
	{
		/*	Read the input one line at a time and then write the lines out in
			reverse order, so that the last input line is printed first, then the
			second last input line, and so on.
		*/
		// Approach : read 1 line by 1 from physical file.

		// ReadDataFromFileAndPrintBackwards();
	}
	// getchar();
	{
		//  Read the first 50 lines of input and then write them out in reverse
		//	order.Read the next 50 lines and then write them out in reverse
		//	order.Do this until there are no more lines left to read, at which
		//	point any remaining lines should be output in reverse order.
		//	In other words, your output will start with the 50th line, then the
		//	49th, then the 48th, and so on down to the first line.This will be
		//	followed by the 100th line, followed by the 99th, and so on down to
		//	the 51st line.And so on.
		//	Your code should never have to store more than 50 lines at any given
		//	time.

		//  ReadDataFromFileAndPrintBackwards50();
	}
	// getchar();
	{
		//	Read the input one line at a time.At any point after reading the
		//	first 42 lines, if some line is blank(i.e., a string of length 0), then
		//	output the line that occurred 42 lines prior to that one.For example,
		//	if Line 242 is blank, then your program should output line 200.
		//	This program should be implemented so that it never stores more
		//	than 43 lines of the input at any given time.

		//	ReadDataFromFileAndPrintWithQueue42();
	}
	// getchar();
	{
		//	Read the input one line at a time and write each line to the output
		//	if it is not a duplicate of some previous input line.Take special care
		//	so that a file with a lot of duplicate lines does not use more memory
		//	than what is required for the number of unique lines.

		// ReadDataFromFileAndPrintWithoutDuplicates();
	}
	// getchar();
	{
		//	Read the input one line at a time and write each line to the output
		//	only if you have already read this line before. (The end result is that
		//	you remove the first occurrence of each line.) Take special care so
		//	that a file with a lot of duplicate lines does not use more memory
		//	than what is required for the number of unique lines.

		// ReadDataFromFileAndPrintOnlyDuplicates();
	}
	// getchar();
	{
		//  Read the entire input one line at a time.Then output all lines sorted by length,
		//  with the shortest lines ﬁrst.In the case where two lines have the same length,
		//  resolve their order using the usual sorted order
		//  Duplicate lines should be printed only once

		//	ReadDataFromFileAndPrintLengthWiseWithoutDuplicates();
	}
	// getchar();
	{
		// Do the same as the previous question except that duplicate lines should be 
		// printed the same number of times that they appear in the input.

		// ReadDataFromFileAndPrintLengthWiseWithDuplicates();
	}
	// getchar();
	{
		//	Read the entire input one line at a time and then output the 
		//	even numbered lines(starting with the ﬁrst line, line 0) 
		//	followed by the odd - numbered lines.

		//	ReadDataAndPrintOddEven();
	}
	// getchar();
	{
		//	Read the entire input one line at a time and randomly permute 
		//	the lines before outputting them.
		//	To be clear : You should not modify the contents of any line. 
		//	Instead, the same collection of lines should be printed, but in a random order

		//	ReadDataAndPrintInRandomOrder();
	}
	getchar();

	return 0;
}