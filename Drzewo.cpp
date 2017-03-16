#include "Drzewo.h"

using namespace std;

Drzewo::Drzewo() {

    rozmiar = 0;

    //Kolory drzewa określane jako " ", zanim są zdefiniowane
    kolorPrawy = " ";
    kolorLewy = " ";
    kolorRodzica = " ";

    //Inicjaliacja strażnika
    straznik.kolor = 'B';
    straznik.rodzic = &straznik;
    straznik.lewo = &straznik;
    straznik.prawo = &straznik;
    korzen = &straznik;
}

Drzewo::~Drzewo() {
    if (korzen)
        usunWszystko();
}

void Drzewo::usunWszystko() {
    usunElement(korzen);

    straznik.kolor = 'B';          // Inicjujemy strażnika
    straznik.rodzic = &straznik;
    straznik.lewo = &straznik;
    straznik.prawo = &straznik;
    korzen = &straznik;


    Drzewo::rozmiar = 0;
}

void Drzewo::usunElement(ElementDrzewa *elementDrzewa) {

    //Jeżeli element nie jest strażnikiem, usuń jego dzieci
    //A nastepnie sam element
    if (elementDrzewa != &straznik) {
        usunElement(elementDrzewa->lewo);
        usunElement(elementDrzewa->prawo);
        delete elementDrzewa;

        //Zmniejsz rozmiar drzewa
        Drzewo::rozmiar--;
    } else {

        cout << "Usuwany element jest strażnikiem!!!" << endl;

    }
}

void Drzewo::obrotWLewo(ElementDrzewa *elementDrzewa) {

    ElementDrzewa *y, *p;

    y = elementDrzewa->prawo;
    if (y != &straznik) {
        p = elementDrzewa->rodzic;
        elementDrzewa->prawo = y->lewo;
        if (elementDrzewa->prawo != &straznik) elementDrzewa->prawo->rodzic = elementDrzewa;

        y->lewo = elementDrzewa;
        y->rodzic = p;
        elementDrzewa->rodzic = y;

        if (p != &straznik) {
            if (p->lewo == elementDrzewa) p->lewo = y; else p->prawo = y;
        } else korzen = y;
    }

}

void Drzewo::obrotWPrawo(ElementDrzewa *elementDrzewa) {

    ElementDrzewa *y, *p;

    y = elementDrzewa->lewo;
    if (y != &straznik) {
        p = elementDrzewa->rodzic;
        elementDrzewa->lewo = y->prawo;
        if (elementDrzewa->lewo != &straznik) elementDrzewa->lewo->rodzic = elementDrzewa;

        y->prawo = elementDrzewa;
        y->rodzic = p;
        elementDrzewa->rodzic = y;

        if (p != &straznik) {
            if (p->lewo == elementDrzewa) p->lewo = y; else p->prawo = y;
        } else korzen = y;
    }

}

void Drzewo::dodaj(int wartosc) {

    ElementDrzewa *X, *Y;

    X = new ElementDrzewa;        // Tworzymy nowy węzeł
    X->lewo = &straznik;          // Inicjujemy pola
    X->prawo = &straznik;
    X->rodzic = korzen;
    X->wartosc = wartosc;
    if (X->rodzic == &straznik) korzen = X; // X staje się korzeniem
    else
        while (true)             // Szukamy liścia do zastąpienia przez X
        {
            if (wartosc < X->rodzic->wartosc) {
                if (X->rodzic->lewo == &straznik) {
                    X->rodzic->lewo = X;  // X zastępuje lewy liść
                    break;
                }
                X->rodzic = X->rodzic->lewo;
            } else if (wartosc > X->rodzic->wartosc) {
                if (X->rodzic->prawo == &straznik) {
                    X->rodzic->prawo = X; // X zastępuje prawy liść
                    break;
                }
                X->rodzic = X->rodzic->prawo;
            } else {
                delete X;
                return;
            }
        }

    X->kolor = 'R';         // Węzeł kolorujemy na czerwono
    while ((X != korzen) && (X->rodzic->kolor == 'R')) {
        if (X->rodzic == X->rodzic->rodzic->lewo) {
            Y = X->rodzic->rodzic->prawo; // Y -> wujek X

            if (Y->kolor == 'R')  // Przypadek 1
            {
                X->rodzic->kolor = 'B';
                Y->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                X = X->rodzic->rodzic;
                continue;
            }

            if (X == X->rodzic->prawo) // Przypadek 2
            {
                X = X->rodzic;
                obrotWLewo(X);
            }

            X->rodzic->kolor = 'B'; // Przypadek 3
            X->rodzic->rodzic->kolor = 'R';
            obrotWPrawo(X->rodzic->rodzic);
            break;
        } else {                  // Przypadki lustrzane
            Y = X->rodzic->rodzic->lewo;

            if (Y->kolor == 'R') // Przypadek 1
            {
                X->rodzic->kolor = 'B';
                Y->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                X = X->rodzic->rodzic;
                continue;
            }

            if (X == X->rodzic->lewo) // Przypadek 2
            {
                X = X->rodzic;
                obrotWPrawo(X);
            }

            X->rodzic->kolor = 'B'; // Przypadek 3
            X->rodzic->rodzic->kolor = 'R';
            obrotWLewo(X->rodzic->rodzic);
            break;
        }
    }
    korzen->kolor = 'B';

    rozmiar++;
}

