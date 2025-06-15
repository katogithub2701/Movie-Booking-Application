#include "Movie.h"

class Person
{
    private:
        static int nextid;
        int UID;
        bool Admin;
        string Name;
        Date Birth;
        string Gender;
        string PhoneNumber;
    public:
        DoublyLinkedList<Movie> *ListM;
        DoublyLinkedList<Show> *ListS;
        DoublyLinkedList<Ticket> ListT;
    public:
        Person();
        Person(string, Date, string, string);
        ~Person();
        void ListMovie(int);
        void ListShow(int,const Movie&);
        void Booking(int);
        string getName();
        Date getBirth();
        string getAddress();
        string getGender();
        string getPhoneNumber();
        string getEmail();
        void ShowInfo();  
};
