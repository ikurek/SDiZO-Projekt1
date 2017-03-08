#include <iostream>
#include "Tablica.h"

using namespace std;

//Konstruktor inicjalizuje zmienne klasowe
Tablica::Tablica() {

    Tablica::wskaznikNaHead = NULL;
    Tablica::rozmiarTablicy = 0;

}

//Destruktor zwalnia pamięć tablicy, jeżeli istnieje
Tablica::~Tablica() {

    if (Tablica::wskaznikNaHead != NULL) {
        delete[]Tablica::wskaznikNaHead;
    }
}

void Tablica::dodajNaPoczatek(int wartosc) {

    //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
    //Przypisz podaną wartość jako pierwszy element tablicy
    int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy + 1];
    nowyWskaznikNaHead[0] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < Tablica::rozmiarTablicy; i++) {
        nowyWskaznikNaHead[i + 1] = Tablica::wskaznikNaHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
    delete Tablica::wskaznikNaHead;
    Tablica::wskaznikNaHead = nowyWskaznikNaHead;

    //Zwiększ rozmiar tablicy o 1
    Tablica::rozmiarTablicy = Tablica::rozmiarTablicy + 1;

}

void Tablica::dodajNaKoniec(int wartosc) {

    //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
    //Przypisz podaną wartość jako ostatni element tablicy
    int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy + 1];
    nowyWskaznikNaHead[Tablica::rozmiarTablicy] = wartosc;

    //Przepisz dane ze starej tablicy do nowej
    for (int i = 0; i < Tablica::rozmiarTablicy; i++) {
        nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i];
    }

    //Zwolnij pamięć poprzedniej tablicy
    //Zastąp wskaźnik na głowę tablicy nowym
    delete Tablica::wskaznikNaHead;
    Tablica::wskaznikNaHead = nowyWskaznikNaHead;

    //Zwiększ rozmiar tablicy o 1
    Tablica::rozmiarTablicy = Tablica::rozmiarTablicy + 1;

}

void Tablica::dodajGdziekolwiek(int wartosc, int pozycja) {
    //Sprawdź, czy wybrana pozycja znajduje się w tablicy
    //Jeżeli nie, anuluj dodawanie
    if (pozycja < 0 || pozycja > Tablica::rozmiarTablicy) {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    } else {

        //Zaalokuj pamięć na tablicę większa o jeden element niż poprzednio
        //Przypisz podaną wartość jako element tablicy na wybranej pozycji
        int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy + 1];
        nowyWskaznikNaHead[pozycja] = wartosc;

        //Przepisz dane ze starej tablicy do nowej
        //Przerwij przed wybraną pozycją
        for (int i = 0; i < pozycja; i++) {
            nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i];
        }

        //Uzupełnij dane w tablicy po wybranej pozycji
        //Przepisz dane ze starej tablicy do nowej
        for (int i = pozycja; i < Tablica::rozmiarTablicy; i++) {
            nowyWskaznikNaHead[i + 1] = Tablica::wskaznikNaHead[i];
        }

        //Zwolnij pamięć poprzedniej tablicy
        //Zastąp wskaźnik na głowę tablicy nowym
        delete Tablica::wskaznikNaHead;
        Tablica::wskaznikNaHead = nowyWskaznikNaHead;

        //Zwiększ rozmiar tablicy o 1
        Tablica::rozmiarTablicy = Tablica::rozmiarTablicy + 1;

    }

}

void Tablica::usunOstatni() {
    //Sprawdź, czy tablica nie jest pusta
    if (Tablica::rozmiarTablicy > 0) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
        int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza ostatnim
        for (int i = 0; i < Tablica::rozmiarTablicy - 1; i++) {
            nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] Tablica::wskaznikNaHead;
        Tablica::wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        Tablica::rozmiarTablicy = Tablica::rozmiarTablicy - 1;
    } else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usunPierwszy() {

    //Sprawdź, czy tablica nie jest pusta
    if (Tablica::rozmiarTablicy > 0) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
        int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy - 1];

        //Przepisz elementy starej tablicy poza pierwszym
        for (int i = 0; i < Tablica::rozmiarTablicy - 1; i++) {
            nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] Tablica::wskaznikNaHead;
        Tablica::wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        Tablica::rozmiarTablicy = Tablica::rozmiarTablicy - 1;
    } else {
        cout << "W tablicy nie ma żadnego elementu!" << endl;
    }

}

void Tablica::usunKtorys(int pozycja) {

    //Sprawdź, czy tablica nie jest pusta
    //Sprawdż czy pozycja nie wykracza poza tablicę
    if (Tablica::rozmiarTablicy > 0 || pozycja > 0 || pozycja < Tablica::rozmiarTablicy) {
        //Zaalokuj pamięć na tablicę mniejszą o jeden element niż poprzednio
        int *nowyWskaznikNaHead = new int[Tablica::rozmiarTablicy - 1];

        //Przepisz elementy do wybranej pozycji
        for (int i = 0; i < pozycja; i++) {
            nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i];
        }

        //Przepisz elementy po wybranej pozycji
        for (int i = pozycja; i < Tablica::rozmiarTablicy - 1; i++) {
            nowyWskaznikNaHead[i] = Tablica::wskaznikNaHead[i + 1];
        }

        //zwolnij pamięć po starym wskaźniku
        //Przypisz nowy wskaźnik na jego miejsce
        delete[] Tablica::wskaznikNaHead;
        Tablica::wskaznikNaHead = nowyWskaznikNaHead;

        //Zmniejsz rozmiar tablicy o 1
        Tablica::rozmiarTablicy = Tablica::rozmiarTablicy - 1;
    } else {
        cout << "W tablicy nie istnieje pozycja [" << pozycja << "]!" << endl;
    }


}

bool Tablica::sprawdzCzyIstnieje(int wartosc) {

    //Przeszukaj tablicę pod kątem wartości
    for (int i = 0; i < Tablica::rozmiarTablicy; i++) {
        //Jeżeli wartość wystąpi w iteracji zwróc true
        if (Tablica::wskaznikNaHead[i] == wartosc) {
            cout << "Szukana wartość zajmuje w tablicy pozycję [" << i << "]" << endl;
            return true;
        }
    }
    //Jeżeli wartość nie wystąpiła w żadnej iteracji tabeli zwróć false
    cout << "Szukana wartość nie występuje w tablicy" << endl;
    return false;
}

void Tablica::wydrukujTablice() {
    cout << "Aktualny stan tablicy:" << endl;
    //Jeżeli tablica nie ma elementów, wyświetl komunikat
    //W przeciwnym wypadku wydrukuj wszystkie elementy tablicy
    if (Tablica::wskaznikNaHead != NULL) {
        for (int i = 0; i < Tablica::rozmiarTablicy; i++) {
            cout << "    [" << i << "] " << Tablica::wskaznikNaHead[i] << endl;
        }
    } else {
        cout << "    Tablica nie ma żadnych elementów" << endl;
    }
}