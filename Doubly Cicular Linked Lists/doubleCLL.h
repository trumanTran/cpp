/*********************************************************************************************
Title: 			TRAN.assignment3 (doubleCLL.h)
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

using namespace std;


#ifndef doubleCLL_H
#define doubleCLL_H

		
class doubleCLL
{
	private:
	
		struct node
		{
			int data;
			struct node *next;
			struct node *prev;
		}*start, *end;
		
		int counter = 0;
			//used to keep count nodes being added to the list
		
    public:
	
		//Constructor
		doubleCLL();
		
		//Destructor 
		~doubleCLL();
		
		//Other Functions
        node *createNode(int);
			//createNode - allocates memory for node dynamically 
			//@param value - value of data for new node
        void insertBegin(int);
			//insertBegin - inserts new node in beginning of list 
			//@param value - value of data for new node
        void insertLast(int);
			//insertLast - inserts new node at the end of the list
			//@param value - value of data for new node
        void insertPos(int, int);
			//insertPos - inserts new node at position chosen by user
			//@param value - value of data for new node
			//@param pos - position user wishes node to be placed 
        void remove(int);
			//remove - removes specified node
			//@param pos - position of node user wishes to remove
		void clear();
			//clear - clears all nodes 
        void search(int);
			//search - goes through entire list to find desired value (if value exists within list)
			//@param value - value user wishes to search for within list
		bool isEmpty();
			//isEmpty - determines whether list is empty 
		int size();
			//size - finds size of list
        void display();
			//display - displays all values within list

		
};


#endif

