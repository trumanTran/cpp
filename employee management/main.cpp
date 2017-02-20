/**************************************************************************************
Title: 			TRAN.hw2 (main.cpp)
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
 #include "employeeManager.h"
 
 using namespace std;
 	
 int main()
 {
	 employeeManager EM;
		//Created a class that will run the employee manager system
	 EM.run();
		//Most of everything runs in employeeManager.cpp
	 
	 return 0;
 } 
 
 