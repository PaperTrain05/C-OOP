/*
 * Qui andremo a mettere i dati richiesti con il tipo, (ho usato un vector essendo che mi e piu facile)
 * e ci saanno il if ecc, includiamo anche le librerie richiste, le funzioni che saranno usate nella classe studente.cpp
 * */

#ifndef UNTITLED_STUDENTE_H
#define UNTITLED_STUDENTE_H
#include <bits/stdc++.h>
using namespace std;

class studente {
public:
    string nome, matrice, cognome, corso;
    int eta;
    vector<float> voti;

    void inputInformazioni();
    float calcolaMedia();
};


#endif
