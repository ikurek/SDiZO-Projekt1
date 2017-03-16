#ifndef SDIZO_PROJEKT_ELEMENTDRZEWA_H
#define SDIZO_PROJEKT_ELEMENTDRZEWA_H


class ElementDrzewa {

public:
    ElementDrzewa *rodzic;
    ElementDrzewa *lewo;
    ElementDrzewa *prawo;

    char kolor;
    int wartosc;

};


#endif //SDIZO_PROJEKT_ELEMENTDRZEWA_H
