#pragma once
#include "BST.h"
#include "TransactionNode.h"
#include "Node.h"

class DataAnalysis
{
	BST mTreeSold;
	BST mTreePurchased;
	ifstream csvFile;
	void openFile();

	void readFile();
	void insertDataFromFile(int units, string type, string transaction);
	void displayTree();
public:
	DataAnalysis();
	~DataAnalysis();

	//run program
	void runAnalysis();
};

