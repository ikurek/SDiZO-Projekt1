//
// Created by igor on 13.03.17.
//

#include "ElementListy.h"

ElementListy::ElementListy(int wartosc, ElementListy *nastepny, ElementListy *poprzedni) {

    ElementListy::wartosc = wartosc;
    ElementListy::nastepny = nastepny;
    ElementListy::poprzedni = poprzedni;

}