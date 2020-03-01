#ifndef MENU_H
#define MENU_H
#include "halmaz.h"


class Menu
{
    public:
        Menu() {};
        void run();

    private:
        int printMenu();
        int kivalaszt();
        void betesz();
        void kivesz();
        void kiiras();
        int osszeg();
        bool ures();
        Halmaz h;
};

#endif // MENU_H
