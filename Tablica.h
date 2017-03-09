#ifndef SDIZO_PROJEKT_TABLICA_H
#define SDIZO_PROJEKT_TABLICA_H


class Tablica {


public:
//Zmienne
    int *wskaznikNaHead;

    int rozmiarTablicy;

//Metody
    Tablica();

    ~Tablica();

    void dodajNaPoczatek(int);

    void dodajNaKoniec(int wartosc);

    void dodajGdziekolwiek(int wartosc, int pozycja);

    void usunOstatni();

    void usunPierwszy();

    void usunKtorys(int pozycja);

    void wydrukujTablice();

    bool sprawdzCzyIstnieje(int wartosc);
};

#endif //SDIZO_PROJEKT_TABLICA_H
