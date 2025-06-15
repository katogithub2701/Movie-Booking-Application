#include "Admin.h"
#include <conio.h>
//#include <windows.h>

//HANDLE ha = GetStdHandle(STD_OUTPUT_HANDLE);

Admin::Admin()
{
}

Admin::~Admin()
{
}

void Admin::ListRevenue()
{
    //SetConsoleTextAttribute(ha, 11);
    cout << "===================================================================\n";
    cout << "                            Revenue\n";
    cout << "===================================================================\n";
    //SetConsoleTextAttribute(ha, 7);
    Ticket price;
    Node<Movie> *tmp = this->ListM->head;
    //SetConsoleTextAttribute(ha, 30);
    cout << left << setw(30) << "Movie" << setw(15) << "Sold Ticket" << setw(15) << "TotalMoney" << endl;
    //SetConsoleTextAttribute(ha, 7); 
    while (tmp != nullptr && tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    while (tmp != nullptr)
    {
        cout << left << setw(30) << tmp->data.GetTitle() << setw(15) << tmp->data.TotalTicket << setw(15) << tmp->data.TotalTicket * price.Price << endl;
        tmp = tmp->prev;
    }
}

void Admin::AddMovie()
{
    Movie newmovie;
    newmovie.SetFilmID(this->ListM->head->data.GetFilmID() + 1);
    newmovie.EnterMovie();
    this->ListM->Insert(newmovie);
}

void Admin::AddShow()
{
    Show newshow;
    Node<Movie> *temp = this->ListM->head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    int i = 0;
    char ch;
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
            newshow.setMovieID(temp->data.GetFilmID());
            newshow.setSID(this->ListS->head->data.getSID() + 1);
            this->ListShow(-1, temp->data);
            newshow.EnterShow();
            this->ListS->Insert(newshow);
            temp->data.ListSM.Insert(newshow);
            system("cls");
            return;
        case 27:
            return;
        default:
            break;
        }
    }
}

void Admin::RemoveMovie()
{
    Node<Movie> *temp = this->ListM->head;
    Node<Show> *tempms;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    int i = 0;
    char ch;
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
            while (tempms != nullptr)
            {
                this->ListS->Remove(tempms->data);
                tempms = tempms->next;
            }
            this->ListM->Remove(temp->data);
            return;
        case 27:
            return;
        default:
            break;
        }
    }
}

void Admin::RemoveShow()
{
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
                    this->ListS->Remove(tempms->data);
                    temp->data.ListSM.Remove(tempms->data);
                    return;
                default:
                    break;
                }
            }
        case 27:
            return;
        default:
            break;
        }
    }
}

void Admin::MenuEM(int arrPos)
{
    system("cls");
    char option[6][30] = {"1. Change movie name", "2. Change duration", "3. Change director",
                          "4. Change genre", "5. Change language", "6. Back to main menu"};
    for (int i = 0; i < 6; i++)
    {
        if (i == arrPos)
        {
            //SetConsoleTextAttribute(ha, 6);
            cout << "-> " << option[i] << endl;
            //SetConsoleTextAttribute(ha, 7);
        }
        else
            cout << "   " << option[i] << endl;
    }
}

void Admin::EditMovie()
{
    string title, director, genre, language;
    int duration;
    Node<Movie> *temp = this->ListM->head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    int i = 0, m = 0;
    char ch, chm, pause;
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
            this->MenuEM(0);
            while (1)
            {
                chm = getch();
                switch (chm)
                {
                case 72:
                    if (m != 0)
                    {
                        m--;
                        this->MenuEM(m);
                    }
                    else
                    {
                        this->MenuEM(m);
                    }
                    break;
                case 80:
                    if (m != 5)
                    {
                        m++;
                        this->MenuEM(m);
                    }
                    else
                    {
                        this->MenuEM(m);
                    }
                    break;
                case 13:
                    switch (m + 1)
                    {
                    case 1:
                        cout << "Enter movie name: ";
                        cin.ignore();
                        getline(cin, title);
                        temp->data.SetTitle(title);
                        cout << "Done!" << endl;
                        cout << "Press any key to back" ;
                        pause = getch();
                        this->MenuEM(m);
                        break;
                    case 2:
                        cout << "Enter duration: ";
                        cin >> duration;
                        temp->data.SetDuration(duration);
                        cout << "Done!" << endl;
                        cout << "Press any key to back" ;
                        pause = getch();
                        this->MenuEM(m);
                        break;
                    case 3:
                        cout << "Enter director: ";
                        cin.ignore();
                        getline(cin, director);
                        temp->data.SetDirector(director);
                        cout << "Done!" << endl;
                        cout << "Press any key to back" ;
                        pause = getch();
                        this->MenuEM(m);
                        break;
                    case 4:
                        cout << "Enter genre: ";
                        getline(cin, genre);
                        temp->data.SetGenre(genre);
                        cout << "Done!" << endl;
                        cout << "Press any key to back" ;
                        pause = getch();
                        this->MenuEM(m);
                        break;
                    case 5:
                        cout << "Enter language: ";
                        getline(cin, language);
                        temp->data.SetLanguage(language);
                        cout << "Done!" << endl;
                        cout << "Press any key to back" ;
                        pause = getch();                        
                        this->MenuEM(m);
                        break;
                    case 6:
                        return;
                    }
                }
            }
            return;
        case 27:
            return;
        default:
            break;
        }
    }
}

