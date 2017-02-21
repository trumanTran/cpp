/*********************************************************************************************
Title: 			TRAN.assignment3 (tranHW3.cpp)
Author: 		Trung Tran
Created on: 	November 17, 2015
Description: 	Implementation of doubly-linked circular list. Does the following:
					1) Insert- several different insert options 
						a)Insert in beginning of list
						b)Insert in end of list
						c)Insert in desired position
					 2) Remove - removes desired node from list
					 3) Contains - searches for desired item in list and gives node position
					 4) Is Empty - determines whether list is empty
					 5) Size - determines size of list
					 6) Display - displays entire list 
Build with:		Make
Usage:			Follow instructions given in options when running program
Purpose:		Practice with doubly-linked circular lists 
**********************************************************************************************/

#include <iostream>
#include<cstdio>
#include<cstdlib>

#include "doubleCLL.h"

using namespace std;

int main()
{
    int choice, value, pos;
    doubleCLL cdl;
	
    while (1)
    {
        cout << "\n****************************************"<<endl;
        cout << "Please Choose One of the Following Options"<<endl;
        cout << "\n****************************************"<<endl;     
		
        cout << "1.Insert at Beginning of List" << endl;
        cout << "2.Insert at End of List" << endl;
        cout << "3.Insert at Chosen Position" << endl;
        cout << "4.Remove at Chosen Position" << endl;
		cout << "5.Clear List" << endl;
        cout << "6.Search Element" << endl;
		cout << "7.Check to see if list is empty" << endl;
		cout << "8.Check Size of list" << endl;
        cout << "9.Display List" << endl;
        cout << "10.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
		
        switch(choice)
        {
        case 1:
			cout << endl << "Enter the element to be inserted in the beginning of list: ";
			cin >> value;
            cdl.insertBegin(value);
            break;
			
        case 2:
			cout << endl << "Enter the element to be inserted in the end of list: ";
			cin >> value;
            cdl.insertLast(value);
            break;   
			
        case 3:
			cout << endl << "Enter the element to be inserted: ";
			cin >> value;
			cout << endl << "Enter the position of element inserted: ";
			cin >> pos;
            cdl.insertPos(value, pos);
            break; 
			
        case 4:
			cout << endl << "Enter the position of element to be removed: ";
			cin >> pos;
            cdl.remove(pos);
            break;
			
		case 5:
			cdl.clear();
			break;
			
        case 6:
			cout << endl << "Enter the value to be searched: ";
			cin >> value;
            cdl.search(value);
            break;
			
		case 7:
		
            if(cdl.isEmpty() == true)
			{
				cout << endl << "List is empty " << endl;
			}
			else
			{
				cout << endl << "List is not empty " << endl;
			}
            break;
		
		case 8:
		
            cout << endl << "List contains " << cdl.size() << " elements" << endl;
            break;
			
        case 9:
            cdl.display();
            break;
			
        case 10:
            exit(1); 
			
        default:
            cout << endl << "Wrong choice. Try again" << endl;	
        }
    }
    return 0;
}



