/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4)
Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	if (s1 == NULL)
	{
		if (s2 == NULL)
			if (s3 == NULL)
				if (s4 == NULL)
					return NULL;
	}
	if (strstr(s1, s2))
	{
		if (strstr(s1, s3))
		{
			if (strstr(s1, s4))
				return s1;
			else if (strstr(s4, s1))
				return s4;

		}
		else if (strstr(s3, s1))
			return s3;
	}
	else if (strstr(s2, s1))
	{
		if (strstr(s2, s3)){
			if (strstr(s2, s4))
				return s2;
			else if (strstr(s4, s2))
				return s4;
		}
		else if (strstr(s3, s2))
			return s3;
		else
		{
			if (strstr(s3, s1))
			{
				if (strstr(s3, s2))
				{
					if (strstr(s3, s4))
						return s3;
					else if (strstr(s4, s3))
						return s4;
					else
					{
						strcat(s3, s4);
						strcat(s3, s2);
						strcat(s3, s1);
						return s3;
					}
				}
				else
				{
					strcat(s3, s4);
					strcat(s3, s2);
					strcat(s3, s1);
					return s3;
				}
			}
else
{
	strcat(s3, s4);
	strcat(s3, s2);
	strcat(s3, s1);
	return s3;
}
		}
	}
	else
	{
		strcat(s1, s2);
		strcat(s1, s3);
		strcat(s1, s4);
		return s1;
	}
	return NULL;
}