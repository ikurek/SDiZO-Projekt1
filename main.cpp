#include <iostream>

#include "Testy.h"
#include "TestyAutomatyczne.h"

using namespace std;

int main() {
    //Inicjalizacja klasy testującej
    Testy testy;
    TestyAutomatyczne testyAutomatyczne;
    int wybor = 99;
    string tn = "n";

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

        //Zamknij, jeżeli wybrano 0
        if (wybor == 0) return 0;

        cout << "Automatyzować test? (t/n): ";
        cin >> tn;

        switch (wybor) {
            default:
                cout << "Błędny wybór!" << endl;
                break;

            case 0:
                break;

            case 1:
                cout << "Rozpoczynam test tablicy dynamicznej..." << endl;
                if (tn == "t") testyAutomatyczne.testTablicy();
                else testy.testTablicy();

                break;

            case 2:
                cout << "Rozpoczynam test listy..." << endl;
                if (tn == "t") testyAutomatyczne.testListy();
                else testy.testListy();
                break;

            case 3:
                cout << "Rozpoczynam test kopca binarnego..." << endl;
                if (tn == "t") testyAutomatyczne.testKopca();
                else testy.testKopca();
                break;

            case 4:
                cout << "Rozpoczynam test drzewa..." << endl;
                if (tn == "t") testyAutomatyczne.testDrzewa();
                else testy.testDrzewa();
                break;

        }
    }
    return 0;
}
