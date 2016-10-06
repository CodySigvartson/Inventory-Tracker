#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ostream;
using std::ios;

//The primary use of inheritance (in C++) is to define an interface in a base class, and implement that interface in each of a number of derived classes

class Node
{
public:
	Node(string newData = "");
	Node(Node &copy);
	virtual ~Node();

	//setters
	void setMpLeft(Node *&newMpLeft);
	void setMpRight(Node *&newMpRight);
	void setData(const string newData);

	//getters
	Node *& getMpLeft();
	Node *& getMpRight();
	string getData() const;

	virtual void printData() = 0;
protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};