void Drzewo::usun(int wartosc) {

    ElementDrzewa *elementDrzewaDoUsuniecia;
    znajdzElement(wartosc, korzen, elementDrzewaDoUsuniecia);

    ElementDrzewa *W, *Y, *Z;

    if ((elementDrzewaDoUsuniecia->lewo == &straznik) || (elementDrzewaDoUsuniecia->prawo == &straznik))
        Y = elementDrzewaDoUsuniecia;
    else Y = znajdzNastepnyElement(elementDrzewaDoUsuniecia);

    if (Y->lewo != &straznik) Z = Y->lewo;
    else Z = Y->prawo;

    Z->rodzic = Y->rodzic;

    if (Y->rodzic == &straznik) korzen = Z;
    else if (Y == Y->rodzic->lewo) Y->rodzic->lewo = Z;
    else Y->rodzic->prawo = Z;

    if (Y != elementDrzewaDoUsuniecia) elementDrzewaDoUsuniecia->wartosc = Y->wartosc;

    if (Y->kolor == 'B')   // Naprawa struktury drzewa czerwono-czarnego
        while ((Z != korzen) && (Z->kolor == 'B'))
            if (Z == Z->rodzic->lewo) {
                W = Z->rodzic->prawo;

                if (W->kolor == 'R') {              // Przypadek 1
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotWLewo(Z->rodzic);
                    W = Z->rodzic->prawo;
                }

                if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {              // Przypadek 2
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if (W->prawo->kolor == 'B') {              // Przypadek 3
                    W->lewo->kolor = 'B';
                    W->kolor = 'R';
                    obrotWPrawo(W);
                    W = Z->rodzic->prawo;
                }

                W->kolor = Z->rodzic->kolor; // Przypadek 4
                Z->rodzic->kolor = 'B';
                W->prawo->kolor = 'B';
                obrotWLewo(Z->rodzic);
                Z = korzen;         // To spowoduje zakończenie pętli
            } else {                // Przypadki lustrzane
                W = Z->rodzic->lewo;

                if (W->kolor == 'R') {              // Przypadek 1
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotWLewo(Z->rodzic);
                    W = Z->rodzic->lewo;
                }

                if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {              // Przypadek 2
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                if (W->lewo->kolor == 'B') {              // Przypadek 3
                    W->prawo->kolor = 'B';
                    W->kolor = 'R';
                    obrotWLewo(W);
                    W = Z->rodzic->lewo;
                }

                W->kolor = Z->rodzic->kolor;  // Przypadek 4
                Z->rodzic->kolor = 'B';
                W->lewo->kolor = 'B';
                obrotWPrawo(Z->rodzic);
                Z = korzen;         // To spowoduje zakończenie pętli
            }

    Z->kolor = 'B';

    delete Y;


}

void Drzewo::znajdzElement(int wartosc, ElementDrzewa *korzenElementuDrzewa, ElementDrzewa *&elementDoZnalezienia) {
    if (korzenElementuDrzewa != &straznik) {
        if (korzenElementuDrzewa->wartosc == wartosc) {
            elementDoZnalezienia = korzenElementuDrzewa;
            return;
        }
        znajdzElement(wartosc, korzenElementuDrzewa->lewo, elementDoZnalezienia);
        znajdzElement(wartosc, korzenElementuDrzewa->prawo, elementDoZnalezienia);
    }
}

void Drzewo::wyszukaj(int wartosc) {
    bool znalezione = false;
    znajdzWartosc(wartosc, korzen, znalezione);

    if (znalezione) {
        cout << "Wartość " << wartosc << " występuje w drzewie" << endl;
    } else {
        cout << "Wartość " << wartosc << " nie występuje w drzewie" << endl;

    }
}

void Drzewo::znajdzWartosc(int wartosc, ElementDrzewa *korzenElementuDrzewa, bool &znalezione) {

    if (korzenElementuDrzewa != &straznik) {
        if (korzenElementuDrzewa->wartosc == wartosc) {
            znalezione = true;
            return;
        }
        znajdzWartosc(wartosc, korzenElementuDrzewa->lewo, znalezione);
        znajdzWartosc(wartosc, korzenElementuDrzewa->prawo, znalezione);
    }

}

ElementDrzewa *Drzewo::znajdzNastepnyElement(ElementDrzewa *p) {
    ElementDrzewa *nastepnyElementDrzewa;

    if (p != &straznik) {
        if (p->prawo != &straznik) return znajdzNajmniejszyElementDrzewa(p->prawo);
        else {
            nastepnyElementDrzewa = p->rodzic;
            while ((nastepnyElementDrzewa != &straznik) && (p == nastepnyElementDrzewa->prawo)) {
                p = nastepnyElementDrzewa;
                nastepnyElementDrzewa = nastepnyElementDrzewa->rodzic;
            }
            return nastepnyElementDrzewa;
        }
    }
    return &straznik;
}

ElementDrzewa *Drzewo::znajdzNajmniejszyElementDrzewa(ElementDrzewa *p) {
    if (p != &straznik)
        while (p->lewo != &straznik) p = p->lewo;
    return p;
}