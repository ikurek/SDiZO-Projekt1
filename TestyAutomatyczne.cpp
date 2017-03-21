#include <iostream>
#include <fstream>
#include "TestyAutomatyczne.h"
#include "Czas.h"
#include "Tablica.h"
#include "Lista.h"
#include "Kopiec.h"
#include "Drzewo.h"

using namespace std;

void TestyAutomatyczne::testTablicy() {
    Czas czas;
    Tablica tablica;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

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

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                return;

            case 1:
                cout << "Rozpoczynam test automatyczny...";

                while (plikWejsciowy.good()) {
                    //Wczytaj wartość z pliku
                    plikWejsciowy >> wartosc;
                    cout << "Wczytuje wartosc " << wartosc << endl;
                    //Wykonaj funkcję z pomiarem
                    czas.czasStart();
                    tablica.dodajNaPoczatek(wartosc);
                    czas.czasStop();
                    //Zapisz do pliku wynik pomiaru
                    plikWyjsciowy << czas.czasWykonania() << endl;
                    cout << "Zapisuje wartosc " << czas.czasWykonania() << endl;
                }

                //Zamknij oba pliki
                plikWejsciowy.close();
                plikWyjsciowy.close();
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                tablica.dodajNaKoniec(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                tablica.dodajGdziekolwiek(wartosc, pozycja);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 4:
                czas.czasStart();
                tablica.usunPierwszy();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 5:
                czas.czasStart();
                tablica.usunOstatni();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                tablica.usunKtorys(pozycja);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                tablica.sprawdzCzyIstnieje(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 8:
                czas.czasStart();
                tablica.wydrukujTablice();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;
        }

    }
}

void TestyAutomatyczne::testListy() {
    Czas czas;
    Lista lista;
    int wybor = 99;
    int wartosc;
    int pozycja;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;


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
        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodajNaPoczatek(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                lista.dodajNaKoniec(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                lista.dodajGdziekolwiek(wartosc, pozycja);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 4:
                czas.czasStart();
                lista.usunPierwszy();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 5:
                czas.czasStart();
                lista.usunOstatni();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 6:
                cout << "Podaj pozycję: ";
                cin >> pozycja;
                czas.czasStart();
                lista.usunKtorys(pozycja);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;

            case 7:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                lista.sprawdzCzyIstnieje(wartosc);
                break;

            case 8:
                czas.czasStart();
                lista.wydrukujListe();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

        }

    }
}

void TestyAutomatyczne::testKopca() {
    Czas czas;
    Kopiec kopiec;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                kopiec.dodaj(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                kopiec.usun(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                kopiec.sprawdzCzyIstnieje(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 4:
                czas.czasStart();
                kopiec.wydrukujKopiec();
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;
        }

    }
}

void TestyAutomatyczne::testDrzewa() {
    Czas czas;
    Drzewo drzewo;
    int wybor = 99;
    int wartosc;
    string daneWyjsciowe;
    string daneWejsciowe;
    ofstream plikWyjsciowy;
    ifstream plikWejsciowy;

    while (wybor != 0) {
        cout << "Wybierz funkcję Drzewa:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wyszukaj" << endl;
        cout << "    4. Wydrukuj drzewo" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cout << "Wybór: ";
        cin >> wybor;
        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return;

        cout << "Plik zawierający dane wejściowe: ";
        cin >> daneWejsciowe;
        cout << "Plik z wynikami testu: ";
        cin >> daneWyjsciowe;


        //Otwórz pliki
        plikWejsciowy.open("/home/igor/SDiZO-Projekt/Input/" + daneWejsciowe);
        plikWyjsciowy.open("/home/igor/SDiZO-Projekt/Output/" + daneWyjsciowe, fstream::out);
        //Sprawdż czy plik jest otwarty poprawnie
        if (plikWejsciowy.is_open()) {
            cout << "Otwarto plik " << daneWejsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wejściowego!" << endl;
            return;
        }

        if (plikWyjsciowy.is_open()) {
            cout << "Otwarto plik " << daneWyjsciowe << endl;
        } else {
            cout << "Nie udało się otworzyć pliku wyjściowego!" << endl;
            return;
        }

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.dodaj(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 2:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.usun(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 3:
                cout << "Podaj wartość: ";
                cin >> wartosc;
                czas.czasStart();
                drzewo.wyszukaj(wartosc);
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

            case 4:
                czas.czasStart();
                cout << "NIE DZIAŁA" << endl;
                czas.czasStop();
                cout << "Czas wykonania: " << czas.czasWykonania() << "ms" << endl;
                break;

        }

    }
}