#ifndef SDIZO_PROJEKT_DRZEWO_H
#define SDIZO_PROJEKT_DRZEWO_H

#include <iostream>
#include "ElementDrzewa.h"

using namespace std;


class Drzewo {

    int rozmiar;
    ElementDrzewa *korzen;
    ElementDrzewa straznik;
    string kolorPrawy;
    string kolorLewy;
    string kolorRodzica;

public:
    Drzewo();

    ~Drzewo();

    void usunWszystko();

    void dodaj(int);

    void usun(int);

    void obrotWLewo(ElementDrzewa *);

    void obrotWPrawo(ElementDrzewa *);

    void wyszukaj(int);

private:


    void usunElement(ElementDrzewa *);

    void znajdzElement(int, ElementDrzewa *, ElementDrzewa *&);

    void znajdzWartosc(int, ElementDrzewa *, bool &znalezione);

    ElementDrzewa *znajdzNastepnyElement(ElementDrzewa *);

    ElementDrzewa *znajdzNajmniejszyElementDrzewa(ElementDrzewa *);

};

#endif //SDIZO_PROJEKT_DRZEWO_H
