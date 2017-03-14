#ifndef SDIZO_PROJEKT_KOPIEC_H
#define SDIZO_PROJEKT_KOPIEC_H


class Kopiec {
public:
    int *tablica;
    unsigned int rozmiar;

    Kopiec();

    ~Kopiec();

    void dodaj(int);

    void usun(int);

    bool sprawdzCzyIstnieje(int);

    void wydrukujKopiec();
};


#endif //SDIZO_PROJEKT_KOPIEC_H
