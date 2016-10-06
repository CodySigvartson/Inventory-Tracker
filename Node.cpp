#include "Node.h"

Node::Node(string newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::Node(Node &copy)
{
	mData = copy.mData;
	mpLeft = copy.mpLeft;
	mpRight = copy.mpRight;
}

Node::~Node()
{
}

//setters
void Node::setMpLeft(Node *&newMpLeft)
{
	mpLeft = newMpLeft;
}

void Node::setMpRight(Node *&newMpRight)
{
	mpRight = newMpRight;
}

void Node::setData(const string newData)
{
	mData = newData;
}

//getters
Node *& Node::getMpLeft()
{
	return mpLeft;
}

Node *& Node::getMpRight()
{
	return mpRight;
}

string Node::getData() const
{
	return mData;
}

void Node::printData()
{
	cout << mData << endl;
}