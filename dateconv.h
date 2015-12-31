// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW4.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#pragma once

// Function: getEpochSecs
// Purpose: Converts a date (month, day, year) into
//		seconds since epoch (Jan 1, 1970)
// Input: 3 unsigned integers holding the current month,
//		day, and year -- note that month starts at
//		1 for January, and years should be 4 digit numbers
//		like 2015
// Output: an unisgned long long with the seconds since
//		epoch indicated by the input
unsigned long long getEpochSecs(unsigned int month, 
	unsigned int day, unsigned int year);

// Function: getYear
// Purpose: Retrieves the year from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the year indicated by the input
unsigned int getYear(unsigned long long epochSecs);

// Function: getMonth
// Purpose: Retrieves the month from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the month indicated by the input
unsigned int getMonth(unsigned long long epochSecs);

// Function: getMonthDay
// Purpose: Retrieves the day of the month from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the day in the month indicated by the input
unsigned int getMonthDay(unsigned long long epochSecs);
