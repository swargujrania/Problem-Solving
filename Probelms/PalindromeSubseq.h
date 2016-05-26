#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define ON 1
#define OFF 0 

char * ReadBinaryString(char *s)
{
	
	int i=0,c =0;
	while((c = getchar()) != ' ' || c != '\t' || c != '\n')
	{
		if(c != '1' || c != '0')
		{
			return NULL;
		}
		s[i++] = c;
	}
	s[i] = '\0';
	return s;
}

int IsPalindrome(char *s)
{
	if(s == NULL)
	{
		return -1;
	}
	
	if(strlen(s) == 1)
	{
		return 1;
	}
	
	int last = strlen(s) - 1;
	int first = 0;
	while(first < last && s[first] == s[last])
	{
		first++; last--;
	}
	if(s[first] == s[last])
	{
		return 1;
	}
	return 0;
}

int NumOfConsecChar(char *s, char c)
{
	if(s == NULL)
	{
		return -1;
	}
	
	int state = OFF, count = 0;
	int i = 0;
	while(s[i])
	{
		if(state == OFF && s[i] == c)
		{
			state = ON;
			
			count++;
		
			
		}
		
		if(state == ON && s[i] != c)
		{
			state = OFF;
			
		}
		i++;
		
	}
	
	return count;
}

int PalindromeToEmpty()
{
	char *s = (char *)malloc(100 * sizeof(char));
	char *t = ReadBinaryString(s);
	if(t == NULL)
	{
		return -1;
	}
	
	if(t == NULL || strlen(t) == 0)
	{
		return -1;
	}
	
	if(IsPalindrome(t))
	{
		return 1;
	}
	
	int numberOfOnes = NumOfConsecChar(t, '1');
	if(numberOfOnes == -1)
	{
		return -1;
	}
	return numberOfOnes + 1;
	
	
}
