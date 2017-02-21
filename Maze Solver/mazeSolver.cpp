/*********************************************************************************************
Title: 			TRAN.assignment2 (mazeSolver.cpp)
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

#include "mazeSolver.h"

mazeSolver::mazeSolver()
{
	
}

mazeSolver::~mazeSolver()
{
	
}

void mazeSolver::setMaze()
{
	ifstream fin("maze.txt");
		//streaming the input file maze.txt
	
	if (!fin)
	{
		cerr << endl << "Input file could not be opened or found! Please resolve...\n";
			//should input file not be found
		exit(0);
	}
	
	//declaration of string to add into the 2d vector maze
	string line;
	
	 while (getline(fin, line)) 
	{
		maze.push_back(line);
	}
	
	fin.close();
	
	//setting row and col value of maze
	ROWS = maze.size();
	COLS = maze[0].size();
}

void mazeSolver::isMazeValid()
{
	for(int i = 1; i < maze.size(); i++ )
    {
		if (maze[i].size() != maze[0].size())
			//comparing each row to maze[0] to determine whether they each have the same number of columns
		{
			cerr << "Invalid maze! Please ensure that maze is an M x N rectangle" << endl;
			exit(0);
		}
	  
    }
	
	
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			if (maze[i][j] == 'S' || maze[i][j] == 'E' || maze[i][j] == ' ' || maze[i][j] == 'X')
			{
				//ensures that only the characters 'S', 'E', ' ' and 'X' are allowed in the maze
				continue;
			}
			else
			{
				cerr << "Invalid maze! Please ensure that maze contains valid characters " << endl;
				exit(0);
			}
		
		}
	}
	
}

void mazeSolver::findStartPosition()
{	
	//go through 2d array to search for 'S'
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			if (maze[i][j] == 'S')
			{
				m = j;
				n = i;
			}
		
		}
	}
}

int mazeSolver::getStartingXCoordinate()
{
	return m;
}

int mazeSolver::getStartingYCoordinate()
{
	return n;
}


void mazeSolver::displayMaze()
{
	int i;

	printf("MAZE:\n\n");
	for ( i = 0; i < ROWS; i++ )
	printf("%.*s\n", COLS, maze[i].c_str());
	printf("\n");

}

bool mazeSolver::findPath(int x, int y)
{
	// Symbols used in maze and maze solver:
	// ' ' = open
	// 'X' = wall
	// 'S' = start
	// 'E' = goal
	// '.' = path
	// '+' = attempted/invalid path
	
	// If x,y is outside maze, return false.
	if ( x < 0 || x > COLS - 1 || y < 0 || y > ROWS - 1 ) return false;

	// If x,y is the goal, return true.
	if ( maze[y][x] == 'E' ) return true;

	// If x,y is not open, return false.
	if ( maze[y][x] != ' ' && maze[y][x] != 'S' ) return false;

	// Mark x,y part of solution path should pathway be valid.
	if (maze[y][x] != 'S') maze[y][x] = '.';

	// If find_path North of x,y is true, return true.
	if ( findPath(x, y - 1) == true ) return true;

	// If find_path East of x,y is true, return true.
	if ( findPath(x + 1, y) == true ) return true;

	// If find_path South of x,y is true, return true.
	if ( findPath(x, y + 1) == true ) return true;

	// If find_path West of x,y is true, return true.
	if ( findPath(x - 1, y) == true ) return true;

	/* Should the current path lead to a dead end, unmark x,y as 
	part of solution path and mark as attempted/invalid. */
	if (maze[y][x] != 'S') maze[y][x] = '+';

	return false;
}