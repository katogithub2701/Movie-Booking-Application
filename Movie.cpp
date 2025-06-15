#include "Movie.h"
#include <cstdlib>
#include <iomanip>
#include <string>

Movie::Movie()
{
    this->FilmID = -1;
    this->Title = "Unknown";
    this->Duration = -1;
    this->Director = "Unknown";
    this->Genre = "Unknown";
    this->Language = "Unknown";
    this->TotalTicket = 0;
}

Movie::~Movie()
{ }

istream& operator>>(istream& i, Movie& m)
{
    i >> m.FilmID;
    i.ignore();
    getline(i, m.Title, ','); 
    i >> m.Duration;
    i.ignore();
    getline(i, m.Director, ','); 
    i.ignore();
    getline(i, m.Genre, ','); 
    i.ignore();
    getline(i, m.Language, ','); 
    return i;
}

ostream& operator<<(ostream& o, const Movie& m)
{
    o << left << setw(3) << m.FilmID << " | " << setw(30) << m.Title << " | " << setw(8) << m.Duration << " | " 
        << setw(20) << m.Director << " | " << setw(25) << m.Genre << " | " 
        << setw(15) << m.Language << endl;
    return o;
}

bool Movie::operator==(const Movie& m)
{
    return this->FilmID == m.FilmID;
}

int Movie::GetFilmID()
{
    return this->FilmID;
}

string Movie::GetTitle()
{
    return this->Title;
}

void Movie::SetFilmID(int id)
{
    this->FilmID = id;
}

void Movie::SetTitle(string t)
{
    this->Title = t;
}

void Movie::SetDuration(int d)
{
    this->Duration = d;
}

void Movie::SetDirector(string d)
{
    this->Director = d;
}

void Movie::SetGenre(string g)
{
    this->Genre = g;
}

void Movie::SetLanguage(string l)
{
    this->Language = l;
}

void Movie::EnterMovie()
{
    cout << "Enter movie name: "; 
    cin.ignore();
    getline(cin, this->Title); 
    cout << "Enter duration(minute): "; cin >> this->Duration;
    cout << "Enter director name: "; 
    cin.ignore();
    getline(cin, this->Director);
    cout << "Enter genre: "; 
    getline(cin, this->Genre);
    cout << "Enter language: "; 
    getline(cin, this->Language);
}

void Movie::Print(ofstream &file)
{
    file << this->FilmID << " " << this->Title << ", " << this->Duration << " "
    << this->Director << ", " << this->Genre << ", " << this->Language << "," << endl;
}