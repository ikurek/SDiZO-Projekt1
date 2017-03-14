#include <iostream>
#include "Kopiec.h"

using namespace std;

Kopiec::Kopiec() {
    Kopiec::tablica = NULL;
    Kopiec::rozmiar = 0;
}

Kopiec::~Kopiec() {

    if (Kopiec::rozmiar > 0) {
        delete[]Kopiec::tablica;
    }

}

void Kopiec::dodaj(int wartosc) {

    //Wartości w kopcu nie mogą się powtarzać
    //Kontynuuj tylko, jeżeli wartość nie istnieje jeszcze w kopcu
    if (!Kopiec::sprawdzCzyIstnieje(wartosc)) {

        //Stwórz nową tablicę większą o jeden element
        int *nowaTablica = new int[Kopiec::rozmiar + 1];


    } else {

        cout << "Wartość " << wartosc << " już istnieje w kopcu!" << endl;

    }

}

void Kopiec::usun(int wartosc) {}

bool Kopiec::sprawdzCzyIstnieje(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < Kopiec::rozmiar; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (Kopiec::tablica[i] == wartosc) {
            cout << "Szukana wartość zajmuje w tablicy kopca pozycję [" << i << "]" << endl;
            return true;
        }
    }
    //Jeżeli wartość nie wystąpiła w żadnej iteracji tabeli zwróć false
    cout << "Szukana wartość nie występuje w kopcu" << endl;
    return false;

}

void Kopiec::wydrukujKopiec() {}