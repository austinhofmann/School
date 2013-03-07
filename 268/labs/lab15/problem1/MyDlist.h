#ifndef MYDLIST_H
#define MYDLIST_H

#include "DNode.h"
#include <iostream>

using namespace std;

template <typename T>
class MyDlist
{
	private: 
		DNode<T> * front;
		DNode<T> * back;
		int size;
	public: 
		MyDlist();
		MyDlist(MyDlist<T> & oList);
		~MyDlist();
		void remove(int index);
		void push_back(T value);
		void insert(T value, int index);
		int getSize();
		bool isEmpty();
		DNode<T> * getNode(int index);
		string toString();
		string toRString();
		T getElement(int index);
		const MyDlist<T> operator =(MyDlist &);
		//string toRString();
};

#include "MyDlist.cpp"
#endif