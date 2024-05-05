//
// Created by mamel on 05/05/2024.
//

#ifndef TESTING_EVENTO_H
#define TESTING_EVENTO_H
#include <bits/stdc++.h>
using namespace std;

class Evento {
private:
    string nome, descrizione, ora;
public:
    //Andremo a creare un costruttore
    Evento(string nome, string descrizione, string ora) {
        this->nome = nome;
        this->descrizione = descrizione;
        this->ora = ora;
    };

    string getNome();
    string getDescrizione();
    string getOra();

    void setNome(string nome);
    void setDescrizione(string descrizione);
    void setOra(string ora);
};


#endif //TESTING_EVENTO_H
