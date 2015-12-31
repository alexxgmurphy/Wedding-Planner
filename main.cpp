#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "hevent.h"
#include "dateconv.h"
#include "hcal.h"

using namespace std;

//Splits the given string str into a vector by splitting at the given character (splitChar)
//returns a vector of the substrings
Vector<string> strSplit(const string& str, char splitChar)
{
	Vector<string>stringVec;
	string tempString = str;

	size_t index = tempString.find_first_of(splitChar);
	while (index != string::npos)
	{
		stringVec.push_back(tempString.substr(0, index));
		tempString = tempString.substr(index + 1);
		index = tempString.find_first_of(splitChar);
	}

	stringVec.push_back(tempString);
	return stringVec;
}

//takes a string of text as input and returns an event based on that line of text (CSV)
HEvent* makeEvent(string line)
{
	Vector<string> csvLine = strSplit(line, ',');
	HEvent* newEvent = new HEvent(stoull(csvLine[0]), csvLine[1], csvLine[2]);
	return newEvent;
}

//creates an HCal object from the text in the given file
HCal* loadCal(const string &filename)
{
	HCal* calendar = new HCal();
	Vector<string> lines;
	string line = "";
	std::ifstream fileInput(filename);
	while (getline(fileInput, line))
	{
		lines.push_back(line);
	}
	for (int i = 1; i < lines.size(); i++)
	{
		calendar->addEvent(makeEvent(lines[i]));
	}
	return calendar;
}

//merges two calendars chronologically
HCal* mergeCals(HCal* a, HCal* b)
{
	HCal* c = new HCal;
	int i = 0;
	int j = 0;
	while (i < a->getSize() && j < b->getSize())
	{
		if (*a->getEvent(i) < *b->getEvent(j))
		{
			c->addEvent(a->getEvent(i));
			i++;
		}
		else
		{
			c->addEvent(b->getEvent(j));
			j++;
		}
	}
	if (i+1 < a->getSize())
	{
		for (int index = i; index < a->getSize(); index++)
		{
			c->addEvent(a->getEvent(index));
		}
	}
	else if (j+1 < b->getSize())
	{
		for (int index = j; index < b->getSize(); index++)
		{
			c->addEvent(b->getEvent(index));
		}
	}
	return c;
}

//converts an epoch time in PST to UTC
unsigned long long convertUTC(const unsigned long long &eTimePST)
{
	unsigned long long eTimeUTC;
	if (eTimePST >= 1420099200 && eTimePST <= 1425801600)
	{
		eTimeUTC = eTimePST - 28800;
	}
	else if (eTimePST >= 1425884400 && eTimePST <= 1446361200)
	{
		eTimeUTC = eTimePST - 25200;
	}
	else if (eTimePST >= 1446451200 && eTimePST <= 1457856000)
	{
		eTimeUTC = eTimePST - 28800;
	}
	else if (eTimePST >= 1457938800 && eTimePST <= 1478415600)
	{
		eTimeUTC = eTimePST - 25200;
	}
	else if (eTimePST >= 1478505600 && eTimePST <= 1489305600)
	{
		eTimeUTC = eTimePST - 28800;
	}
	else
	{
		eTimeUTC = eTimePST - 28800;
	}
	return eTimeUTC;
}

int main(int argc, char** argv)
{
	Vector<HCal*> calendars;
	HCal* a = loadCal("BRHol2015.csv");
	HCal* b = loadCal("INHol2015.csv");
	HCal* c = mergeCals(a, b);
	HCal* d = loadCal("USHol2015.csv");
	HCal* fifteen = mergeCals(c, d);

	HCal* e = loadCal("BRHol2016.csv");
	HCal* f = loadCal("INHol2016.csv");
	HCal* g = mergeCals(e, f);
	HCal* h = loadCal("USHol2016.csv");
	HCal* sixteen = mergeCals(g, h);

	HCal* calendar = mergeCals(fifteen, sixteen);

	cout << "Welcome to the wedding planner!" << endl;
	cout << "Please enter a date in MM/DD/YY format: ";
	string date = " ";
	cin >> date;
	int indexFound;
	unsigned int month;
	unsigned int day;
	unsigned int year;
	unsigned long long UTCTime;
	while (!(date == "Q" || date == "q"))
	{
		Vector<string> dateVec = strSplit(date, '/');
		month = stoi(dateVec[0]);
		day = stoi(dateVec[1]);
		year = stoi(dateVec[2]);
		UTCTime = convertUTC(getEpochSecs(month, day, year));
		HEvent* find = new HEvent(UTCTime, "Wedding Date", "Personal");
		indexFound = calendar->search(find);
		if (indexFound == -1)
		{
			cout << "That date is completely available!" << endl;
		}
		else
		{
			cout << *calendar->getEvent(indexFound);
		}
		cout << "Enter another wedding date to search again, or Q to quit" << endl;
		cin >> date;
	}

	return 0;
}