void Admin::MenuES(int arrPos)
{
    system("cls");
    char option[3][30] = {"1. Change time start", "2. Change hall name", "3. Back to main menu"};
    for (int i = 0; i < 3; i++)
    {
        if (i == arrPos)
        {
            //SetConsoleTextAttribute(ha, 6);
            cout << "-> " << option[i] << endl;
            //SetConsoleTextAttribute(ha, 7);
        }
        else
            cout << "   " << option[i] << endl;
    }
}

void Admin::EditShow()
{
    Node<Movie> *temp = this->ListM->head;
    Node<Show> *tempms, *temps;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    int i = 0, l = 0, m = 0;
    char ch, chs, chm, pause;
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
            temps = this->ListS->head;
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
                    this->MenuES(0); 
                    while (1)
                    {
                        chm = getch();
                        switch (chm)
                        {
                        case 72:
                            if (m != 0)
                            {
                                m--;
                                this->MenuES(m);
                            }
                            else
                            {
                                this->MenuES(m);
                            }
                            break;
                        case 80:
                            if (m != 2)
                            {
                                m++;
                                this->MenuES(m);
                            }
                            else
                            {
                                this->MenuES(m);
                            }
                            break;
                        case 13:
                            while (temps != nullptr)
                            {
                                if (temps->data.getSID() == tempms->data.getSID())
                                    break;
                                temps = temps->next;
                            }
                            switch (m + 1)
                            {
                            case 1:
                                cout << "Enter Day Start: ";
                                tempms->data.TimeStart.setDay();
                                cout << "Enter Month Start: ";
                                tempms->data.TimeStart.setMonth();
                                cout << "Enter Year Start: ";
                                tempms->data.TimeStart.setYear();
                                cout << "Enter Hour: ";
                                tempms->data.TimeStart.setHour();
                                cout << "Enter Minute: ";
                                tempms->data.TimeStart.setMinute();
                                temps->data.TimeStart = tempms->data.TimeStart;
                                cout << "Done!" << endl;
                                cout << "Press any key to back" ;
                                pause = getch();
                                this->MenuES(m);
                                break;
                            case 2:
                                cout << "Enter Hall Number: ";
                                cin >> tempms->data.h.HallName;
                                temps->data.h.HallName = tempms->data.h.HallName;
                                cout << "Done!" << endl;
                                cout << "Press any key to back" ;
                                pause = getch();
                                this->MenuES(m);
                                break;
                            case 3:
                                return;
                            }
                            return;
                        }
                    }
                case 27:
                    return;
                }
            }
            return;
        case 27:
            return;
        }
    }
}

void Admin::SaveChange()
{
    // In file danh sach Movie
    ofstream ClearMFile("MovieDB.txt", ios::trunc);
    ClearMFile.close();
    ofstream PrintMFile("MovieDB.txt", ios::app);
    Node<Movie> *temp = this->ListM->head;
    while (temp != nullptr && temp->next != nullptr)
    {
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        temp->data.Print(PrintMFile);
        temp = temp->prev;
    }
    PrintMFile.close();

    // In file danh sach Show
    ofstream ClearSFile("ShowDB.txt", ios::trunc);
    ClearSFile.close();
    ofstream PrintSFile("ShowDB.txt", ios::app);
    Node<Show> *temps = this->ListS->head;
    while (temps != nullptr && temps->next != nullptr)
    {
        temps = temps->next;
    }
    while (temps != nullptr)
    {
        temps->data.Print(PrintSFile);
        temps = temps->prev;
    }
    PrintSFile.close();
}

void Admin::Menu(int arrPos)
{
    system("cls");
    char option[9][30] = {"1. View revenue", "2. Add movie", "3. Remove movie",
                          "4. Edit movie", "5. Add show", "6. Remove show",
                          "7. Edit show", "8. Show movie list", "9. Exit and save"};
    //SetConsoleTextAttribute(ha, 11);
    cout << "   -----------------" << endl;
    cout << "       Main menu" << endl;
    cout << "   -----------------" << endl;
    //SetConsoleTextAttribute(ha, 7);
    for (int i = 0; i < 9; i++)
    {
        if (i == arrPos)
        {
            //SetConsoleTextAttribute(ha, 10);
            cout << "-> " << option[i] << endl;
            //SetConsoleTextAttribute(ha, 7);
        }
        else
            cout << "   " << option[i] << endl;
    }
}

void Admin::ShowMenu()
{
    int i = 0;
    char ch, pause;
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
            if (i != 8)
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
                this->ListRevenue();
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 2:
                this->AddMovie();
                cout << "Done!" << endl;
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 3:
                this->RemoveMovie();
                cout << "Done!" << endl;
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 4:
                this->EditMovie();
                this->Menu(i);
                break;
            case 5:
                this->AddShow();
                cout << "Done!" << endl;
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 6:
                this->RemoveShow();
                cout << "Done!" << endl;
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 7:
                this->EditShow();
                this->Menu(i);
                break;
            case 8:
                this->ListMovie(-1);
                cout << "Press any key to back to main menu" ;
                pause = getch();
                this->Menu(i);
                break;
            case 9:
                this->SaveChange();
                return;
            default:
                cout << "Error!" << endl;
                break;
            }
            break;
        case 27:
            return;
        default:
            break;
        }
    }
}