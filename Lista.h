//
// Created by igor on 08.03.17.
//

#ifndef SDIZO_PROJEKT_LISTA_H
#define SDIZO_PROJEKT_LISTA_H

#include <iostream>
#include "ElementListy.h"

using namespace std;

class Lista {

public:

    int rozmiar;

    Lista();

    ~Lista();

    ElementListy *pierwszyElement;
    ElementListy *ostatniElement;
    ElementListy *aktualnyElement;

    void dodajNaPoczatek(int wartosc);

    void dodajGdziekolwiek(int wartosc, int pozycja);

    void dodajNaKoniec(int wartosc);

    void wydrukujListe();
};

#endif //SDIZO_PROJEKT_LISTA_H
