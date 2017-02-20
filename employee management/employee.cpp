/**************************************************************************************
Title: 			TRAN.hw2 (employee.cpp)
Author: 		Trung Tran
Created on: 	July 22, 2015
Description: 	Creating an employee management system. From the two text files
				(details.txt & timelog.txt), users are able to do the following 
				three tasks: 1) look up employee details through ID number, name, 
				department, and position. 2) look up employee time logs via ID
				3) change employee information via ID number. Changes can be saved.
Purpose:		Practice with classes, vectors, reading from external files and saving
				changes onto the same files. 
***************************************************************************************/

#include "employee.h"

employee::employee()
{
	newID = "0";
	newDateOfBirth = "00/00/0000";
	newSSN = "000-00-0000";
	
}

employee::employee(string ID, string name, string dateOfBirth, string SSN, string department, string position )
{
	newID = ID;
	newName = name;
	newDateOfBirth = dateOfBirth;
	newSSN = SSN;
	newDepartment = department;
	newPosition = position;
}

employee::~employee()
{
	
}

string employee::getID () const
{
	return newID;
}

string employee::getName () const
{
	return newName;
}

string employee::getDateOfBirth() const
{
	return newDateOfBirth;
}

string employee::getSSN () const
{
	return newSSN;
}

string employee::getDepartment() const
{
	return newDepartment;
}

string employee::getPosition() const
{
	return newPosition;
}

void employee::setID(string ID)
{
	newID = ID;
}

void employee::setName(string name)
{
	newName = name;
}

void employee::setDateOfBirth(string dateOfBirth)
{
	newDateOfBirth = dateOfBirth;
}

void employee::setSSN(string SSN)
{
	newSSN = SSN;
}

void employee::setDepartment(string department)
{
	newDepartment = department;
} 

void employee::setPosition(string position)
{
	newPosition = position;
}