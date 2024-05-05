//
// Created by mamel on 05/05/2024.
//

#include "F:/Developing/CLion/Agenda/it/mameli_alemanno/calendario/libs/Giorno.h"


void Giorno::aggiungiEvento(Evento evento) {
    eventi.push_back(evento);
}

void Giorno::rimuoviEvento(Evento evento) {
    for (int i = 0; i < eventi.size(); i++) {
        if (eventi[i].getNome() == evento.getNome()) {
            eventi.erase(eventi.begin() + i);
        }
    }
}

vector<Evento> Giorno::getEventi() {
    return eventi;
}

