#include <iostream>
#include <vector>
#include "halmaz.h"
#include "menu.h"

/* Valósítsa meg az egész számokat tartalmazó halmaz típust! Ábrázolja a halmaz elemeit egy
 * sorozatban! Implementálja a szokásos mûveleteket (adott elem betevése, kivétele, valamelyik
 * elem kiválasztása – de nem kivétele), valamint a halmaz elemeinek összegét visszaadó
 * mûveletet (ehhez célszerû a halmazt reprezentáló sorozat mellett külön eltárolni ezt az
 * összeget, és ezt karbantartani), továbbá egy halmaz kiírását! */

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

vector<Item> setup()
{
    int db;
    vector<Item> v;
    cout << "Please provide the number of contestants. (n)\n>>>";
    cin >> db;
    cout << "Please provide the (n) names and (n) results:\n>>>";
    Item tmp;
    for(int i = 0; i < db; ++i) {
        cin >> tmp;
        // cout << tmp << endl; - Ellenőrzés
        v.push_back(tmp);
    }
    return v;
}

int main()
{
    cout << "Halmaz" << endl;

    Menu Test;
    Test.run();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"



#endif
