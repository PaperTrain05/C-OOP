//
// Created by mamel on 05/05/2024.
//

#ifndef TESTING_GIORNO_H
#define TESTING_GIORNO_H
#include <bits/stdc++.h>
#include "Evento.h"
using namespace std;

class Giorno {
private:
    vector<Evento> eventi;
public:
    void aggiungiEvento(Evento evento);
    void rimuoviEvento(Evento evento);
    vector<Evento> getEventi();
};


#endif //TESTING_GIORNO_H
