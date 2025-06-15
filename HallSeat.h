#include <iostream>
using namespace std;

class HallSeat
{
    private:
        bool SeatStatus;
        int Hall_Col;
        int Hall_Row;
    public:
        HallSeat();
        ~HallSeat();
        friend ostream& operator<<(ostream&, const HallSeat&);
        const HallSeat& operator=(const HallSeat&);
        void ChangeSeatStatus();
        void SetCol(int);
        void SetRow(int);
        bool GetStatusSeat();
};