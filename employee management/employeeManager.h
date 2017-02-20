/**************************************************************************************
Title: 			TRAN.hw2 (employeeManager.h)
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
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "employee.h"
#include "timeLog.h"
 
using namespace std;

#ifndef employeeManager_H
#define employeeManager_H

class employeeManager
{
	public:
		//default constructor
		employeeManager();
		
		//destructor 
		~employeeManager();
		
		//other functions
		void run();
			
			
	private: 
		//member variables
		 vector <employee> abcCorp;
		 vector <timeLog> employeeTimes;
		 
		 //functions to use within class
		 void fillEmployeeDetails();
			 //fillEmployeeDetails - fills in details (ID, Name, DoB, SSN, Department, Position) of all employees in company 
		 void fillEmployeeTimeLogs();
			 //fillEmployeeTimeLogs - fills in time logs of all employees in the company
		 void mainMenu();
			 //mainMenu - displays the main menu of Employee Management System
		 void searchEmployee();
			 //searchEmployee - displays menu and interface for searching employee
		 void viewTimeLogs();
			//viewTimesLogs - interface for searching employee via ID to view date and times they clocked in and out of work
		 void updateInfo();
			//updateInfo - interface for changing employee information, which includes name, SSN, DOB, department and position
		 void saveAndExit();
			//saveAndExit - function called to save updated information and exit the program
		
};

#endif