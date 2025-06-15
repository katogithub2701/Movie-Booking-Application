#include "User.h"
#include <conio.h>
//#include <windows.h>
//HANDLE hu= GetStdHandle(STD_OUTPUT_HANDLE);
static int BID = 1;

User::User()
{
}

User::~User()
{
}

void User::CreateTicket(Ticket &newticket, Show &s)
{
    newticket.setShow(s);
    newticket.TicketID = newticket.NextID++;
    bool check;
    do
    {
        cout << "Enter seat(Eg: A0): ";
        char cr;
        cin >> cr;
        int r;
        int c;
        cin >> c;
        if (cr > 'J' || cr < 'A' || c > 9 || c < 0)
        {
            cout << "Error! Enter again." << endl;
        }
        else
        {
            switch (cr)
            {
            case 'A':
                r = 0;
                break;
            case 'B':
                r = 1;
                break;
            case 'C':
                r = 2;
                break;
            case 'D':
                r = 3;
                break;
            case 'E':
                r = 4;
                break;
            case 'F':
                r = 5;
                break;
            case 'G':
                r = 6;
                break;
            case 'H':
                r = 7;
                break;
            case 'I':
                r = 8;
                break;
            case 'J':
                r = 9;
                break;
            default:
                break;
            }
            newticket.setHallSeatRow(r);
            newticket.setHallSeatCol(c);
            if (s.h.hs[r][c].GetStatusSeat() == 0)
            {
                s.h.hs[r][c].ChangeSeatStatus();
                break;
            }
            else
            {
                cout << "Error! Enter again." << endl;
            }
            break;
        }
    } while (1);
    s.CreatedTicket++;
}

void User::Booking()
{
    int index = 0;
    Ticket *newt;
    Bill b;
    string fileName = "Bill" + to_string(BID++) + ".txt";
    ofstream Bill(fileName);
    Node<Movie> *temp = this->ListM->head;
    Node<Show> *tempms;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    int i = 0, l = 0;
    char ch, chs;
    this->ListMovie(0);
    while (1)
    {
        ch = getch();
        switch (ch)
        {
        case 72:
            if (temp->next != nullptr)
            {
                i--;
                temp = temp->next;
                this->ListMovie(i);
            }
            else
            {
                this->ListMovie(i);
            }
            break;
        case 80:
            if (temp->prev != nullptr)
            {
                i++;
                temp = temp->prev;
                this->ListMovie(i);
            }
            else
            {
                this->ListMovie(i);
            }
            break;
        case 13:
            tempms = temp->data.ListSM.head;
            while (tempms != nullptr && tempms->next != nullptr)
            {
                tempms = tempms->next;
            }
            system("cls");
            this->ListShow(l, temp->data);
            while (1)
            {
                chs = getch();
                switch (chs)
                {
                case 72:
                    if (tempms->next != nullptr)
                    {
                        l--;
                        tempms = tempms->next;
                        this->ListShow(l, temp->data);
                    }
                    else
                    {
                        this->ListShow(l, temp->data);
                    }
                    break;
                case 80:
                    if (tempms->prev != nullptr)
                    {
                        l++;
                        tempms = tempms->prev;
                        this->ListShow(l, temp->data);
                    }
                    else
                    {
                        this->ListShow(l, temp->data);
                    }
                    break;
                case 13:
                    system("cls");
                    cout << "How many ticket(s) do you want to book?" << endl;
                    cout << "Input your index: ";
                    cin >> index;
                    newt = new Ticket[index];
                    system("cls");
                    tempms->data.h.ShowSeats();
                    for (int k = 0; k < index; k++)
                    {
                        newt[k].setMovieName(temp->data.GetTitle());
                        this->CreateTicket(newt[k], tempms->data);
                        temp->data.TotalTicket++;
                        system("cls");
                        tempms->data.h.ShowSeats();
                    }
                    system("cls");
                    b.setLength(index);
                    b.setTicketList(newt);
                    b.setHallName(tempms->data.h.HallName);
                    b.setDate(tempms->data.TimeStart);
                    this->ListB.Insert(b);
                    cout << b;
                    Bill << b;
                    Bill.close();
                    system("pause");
                    return;
                default:
                    break;
                }
            }
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }
}

void User::Menu(int arrPos)
{
    system("cls");
    char option[4][30] = {"1. Create a ticket", "2. View bills", "3. Show infomation", "4. Exit"};
    //SetConsoleTextAttribute(hu, 11);
    cout << "   -----------------" << endl;
    cout << "       Main menu" << endl;
    cout << "   -----------------" << endl;
    //SetConsoleTextAttribute(hu, 7);
    for (int i = 0; i < 4; i++)
    {
        if (i == arrPos)
        {
            //SetConsoleTextAttribute(hu, 10);
            cout << "-> " << option[i] << endl;
            //SetConsoleTextAttribute(hu, 7);
        }
        else
            cout << "   " << option[i] << endl;
    }
}

void User::ShowMenu()
{
    int i = 0;
    char ch;
    this->Menu(0);
    while (1)
    {
        ch = getch();
        switch (ch)
        {
        case 72:
            if (i != 0)
            {
                i--;
                this->Menu(i);
            }
            else
            {
                this->Menu(i);
            }
            break;
        case 80:
            if (i != 3)
            {
                i++;
                this->Menu(i);
            }
            else
            {
                this->Menu(i);
            }
            break;
        case 13:
            system("cls");
            switch (i + 1)
            {
            case 1:
                this->Booking();
                this->Menu(i);
                break;
            case 2:
                this->ListB.Display();
                system("pause");
                this->Menu(i);
                break;
            case 3:
                this->ShowInfo();
                system("pause");
                this->Menu(i);
                break;
            case 4:
                return;
            default:
                break;
            }
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }
}