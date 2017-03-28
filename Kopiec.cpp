#include <iostream>
#include <cmath>
#include "Kopiec.h"

using namespace std;

Kopiec::Kopiec() {
    Kopiec::tablica = NULL;
    Kopiec::rozmiar = 0;
}

Kopiec::~Kopiec() {

    if (Kopiec::rozmiar > 0) {
        delete[]tablica;
    }

}

void Kopiec::dodaj(int wartosc) {

    //Wartości w kopcu nie mogą się powtarzać
    //Kontynuuj tylko, jeżeli wartość nie istnieje jeszcze w kopcu
    if (!Kopiec::sprawdzCzyIstnieje(wartosc)) {

        //Stwórz nową tablicę większą o jeden element
        int *nowaTablica = new int[rozmiar + 1];

        //Przepisanie danych ze starej tablicy do nowej
        for (int i = 0; i < rozmiar; i++) {
            nowaTablica[i] = tablica[i];
        }

        //Dodanie wybranej wartości do kopca
        nowaTablica[rozmiar] = wartosc;

        //Usuń starą tablicę
        delete[]tablica;

        //Zastąp starą tablicę nową
        tablica = nowaTablica;

        //Popraw kolejność elementów w kopcu
        Kopiec::poprawStrukture();

        //Zwiększ rozmiar kopca
        rozmiar++;


    }

}

void Kopiec::usun(int wartosc) {

    //Iteracja po całej tablicy kopca w elu znalezienia wartości
    for (int i = 0; i < rozmiar; i++) {

        if (tablica[i] == wartosc) {

            //Stwórz nową tablicę, pomniejszoną o jeden element
            int *nowaTablica = new int[rozmiar - 1];

            //Przepisz elementy z tablicy do pozycji na której znajduje się usuwany element
            for (int k = 0; k < i; k++) {
                nowaTablica[k] = tablica[k];
            }

            //Przepisz pozostałe elementy przesunięte o jedną pozycję
            for (int k = i + 1; k < rozmiar; k++) {
                nowaTablica[k - 1] = tablica[k];
            }

            //usuń starą tablicę i przypisz na jej miejsce nową
            delete[]tablica;
            tablica = nowaTablica;

            //Zmniejsz rozmiar tablicy
            rozmiar--;

            //Popraw kolejność elementów w tablicy kopca
            Kopiec::poprawStrukture();
            return;

        }

    }

}

bool Kopiec::sprawdzCzyIstnieje(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < rozmiar; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (tablica[i] == wartosc) {
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
    for (int i = rozmiar; 0 < i; i--) {
        if (tablica[i - 1] < tablica[i]) {
            tymczasowa = tablica[i - 1];
            tablica[i - 1] = tablica[i];
            tablica[i] = tymczasowa;
        }


    }

}

int Kopiec::iloscPoziomow() {

    int iloscPoziomow = 0;
    int iloscElementow = 0;

    do {
        iloscElementow = iloscElementow + pow(2, iloscPoziomow);
        iloscPoziomow = iloscPoziomow + 1;
    } while (iloscElementow < rozmiar);

    return iloscPoziomow;
}