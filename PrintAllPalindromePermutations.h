#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHARCOUNT = 26 /* assuming only a-z*/

typedef struct Map
{
	char c;
	int count;
}Map;

typedef struct MapArray
{
	Map *map;
	int size;
}MapArray;

int NumberOfUniqueChar(char *s)
{
	
}

void InitializeMapArray(MapArray **mapArray)
{
	MapArray *current = *mapArray;
	Map *map = current->map;
	
	int i=0;
	for(i=0; i < current->size; i++)
	{
		(map + i)->char = '\0';
		(map +i)->count = 0;
	}
}

int GetMapIndexWithChar(MapArray *mapArray, char c)
{
	Map *map = mapArray->map;
	int i = 0, index = 0;
	for(i=0; i<mapArray->size; i++)
	{
		if((map + i)->char == c)
		{
			return i;
		}
	}
	
	return -1;
	
}

void ConvertStringToMap(char *s, MapArray **mapArray)
{
	MapArray *current = *mapArray;
	Map *map = current->map;
	
	int i=0, mapIndex = 0;
	while(s[i])
	{
		int index = GetMapIndexWithChar(mapArray, s[i]);
		if(index < 0)
		{
			
			(map+mapIndex)->char = s[i];
			(map+mapIndex)->count++;
			mapIndex++;			
			continue;
			
		}
		(map+index)->count++;
		
	}
}

int GetMapCountwithOddCount(Map *map)
{
	
}

int GetMapWithOddCount(MapArray *mapArray)
{
	int i=0;
	int index = -2; //all even char count
	Map *map = mapArray->map;
	 
	for(i=0; i<mapArray->size; i++)
	{
		if((map + i)->count % 2 != 0)
		{
			if(index != -2)
			{
				return -1; // no palindrome possible;
			}
			index = i;
		}
	}
	
	return index;
}

void HalfTheCharCount(Map *map)
{
	
}

void GenerateAndPrintPerm(Map *map)
{
	
}

void PrintPalindromePermute()
{
	char *s = (char *)malloc(100 * sizeof(char));
	char *t = gets(s);
	Reset(s);
	int length = strlen(t);
	
	MapArray *mapArray = (MapArray *)malloc(sizeof(MapArray));
	mapArray->size = length;
	mapArray->map = (Map *)malloc(length * sizeof(Map));
	
	InitializeMapArray(&mapArray);
	ConvertStringToMap(t, &map);
	int oddCountMapIndex = GetMapWithOddCount(mappArray);
	
	if(oddCountMapIndex == -1)
	{
		printf("No palindrome permutation possible!");
		return;
	}
	if(oddCountMapIndex >= 0)
	{
		
	}
	
}