#include "halmaz.h"

Halmaz::Halmaz() {};

Halmaz::Halmaz(vector<int> h)
{
    for(int i = 0; i <h.size(); ++i)
    {
        if(!eleme(h[i]))
        {
            this->h.push_back(h[i]);
        }
    }
}

bool eleme(int elem)
{
    for(int i = 0; i < h.size(); i++)
    {
        if(h[i] == elem)
        {
            return true;
        }
    }
    return false;
}

int Halmaz::kivalaszt(int i) const
{
    return h[i];
}



void Halmaz::betesz(int a)
{
    if(!eleme[a])
    {
        this->h.push_back(a);
    }
}

void Halmaz::kivesz(int i)
{
    if(!üres())
    {
        int a = h[i];
        h[i] = h.back();
        h.pop_back();
        return a;
    }
    else
    {
        throw EMPTY;
    }
}

int Halmaz::kivalaszt(int i) const
{
    if(!üres())
    {
        return h[i];
    }
    else
    {
        throw EMPTY;
    }
}

void Halmaz::kiiras() const
{
    cout << "{" << h[0];
    for(int i = 0; i < h.size();i++)
    {
        cout<<"," << h[i];
    }
    cout <<"}" << endl;
}

int Halmaz::osszeg() const
{
    int s = 0;
    for(int i = 0; i <h.size(); i++)
    {
        s += h[i];
    }
    return s;
}

bool Halmaz::ures()
{
    if(h.size() == 0)
    {
        return true;
    }
    return false;
}
