/*********************************************************************************************
Title: 			TRAN.assignment2 (tranHW2.cpp)
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

#include "mazeSolver.h"

using namespace std;

int main()
{
	mazeSolver maze;
	
	maze.setMaze();
	maze.isMazeValid();
	maze.findStartPosition();
	int m,n;
	m = maze.getStartingXCoordinate();
	n = maze.getStartingYCoordinate();
	
	maze.displayMaze();
	
	if ( maze.findPath(m,n) == true )
		cout << "Found successful path from 'S' to 'E'!\n";
	else
		cout << "Failed finding path from 'S' to 'E' \n";

	maze.displayMaze();

	return 0;
}



