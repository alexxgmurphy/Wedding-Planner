// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// NOTE: You should not need to edit this file for HW4.
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "dateconv.h"
#include <ctime>

// Function: getEpochSecs
// Purpose: Converts a date (month, day, year) into
//		seconds since epoch (Jan 1, 1970)
// Input: 3 unsigned integers holding the current month,
//		day, and year -- note that month starts at
//		1 for January, and years should be 4 digit numbers
//		like 2015
// Output: an unisgned long long with the seconds since
//		epoch indicated by the input
unsigned long long getEpochSecs(unsigned int month, unsigned int day, unsigned int year)
{
	unsigned long long retval = 0;
	tm tempTime;

	tempTime.tm_year = year - 1900;
	tempTime.tm_mon = month - 1;
	tempTime.tm_mday = day;
	tempTime.tm_hour = 0;
	tempTime.tm_min = 0;
	tempTime.tm_sec = 0;
	tempTime.tm_isdst = -1;

	time_t tstruct = std::mktime(&tempTime);
	retval = (unsigned long long)tstruct;
	return retval;
}

// Function: getYear
// Purpose: Retrieves the year from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the year indicated by the input
unsigned int getYear(unsigned long long epochSecs)
{
	std::time_t test = epochSecs;
	tm retval;

#if defined (_MSC_VER)
	// Windows
	gmtime_s(&retval, &test);
#else
	// Mac
	gmtime_r(&test, &retval);
#endif

    return (retval.tm_year + 1900);
}

// Function: getMonth
// Purpose: Retrieves the month from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the month indicated by the input
unsigned int getMonth(unsigned long long epochSecs)
{
    std::time_t test = epochSecs;
    tm retval;
    
#if defined (_MSC_VER)
	// Windows
    gmtime_s(&retval, &test);
#else
	// Mac
    gmtime_r(&test, &retval);
#endif
    
    return (retval.tm_mon + 1);
}

// Function: getMonthDay
// Purpose: Retrieves the day of the month from the date given by the input 
// Input: An unsigned long long that holds a number of seconds since
//		epoch (1/1/1970)
// Output: an unsigned int with the day in the month indicated by the input
unsigned int getMonthDay(unsigned long long epochSecs)
{
    std::time_t test = epochSecs;
    tm retval;
    
#if defined (_MSC_VER)
	// Windows
    gmtime_s(&retval, &test);
#else
	// Mac
    gmtime_r(&test, &retval);
#endif
    
    return (retval.tm_mday);
}



