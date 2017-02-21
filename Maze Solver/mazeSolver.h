/*********************************************************************************************
Title: 			TRAN.assignment2 (mazeSolver.h)
Author: 		Trung Tran
Created on: 	October 23, 2015
Description: 	Maze pathfinder. Does the following:
					1) Reads input array of characters ('X','S',' ', or 'E')
					from "maze.txt" file that are arranged as a rectangular maze 
					2) First searches for the char 'S' as start and attempts to solve maze by 
					finding valid path to 'E'
					3) If valid, output will show the pathway (and attempted pathway) used to 
					solving the maze
Build with:		Make
Usage:			Be sure to include a maze.txt file that contains a maze with valid characters
Purpose:		Practice with recursion and algorithms  
**********************************************************************************************/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#ifndef mazeSolver_H
#define mazeSolver_H

class mazeSolver
{
	public:
		//default constructor
		mazeSolver();
		
		//destructor 
		~mazeSolver();
		
		//Other functions
		void setMaze();
			//setMaze - streams maze from maze.txt to program to solve 
		void isMazeValid();
			/* isMazeValid - determines whether given maze is M x N rectangle. 
			Also makes sure that all characters within maze are valid */
		void findStartPosition();
			/* findStartPosition - goes through entire maze before analysis to 
			find 'S' which is the starting position */
		int getStartingXCoordinate();
			//getStartingXCoordinate - returns X coordinate of starting position to use for findPath
		int getStartingYCoordinate();
			//getStartingYcoordinate - returns Y coordinate of starting position to use for findPath
		void displayMaze();
			//displayMaze - displays input and output maze in cmd prompt/terminal
		bool findPath(int x, int y);
			//findPath - recursive algorithm used to find the correct path from 'S' to 'E'
			//@param x - x coordinate of starting position
			//@param y - y coordinate of starting position
			
			
			
	private: 
		//member variables
		 vector <string> maze;
			//the maze itself that was streamed from maze.txt
		 int ROWS;
			//number of rows in the maze
		 int COLS;
			//number of columns in the maze
		 int m;
			//x coordinate of 'S'
		 int n;
			//y coordinate of 'S'
		 
		
};


#endif

