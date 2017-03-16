#include <iostream>
#include "Kopiec.h"
#include <cmath>

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

        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < Kopiec::rozmiar; i++) {
            nowaTablica[i] = Kopiec::tablica[i];
        }

        //Dodanie wybranej wartości do kopca
        nowaTablica[Kopiec::rozmiar] = wartosc;

        //Usuń starą tablicę
        delete[]Kopiec::tablica;

        //Zastąp starą tablicę nową
        Kopiec::tablica = nowaTablica;

        //Popraw kolejność elementów w kopcu
        cout << "Poprawianie struktury kopca..." << endl;
        Kopiec::poprawStrukture();

        //Zwiększ rozmiar kopca
        Kopiec::rozmiar = Kopiec::rozmiar + 1;






    }

}

void Kopiec::usun(int wartosc) {

    //Iteracja po całej tablicy kopca w elu znalezienia wartości
    for (int i = 0; i < Kopiec::rozmiar; i++) {

        if (Kopiec::tablica[i] == wartosc) {

            //Stwórz nową tablicę, pomniejszoną o jeden element
            int *nowaTablica = new int[Kopiec::rozmiar - 1];

            //Przepisz elementy z tablicy do pozycji na której znajduje się usuwany element
            for (int k = 0; k < i; k++) {
                nowaTablica[k] = Kopiec::tablica[k];
            }

            //Przepisz pozostałe elementy przesunięte o jedną pozycję
            for (int k = i + 1; k < Kopiec::rozmiar; k++) {
                nowaTablica[k - 1] = Kopiec::tablica[k];
            }

            //usuń starą tablicę i przypisz na jej miejsce nową
            delete[]Kopiec::tablica;
            Kopiec::tablica = nowaTablica;

            //Zmniejsz rozmiar tablicy
            Kopiec::rozmiar = Kopiec::rozmiar - 1;

            //Popraw kolejność elementów w tablicy kopca
            Kopiec::poprawStrukture();

        }

    }

}

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


//FIXME: Nie diała
void Kopiec::wydrukujKopiec() {


}

void Kopiec::poprawStrukture() {

    //Zmienna pomocnicza do pętli sortującej
    int tymczasowa = 0;

    //Pętla sortująca, układająca elementy kopca w odpowiedniej kolejności
    //
    for (int i = Kopiec::rozmiar; 0 < i; i--) {
        if (Kopiec::tablica[i - 1] < Kopiec::tablica[i]) {
            tymczasowa = Kopiec::tablica[i - 1];
            Kopiec::tablica[i - 1] = Kopiec::tablica[i];
            Kopiec::tablica[i] = tymczasowa;
        }


    }

}

int Kopiec::iloscPoziomow() {

    int iloscPoziomow = 0;
    int iloscElementow = 0;

    do {
        iloscElementow = iloscElementow + pow(2, iloscPoziomow);
        iloscPoziomow = iloscPoziomow + 1;
    } while (iloscElementow < Kopiec::rozmiar);

    return iloscPoziomow;
}