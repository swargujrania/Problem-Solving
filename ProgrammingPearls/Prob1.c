#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *A, int size);
void GetArray(int *a, int size, char *name);

int main()
{

  int inputSize = 10;
  int *inputArray = (int *)malloc(inputSize * sizeof(int));
  GetArray(inputArray, inputSize, "input");

  int arraySize = 4;
  int *inMemArray = (int *)malloc(arraySize * sizeof(int));
 

  int inputIdx = 0, rounds = inputSize/arraySize, i = 0;
  int count = 0;

  for(i=0; i<=rounds; i++)
    {
      //clear inMemArray
      int j = 0;
      for(j=0; j<arraySize; j++)
	{
	  inMemArray[j] = 0;
	}
      for(inputIdx = 0; inputIdx < inputSize; inputIdx++)
	{
	  int current = inputArray[inputIdx];
	  if(current >= (i*arraySize) && current < (i+1)*arraySize)
	    {
	      inMemArray[(current)%arraySize]++;	      
	    }
	}

      PrintArray(inMemArray, arraySize);
    }
  printf("\n");
  return 0;
}

void PrintArray(int *a, int size)
{
  int i=0;
  for(i=0; i<size; i++)
    {
      int count = a[i];
      while(count > 0)
	{
	  printf("%d\t", i+1);
	  count--;
	}
    }
}

void GetArray(int *a, int size, char *name)
{
  
  printf("enter %d elements for %s array:\n ", size, name);
  int i=0;
  while(i < size)
    {
      scanf("%d", a+i);
      i++;
    }
}
