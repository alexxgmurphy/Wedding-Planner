#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"

using namespace std;

HEvent::HEvent(const unsigned long long &epochTime, const string &holidayName, const string &holidayType)
{
	mEpochTime = epochTime;
	mHolidayName = holidayName;
	mHolidayType = holidayType;
}

unsigned long long HEvent::getEpochTime()
{
	return mEpochTime;
}

string HEvent::getHolidayName()
{
	return mHolidayName;
}

string HEvent::getHolidayType()
{
	return mHolidayType;
}

bool operator== (const HEvent &event1, const HEvent &event2)
{
	return event1.mEpochTime == event2.mEpochTime;
}

bool operator!= (const HEvent &event1, const HEvent &event2)
{
	return !(event1.mEpochTime == event2.mEpochTime);
}

bool operator< (const HEvent &event1, const HEvent &event2)
{
	return event1.mEpochTime < event2.mEpochTime;
}

ostream& operator<< (ostream &os, const HEvent& event1)
{
	os << getMonth(event1.mEpochTime) << "/" << getMonthDay(event1.mEpochTime) << "/" << getYear(event1.mEpochTime) << " is " << event1.mHolidayName << " (" << event1.mHolidayType << ")\n";
	return os;
}
