#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"
#include "hcal.h"

using namespace std;

HCal::HCal()
{
	Vector<HEvent*> events;
}

int HCal::binarySearchPart(unsigned long long eTime, int begin, int end)
{
	int middleIndex = (end + begin) / 2;

	if (events[middleIndex]->getEpochTime() == eTime)
	{
		return middleIndex;
	}
	if (begin == end || begin == end+1 || begin == end-1)
	{
		return -1;
	}
	else if (eTime < events[middleIndex]->getEpochTime())
	{

		return binarySearchPart(eTime, begin, middleIndex-1);
	}
	else
	{
		return binarySearchPart(eTime, middleIndex+1, end);
	}
}

int HCal::search(HEvent* date)
{
	int index = binarySearchPart(date->getEpochTime(), 0, events.size()-1);
	return index;
}

void HCal::addEvent(HEvent* newEvent)
{
	events.push_back(newEvent);
}
int HCal::getSize()
{
	return events.size();
}
HEvent* HCal::getEvent(int index)
{
	return events[index];
}
