#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {

    Lista::pierwszyElement = NULL;
    Lista::aktualnyElement = NULL;
    Lista::ostatniElement = NULL;\
    Lista::rozmiar = 0;

}

Lista::~Lista() {

}

void Lista::dodajNaPoczatek(int wartosc) {

    //Sprawdź, czy istnieje element początkowy
    if (Lista::pierwszyElement == NULL) {
        //Utwórz nowy element i ustaw go jako element początkowy
        Lista::pierwszyElement = new ElementListy(wartosc, NULL, NULL);

    } else {
        //Ustaw element ktory był pierwszym jako aktualny
        Lista::aktualnyElement = Lista::pierwszyElement;
        //Zastąp pierwszy element nowym
        //Ustaw jego wartość oraz element kolejny na element aktualny (były pierwszy)
        Lista::pierwszyElement = new ElementListy(wartosc, NULL, Lista::aktualnyElement);
        Lista::aktualnyElement->poprzedni = Lista::pierwszyElement;

    }

    //Zwiększ rozmiar listy
    Lista::rozmiar = Lista::rozmiar + 1;

}

void Lista::dodajNaKoniec(int wartosc) {

}

void Lista::dodajGdziekolwiek(int wartosc, int pozycja) {

}

void Lista::wydrukujListe() {

    //Ustaw jako akutualny element pierwszy element listy
    Lista::aktualnyElement = Lista::pierwszyElement;

    for (int i = 0; i < Lista::rozmiar; i++) {

        cout << "[" << i << "] " << Lista::aktualnyElement->wartosc << endl;

        //Przypisz kolejny element listy jako aktualny
        Lista::aktualnyElement = Lista::aktualnyElement->nastepny;

    }

}