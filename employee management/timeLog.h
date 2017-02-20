/**************************************************************************************
Title: 			TRAN.hw2 (timeLog.h)
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
#include <vector>
#include <iomanip>
using namespace std;

#ifndef timeLog_H
#define timeLog_H

class timeLog
{
	public:
		//default constructor
		timeLog();
		
		//destructor 
		~timeLog();
		
		//getters 
		string getID() const;
			//getID - returns ID of employee
		vector <string> getDates(); 
			//getDates - returns dates employee went to work
		vector <int> getClockIns();
			//getClockIns - returns times employee clocked into work
		vector <int> getClockOuts();
			//getClockOuts - returns times employee clocked out of work 
		
		//setter
		void setID(string);
			//setID - sets ID of employee
			//@param int - ID of employee
		void addDate(string);
			//addDate - adds date employee went to work
			//@param string - date employee went to work
		void addClockIn(int);
			//addClockIn - adds time employee clocked into work
			//@param int - time employee clocked into work
		void addClockOut(int);
			//addClockOut - adds time employee clocked out of work
			//@param int - time employee clocked out of work
		
		//other functions
		void displayTimeLogs();
			//displayTimeLogs - will display daily clock in and clock out times as well as total hours worked for the day for specific employee
		double totalHoursWorked();
			//totalHoursWorked - gives the total number of hours employee worked at company during his/her time here
			//@param double - total number of hours worked
		
		
	private: 
		//member variables
		string newID; 
		vector <string> newDates;
		vector <int> newClockIns;
		vector <int> newClockOuts;
		vector <double> dailyHoursWorked;
		
		//other fuctions 
		void hoursWorked();
			//hoursWorked - calculate number of hours worked within a day 
		
			
};

#endif