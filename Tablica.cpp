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
    //TODO: Czy trzeba to usuwać? I tak będzie nadpisane...
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
    //TODO: Czy trzeba to usuwać? I tak będzie nadpisane...
    delete Tablica::wskaznikNaHead;
    Tablica::wskaznikNaHead = nowyWskaznikNaHead;

    //Zwiększ rozmiar tablicy o 1
    Tablica::rozmiarTablicy = Tablica::rozmiarTablicy + 1;

}

void Tablica::dodajGdziekolwiek(int wartosc, int pozycja) {


}

void Tablica::usunOstatni() {

}

void Tablica::usunPierwszy() {

}

void Tablica::usunKtorys(int pozycja) {

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