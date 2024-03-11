// ItemType.h This file contains the member variables and prototypes of our item type class
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
class ItemType
{
private:
	string description = "";
	long long int VIN = 0;

	//const string DESCRIPTION = "Undefined Car";
	//const long long int CONSTVIN = 0;

public:
	ItemType();
	~ItemType();
	ItemType(string myDescription, long long int myVIN);
	string Compare(ItemType *ITptr);
	long long int GetData(string& myDescription);
	void PrintInfo();
};

