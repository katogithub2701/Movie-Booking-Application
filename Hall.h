#include "HallSeat.h"

class Hall
{
    public:
        string HallName;
        HallSeat hs[10][10];
    public:
        Hall();
        ~Hall();
        void ShowSeats();
        friend istream& operator>>(istream&, Hall&);
};