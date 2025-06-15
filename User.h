#include "Person.h"

class User : public Person
{
    public:
        DoublyLinkedList<Bill> ListB;
    public:
        User();
        ~User();
        void CreateTicket(Ticket&, Show&);
        void Menu(int);
        void ShowMenu();
        void Booking();
        void ListRevenue();
        void AddMovie();
        void AddShow();
};