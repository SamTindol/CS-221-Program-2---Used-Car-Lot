// Node.cpp This file contains the insides of our node class functions
// For Program 2 Implementation
// Author: Samuel Tindol: This is entirely my work.
// email: st0135@uah.edu
// For: CS221-02, Spring 2024, Mrs. Delugach
// Using Compiler MVS 2022

#include "Node.h"

// Blank default constructor
Node::Node()
{

}

// Cinstructor with arguments
Node::Node(ItemType newItem)
{
	next = NULL;
	item = new ItemType(newItem);
}

// Destructor
Node::~Node()
{
	if (item != NULL)
	{
		delete item;
		item = NULL;
	}

	if (next != NULL)
	{
		delete next;
		next = NULL;
	}
}

// This function will set the next member pointer for the node we are in
void Node::SetNext(Node* Nptr)
{
	next = Nptr;
}

// This function will return the item pointer of the node we are in
ItemType Node::GetItem()
{
	return *item;
}

// This function will return the next pointer of the node we are in
Node* Node::Next()
{
	return next;
}