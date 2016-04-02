/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int valid_date(int, int, int);
struct node{
	int data;
	struct node *next;
};


int between_days(struct node *date1head, struct node *date2head){
	if (date1head != NULL&&date2head != NULL){
		int day1, day2, mon1, mon2, year1, year2;
		day1 = (date1head->data * 10) + (date1head->next)->data;
		day2 = (date2head->data * 10) + (date2head->next)->data;
		date1head = date1head->next; date1head = date1head->next;
		date2head = date2head->next;
		date2head = date2head->next;
		mon1 = date1head->data * 10 + (date1head->next)->data;
		mon2 = date2head->data * 10 + (date2head->next)->data;
		date1head = date1head->next; date1head = date1head->next;
		date2head = date2head->next;
		date2head = date2head->next;
		year1 = (date1head->data * 10) + (date1head->next)->data;
		date1head = date1head->next; date1head = date1head->next;
		year1 = year1 * 100 + (date1head->data * 10) + (date1head->next)->data;
		year2 = date1head->data * 10 + (date1head->next)->data;
		date2head = date2head->next;
		date2head = date2head->next;
		year2 = year2 * 100 + date2head->data * 10 + (date2head->next)->data;
		int result = 0;
		int arr[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		int vali1 = valid_date(day1, mon1, year1);
		int vali2 = valid_date(day2, mon2, year2);
		while (year1 < year2)
		{
			if (year1 % 4 == 0 || year1 % 100 == 0 || year1 % 400 == 0)
			{
				if (mon1 != 1)
					result = result + 365 - (arr[mon1] + day1);
				else
					result = result + 365 - day1;
			}
			year1++;
		}
		result = result + 365 - arr[mon2 + 1] - arr[mon1 + 1] - 2;
		return result;
	}
	return -1;
}
int valid_date(int d, int m, int y)
{
	if (d>0 && m > 0 && m < 13 && y > 999 && y < 10000){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if (d < 32)
				return 1;
			else
				return 0;
		}
		else if (m == 2)
		{
			if (y % 100 == 0 || y % 400 == 0 || y % 4 == 0)
			{
				if (d < 30)
					return 1;
				else
					return 0;
			}
			else
			{
				if (d < 29)
					return 1;
				else
					return 0;
			}
		}
		else
		{
			if (d < 31)
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}