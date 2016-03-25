/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

/*int isvalid(int *mem, int x1, int y1, int rows, int columns)
{
	if (x1 < rows && y1 < columns && *(mem + x1*columns + y1) == 0)
		return 1;
	return 0;
}
int print_spiral(int **input_array, int *mem, int *final, int x1, int y1,int *c,int rows, int columns)
{
	int t=0;
	if (isvalid(mem, x1, y1, rows, columns))
	{
		*(final + *c) = input_array[x1][y1];
		*c += 1;
		*(mem + x1*columns + y1) = 1;
		if (*c == (rows*columns - 1))
			return 1;
	}
		t = print_spiral(input_array, mem, final, x1, y1 + 1, c, rows, columns);
		if (t == 1)
			return 1;
		t = print_spiral(input_array, mem, final, x1+1, y1, c, rows, columns);
		if (t == 1)
			return 1;
		t = print_spiral(input_array, mem, final, x1, y1 - 1, c, rows, columns);
		if (t == 1)
			return 1;
		t = print_spiral(input_array, mem, final, x1-1, y1, c, rows, columns);
		if (t == 1)
			return 1;
	return 0;
	

}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows<0 ||columns<0)
		return NULL;
	int count = 0,i=0,j=0;
	int *c = &count;
	int *mem = (int *)malloc(sizeof(int)*rows*columns);
	int *final = (int *)malloc(sizeof(int)*rows*columns);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			*(mem + i*columns + j) = 0;
			*(final + i*columns + j) = 0;
		}
	}
	print_spiral(input_array,mem,final,0,0,c,rows,columns);
	return final;
}*/



void print_spiral(int x1, int y1, int rows, int columns, int *count, int **input_array, int *final,int limit)
{
	int i = 0, j = 0;
	for (; j < columns; j++)
	{
		*(final + (*count)) = input_array[x1+i][y1+j];
		*count += 1;
	}
	j--;
	i++;
	if (*count == limit)
		return;
	for (; i < rows; i++)
	{
		*(final + (*count)) = input_array[x1 + i][y1 + j];
		*count += 1;
	}
	i--;
	j--;
	if (*count == limit)
		return;
	for (; j>=0; j--)
	{
		*(final + (*count)) = input_array[x1 + i][y1 + j];
		*count += 1;
	}
	j++;
	i--;
	if (*count == limit)
		return;
	for (; i >0; i--)
	{
		*(final + (*count)) = input_array[x1 + i][y1 + j];
		*count += 1;
	}
	if (*count == limit)
		return;
	print_spiral(x1 + 1, y1 + 1, rows - 2, columns - 2, count, input_array, final,limit);
}

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows<0 || columns<0||(rows==0&&columns==0))
		return NULL;
	int count = 0, i = 0, j = 0;
	int *c = &count;
	//int *mem = (int *)malloc(sizeof(int)*rows*columns);
	int *final = (int *)malloc(sizeof(int)*rows*columns);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			//*(mem + i*columns + j) = 0;
			*(final + i*columns + j) = 0;
		}
	}
	print_spiral(0,0,rows,columns,c,input_array,final,rows*columns);
	return final;
}
