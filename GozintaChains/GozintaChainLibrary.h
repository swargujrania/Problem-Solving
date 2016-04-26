#include <stdio.h>
#include <stdlib.h>
#include "Stacks.h";

#define TRUE 1;
#define FALSE 0;
#define MAX 1000000;

typedef struct Factors
{
	int *factorArray;
	int size;
}Factors;

Factors* Factorize(int n)
{
	int i = 0, j=0;	
	
	int *tempArray = (int*)malloc(n * sizeof(int));
	
	for(i=0; i<=n; i++)
	{
		if(n%i == 0)
		{
			tempArray[j++] = i;
		}
	}
	
	Factors *factors = (Factors *)malloc(sizeof(Factors));
	factors->factorArray = (int *)malloc(j * sizeof(int));
	
	for(i = 0; i< j; i++)
	{
		factors->factorArray[i] = tempArray[i];
	}
	
	
	
	return factors;
}

//form the DAG out of nodes.

typedef struct Node
{
	int value;
	int *next;
	int nextArraySize;
}Node;

Node* CreateNode(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->next = NULL;
	newNode->nextArraySize = 0;
	
	return newNode;
}

Node** CreateTree(Factors *factArray)
{
	int i=0;
	
	int factorCount = factArray->size;
	int *factors = factArray->factorArray;
	
	Node ** nodeArray = (Node **)malloc(factorCount * sizeof(Node*));
	
	
	for(i=0; i<factorCount; i++)
	{
		nodeArray[i] = CreateNode(factors[i]);		
	}
	
	//make connections
	
	for(i = 0; i < factorCount; i++)
	{
		//count the number of immediate connections
		int connectionCount = 0;
		
		for(j = i+1; j < factorCount; j++)
		{
			if(nodeArray[j]->value % nodeArray[i]->value == 0)
			{
				connectionCount++;
			}
		}
		
		//populate the nextArray
		nodeArray[i]->next = (int *)malloc(connectionCount * sizeof(int));
		nodeArray[i]->nextArraySize = connectionCount;
		int k = 0;
		for(j = i+1; j < factorCount; j++)
		{
			if(nodeArray[j]->value % nodeArray[i]->value == 0)
			{
				nodeArray[i]->next[k++] = j;
			}
		}
	}
	
	return nodeArray;
}


//perform DFS and increase count everytime the destination node is reached

int GozintaChainCount(Node *nodeArray, Factors* factArray, int numValue)
{
	
	int factorCount = factArray->size;
	
	Stack *stack = InitStack(factorCount);	
	Push(&stack, 0);
	int i=0;
	int chainCount = 0;
	
	while(stack->top >= 0)
	{
		int currentIndex = Pop(&stack);
		if(currentIndex == factorCount-1)
		{
			chainCount++;
			continue;
		}
		
		Node *temp = nodeArray[currentIndex];
		
		for(i = 0; i < temp->nextArraySize; i++)
		{
			Push( &stack, temp->next[i]->value);
		}
	}
	
	return chainCount;
}


int IsCriteriaSatisfied(int num)
{
	Factors *factorArray = Factorize(num);	
	Node **nodeArray = CreateTree(factorArray);
	
	int chainCount = GozintaChainCount(*nodeArray, factorArray, num);
	
	return (chainCount == num) ? TRUE : FALSE;
	
}

int CriteriaSatisfyingNumberSum()
{
	int i=0;
	int sum = 0;
	for(i = 0; i < MAX; i++)
	{
		if(IsCriteriaSatisfied(i))
		{
			sum += i;
			continue;
		}
	}
	
	return sum;
}
