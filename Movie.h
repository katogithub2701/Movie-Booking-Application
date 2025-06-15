#include <string>
#include "Bill.h"

class Movie
{
    protected:
        int FilmID;
        string Title;
        int Duration;
        string Director;
        string Genre;
        string Language;
    public:
        DoublyLinkedList<Show> ListSM;
        int TotalTicket;
        Movie();
        ~Movie();
        friend istream& operator>>(istream&, Movie&);
        friend ostream& operator<<(ostream&, const Movie&);
        bool operator==(const Movie&);
        int GetFilmID();
        string GetTitle();

        void SetFilmID(int);
        void SetTitle(string);
        void SetDuration(int);
        void SetDirector(string);
        void SetGenre(string);
        void SetLanguage(string);

        void EnterMovie();
        void Print(ofstream&);
};