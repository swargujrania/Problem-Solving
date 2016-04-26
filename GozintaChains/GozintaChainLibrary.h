#include <stdio.h>
#include <stdlib.h>
#include "Stacks.h"

int * Factorize(int n)
{
	int i = 0, j=0;
	int *factors = (int*)malloc(n * sizeof(int));
	
	for(i=0; i<=n; i++)
	{
		if(n%i == 0)
		{
			factors[j++] = i;
		}
	}
	
	realloc(factors, (size_t)j);
	
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

Node** CreateTree(int *factors, int factorCount)
{
	int i=0;
	
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

//Stack operations


int GozintaChainCount(Node *nodeArray, int factorCount, int numValue)
{
	Stack *stack = InitStack(factorCount);	
	Push(&stack, 0);
	int i=0;
	
	while(stack->top >= 0)
	{
		int currentIndex = Pop(&stack);
		Node *temp = nodeArray[currentIndex];
		
		for(i = 0; i < temp->nextArraySize; i++)
		{
			Push( &stack, temp->next[i]->value);
		}
	}
	
}