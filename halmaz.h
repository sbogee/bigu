#ifndef HALMAZ_H
#define HALMAZ_H

#include <vector>
#include <iostream>
#include <ostream>

class Halmaz
{
    public:
        Halmaz();
        Halmaz(vector<int> h);
        bool eleme(int elem);
        int kivalaszt(int i) const;
        void betesz(int a);
        void kivesz(int i);
        void kiiras() const;
        int osszeg() const;
        bool ures();

    private:
        vector <int> h;
};

#endif // HALMAZ_H
