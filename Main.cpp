#include "Admin.h"
//#include <windows.h>

//HANDLE hm = GetStdHandle(STD_OUTPUT_HANDLE);

// void LOGO()
// {
//     SetConsoleTextAttribute(hm, 1);
//     cout << "                 :-=-:     -==-.\n";
//     cout << "               -%@@@@@%- +@@@@@@#.\n";
//     cout << "              :@@@@@@@@@#@@@@@@@@%\n";
//     cout << "              :@@@@@@@@@#@@@@@@@@%\n";
//     SetConsoleTextAttribute(hm, 5);
//     cout << "               -%@@@@@%- +@@@@@@*.     .\n";;
//     cout << "               .*#@@@#*****%@@%*+ .-+#@@-\n";
//     cout << "               :@@@@@@@@@@@@@@@@% @@@@@@=\n";
//     cout << "               :@@@@@@@@@@@@@@@@% @@@@@@=\n";
//     SetConsoleTextAttribute(hm, 9);
//     cout << "               :@@@@@@@@@@@@@@@@% :=*#@@-\n";
//     cout << "               :@@@@@@@@@@@@@@@@%      .\n";
//     cout << "                ::::::-@@@#::::::\n";
//     cout << "                       #%#*\n";
//     cout << "                      #-*=++\n";
//     SetConsoleTextAttribute(hm, 12);
//     cout << "                     #= *= *=\n";
//     cout << "                    **++%#++#-\n";
//     cout << "                   ++   *=   #:\n";
//     SetConsoleTextAttribute(hm, 7);
// }
void Input(DoublyLinkedList<Movie> &MovieList, DoublyLinkedList<Show> &ShowList)
{
    // Nhap file vao
    ifstream MovieFile("MovieDB.txt");
    Movie TempM;
    while (MovieFile >> TempM)
    {
        MovieList.Insert(TempM);
    }
    MovieFile.close();
    ifstream ShowFile("ShowDB.txt");
    Show TempS;
    while (ShowFile >> TempS)
    {
        Node<Movie> *temp = MovieList.head;
        while (temp != nullptr && temp->next != nullptr)
        {
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            if (TempS.getMovieID() == temp->data.GetFilmID())
                temp->data.ListSM.Insert(TempS);
            temp = temp->prev;
        }
        ShowList.Insert(TempS);
    }
    ShowFile.close();
}

int main()
{
    DoublyLinkedList<Movie> MovieList;
    DoublyLinkedList<Show> ShowList;
    string account, password;
    User u;
    u.ListM = &MovieList;
    u.ListS = &ShowList;
    Admin a;
    a.ListM = &MovieList;
    a.ListS = &ShowList;
    
    // Nhap file vao
    Input(MovieList, ShowList);

    // Thuc hien chuong trinh

    while (1)
    {
        //LOGO();
        cout << "--------------------SIGN IN---------------------" << endl << endl;
        cout << setw(22) << "Account: ";
        cin >> account;
        cout << setw(22) << "Password: ";
        cin >> password;
        if (account == "admin" && password == "admin")
        {
            a.ShowMenu();
        }
        else if (account == "user" && password == "user")
        {
            u.ShowMenu();
        }
        else
        {
            system("cls");
            cout << "Wrong account or password!" << endl;
        }
    }
    return 0;
}