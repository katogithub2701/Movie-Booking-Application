#include "Hall.h"

Hall::Hall()
{
    this->HallName = "";
}

Hall::~Hall()
{
}

void Hall::ShowSeats()
{
    cout << "=================================================";
    cout << "\n-------- S     C     R     E     E     N --------" << endl;
    cout << "=================================================\n";
    cout << "<- EXIT                               ENTRANCE <-\n" << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            (this->hs)[i][j].SetRow(i);
            (this->hs)[i][j].SetCol(j);
            cout << *(*(this->hs + i) + j);
        }
        cout << endl;
        cout << endl;   
    }
    cout << "- White: Empty\n";
    cout << "- Red: Booked\n";
}

istream& operator>>(istream& i, Hall& H)
{
    i >> H.HallName;
    return i;
}