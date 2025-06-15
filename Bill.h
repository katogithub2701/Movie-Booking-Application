#include <iomanip>
#include "DoublyLinkedList.cpp"
#include "Ticket.h"

class Bill
{
    private:
        Date TimeStart;
        int length;
        Ticket *TicketList;
        string HallName;
    public:
        Bill();
        ~Bill();
        void setDate(Date&);
        void setTicketList(Ticket*);
        void setLength(int);
        void setHallName(string);
        friend ostream& operator<<(ostream&, Bill&);
};