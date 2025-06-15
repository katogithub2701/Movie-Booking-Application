#include <fstream>
#include <iomanip>
#include "Hall.h"
#include "Date.h"
class Show
{
    public:
        Date TimeStart;
        Hall h;
        int CreatedTicket;
    private:
        int SID;
        int MovieID;
    public:
        Show();
        ~Show();
        friend istream& operator>>(istream&, Show&);
        friend ostream& operator<<(ostream&, Show&);
        int getMovieID();
        int getSID();
        string getHall();
        int getTotalSeat();
        void setMovieID(int);
        void setSID(const int&);
        bool operator==(const Show&);
        void EnterShow();
        void Print(ofstream&);
};