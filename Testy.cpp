#include <iostream>
#include "Testy.h"
#include "Tablica.h"

using namespace std;

Testy::Testy() {

}

void Testy::testTablicy() {
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;

    while (wybor != 0) {
        cout << "Wybierz funkcję tablicy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                tablica.dodajNaPoczatek(wartosc);
                tablica.wydrukujTablice();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                tablica.dodajNaKoniec(wartosc);
                tablica.wydrukujTablice();
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                tablica.dodajGdziekolwiek(wartosc, pozycja);
                break;

            case 4:
                break;

        }

    }
}