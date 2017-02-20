/**************************************************************************************
Title: 			TRAN.hw2 (employee.h)
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

#include <iostream>
#include <string>
using namespace std;

#ifndef employee_H
#define employee_H

class employee
{
	public:
		//default constructor
		employee();
		
		//overload constructor 
		employee(string, string, string, string, string, string);
			//employee - constructor for creating employee object
			//@param string - ID number of employee 
			//@param string - Name of employee
			//@param string - Date of birth of employee
			//@param string - SSN of employee
			//@param string - Department employee works in 
			//@param string - Position employee works as
		
		//destructor 
		~employee();
		
		//getters 
		string getID() const;
			//getID - returns ID of employee
		string getName() const; 
			//getName - returns name of employee
		string getDateOfBirth() const;
			//getDateOfBirth - returns date of birth of employee
		string getSSN() const;
			//getSSN - returns SSN of employee 
		string getDepartment() const;
			//getDepartment - returns department of employee
		string getPosition() const;
			//get Position - returns position of employee
		
		//setter
		void setID(string);
			//setID - sets ID of employee
			//@param int - ID of employee
		void setName(string);
			//setName - sets name of employee
			//@param string - name of employee
		void setDateOfBirth(string);
			//setDateOfBirth - sets date of birth of employee
			//@param string - date of birth of employee
		void setSSN(string);
			//setSSN - sets SSN of employee
			//@param string - SSN of employee
		void setDepartment(string);
			//setDepartment - sets department of employee
			//@param string - department of employee 
		void setPosition(string);
			//setPosition - sets position of employee
			//@param string - position of employee			
		
		//other functions
		
			
	private: 
		//member variables
		string newID; 
		string newName; 
		string newDateOfBirth;
		string newSSN;
		string newDepartment;
		string newPosition;
};

#endif

