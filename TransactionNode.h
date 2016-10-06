#pragma once
#include "Node.h"

class TransactionNode : public Node
{
	int mUnits;
public:
	TransactionNode(int newUnits = 0, string newData = "");
	~TransactionNode();

	//setters
	void setUnits(const int newUnits);

	//getters
	int getUnits() const;

	//pure virtual
	void printData();
};
