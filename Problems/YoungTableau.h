#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define CORRECT 0
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4

typedef struct Matrix
{
	int **matrix;
	int row;
	int col;
}Matrix;

typedef struct CorrectPlace
{
	int isCorrect;
	int direction;
}CorrectPlace;

void IsCorrectlyPlaced(Matrix *matrix, int i, int j, CorrectPlace *correctPlace)
{	
	
	if(matrix == NULL || matrix->row <=0 ||matrix->col <=0 || i < 0 || i >= matrix->row || j <0 || j >= matrix->col)
	{
		printf("INVALID INPUT: CANNOT PERFORM OPERATION");
		exit(-1);
	}
	if(j > 0)
	{
		if(matrix->matrix[i][j-1] > matrix->matrix[i][j])
		{
			correctPlace->isCorrect = FALSE;
			correctPlace->direction = LEFT;
			return;// correctPlace;
		}
	}
	if(j < matrix->col-1)
	{
		if(matrix->matrix[i][j+1] < matrix->matrix[i][j])
		{
			correctPlace->isCorrect = FALSE;
			correctPlace->direction = RIGHT;
			return;// correctPlace;
		}
	}
	if(i > 0)
	{
		if(matrix->matrix[i-1][j] > matrix->matrix[i][j])
		{
			correctPlace->isCorrect = FALSE;
			correctPlace->direction = UP;
			return;// correctPlace;
		}
	}
	if(i < matrix->row-1)
	{
		if(matrix->matrix[i+1][j] < matrix->matrix[i][j])
		{
			correctPlace->isCorrect = FALSE;
			correctPlace->direction = DOWN;
			return;// correctPlace;
		}
	}
	
	correctPlace->isCorrect = TRUE;
	correctPlace->direction = CORRECT;
	return;// correctPlace;
}

void Move(Matrix *matrix, int i, int j, int direction)
{
	if(matrix == NULL || matrix->row <=0 ||matrix->col <=0 || i < 0 || i >= matrix->row || j <0 || j >= matrix->col)
	{
		printf("INVALID INPUT: CANNOT PERFORM OPERATION");
		exit(-1);
	}
	int col = j, row = i;
	int num = matrix->matrix[i][j];
	
	switch(direction)
	{
		case 0: return;
		case 1:
			//MOVE RIGHT
			while((++col) < matrix->col && matrix->matrix[i][col] < num)
			{
				matrix->matrix[i][col-1] = matrix->matrix[i][col];
				Tableaufy(matrix, i col-1);
				
			}
			matrix->matrix[i][col-1] = num;
			break;
		case 2:
			//MOVE UP
			while((--row) >= 0 && matrix->matrix[row][i] > num)
			{
				matrix->matrix[row+1][j] = matrix->matrix[row][j];
				Tableaufy(matrix, row+1, j);
				
			}
			matrix->matrix[i][col-1] = num;
			break;
		case 3:
		
			//MOVE LEFT
			while((--col) >= 0 && matrix->matrix[i][col] > num)
			{
				matrix->matrix[i][col+1] = matrix->matrix[i][col];
				Tableaufy(matrix, i col+1);
				
			}
			matrix->matrix[i][col+1] = num;
			break;
		case 4:
		//MOVE DOWN
			while((++row) >= 0 && matrix->matrix[row][i] < num)
			{
				matrix->matrix[row-1][j] = matrix->matrix[row][j];
				Tableaufy(matrix, row-1, j);
				
			}
			matrix->matrix[i][col-1] = num;
			break;
		case default:
			return;
	}
}

void Tableaufy(Matrix *matrix, int i, int j)
{
	if(matrix == NULL || matrix->row <=0 ||matrix->col <=0 || i < 0 || i >= matrix->row || j <0 || j >= matrix->col)
	{
		printf("INVALID INPUT: CANNOT PERFORM OPERATION");
		exit(-1);
	}
	
	CorrectPlace *correctPlace = (CorrectPlace *)malloc(sizeof(CorrectPlace));
	IsCorrectlyPlaced(matrix, i, j, correctPLace);
	while(correctPlace->isCorrect != TRUE)		
	{
		Move(matrix, i, j, correctPlace->direction);	
		IsCorrectlyPlaced(matrix, i, j, correctPLace);
	}
	
	if(correctPlace->isCorrect = TRUE)
	{
		return;
	}
	
}