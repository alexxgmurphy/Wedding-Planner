#ifndef HEVENT_H
#define HEVENT_H

#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "dateconv.h"

using namespace std;

class HEvent
{
private:
	unsigned long long mEpochTime;
	string mHolidayName;
	string mHolidayType;
public:
	//parametrized constructor
	HEvent(const unsigned long long &epochTime, const string &holidayName, const string &holidayType);
	
	//getters
	unsigned long long getEpochTime();
	string getHolidayName();
	string getHolidayType();

	//operator overloads
	friend bool operator== (const HEvent &event1, const HEvent &event2);
	friend bool operator!= (const HEvent &event1, const HEvent &event2);
	friend bool operator< (const HEvent &event1, const HEvent &event2);
	friend ostream& operator<< (ostream &os, const HEvent& event1);
};

#endif
