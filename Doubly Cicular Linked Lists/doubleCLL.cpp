/*********************************************************************************************
Title: 			TRAN.assignment3 (doubleCLL.cpp)
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

#include "doubleCLL.h"

doubleCLL::doubleCLL()
{
	start = NULL;
    end = NULL;	
}

doubleCLL::~doubleCLL()
{
	clear();	
}

//MEMORY ALLOCATION FOR NODE DYNAMICALLY

doubleCLL::node* doubleCLL::createNode(int value)
{
    counter++;  
    struct node *temp;
		//declare temp variable to create new node
    temp = new(struct node);
    temp -> data = value;
		//point temp to desired value 
    temp -> next = NULL;
		//point temp to next node
    temp -> prev = NULL;
		//point temp to previous node
    return temp;
}

//INSERT ELEMENT IN THE BEGINNING POSITION

void doubleCLL::insertBegin(int value)
{
    struct node *temp;
    temp = createNode(value);
    if (start == end && start == NULL)
		//should list be empty
    {    
        start = end = temp;
        start -> next = end -> next = NULL;
        start -> prev = end -> prev = NULL;
		cout << endl << "Element inserted in empty list" << endl;
    }
    else
    {
        temp -> next = start;
        start -> prev = temp;
        start = temp;
        start -> prev = end;
        end -> next = start;
        cout << endl << "Element inserted" << endl;
    }
}
 
//INSERT ELEMENT IN THE LAST POSITION

void doubleCLL::insertLast(int value)
{
	
    struct node *temp;
    temp = createNode(value);
    if (start == end && start == NULL)
    {
        cout<<"Element inserted in empty list"<<endl;
        start = end = temp;
        start -> next = end -> next = NULL;    
        start -> prev = end -> prev = NULL;
    }
    else
    {
        end -> next = temp;
        temp -> prev = end;
        end = temp;
        start -> prev = end;
        end -> next = start;
    }
}

//INSERT ELEMENT IN CHOSEN POSITION

void doubleCLL::insertPos(int value, int pos)
{    
    int i;
    struct node *temp, *s, *ptr;
    temp = createNode(value);
    if (start == end && start == NULL)
    {
        if (pos == 1)
        {
            start = end = temp;
            start -> next = end -> next = NULL;    
            start -> prev = end -> prev = NULL;
			cout << endl << "Element inserted" << endl;
        }
        else
        {
            cout << endl << "Position out of range"<<endl;
            counter--;
            return;
        }
    }  
    else
    {
        if (counter < pos)
        {
             cout << endl << "Position out of range" << endl;
             counter--;
             return;   		
        }
        s = start;		
        for (i = 1;i <= counter;i++)
        {
            ptr = s;
            s = s-> next;
            if (i == pos - 1)
            {
                ptr -> next = temp;
                temp -> prev = ptr;
                temp -> next = s;
                s -> prev = temp;
                cout << endl << "Element inserted" << endl;
                break;
            }
        }
    }
}

//DELETE ELEMENT IN CHOSEN POSITION

void doubleCLL::remove(int pos)
{    
    int i;
    node *ptr, *s;
    if (start == end && start == NULL)
    {
        cout << "List is empty, nothing to delete"<<endl;
        return;
    }
   
    if (counter < pos)
    {
        cout << "Position out of range" << endl;
        return;
    }
    s = start;
    if(pos == 1)
    {
        counter--;
        end -> next = s -> next;
        s -> next -> prev = end;
        start = s -> next;
        free(s);
        cout << "Element Deleted" << endl;
        return;	   
    }
    for (i = 0;i < pos - 1;i++ )
    {  
        s = s -> next;
        ptr = s -> prev;    	  
    }    
    ptr -> next = s -> next;
    s -> next -> prev = ptr;
    if (pos == counter)
    {
        end = ptr; 	   
    }
    counter--;
    free(s);
    cout << "Element Deleted" << endl;
}

//CLEAR ENTIRE LIST(REMOVE ALL NODES)

void doubleCLL::clear()
{
    node *pDel = start;
    
    //Traverse the list and delete the node one by one from the start
    for (int i = 0;i < counter-1;i++)
    {	
		start = start -> next;
			//set start to next node
        delete pDel;
			//delete node pDel(which was set to first node)
        pDel = start; 
			//reassign pDel to new start node
		
    }
    
    //Reset the start and end node
    end = start = NULL; 
	counter = 0;
		//counter is reset to 0
	
	cout << "List cleared " << endl;
}


//SEARCH FOR GIVEN ELEMENT IN LIST 

void doubleCLL::search(int value)
{
    int pos = 0, i;
    bool flag = false;
    struct node *s;
	
    if (start == end && start == NULL)
    {
        cout << endl << "The List is empty, nothing to search" << endl;
        return;
    }
   
    s = start;
    for (i = 0;i < counter;i++)
    {
        pos++;
        if (s-> data == value)
        {
            cout << endl << "Element " << value << " found at position: " << pos << endl;
            flag = true;
        }    
        s = s -> next;
    }
    if (!flag)
        cout << endl << "Element not found in the list" << endl;   
}

//DETERMINE WHETHER LIST IS EMPTY

bool doubleCLL::isEmpty()
{
	if (start == end && start == NULL)
    {
        return true;
    }
	
	else
	{
		return false;
	}		
}

int doubleCLL::size()
{
	return counter;	
}

//DISPLAY LIST

void doubleCLL::display()
{
    int i;
    struct node *s;
    if (start == end && start == NULL)
    {
        cout << endl << "The List is empty, nothing to display" << endl;
        return;
    }
    s = start;
	cout << endl;
    for (i = 0;i < counter-1;i++)
    {	
        cout << s -> data << " " ;
        s = s-> next; 
    }
    cout << s-> data << endl;
}
