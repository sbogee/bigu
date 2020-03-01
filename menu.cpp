#include "menu.h"
#include <iostream>
#include <sstream>

using namespace std;

bool check(int a) { return a >= 0 && a <= menudb; }

template <typename Item>
Item read( const std::string &msg, const std::string &err, bool valid(Item))
{
    Item n;
    bool wrong;
    do {
        std::cout << msg;
        std::cin >> n;
        if ((wrong = std::cin.fail())) std::cin.clear();
        std::string tmp;
        getline(std::cin, tmp);
        wrong = wrong || tmp.size()!=0 || !valid(n);
        if (wrong) std::cout << err << std::endl;
    } while (wrong);
    return n;
}

void Menu::run()
{
    int v;
    do {
        v = printMenu();
        switch (v) {
            case 1:
                kivalaszt();
                printHalmaz();
                break;
            case 2:
                betesz();
                printHalmaz();
                break;
            case 3:
                kivesz();
                printHalmaz();
                break;
            case 4:
                printHalmaz();
                break;
            case 5:
                loadTest();
                break;
            case 6:
                ures();
                printHalmaz();
                break;
            default:
                cout<<"\nSee you!\n";
                break;

        }
    } while (v != 0);
}


int Menu::printMenu()
{
    int answer;
    cout << "\n****************************************\n";
    cout << "0. Quit\n";
    cout << "1. Get element\n";
    cout << "2. Add element\n";
    cout << "3. Remove element\n";
    cout << "4. Print Halmaz\n";
    cout << "5. Load test (maximum number of elements to add to Halmaz)\n";
    cout << "6. Is the Halmaz empty?\n";
    cout << "****************************************\n";
    ostringstream s;
    s << "Number should be between 0 and " << menudb << endl;
    string errorMessage = s.str();
    answer = read<int>(">>>", errorMessage, check);
    return answer;
}

void Menu::kivalaszt()
{
    Item e;
    bool fail = false;
    try {
        e = h.kivalaszt();
    } catch (Halmaz::Exception err) {
        fail = true;
        if (err == Halmaz::EMPTY_PRQUEUE)
            cerr << "kivalaszt failed, empty Halmaz!\n";
        else
            cerr << "The program doesn't work as intended, consult the writer :)\n";
    }
    if (!fail) cout << "Selected element:\n" << e << endl;
}

void Menu::betesz()
{
    Item e;
    cout << "Item to add:\n>>>>";
    cin >> e;
    h.betesz(e);
}

void Menu::ures()
{
    if (h.ures())
        cout << "The Halmaz is empty.\n";
    else
        cout << "The Halmaz is not empty.\n";
}

void Menu::kivesz()
{
    Item e;
    bool fail = false;
    try {
        e = h.kivesz();
    } catch (Halmaz::Exception err) {
        fail = true;
        if (err == Halmaz::EMPTY_PRQUEUE)
            cerr << "kivesz failed, empty Halmaz!\n";
        else
            cerr << "The program doesn't work as intended, consult the writer :)\n";
    }
    if (!fail) cout << "Element taken out:\n" << e << endl;
}
void Menu::loadTest()
{
    const long int size = 1000000000;
    Halmaz h;
    cout << "Current element:\n";
    try {
        for (long int i = 1; i < size; ++i) {
            if (i % 1000000 == 0) cout << i <<endl;
            h.add(Item("a", i));
        }
    } catch(...) {
        cerr << "No more memory!\n";
        cerr<<"Size of halmaz: " << h.getLength() << endl;
    }
}


void Menu::printHalmaz()
{
    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
    cout << "Halmaz:\n";
    cout << "Size of Halmaz (only for testing): " << h.getLength() << endl;
    for (int i = 0; i < h.getLength(); ++i) {
        cout << h.getElement(i) << endl;
    }
    cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n";
}



