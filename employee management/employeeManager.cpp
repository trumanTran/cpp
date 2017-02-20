/**************************************************************************************
Title: 			TRAN.hw2 (employeeManager.cpp)
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

#include "employeeManager.h"

employeeManager::employeeManager()
{
	
}

employeeManager::~employeeManager()
{
	
}

void employeeManager::run()
{	
	 fillEmployeeDetails();
		//call function to fill vector of all employees and their details
	 fillEmployeeTimeLogs();
		//call function to fill vector of all clock ins and clock outs of each employee 
	 
	 mainMenu();
}

void employeeManager::fillEmployeeDetails()
{
	 ifstream employeeDetails("details.txt"); 
	 
	 if(employeeDetails)
	 {
		 string employeeID;
		 string employeeName;
		 string employeeDOB;
		 string employeeSSN;
		 string employeeDepartment;
		 string employeePosition;
		 
		 while(employeeDetails >> employeeID >> employeeName >> employeeDOB >> employeeSSN >> employeeDepartment >> employeePosition)
		 {
			employee shell(employeeID, employeeName, employeeDOB, employeeSSN, employeeDepartment, employeePosition);
				//creating the shell of what to place inside for each employee 
			abcCorp.push_back(shell);
				//filling up the array with every employee recorded on the details.txt

		 } 
		 
		 employeeDetails.close();
	 }
	 else
		//should the file be missing
	 {
		 cerr << endl << "File 'details.txt' could not be opened or found! Please resolve...\n";
		 exit(1);
	 }
 
}

 void employeeManager::fillEmployeeTimeLogs()
 {
	 ifstream timeLogs("timelog.txt");
	 string employeeID;
	 string date;
	 int clockedIn;
	 int clockedOut;
	 
	 if(timeLogs)
	 { 
		 for(unsigned int i = 0; i < abcCorp.size(); i++)
			 //this first loop is used to create an object for each distinct ID within timelog.txt
		 {
			 timeLog shell;	
			 while(timeLogs >> employeeID >> date >> clockedIn >> clockedOut)
			 {
					if(employeeID == abcCorp[i].getID())
					{
						shell.setID(employeeID);
						break;
					}	
			 }
			 employeeTimes.push_back(shell);
		 }
		 timeLogs.close();
	 }
	 else
	 {
		 cerr << endl << "File 'timelog.txt' could not be opened or found! Please resolve...\n";
		 exit(1);
	 }
	 
	 timeLogs.open("timelog.txt");
	 while(timeLogs >> employeeID >> date >> clockedIn >> clockedOut)
		 //once an object is created for each ID, this function is used to sort and fill out the date worked, clock ins and clocks outs for each ID
	 {
		 for(unsigned int j = 0; j < employeeTimes.size(); j++)
		 {
				if(employeeID == employeeTimes[j].getID())
				{
					employeeTimes[j].addDate(date);
					employeeTimes[j].addClockIn(clockedIn);
					employeeTimes[j].addClockOut(clockedOut);
				}	
		 }
	 }
	 
	 
	 timeLogs.close();
 }
 
 void employeeManager::mainMenu()
 {
	string userOption = "";
		//declaring variable for user to choose option
	  
	 cout << endl << "Employee Management System\n" << 
	 "__________________________\n\n" <<
	 "Please select the following options:\n\n" <<
	 "1) Search Employee\n" <<
	 "2) View Time Logs\n" <<
	 "3) Update Employee Information\n" <<
	 "4) Save and Exit\n\n" <<
	 "Option (choose 1-4): ";
	 
	 cin >> userOption;
	 
	 cout << endl;
	 
	 if (userOption == "1")
	 {
		 searchEmployee();
	 }
	 else if (userOption == "2")
	 {
		 viewTimeLogs();
	 }
	 else if (userOption == "3")
	 {
		 updateInfo();
	 }
	 else if (userOption == "4")
	 {
		saveAndExit();
	 }
	 else
	 {
		cout << "Sorry that is an invalid option.\n\n"; 
		mainMenu();
	 }
	 
 }
 
 void employeeManager::searchEmployee()
 {
	string searchOption = "";
		//declaring variable for search option
	 cout << "Search Employee\n" <<
	 "_______________\n\n" <<
	 "What parameter would you like to search by? \n\n" <<
	 "1)ID Number\n" << 
	 "2)Name\n" <<
	 "3)Department\n" <<
	 "4)Position\n" <<
	 "5)Return to Main Menu\n\n" <<
	 "Option (choose 1-5): ";
	 
	 cin >> searchOption;
	 cout << endl;
	 
	 if (searchOption == "1")
	 {
		 string ID = "";
		 cout << "Please input an employee ID: ";
		 cin >> ID;
		 cout << endl << endl;
		 
		 unsigned int i = 0;
		 bool notFound = true;
		 while (i < abcCorp.size())
		 {
			 if(ID == abcCorp[i].getID())
			 {
				 cout << "ID#: " << abcCorp[i].getID() << " \n" <<
				 "Name: " << abcCorp[i].getName() << " \n" << 
				 "DoB: " << abcCorp[i].getDateOfBirth() << " \n" << 
				 "SSN: " << abcCorp[i].getSSN() << " \n" <<
				 "Department: " << abcCorp[i].getDepartment() << " \n" <<
				 "Position: " << abcCorp[i].getPosition() << " \n" <<
				 "Total Number of Hours Worked: " << fixed << setprecision(2) << employeeTimes[i].totalHoursWorked() << "\n\n";
				 notFound = false;
				 break;
			 }
			 i++;
		 }
		 if (notFound)
		 {
			cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
		 }
		 mainMenu();
	 }
	 
	 else if (searchOption == "2")
	 {
		 string name = "";
		 cout << "Please input an employee name (first name only please): ";
		 cin >> name;
		 for(unsigned int i = 0; i < name.length(); ++i) 
		 {
			 name[i] = tolower(name[i]);
				/* making sure that even if user inputs capital letters,
				it would recognize the name by making everything lower 
				case */
		 }
		 cout << endl << endl; 
		 
		 unsigned int i = 0;
		 bool notFound = true;
		 while (i < abcCorp.size())
		 {
			 if(name == abcCorp[i].getName())
			 {
				 cout << "ID#: " << abcCorp[i].getID() << " \n" <<
				 "Name: " << abcCorp[i].getName() << " \n" << 
				 "DoB: " << abcCorp[i].getDateOfBirth() << " \n" << 
				 "SSN: " << abcCorp[i].getSSN() << " \n" <<
				 "Department: " << abcCorp[i].getDepartment() << " \n" <<
				 "Position: " << abcCorp[i].getPosition() << " \n" <<
				 "Total Number of Hours Worked: " << fixed << setprecision(2) << employeeTimes[i].totalHoursWorked() << "\n\n";
				 notFound = false;
			 }
			 i++;
		 }
		 if (notFound)
		 {
			cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
		 }
		 mainMenu();
		
	 }
	 
	 else if (searchOption == "3")
	 {
		 string department = "";
		 cout << "Please input a department: ";
		 cin >> department;
		 for(unsigned int i = 0; i < department.length(); ++i) 
		 {
			 department[i] = tolower(department[i]);
				/* making sure that even if user inputs capital letters,
				it would recognize the department by making everything lower 
				case */
		 }
		 cout << endl << endl; 
		 
		 unsigned int i = 0;
		 bool notFound = true;
		 while (i < abcCorp.size())
		 {
			 if(department == abcCorp[i].getDepartment())
			 {
				 cout << "ID#: " << abcCorp[i].getID() << " \n" <<
				 "Name: " << abcCorp[i].getName() << " \n" << 
				 "DoB: " << abcCorp[i].getDateOfBirth() << " \n" << 
				 "SSN: " << abcCorp[i].getSSN() << " \n" <<
				 "Department: " << abcCorp[i].getDepartment() << " \n" <<
				 "Position: " << abcCorp[i].getPosition() << " \n" <<
				 "Total Number of Hours Worked: " << fixed << setprecision(2) << employeeTimes[i].totalHoursWorked() << "\n\n";
				 notFound = false;
			 }
			 i++;
		 }
		 if (notFound)
		 {
			cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
		 }
		 mainMenu();
	 }
	 
	 else if (searchOption == "4")
	 {
		 string position = "";
		 cout << "Please input a position: ";
		 cin >> position;
		  for(unsigned int i = 0; i < position.length(); ++i) 
		 {
			 position[i] = tolower(position[i]);
				/* making sure that even if user inputs capital letters,
				it would recognize the position by making everything lower 
				case */
		 }
		 cout << endl << endl; 
		 
		 unsigned int i = 0;
		 bool notFound = true;
		 while (i < abcCorp.size())
		 {
			 if(position == abcCorp[i].getPosition())
			 {
				 cout << "ID#: " << abcCorp[i].getID() << " \n" <<
				 "Name: " << abcCorp[i].getName() << " \n" << 
				 "DoB: " << abcCorp[i].getDateOfBirth() << " \n" << 
				 "SSN: " << abcCorp[i].getSSN() << " \n" <<
				 "Department: " << abcCorp[i].getDepartment() << " \n" <<
				 "Position: " << abcCorp[i].getPosition() << " \n" <<
				 "Total Number of Hours Worked: " << fixed << setprecision(2) << employeeTimes[i].totalHoursWorked() << "\n\n";
				 notFound = false;
			 }
			 i++;
		 }
		 if (notFound)
		 {
			cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
		 }
		 mainMenu();
	 }
	 else if (searchOption == "5")
	 {
		 mainMenu();
	 }
	 else
	 {
		cout << "Sorry that is an invalid option.\n\n"; 
		mainMenu();
	 } 
 }
 
 void employeeManager::viewTimeLogs()
 {
	 string ID = "";
		//declaring variable for ID to search for employee time logs
	 cout << "View Time Logs\n" <<
	 "______________\n\n" <<
	 "Please input ID of employee: ";
	 
	 cin >> ID;
	 cout << endl << endl;
	 
	 unsigned int i = 0;
	 bool notFound = true;
	 while (i < employeeTimes.size())
	 {
		 if(ID == employeeTimes[i].getID())
		 {
			 employeeTimes[i].displayTimeLogs();
			 cout << endl;			 
			 notFound = false;
			 break;
		 }
		 i++;
	 }
	 if (notFound)
	 {
		cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
	 }
	 mainMenu();
	 
 }
 
  void employeeManager::updateInfo()
 {
	 string ID = "";
		//declaring variable for ID as input to search and change employee info
	 cout << "Update Employee Information\n" <<
	 "___________________________\n\n" <<
	 "Please input ID of employee: ";
	 
	 cin >> ID;
	 cout << endl << endl;
	 
	 unsigned int i = 0;
	 bool notFound = true;
	 while (i < abcCorp.size())
	 {
		 if(ID == abcCorp[i].getID())
		 {
			 bool stayInMenu = true;
			 while(stayInMenu)
			 {
				 string changeOption = "";
				 cout << "What parameter would you like to change? \n\n" <<
				 "1)Name\n" << 
				 "2)Date of Birth\n" <<
				 "3)SSN\n" <<
				 "4)Department\n" <<
				 "5)Position\n" <<
				 "6)Make No Changes (Return to Main Menu)\n\n" <<
				 "Option (choose 1-6): ";
				 
				 cin >> changeOption;
				 cout << endl << endl;
				 
				 if(changeOption == "1")
				 {
					 string changeName = "";
					  //declaring variable to change name parameter
					 cout << "You wish to edit name(currently: " << abcCorp[i].getName() << ").\n" <<
					 "Enter new value: ";
					 cin >> changeName;
					 for(unsigned int j = 0; j < changeName.length(); ++j) 
					 {
						 changeName[j] = tolower(changeName[j]);
							 /* making sure that even if user inputs capital letters,
							 it would make everything lower case to keep thing file consistent */
					 }
					 abcCorp[i].setName(changeName);
					 
					 bool yesOrNo = true;
					 while(yesOrNo)
					 {
						 cout << endl << "Value updated. Change another parameter? (choose y or n): ";
						 string change = "";
						 cin >> change;
						 cout << endl;
						 if(change == "y" || change == "Y")
						 {
							 break;
						 }
						 else if (change == "n"||change == "N")
						 {
							 stayInMenu = false;
							 break;
						 }
						 else
							 cout << "Invalid Option\n\n";
					 }
				 }
				 
				 else if(changeOption == "2")
				 {
					 string changeDOB = "";
					 int month;
					 string m;
					 int day;
					 string d;
					 string year = "";
					  //declaring variable to change DOB parameter
					 cout << "You wish to edit date of birth (currently: " << abcCorp[i].getDateOfBirth() << ").\n";
					 bool changeMonth = true;
					 while(changeMonth)
					 {
						cout <<"Enter new value for month (1-12): ";
						if (!(cin >> month)|| month < 1 || month > 12) 
							//should the user have an invalid input for month
						{
							cin.clear();
							cin.ignore(512, '\n');
							cout << "Your input is not valid,try again...\n";
						}
						else
						{
							stringstream convertM;
							convertM << month;
								//converting int month to a string to later concatenate 
							m = convertM.str();
							break;	
						}
					 }
					 bool changeDay = true;
					 while(changeDay)
					 {
						cout <<"Enter new value for day (1-31): ";
						if (!(cin >> day)|| day < 1 || day > 31) 
							//should the user have an invalid input for day
						{
							cin.clear();
							cin.ignore(512, '\n');
							cout << "Your input is not valid,try again...\n";
						}
						else
						{
							stringstream convertD;
							convertD << day;
								//converting int day to a string to later concatenate 
							d = convertD.str();
							break;	
						}
					 }
					 bool changeYear = true;
					 while(changeYear)
					 {
						cout <<"Enter new value for year (in the format YYYY): ";
						cin >> year;
						if(year.length()== 4)
							//to ensure that string year is of length 4
						{
							break;
						}
						else
						{
							cout << "Your input is not valid, try again...\n";
						}
					 }
					 
					 changeDOB = m + "/" + d + "/" + year;
						//concatenating all the string to have the full format MM/DD/YYYY
					 abcCorp[i].setDateOfBirth(changeDOB);
					 
					 bool yesOrNo = true;
					 while(yesOrNo)
					 {
						 cout << endl << "Value updated. Change another parameter? (choose y or n): ";
						 string change = "";
						 cin >> change;
						 cout << endl;
						 if(change == "y" || change == "Y")
						 {
							 break;
						 }
						 else if (change == "n"||change == "N")
						 {
							 stayInMenu = false;
							 break;
						 }
						 else
							 cout << "Invalid Option\n\n";
					 }
				 }
				 
				 else if(changeOption == "3")
				 {
					 string changeSSN = "";
					  //declaring variable to change SSN parameter
					 cout << "You wish to edit SSN (currently: " << abcCorp[i].getSSN() << ").\n" <<
					 "Enter new value\n" <<
					 "(please put in format ###-##-####, including the dashes): ";
					 cin >> changeSSN;
					 abcCorp[i].setSSN(changeSSN);
					 
					 bool yesOrNo = true;
					 while(yesOrNo)
					 {
						 cout << endl << "Value updated. Change another parameter? (choose y or n): ";
						 string change = "";
						 cin >> change;
						 cout << endl;
						 if(change == "y" || change == "Y")
						 {
							 break;
						 }
						 else if (change == "n"||change == "N")
						 {
							 stayInMenu = false;
							 break;
						 }
						 else
							 cout << "Invalid Option\n\n";
					 }
				 }
				 
				 else if(changeOption == "4")
				 {
					 string changeDepartment = "";
					  //declaring variable to change name parameter
					 cout << "You wish to edit department(currently: " << abcCorp[i].getDepartment() << ").\n" <<
					 "Enter new value: ";
					 cin >> changeDepartment;
					 for(unsigned int j = 0; j < changeDepartment.length(); ++j) 
					 {
						 changeDepartment[j] = tolower(changeDepartment[j]);
							/* making sure that even if user inputs capital letters,
							 it would make everything lower case to keep thing file consistent */
					 }
					 abcCorp[i].setDepartment(changeDepartment);
					 
					 bool yesOrNo = true;
					 while(yesOrNo)
					 {
						 cout << endl << "Value updated. Change another parameter? (choose y or n): ";
						 string change = "";
						 cin >> change;
						 cout << endl;
						 if(change == "y" || change == "Y")
						 {
							 break;
						 }
						 else if (change == "n"||change == "N")
						 {
							 stayInMenu = false;
							 break;
						 }
						 else
							 cout << "Invalid Option\n\n";
					 }
				 }
				 
				 else if(changeOption == "5")
				 {
					 string changePosition = "";
					  //declaring variable to change name parameter
					 cout << "You wish to edit position(currently: " << abcCorp[i].getPosition() << ").\n" <<
					 "Enter new value: ";
					 cin >> changePosition;
					 for(unsigned int j = 0; j < changePosition.length(); ++j) 
					 {
						 changePosition[j] = tolower(changePosition[j]);
							 /* making sure that even if user inputs capital letters,
							 it would make everything lower case to keep thing file consistent */
					 }
					 abcCorp[i].setPosition(changePosition);
					 
					 bool yesOrNo = true;
					 while(yesOrNo)
					 {
						 cout << endl << "Value updated. Change another parameter? (choose y or n): ";
						 string change = "";
						 cin >> change;
						 cout << endl;
						 if(change == "y" || change == "Y")
						 {
							 break;
						 }
						 else if (change == "n"||change == "N")
						 {
							 stayInMenu = false;
							 break;
						 }
						 else
							 cout << "Invalid Option\n\n";
					 }
				 }
				 else if (changeOption == "6")
				 {
					 mainMenu();
				 }
				 else 
				 {
					 cout << "Invalid input. Please try again...";
				 }
			 }
			 
			 notFound = false;
		 }
		 i++;
	 }
	 if (notFound)
	 {
		cout << "Your input does not match any of the employees in the log. Please try again...\n\n"; 
	 }
	 mainMenu();
 }

 void employeeManager::saveAndExit()
 {
	 ofstream updatedEmployeeInfo;
	 updatedEmployeeInfo.open("details.txt");
	 
	 for(unsigned int i = 0; i < abcCorp.size();i++)
	 {
		 updatedEmployeeInfo << abcCorp[i].getID() << " " << abcCorp[i].getName() << " " <<
		 abcCorp[i].getDateOfBirth() << " " << abcCorp[i].getSSN() << " " << abcCorp[i].getDepartment() << " " <<
		 abcCorp[i].getPosition() << "\n";
	 }
	 updatedEmployeeInfo.close();
	 exit(1);
 }