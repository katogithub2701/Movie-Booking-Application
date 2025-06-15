#include <iomanip>
#include "Show.h"

class Ticket
{
    public:
        int TicketID;
        static int NextID;
        const static int Price = 85000;
    private:
        string MovieName;
        Show *sh;
        HallSeat hs;
    public:
        Ticket();
        ~Ticket();
        void setHallSeatRow(int&);
        void setHallSeatCol(int&);
        void setShow(Show&);
        void setMovieName(string);
        string getMovieName();
        void setHS(HallSeat&);
        friend ostream& operator<<(ostream&, Ticket&);
};