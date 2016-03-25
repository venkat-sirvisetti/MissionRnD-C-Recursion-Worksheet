/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int isvalid(int *maze, int *mem, int rows, int columns, int x1, int y1)
{
	if (x1 < 0 || x1 >= rows || y1 < 0 || y1 >= columns)
		return 0;
	if (*(mem+x1*columns+y1) != 1 && *((maze + x1*columns) + y1) == 1)
		return 1;
	return 0;
}

int path(int *maze, int *mem, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int t = 0;
	if (x1 == x2 && y1 == y2)
		return 1;
	if (isvalid(maze,mem, rows, columns, x1 - 1, y1))
	{
		*(mem+(x1-1)*columns+y1) = 1;
		t=path(maze, mem, rows, columns, x1 - 1, y1, x2, y2);
		if (t == 1)
			return 1;
	}
	if (isvalid(maze, mem, rows, columns, x1, y1 + 1))
	{
		*(mem + (x1)*columns + y1+1) = 1;
		t = path(maze, mem, rows, columns, x1, y1+1, x2, y2);
		if (t == 1)
			return 1;
	}
	if (isvalid(maze, mem, rows, columns, x1+1, y1))
	{
		*(mem + (x1+1)*columns + y1) = 1;
		t = path(maze, mem, rows, columns, x1+1, y1, x2, y2);
		if (t == 1)
			return 1;
	}
	if (isvalid(maze, mem, rows, columns, x1, y1-1))
	{
		*(mem + (x1)*columns + y1-1) = 1;
		t = path(maze, mem, rows, columns, x1, y1-1, x2, y2);
		if (t == 1)
			return 1;
	}
	return 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (rows <= 0 || columns <= 0 || x1<0 ||y1<0 ||x2<0||y2<0)
		return 0;
	int *mem = (int *)malloc(sizeof(int)*rows*columns);
	int i = 0,j=0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			*(mem+i*columns+j) = 0;
		}
	}
	if (isvalid(maze, mem, rows, columns, x1, y1))
	{
		*(mem+x1*columns+y1) = 1;
		i = path(maze, mem, rows, columns, x1, y1, x2, y2);
		return i;
	}
	return 0;
	
}
