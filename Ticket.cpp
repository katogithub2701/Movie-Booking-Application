#include "Ticket.h"

int Ticket::NextID = 1000;

Ticket::Ticket()
{ }
    
Ticket::~Ticket()
{ }

void Ticket::setHallSeatRow(int &R)
{
    this->hs.SetRow(R);
}

void Ticket::setHallSeatCol(int &C)
{
    this->hs.SetCol(C);
}

void Ticket::setHS(HallSeat &hs)
{
    this->hs = hs;
}

ostream& operator<<(ostream& o, Ticket& T)
{
    o << T.hs;
    return o;
}

void Ticket::setShow(Show &s)
{
    this->sh = &s;
}

string Ticket::getMovieName()
{
    return this->MovieName;
}

void Ticket::setMovieName(string name)
{
    this->MovieName = name;
}