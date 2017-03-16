#include <iostream>

#include "Testy.h"

using namespace std;

int main() {
    //Inicjalizacja klasy testującej
    Testy testy;
    int wybor = 99;

    cout << "SDiZO, Projekt 1, Igor Kurek, 226004" << endl << endl;


    //Początkowe menu wyboru
    while (wybor != 0) {
        cout << "Wybierz test:" << endl;
        cout << "    1. Tablica Dynamiczna" << endl;
        cout << "    2. Lista" << endl;
        cout << "    3. Kopiec Binarny" << endl;
        cout << "    4. Drzewo Czerowno-Czarne" << endl;
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
                cout << "Rozpoczynam test tablicy dynamicznej..." << endl;
                testy.testTablicy();
                break;

            case 2:
                cout << "Rozpoczynam test listy..." << endl;
                testy.testListy();
                break;

            case 3:
                cout << "Rozpoczynam test kopca binarnego..." << endl;
                testy.testKopca();
                break;

            case 4:
                cout << "Rozpoczynam test drzewa..." << endl;
                testy.testDrzewa();
                break;

        }
    }
    return 0;
}
