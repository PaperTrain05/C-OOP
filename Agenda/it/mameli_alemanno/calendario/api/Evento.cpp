//
// Created by mamel on 05/05/2024.
//

#include "../libs/Evento.h"
#include <bits/stdc++.h>
using namespace std;

string Evento::getNome() {
    return nome;
}

string Evento::getDescrizione() {
    return descrizione;
}

string Evento::getOra() {
    return ora;
}

void Evento::setNome(string nome) {
    this->nome = nome;
}

void Evento::setDescrizione(string descrizione) {
    this->descrizione = descrizione;
}

void Evento::setOra(string ora) {
    this->ora = ora;
}