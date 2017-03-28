#ifndef SDIZO_PROJEKT_DRZEWO_H
#define SDIZO_PROJEKT_DRZEWO_H

#include <iostream>
#include "ElementDrzewa.h"

using namespace std;


class Drzewo {

public:

    int rozmiar;

    Drzewo();

    ~Drzewo();

    void usunWszystko();

    void dodaj(int);

    void usun(int);

    void obrotWLewo(ElementDrzewa *);

    void obrotWPrawo(ElementDrzewa *);

    void sprawdzCzyIstnieje(int);

private:

    ElementDrzewa *korzen;

    ElementDrzewa straznik;

    void usunElement(ElementDrzewa *);

    void znajdzElement(int, ElementDrzewa *, ElementDrzewa *&);

    void znajdzWartosc(int, ElementDrzewa *, bool &znalezione);

    ElementDrzewa *znajdzNastepnyElement(ElementDrzewa *);

    ElementDrzewa *znajdzNajmniejszyElementDrzewa(ElementDrzewa *);

    void wydrukujDrzewo();
};

#endif //SDIZO_PROJEKT_DRZEWO_H
