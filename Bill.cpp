#include "Bill.h"

Bill::Bill()
{
    this->length = 0;
}

Bill::~Bill()
{
}

void Bill::setDate(Date& d)
{
    this->TimeStart = d;
}

void Bill::setTicketList(Ticket* t)
{
    this->TicketList = t;
}

void Bill::setLength(int l)
{
    this->length = l;
}

void Bill::setHallName(string hn)
{
    this->HallName = hn;
}

ostream& operator<<(ostream& o,Bill& b)
{
    o << "--------------- BILL ---------------" << endl;
    o << left << setw(15) << "Film:" << b.TicketList->getMovieName() << endl;
    o << left << setw(15) << "Hall:" << b.HallName << endl;
    o << left << setw(15) << "Date:" << ((b.TimeStart.getHour() > 9) ? "" : "0") << b.TimeStart.getHour() << ":" 
                        << ((b.TimeStart.getMinute() > 9) ? "" : "0") << b.TimeStart.getMinute() << " " << b.TimeStart << endl;
    o << left << setw(15) << "Ticket:" << b.length << " x Ticket " << "( ";
    for (int i = 0; i < b.length; i++)
    {
        o << *(b.TicketList + i);
    }
    o << ")" << endl;
    o << left << setw(15) << "Total Price: " << b.TicketList->Price*b.length << endl;
    o << endl;
    return o;
}