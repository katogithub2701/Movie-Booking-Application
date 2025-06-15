//#include <windows.h>
#include "HallSeat.h"

//HANDLE hS = GetStdHandle(STD_OUTPUT_HANDLE);

HallSeat::HallSeat()
{
    this->SeatStatus = false;
    this->Hall_Col = -1;
    this->Hall_Row = -1;
}

HallSeat::~HallSeat()
{
}

ostream& operator<<(ostream& o, const HallSeat& s)
{
    char rowlabel = 'A' + s.Hall_Row;
    if (s.SeatStatus == false)
    {
        o << "[" << rowlabel << s.Hall_Col << "] ";
    }
    else
    {
        //SetConsoleTextAttribute(hS, 4);
        o << "[" << rowlabel << s.Hall_Col << "] ";
        //SetConsoleTextAttribute(hS, 7);
    }
    return o;
}

void HallSeat::SetCol(int temp)
{
    this->Hall_Col = temp;
}

void HallSeat::SetRow(int temp)
{
    this->Hall_Row = temp;
}

void HallSeat::ChangeSeatStatus()
{
    this->SeatStatus = !this->SeatStatus;
}

bool HallSeat::GetStatusSeat()
{
    return this->SeatStatus;
}

const HallSeat& HallSeat::operator=(const HallSeat& hs)
{
    this->SeatStatus = hs.SeatStatus;
    this->Hall_Col = hs.Hall_Col;
    this->Hall_Row = hs.Hall_Row;
    return *this;
}
