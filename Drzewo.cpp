#include "Drzewo.h"

using namespace std;

Drzewo::Drzewo() {

    rozmiar = 0;

    //Kolory drzewa określane jako " ", zanim są zdefiniowane

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

    //Inicjalizacja strażnika
    straznik.kolor = 'B';
    straznik.rodzic = &straznik;
    straznik.lewo = &straznik;
    straznik.prawo = &straznik;
    korzen = &straznik;


    //Ustaw rozmiar drzewa na 1
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

    //Stworzenie nowego węzła dla drzewa
    X = new ElementDrzewa;
    X->lewo = &straznik;
    X->prawo = &straznik;
    X->rodzic = korzen;
    X->wartosc = wartosc;

    //Przypisanie korzenia jako X, jeżeli rodzic jest strażnikiem
    //W przeciwnym wypadku, zastąpienie liścia
    if (X->rodzic == &straznik) {
        korzen = X;
    } else {
        //Pętla wyszukuje liść do zastąpienia przez X
        //Zależnie od sytuacji zastępuje prawy lub lewy liść drzewa
        while (true) {
            //X zastępuje lewy liść
            if (wartosc < X->rodzic->wartosc) {
                if (X->rodzic->lewo == &straznik) {
                    X->rodzic->lewo = X;
                    break;
                }
                X->rodzic = X->rodzic->lewo;

                // X zastępuje prawy liść
            } else if (wartosc > X->rodzic->wartosc) {
                if (X->rodzic->prawo == &straznik) {
                    X->rodzic->prawo = X;
                    break;
                }
                X->rodzic = X->rodzic->prawo;

                //Brak możliwości zastąpienia liścia
            } else {
                delete X;
                return;
            }
        }

        //Kolorowanie węzła na czerwono
        X->kolor = 'R';
        while ((X != korzen) && (X->rodzic->kolor == 'R')) {
            if (X->rodzic == X->rodzic->rodzic->lewo) {
                Y = X->rodzic->rodzic->prawo;

                //Przypadek 1
                if (Y->kolor == 'R') {
                    X->rodzic->kolor = 'B';
                    Y->kolor = 'B';
                    X->rodzic->rodzic->kolor = 'R';
                    X = X->rodzic->rodzic;
                    continue;
                }

                //Przypadek 2
                if (X == X->rodzic->prawo) {
                    X = X->rodzic;
                    obrotWLewo(X);
                }

                //Przypadek 3
                X->rodzic->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                obrotWPrawo(X->rodzic->rodzic);
                break;

                //Przypadki lustrzane
            } else {
                Y = X->rodzic->rodzic->lewo;

                //Przypadek lustrzany 1
                if (Y->kolor == 'R') {
                    X->rodzic->kolor = 'B';
                    Y->kolor = 'B';
                    X->rodzic->rodzic->kolor = 'R';
                    X = X->rodzic->rodzic;
                    continue;
                }

                //Przypadek lustrzany 2
                if (X == X->rodzic->lewo) {
                    X = X->rodzic;
                    obrotWPrawo(X);
                }

                //Przypadek lustrzany 3
                X->rodzic->kolor = 'B';
                X->rodzic->rodzic->kolor = 'R';
                obrotWLewo(X->rodzic->rodzic);
                break;
            }
        }
        korzen->kolor = 'B';

        //Zwiększenie rozmiaru drzewa o 1
        rozmiar++;
    }
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

                //Przypadek 1
                if (W->kolor == 'R') {
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotWLewo(Z->rodzic);
                    W = Z->rodzic->prawo;
                }

                //Przypadek 2
                if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                //Przypadek 3
                if (W->prawo->kolor == 'B') {
                    W->lewo->kolor = 'B';
                    W->kolor = 'R';
                    obrotWPrawo(W);
                    W = Z->rodzic->prawo;
                }

                //Przypadek 4
                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = 'B';
                W->prawo->kolor = 'B';
                obrotWLewo(Z->rodzic);

                //Zakończenie pętli
                Z = korzen;

                //Przypadki lustrzane
            } else {
                W = Z->rodzic->lewo;

                //Lustrzany przypadek 1
                if (W->kolor == 'R') {
                    W->kolor = 'B';
                    Z->rodzic->kolor = 'R';
                    obrotWLewo(Z->rodzic);
                    W = Z->rodzic->lewo;
                }

                //Lustrzany przypadek 2
                if ((W->lewo->kolor == 'B') && (W->prawo->kolor == 'B')) {
                    W->kolor = 'R';
                    Z = Z->rodzic;
                    continue;
                }

                //Lustrzany przypadek 3
                if (W->lewo->kolor == 'B') {
                    W->prawo->kolor = 'B';
                    W->kolor = 'R';
                    obrotWLewo(W);
                    W = Z->rodzic->lewo;
                }

                //Lustrzany przypadek 4
                W->kolor = Z->rodzic->kolor;
                Z->rodzic->kolor = 'B';
                W->lewo->kolor = 'B';
                obrotWPrawo(Z->rodzic);

                //Zakończenie pętli
                Z = korzen;
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

void Drzewo::sprawdzCzyIstnieje(int wartosc) {
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

void Drzewo::wydrukujDrzewo() {

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