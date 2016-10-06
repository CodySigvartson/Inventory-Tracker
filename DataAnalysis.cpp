#include "DataAnalysis.h"

DataAnalysis::DataAnalysis()
{
}

DataAnalysis::~DataAnalysis()
{
}

//opens the .csv file to read from
void DataAnalysis::openFile()
{
	csvFile.open("data.csv", ios::in);
	if (csvFile.is_open())
	
	{
		readFile();
	}
	else
		cout << "Unable to open your file";
}

//reads the file one line at a time until EOF
void DataAnalysis::readFile()
{
		string header; //read in the header
		std::getline(csvFile, header);
		while (!csvFile.eof())
		{
			string units; //read in units
			std::getline(csvFile, units, ',');
			int numUnits = 0;
			numUnits = atoi(units.c_str()); //convert the string units to an int amount of units
			string type; //read in type
			std::getline(csvFile, type, ',');
			string transaction; //read in transaction
			std::getline(csvFile, transaction, '\n');
			insertDataFromFile(numUnits, type, transaction);
		}
}

//analyzes transaction type and inserts the units and type into the proper tree
void DataAnalysis::insertDataFromFile(int units, string type, string transaction)
{
	if (transaction == "Purchased") //if what was read from file was transaction type purchase, insert into purchase BST
	{
		mTreePurchased.insertInBST(units, type);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insertInBST(units, type);
	}
}

//displays the trees, least purchased and sold, most purchased and sold
void DataAnalysis::displayTree()
{
	cout << "Purchased information: " << endl;
	cout << "--------------------" << endl;
	cout << "Largest: " << endl;
	mTreePurchased.findLargest(mTreePurchased.getRoot());
	cout << "Smallest: " << endl;
	mTreePurchased.findSmallest(mTreePurchased.getRoot());
	cout << "All purchased units: " << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl;
	cout << "Sold information: " << endl;
	cout << "--------------------" << endl;
	cout << "Largest: " << endl;
	mTreeSold.findLargest(mTreeSold.getRoot());
	cout << "Smallest: " << endl;
	mTreeSold.findSmallest(mTreeSold.getRoot());
	cout << "All sold units: " << endl;
	mTreeSold.inOrderTraversal();
}

//runs entire program
void DataAnalysis::runAnalysis()
{
	openFile(); //open the file for reading
	readFile(); //read from file, insert into proper tree
	displayTree(); //dislay the smallest units/type and largest units/type
	csvFile.close(); //close the file
}