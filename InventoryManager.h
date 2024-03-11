// InventoryManager.hThis file contains our member pointers and variabes,
// and it contains our linked list class function prototypes.
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#pragma once
#include "Node.h"
class InventoryManager : public Node
{
private:
	Node* head = NULL;
	Node* curPos = NULL;
	int maxItems = 0;
	int length = 0;

	const int MAXITEMS = 10;

public:
	InventoryManager();
	InventoryManager(int myMaxItems);
	~InventoryManager();
	bool PutItem(ItemType* ITptr);
	ItemType* GetItem(ItemType* Itptr, bool &found);
	bool DeleteItem(ItemType* ITptr);
	void ResetList();
	bool IsFull();
	void MakeEmpty();
	void PrintList();
	Node* GetNext();
	int GetLength();
};

