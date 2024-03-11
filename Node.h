// Node.h This file contains our member pointers and prototype functions for our node class
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#pragma once
#include "ItemType.h"

class Node : public ItemType
{
private:
	ItemType* item = NULL;
	Node* next = NULL;

public:
	Node();
	Node(ItemType newItem);
	~Node();
	void SetNext(Node* Nptr);
	ItemType GetItem();
	Node* Next();
};

