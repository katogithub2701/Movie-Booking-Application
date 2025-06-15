#include <windows.h>
#include "Person.h"

int Person::nextid = 15036;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

Person::Person()
{
    this->UID = this->nextid++;
    this->Admin = false;
    this->Name = "Ngo Quoc Anh";
    this->Gender = "Nam";
    this->PhoneNumber = "0123456789";
    this->Birth = Date(15, 1, 2004);
    this->ListM = nullptr;
    this->ListS = nullptr;
}

Person::Person(string name, Date birth, string gender, string phone)
    : Name(name), Birth(birth), Gender(gender), PhoneNumber(phone)
{ }

Person::~Person()
{ }

void Person::ListMovie(int arrPos)
{
    system("cls");
    int i = 0;
    cout << "Choose movie" << endl;
    SetConsoleTextAttribute(h, 5);
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << left << "   " <<  setw(3) << "ID" << " | " << setw(30) << "Title" << " | " << setw(8) << "Duration" << " | " 
        << setw(20) << "Director" << " | " << setw(25) << "Genre" << " | " 
        << setw(15) << "Language" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    SetConsoleTextAttribute(h, 7);
    Node<Movie>* temp = this->ListM->head;
    while (temp != nullptr && temp->next != nullptr) 
    {
        temp = temp->next;
    }
    while (temp != nullptr) 
    {
        if (i == arrPos)
        {
            SetConsoleTextAttribute(h, 12);
            cout << "-> " << temp->data;
            SetConsoleTextAttribute(h, 7);
        }
        else
            cout << "   " << temp->data;
        temp = temp->prev;
        i++;
    }
    cout << "---------------------------------------------------------------------------------------------------------------------\n";
    cout << endl;
}

void Person::ListShow(int arrPos, const Movie &m)
{
    system("cls");
    int i = 0;
    cout << "Choose show" << endl;
    SetConsoleTextAttribute(h, 2);
    cout << "------------------------------------------------\n";
    cout << left << "   " << setw(5) << "ID" << " | " << setw(10) << "Hall" << " | " << setw(10) << "Day" << " | " 
        << "TimeStart" << endl;
    cout << "------------------------------------------------\n";    
    SetConsoleTextAttribute(h, 7);
    Node<Show>* temp = m.ListSM.head;
    while (temp != nullptr && temp->next != nullptr) 
    {
        temp = temp->next;
    }
    while (temp != nullptr) 
    {
        if (i == arrPos)
        {
            SetConsoleTextAttribute(h, 13);
            cout << "-> " << temp->data;
            SetConsoleTextAttribute(h, 7);
        }
        else
            cout << "   " << temp->data;
        temp = temp->prev;
        i++;
    }
    cout << "------------------------------------------------\n";
    cout << endl;
}

string Person::getName()
{
    return this->Name;
}

Date Person::getBirth()
{
    return this->Birth;
}

string Person::getGender()
{
    return this->Gender;
}

string Person::getPhoneNumber()
{
    return this->PhoneNumber;
}

void Person::ShowInfo()
{
    cout << left << setw(15) << "ID: " << this->UID << endl;
    cout << left << setw(15) << "Name: " << this->Name << endl;
    cout << left << setw(15) << "Birth: " << this->Birth << endl;
    cout << left << setw(15) << "Gender: " << this->Gender << endl;
    cout << left << setw(15) << "PhoneNumber: " << this->PhoneNumber << endl;
}