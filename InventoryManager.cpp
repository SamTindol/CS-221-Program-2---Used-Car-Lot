// INventoryManager.cpp Thsi file contains the insides of our liked list class functions
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#include "InventoryManager.h"
#include <iostream>
using namespace std;

// Blank default constructor
InventoryManager::InventoryManager()
{

}

// Constructor with arguments
InventoryManager::InventoryManager(int myMaxItems)
{
	head = NULL;
	curPos = NULL;
	maxItems = myMaxItems;
	length = 0;

	if (myMaxItems < 1)
	{
		maxItems = MAXITEMS;
	}

	cout << "Welcome to the Grease Lightning Car Lot from Sam Tindol!" << endl << endl;
}

// Destructor
InventoryManager::~InventoryManager()
{
	if (head != NULL) {
		delete head;
		head = NULL;
	}
	
	if (curPos != NULL)
	{
		delete curPos;
		curPos = NULL;
	}
}

// Put Item function will put new Item at the front of the list.
bool InventoryManager::PutItem(ItemType* ITptr)
{
	bool result = false;
	bool found;
	
	// Calling GetItem to populate the found bool
	GetItem(ITptr, found);

	ItemType* thisItem = NULL;
	Node* newNode = NULL;

	if (ITptr != NULL && IsFull() == false && found != true) {
		newNode = new Node(*ITptr);

		newNode->SetNext(head);
		head = newNode;

		// This is allowing us to read the data so we can print it to the screen
		thisItem = new ItemType(*ITptr);

		length++;
		result = true;
		cout << "Added       ";
		thisItem->PrintInfo();
		cout << "at: " << newNode << endl << endl;
	}
	else if (found == true)
	{
		cout << "Already exists" << endl << endl;
	}

	delete thisItem;
	thisItem = NULL;
	return result;
}

// Get Item unction will return a copy of the Item Type and populate the found variable
ItemType* InventoryManager::GetItem(ItemType* ITptr, bool& found)
{
	ResetList();
	ItemType *result = NULL;
	ItemType* myItem = new ItemType;
	string description;
	string equality = "Undefined";
	found = false;

	cout << "\nSearchig...   ";

	while (curPos != NULL && equality != "EQUAL" && ITptr != NULL)
	{
		// Gets the data so we can rpint it to the screen as we search
		*myItem = curPos->GetItem();
		cout << myItem->GetData(description) << ", ";
		equality = curPos->GetItem().Compare(ITptr);

		if (equality != "EQUAL")
		{
			curPos = curPos->Next();
		}
	}
	cout << endl << endl;

	if (equality == "EQUAL" && curPos != NULL)
	{
		// Creates a copy of our item type that will be returned by the function
		result = new ItemType(curPos->GetItem());
		cout << "Item found" << endl;
		found = true;
	}

	return result;

}

// The DeleteItem function will delete the item given by the argument.
bool InventoryManager::DeleteItem(ItemType* ITptr)
{
	ResetList();
	bool found = false;
	Node* previous = curPos;
	ItemType *myItem = new ItemType;
	string description;
	
	while (ITptr != NULL && curPos != NULL && found != true)
	{
		*myItem = curPos->GetItem();

		// Extra check if we are deleting the item in the node that is pointed to by the head. If so, we need to change the head
		if (myItem->GetData(description) == ITptr->GetData(description) && curPos == head)
		{
			found = true;
			head = head->Next();
		}

		else if (myItem->GetData(description) == ITptr->GetData(description) && curPos != head)
		{
			cout << "Deleted Item: " << myItem->GetData(description) << ", " << description << "     at: " << curPos << endl << endl;
			previous->SetNext(curPos->Next());
			found = true;
		}
		previous = curPos;
		curPos = curPos->Next();

	} 
	
	delete myItem;
	myItem = NULL;

	return found;
}

// This function will move the current position pointer back to the head
void InventoryManager::ResetList()
{
	curPos = head;
}

// This function will test if the list is full
bool InventoryManager::IsFull()
{
	return(length == maxItems);
}

// This function will travese the list deleting each node as it goes along.
void InventoryManager::MakeEmpty()
{
	ResetList();
	Node* temp = NULL;

	while (head != NULL)
	{
		temp = head;
		head = head->Next();
		delete temp;
		temp = NULL;
	}
	cout << "\nThe end of the list has been reached and has been made empty" << endl;
}

// This function will print the contents of the linked list
void InventoryManager::PrintList()
{
	Node* index = NULL;
	ResetList();
	ItemType* myItem = new ItemType;
	
	while (curPos != NULL)
	{
		*myItem = curPos->Node::GetItem();
		myItem->PrintInfo();
		cout << "at: " << curPos << endl;
		curPos = curPos->Next();
	}
	delete index;
	index = NULL;
}

// This function will increment the curPos pointer and return it
Node* InventoryManager::GetNext()
{
	Node* result = NULL;

	// If curPos is null we will not get the next.
	if (curPos == NULL)
	{
		result = NULL;
	}
	
	// If GetNext is called after a ResetList(), it will return the head and increment
	else if (curPos == head)
	{
		result = head;
		curPos = curPos->Next();
	}

	// If it is neither of the conditions above, it we will return the curPos pointer and get the next.
	else if (curPos != NULL && curPos != head)
	{
		curPos = curPos->Next();
		result = curPos;
	}
	
	return result;
}

// This function will return the length member variable
int InventoryManager::GetLength()
{
	return length;
}