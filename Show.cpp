#include "Show.h"

Show::Show()
{
    this->SID = 0;
    this->MovieID = 0;
    this->CreatedTicket = 0;
}

Show::~Show()
{
    
}

istream& operator>>(istream& in, Show& md)
{
    in >> md.SID;
    in >> md.h;
    in >> md.MovieID;
    in >> md.TimeStart;
    return in; 
}

int Show::getMovieID()
{
    return this->MovieID;
}

int Show::getSID()
{
    return this->SID;
}

string Show::getHall()
{
    return this->h.HallName;
}

void Show::setMovieID(int id)
{
    this->MovieID = id;
}

void Show::setSID(const int& id)
{
    this->SID = id;
}

ostream& operator<<(ostream& o, Show& md)
{
    o << left << setw(5) << md.getSID() << " | " << setw(10) << md.getHall() << " | " << md.TimeStart << " |  " 
        << ((md.TimeStart.getHour() > 9) ? "" : "0") << md.TimeStart.getHour() << " : " 
        << ((md.TimeStart.getMinute() > 9) ? "" : "0") << md.TimeStart.getMinute() << endl;
    return o;
}

bool Show::operator==(const Show& show)
{
    return this->SID == show.SID;
}

void Show::EnterShow()
{
    cout << "Enter Hall Number: ";
    cin >> this->h.HallName;
    cout << "Enter Day Start: ";
    this->TimeStart.setDay();
    cout << "Enter Month Start: ";
    this->TimeStart.setMonth();
    cout << "Enter Year Start: ";
    this->TimeStart.setYear();
    cout << "Enter Hour: ";
    this->TimeStart.setHour();
    cout << "Enter Minute: ";
    this->TimeStart.setMinute();
}

void Show::Print(ofstream& file)
{
    file << this->SID << " " << this->h.HallName << " " << this->getMovieID() << " "
    << ((this->TimeStart.getDay() > 9) ? "" : "0") << this->TimeStart.getDay() << " "
    << ((this->TimeStart.getMonth() > 9) ? "" : "0") << this->TimeStart.getMonth() << " " 
    << ((this->TimeStart.getYear() > 9) ? "" : "0") << this->TimeStart.getYear() << " "
    << ((this->TimeStart.getHour() > 9) ? "" : "0") << this->TimeStart.getHour() << " " 
    << ((this->TimeStart.getMinute() > 9) ? "" : "0") << this->TimeStart.getMinute() << endl;
}