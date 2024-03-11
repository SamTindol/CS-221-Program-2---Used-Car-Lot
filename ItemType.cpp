// ItemType.cpp This item contains our the insides of our item type class functions
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#include "ItemType.h"
#include <iostream>
#include <iomanip>

// Default Constructor
ItemType::ItemType()
{
	description = "Undefined Car";
	VIN = 0;
}

// Destructor
ItemType::~ItemType()
{
	description = "undefined Car";
	VIN = 0;
}

// Constructor with arguments
ItemType::ItemType(string myDescription, long long int myVIN)
{
	description = myDescription;
	VIN = myVIN;
}

// This function will compare the key value of the poiner to the VIN member variable. It will return a string based
// on whether the values are equal or not
string ItemType::Compare(ItemType* ITptr)
{
	string result = "";
	
	string dummy = "";

	long long int key = 0;

	if (ITptr != NULL) {
		key = ITptr->GetData(dummy);
		if (key > VIN)
		{
			result = "GREATER";
		}

		else if (key < VIN)
		{
			result = "LESS";
		}
		else
		{
			result = "EQUAL";
		}
	}

	return result;
}

// This function will return the VIN of the item we are in and will populate the description variable as a pass by reference
long long int ItemType::GetData(string& myDescription)
{
	myDescription = description;
	return VIN;
}

// This function will print the VIN and description based on what item we are in.
void ItemType::PrintInfo()
{
	cout << VIN << ", " << left << setw(35) <<  description;
}