#include "Date.h"

Date::Date()
{
    this->Day = 0;
    this->Month = 0;
    this->Year = 0;
    this->Hour = 0;
    this->Minute = 0;
}

Date::~Date()
{
}

Date::Date(int day, int month, int year)
    : Day(day), Month(month), Year(year)
{ }

void Date::setDay()
{
    cin >> this->Day;
}

void Date::setMonth()
{
    cin >> this->Month;
}

void Date::setYear()
{
    cin >> this->Year;
}

void Date::setHour()
{
    cin >> this->Hour;
}

void Date::setMinute()
{
    cin >> this->Minute;
}

int Date::getDay()
{
    return this->Day;
}

int Date::getMonth()
{
    return this->Month;
}

int Date::getYear()
{
    return this->Year;
}

int Date::getHour()
{
    return this->Hour;
}

int Date::getMinute()
{
    return this->Minute;
}

istream& operator>>(istream& i, Date& d)
{
    i >> d.Day;
    i >> d.Month;
    i >> d.Year;
    i >> d.Hour;
    i >> d.Minute;
    return i;
}

ostream& operator<<(ostream& o, const Date& d)
{
    o << ((d.Day > 9) ? "" : "0") << d.Day << "/" << ((d.Month > 9) ? "" : "0") << d.Month << "/" << d.Year;
    return o;
}