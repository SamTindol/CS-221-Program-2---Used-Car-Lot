// Program 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "InventoryManager.h"
//#include "Node.h"
//#include "ItemType.h"

int main()
{
    string description = "BA 1965 Mustang GT Fastback";
    long long int VIN = 48383829922;

    InventoryManager* carList = new InventoryManager(7);
    ItemType* item1 = NULL;
    item1 = new ItemType(description, VIN);
    ItemType* item2 = new ItemType("2015 Hyundai Sonata", 1231214312142);
    ItemType* item3 = new ItemType("2009 Hyundai Elantra", 4542353734373537);
    ItemType* item4 = new ItemType("2011 Hyundai Santa Fe", 123456765432132);
    ItemType* item5 = new ItemType("2001 Dodge Dakota", 3135241534262);

    carList->PutItem(item1);
    //system("pause");
    carList->PutItem(item2);
    //system("pause");
    carList->PutItem(item3);
    //system("pause");
    carList->PutItem(item4);
    //system("pause");
    carList->PutItem(item5);
    //system("pause");
    cout << "\n*****************************************" << endl;
    cout << "Calling Print List" << endl << endl;
    carList->PrintList(); //
    //system("pause");
    cout << endl << endl;
    //carList->DeleteItem(item4);
    //carList->PrintList();
    carList->MakeEmpty();
    carList->PutItem(item2);
    carList->PrintList();

    //carList->MakeEmpty();
    //carList->PutItem(item1);
    //carList->PrintList();
    delete carList;
    //system("pause");
    carList = NULL;

    system("pause");
    return 0;

}
