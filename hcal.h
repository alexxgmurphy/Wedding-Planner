#ifndef HCAL_H
#define HCAL_H


#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"

using namespace std;

class HCal
{
private:
	Vector<HEvent*> events;

	//binary search function, matches eTime, begin and end are the start and end indices
	int binarySearchPart(unsigned long long eTime, int begin, int end);
public:
	HCal();
	void addEvent(HEvent* newEvent);
	int getSize();
	HEvent* getEvent(int index);
	int search(HEvent* date);
};

#endif
