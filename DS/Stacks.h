#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
	int *a;
	int top;
	int size;
}Stack;

Stack * InitStack(int size)
{
	Stack *stack = (Stack*)malloc(sizeof(stack));
	stack->a = (int *)malloc(size * sizeof(int));
	stack->top = -1;
	stack->size = size;
	
	return stack;
}

void Push(Stack **stack, int value)
{
	if(!stack)
	{
		printf("No stack\n");
		return;
	}
	Stack *temp = *stack;
	if(temp->top == temp->size-1)
	{
		printf("Error, reached stack limit.");
		return;
	}
	
	temp->a[++(temp->top)] = value;
	return;
}

int Pop(Stack **stack)
{
	if(!stack)
	{
		return;
	}
	Stack *temp = *stack;
	
	if(temp->top == -1)
	{
		printf("Stack empty.");
		return;
	}
	
	return temp->a[(temp->top)--];
}
