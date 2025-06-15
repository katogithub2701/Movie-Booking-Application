#include <iostream>

using namespace std;

class Date
{
    private:
        int Day;
        int Month;
        int Year;
        int Hour;
        int Minute;
    public:
        Date();
        ~Date();
        Date(int, int, int);
        void setDay();
        void setMonth();
        void setYear();
        void setHour();
        void setMinute();
        int getDay();
        int getMonth();
        int getYear();
        int getHour();
        int getMinute();
        friend istream& operator>>(istream&, Date&);
        friend ostream& operator<<(ostream&, const Date&);
};