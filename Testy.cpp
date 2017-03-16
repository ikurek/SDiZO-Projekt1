#include <iostream>
#include "Testy.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

using namespace std;


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
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
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
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                tablica.dodajNaKoniec(wartosc);
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                tablica.dodajGdziekolwiek(wartosc, pozycja);
                break;

            case 4:
                tablica.usunPierwszy();
                break;

            case 5:
                tablica.usunOstatni();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                tablica.usunKtorys(pozycja);
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                tablica.sprawdzCzyIstnieje(wartosc);
                break;

            case 8:
                tablica.wydrukujTablice();
                break;

        }

    }
}

void Testy::testListy() {
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;

    while (wybor != 0) {
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listę" << endl;
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
                lista.dodajNaPoczatek(wartosc);
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                lista.dodajNaKoniec(wartosc);
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                lista.dodajGdziekolwiek(wartosc, pozycja);
                break;

            case 4:
                lista.usunPierwszy();
                break;

            case 5:
                lista.usunOstatni();
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                lista.usunKtorys(pozycja);

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                lista.sprawdzCzyIstnieje(wartosc);
                break;

            case 8:
                lista.wydrukujListe();
                break;

        }

    }
}

void Testy::testKopca() {
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    while (wybor != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
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
                kopiec.dodaj(wartosc);
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                kopiec.usun(wartosc);
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                kopiec.sprawdzCzyIstnieje(wartosc);
                break;

            case 4:
                kopiec.wydrukujKopiec();
                break;

        }

    }
}

void Testy::testDrzewa() {
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    while (wybor != 0) {
        cout << "Wybierz funkcję Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
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
                drzewo.dodaj(wartosc);
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                drzewo.usun(wartosc);
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                drzewo.wyszukaj(wartosc);
                break;

            case 4:
                cout << "NIE DZIAŁA" << endl;
                break;

        }

    }
}
