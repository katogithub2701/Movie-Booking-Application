#include "User.h"

class Admin : public Person
{
    public:
        Admin();
        ~Admin();
        void ListRevenue();
        void AddMovie();
        void AddShow();
        void RemoveMovie();
        void RemoveShow();
        void MenuEM(int);
        void EditMovie();
        void MenuES(int);
        void EditShow();
        void SaveChange();
        void Menu(int);
        void ShowMenu();
};