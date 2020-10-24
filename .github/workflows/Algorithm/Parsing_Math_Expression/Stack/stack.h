#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <sstream>
#include <stdlib.h>

using namespace std;

template<typename DataType>
class StackNode
{
public:
	DataType data;
	StackNode *link = NULL;

public:
	StackNode<DataType>()
	{
		link = NULL;
	}
};

template<typename DataType>
std::string cout2string(const DataType& X)
{
    ostringstream strs;
    strs << X;
    return strs.str();
}

template<typename DataType>
class Stack
{
	friend ostream & operator <<(ostream &o, const Stack<DataType>& X)
	{
		Stack<DataType> S1;
		Stack<DataType> S2;
		S1 = X;
		S2 = X;

		o << endl << endl;

		if( S1.empty() )
		{
			o << "| (void) |" << endl;
			o << "----------" << endl;
		}
		else
		{
			DataType longest_element = S1.pop();
			string longest_string = cout2string(longest_element);
			while( !S1.empty() )
			{
				DataType temp_element = S1.pop();
				string temp_string = cout2string(temp_element);
				if( temp_string.size() > longest_string.size() )
				{
					longest_string = temp_string;
				}
			}

			while(!S2.empty())
			{
				DataType temp_element = S2.pop();
				o << "| " << temp_element << " ";
				int i = 0;
				string temp_string = cout2string(temp_element);

				while(i != longest_string.size()-temp_string.size())
				{
					o << " ";
					i++;
				}

				o << "|" << endl;
			}
			o << "--";
			for(int i = 0; i < longest_string.size(); i++)
			{
				o << "-";
			}
			o << "--" << endl;
		}	

		return o;
	}

private:
	StackNode<DataType> *head;

public:
	Stack<DataType>();
	Stack<DataType>(const Stack<DataType>& X);
	~Stack<DataType>();
	Stack<DataType>& operator =(const Stack<DataType>& X);

	void clear();
	void push(DataType x);
	DataType pop();
	DataType top()const;
	bool empty()const;
	int length()const;
	Stack<DataType>& inverse();
};

#define STACK_REALIZE
#include "stack.cpp"

#endif
