/**************************************************************************************
Title: 			TRAN.hw2 (timeLog.cpp)
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

#include "timeLog.h"

timeLog::timeLog()
{
	newID = "0";
	
}

timeLog::~timeLog()
{
	
}

string timeLog::getID() const
{
	return newID;
}

vector <string> timeLog::getDates()
{
	return newDates;
}

vector <int> timeLog::getClockIns()
{
	return newClockIns;
}

vector <int> timeLog::getClockOuts () 
{
	return newClockOuts;
}

void timeLog::setID(string ID)
{
	newID = ID;
}

void timeLog::addDate(string date)
{
	newDates.push_back(date);
		//this will add any date employee has worked at the company
}

void timeLog::addClockIn(int timeIn)
{
	newClockIns.push_back(timeIn);
		//add any time the employee clocked into work
}

void timeLog::addClockOut(int timeOut)
{
	newClockOuts.push_back(timeOut);
		//add any time the employee clocked out of work
}


void timeLog::hoursWorked()
{
	for(unsigned int i = 0; i < newClockIns.size();i++)
	{
		int hr_clockIn = newClockIns[i] / 100;
		int hr_clockOut = newClockOuts[i] / 100;
		// to extract hr from XXYY 

		int min_clockIn = newClockIns[i] % 100;
		int min_clockOut = newClockOuts[i] % 100;
		// to extract min from XXYY 

		double diffMin, diffHr, minToHour, completeTime;
		
		if (min_clockOut > min_clockIn)
		{
			diffMin = min_clockOut - min_clockIn;
		}
		else
		{
			diffMin = (min_clockOut + 60) - min_clockIn;
			hr_clockOut--;
				// because we are borrowing 60 min from hr_clockOut
		}
		minToHour = diffMin/60;
			//converting minutes to hour format
		diffHr = hr_clockOut - hr_clockIn;
		completeTime = diffHr + minToHour;
		
		dailyHoursWorked.push_back(completeTime);
	}
}

void timeLog::displayTimeLogs()
{
	hoursWorked();
		//call hoursWorked function to fill out the vector of hours worked for that specific employee
	for(unsigned int i = 0; i < newDates.size(); i++ )
		{
			cout << newDates[i] << " ";
			cout << setfill('0') << setw(4) << newClockIns[i] << " " 
			<< newClockOuts[i] << " " << 
			fixed << setprecision(2) << dailyHoursWorked[i] << endl;
		}
	dailyHoursWorked.clear();
		//clear vector so that it doesn't interfere with other functions
}

double timeLog::totalHoursWorked()
{
	hoursWorked();
		//call hoursWorked function to fill out the vector of hours worked for that specific employee
	double totalHours = 0;
	for(unsigned int i = 0; i < dailyHoursWorked.size(); i++)
	{
		totalHours += dailyHoursWorked[i];
	}
	dailyHoursWorked.clear();
		////clear vector so that it doesn't interfere with other functions
	return totalHours;
	
}