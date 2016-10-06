#pragma once
#include "Node.h"
#include "TransactionNode.h"

class BST
{
	Node *mpRoot;
	void destroyTree(Node *root);
	void insertInBST(Node *& root, int mUnits, string mData);
	void inOrderTraversal(Node *root);
public:
	BST();
	~BST();

	//setters
	void setMpRoot(Node *newRoot);

	//getters
	Node *& getRoot();
	
	void inOrderTraversal();
	TransactionNode & findSmallest(Node *root);
	TransactionNode & findLargest(Node *root);
	void insertInBST(int mUnits, string mData);
};

ostream & operator<<(ostream &lhs, TransactionNode & rhs);

