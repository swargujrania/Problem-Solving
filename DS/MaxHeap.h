#include <stdio.h>
#include <stdlib.h>

//Array implementation of binary max heap

typedef struct Array
{
	int *a;
	int size;
}Array;



void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;	
	
}

int Left(Array *array, int i)
{
	if(array == NULL || array->a == NULL || array->size <=0)
	{
		return -1;
	}
	if(i < 0 || i > array->size)
	{
		return -1;
	}
	return 2 *i;
	
	
}

int Right(Array *array, int i)
{	
	
	if(array == NULL || array->a == NULL || array->size <=0)
	{
		return -1;
	}
	if(i < 0 || i > array->size)
	{
		return -1;
	}
	return (2*i)+1;
	
}

void MaxHeapify(Array **array, i)
{
	Array *temp = *array;
	if(temp == NULL)
	{
		return;
	}
	if((temp)->a == NULL||(temp)->size <= 0)
	{
		return;
	}
	if(i < 0 || i > (temp)->size)
	{
		return;
	}
	
	int largest = i;
	int l = Left(temp,i);
	int r = Right(temp,i);
	
	int *inTemp = temp->a;
	largest = (l < temp->size && inTemp[l] > inTemp[largest]) ? l : largest;
	largest = (r < temp->size && inTemp[r] > inTemp[largest]) ? r : largest;
	
	if(largest == i)
	{
		return;
	}
	Swap(inTemp + i, inTemp + largest);
	MaxHeapify(array, largest);
}

void IterativeMaxHeapify(Array **array, i)
{
	Array *temp = *array;
	if(temp == NULL)
	{
		return;
	}
	if((temp)->a == NULL||(temp)->size <= 0)
	{
		return;
	}
	if(i < 0 || i > (temp)->size)
	{
		return;
	}
	
	int largest = i;
	int l = Left(temp,i);
	int r = Right(temp,i);
	
	while(l < temp->size && r < temp->size)
	{
		largest = (inTemp[l] > inTemp[largest]) ? l : largest;
		largest = (inTemp[r] > inTemp[largest]) ? r : largest;
	
		if(largest == i)
		{
			break;
		}
		Swap(inTemp + i, inTemp + largest);
	}
}


void BuildMaxHeapFromArray(Array *a)
{
	int heapSize = a->size;
	int i=0;
	
	for(i= a->size/2; i >=0; i--)
	{
		MaxHeapify(&array, i);
	}
}

void HeapSort(Array *a)
{
	int i=0;
	int heapSize = a->size;
	BuildMaxHeapFromArray(a)
	{
		for(i = a->size-1; i <= 1; i--)
		{
			Swap(a->a[i], a->a[0]);
			heapSize--;
			MaxHeapify(&array, 0);
		}
	}
}
