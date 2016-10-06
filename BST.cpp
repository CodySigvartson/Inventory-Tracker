#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	//call private function
	destroyTree(mpRoot);
}

void BST::setMpRoot(Node *newRoot)
{
	mpRoot = newRoot;
}

Node *& BST::getRoot()
{
	return mpRoot;
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::insertInBST(int mUnits, string mData)
{
	insertInBST(mpRoot, mUnits, mData); //calling private insert to protect root
}

TransactionNode & BST::findSmallest(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	//traverse tree to as far left as possible
	if (pMem->getMpLeft() != nullptr)
	{
		return findSmallest(pMem->getMpLeft());
	}
	cout << *(pMem);
		return *(pMem);
}

TransactionNode & BST::findLargest(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	//traverse tree to as far left as possible
	if (pMem->getMpRight() != nullptr)
	{
		return findLargest(pMem->getMpRight());
	}
	cout << *(pMem);
		return *(pMem);
}

//PRIVATE FUNCTIONS
void BST::destroyTree(Node *root)
{
	if (root != nullptr)
	{
		destroyTree(root->getMpLeft()); //go as far left as possible
		destroyTree(root->getMpRight()); //go as far right as possible
		delete root; //delete
	}
}

void BST::insertInBST(Node *& root, int mUnits, string mData)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root); //cast Node *root to TransactionNode which is now pMem

	//check for empty list
	if (root == nullptr)
	{
		//set root to first insert
		pMem = new TransactionNode(mUnits, mData);
		root = pMem;
	}
	else //tree is not empty
	{
		if (mUnits < pMem->getUnits())
		{
			//go left
			insertInBST(pMem->getMpLeft(), mUnits, mData);
		}
		else if (mUnits > pMem->getUnits())
		{
			//go right
			insertInBST(pMem->getMpRight(), mUnits, mData);
		}
	}
}

void BST::inOrderTraversal(Node *root)
{
	TransactionNode *pMem = dynamic_cast<TransactionNode *>(root);

	if (pMem != nullptr) 
	{
		inOrderTraversal(pMem->getMpLeft());
		cout << "Item: " << pMem->getData() << endl;
		cout << "Units: " << pMem->getUnits() << endl;
		inOrderTraversal(pMem->getMpRight());
	}
}

ostream & operator<<(ostream &lhs, TransactionNode & rhs)
{
	lhs << rhs.getData() << endl << rhs.getUnits() << endl;
	return lhs;
}