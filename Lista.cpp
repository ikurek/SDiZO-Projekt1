#include <iostream>
#include "Lista.h"

using namespace std;

Lista::Lista() {

    Lista::pierwszyElement = NULL;
    Lista::aktualnyElement = NULL;
    Lista::ostatniElement = NULL;
    Lista::rozmiar = 0;

}

Lista::~Lista() {

}

void Lista::dodajNaPoczatek(int wartosc) {

    //Sprawdź, czy istnieje element początkowy
    if (Lista::pierwszyElement == NULL) {
        //Utwórz nowy element i ustaw go jako element początkowy i końcowy
        Lista::pierwszyElement = new ElementListy(wartosc, NULL, NULL);
        Lista::ostatniElement = Lista::pierwszyElement;

    } else {
        //Ustaw element ktory był pierwszym jako aktualny
        Lista::aktualnyElement = Lista::pierwszyElement;
        //Zastąp pierwszy element nowym
        //Ustaw jego wartość oraz element kolejny na element aktualny (były pierwszy)
        Lista::pierwszyElement = new ElementListy(wartosc, Lista::aktualnyElement, NULL);
        Lista::aktualnyElement->poprzedni = Lista::pierwszyElement;

    }

    //Zwiększ rozmiar listy
    Lista::rozmiar = Lista::rozmiar + 1;

}

void Lista::dodajNaKoniec(int wartosc) {
    //Sprawdź, czy istnieje element początkowy
    if (Lista::pierwszyElement == NULL) {
        //Utwórz nowy element i ustaw go jako element początkowy i końcowy
        Lista::ostatniElement = new ElementListy(wartosc, NULL, NULL);
        Lista::pierwszyElement = ostatniElement;

    } else {
        //Ustaw element który był ostatnim jako aktualny
        Lista::aktualnyElement = Lista::ostatniElement;
        //Zastąp ostatni element nowym
        //Ustaw jego wartość oraz element poprzedni na element aktualny (były ostatni)
        Lista::ostatniElement = new ElementListy(wartosc, NULL, Lista::aktualnyElement);
        Lista::aktualnyElement->nastepny = Lista::ostatniElement;
    }
    //Zwiększ rozmiar listy o 1
    Lista::rozmiar = Lista::rozmiar + 1;
}

//FIXME: NIE DZIAŁA!!!
void Lista::dodajGdziekolwiek(int wartosc, int pozycja) {

    //Sprawdź czy w liście istnieje pozycja podana przez użytkownika
    if (pozycja < 0 || pozycja > Lista::rozmiar) {
        cout << "W liście nie istnieje pozycja [" << pozycja << "]" << endl;
        return;
    }
    //Sprawdź czy wybrana pozycja jest pierwszą
    if (pozycja == 0) {
        Lista::dodajNaPoczatek(wartosc);
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (pozycja == Lista::rozmiar - 1) {
        Lista::dodajNaKoniec(wartosc);
        return;
    }

    //Sprawdź w której połowie listy znajduje się wybrany element
    if (pozycja < Lista::rozmiar / 2) { //liczone od indeksu zerowego

        //Przypisz za aktualny element pierwszy
        Lista::aktualnyElement = Lista::pierwszyElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < pozycja; ++i) {
            Lista::aktualnyElement = Lista::aktualnyElement->nastepny;
        }

    } else {

        //Przypisz za aktualny element ostatni
        Lista::aktualnyElement = Lista::ostatniElement;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < Lista::rozmiar - pozycja; ++i) {
            Lista::aktualnyElement = Lista::aktualnyElement->poprzedni;
        }

    }

    //Stwórz nowy element listy z podanymi parametrami
    ElementListy *nowyElementListy = new ElementListy(wartosc, Lista::aktualnyElement,
                                                      Lista::aktualnyElement->nastepny);

    //przypisz nowy element w odpowiednim miejscu tablicy
    Lista::aktualnyElement->nastepny->poprzedni = nowyElementListy;
    Lista::aktualnyElement->nastepny = nowyElementListy;

    //Zwiększ rozmiar listy
    Lista::rozmiar = Lista::rozmiar + 1;
}

void Lista::usunPierwszy() {

    //przypisz drugi element jako aktualny
    Lista::aktualnyElement = Lista::pierwszyElement->nastepny;

    //Usuń pierwszy element
    delete Lista::pierwszyElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako pierwszy
    //Jeżeli nie, wyzeruj elementy listy
    if (Lista::rozmiar > 1) {
        Lista::aktualnyElement->poprzedni = NULL;
        Lista::pierwszyElement = Lista::aktualnyElement;
    } else {
        Lista::aktualnyElement = NULL;
        Lista::pierwszyElement = NULL;
        Lista::ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    Lista::rozmiar = Lista::rozmiar - 1;
}

void Lista::usunOstatni() {

    //Przypisz przedostani element jako aktualny
    Lista::aktualnyElement = Lista::ostatniElement->poprzedni;
    //Usuń ostatni element
    delete Lista::ostatniElement;

    //Sprawdź, czy w liście są jeszcze jakieś elementy
    //Jeżeli tak, ustaw aktualny element jako ostatni
    //Jeżeli nie, wyzeruj elementy listy
    if (Lista::rozmiar > 1) {
        Lista::aktualnyElement->nastepny = NULL;
        Lista::ostatniElement = Lista::aktualnyElement;
    } else {
        Lista::aktualnyElement = NULL;
        Lista::pierwszyElement = NULL;
        Lista::ostatniElement = NULL;
    }

    //Zmniejsz rozmiar listy
    Lista::rozmiar = Lista::rozmiar - 1;

}

//FIXME: Nie działa dodawanie, to nie ma też usuwania...
void Lista::usunKtorys(int pozycja) {

}

bool Lista::sprawdzCzyIstnieje(int wartosc) {

    //Jeżeli lista jest pusta, zwróć false z automatu
    if (Lista::rozmiar == 0) {
        return false;

    }

    //Przypisa pierwszy element jako aktualny
    Lista::aktualnyElement = Lista::pierwszyElement;

    //Przeszukaj listę pod kątem wartości
    for (int i = 0; i < Lista::rozmiar; i++) {
        if (Lista::aktualnyElement->wartosc == wartosc) {
            cout << "Szukana wartość zajmuje w liście pozycję [" << i << "]" << endl;
            return true;
        }

        Lista::aktualnyElement = Lista::aktualnyElement->nastepny;
    }

    //Jeżeli wartość nie wystąpiła w żadnej iteracji listy zwróć false
    cout << "Szukana wartość nie występuje w liście" << endl;
    return false;
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