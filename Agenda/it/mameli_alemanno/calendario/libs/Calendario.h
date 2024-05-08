//
// Created by mamel on 05/05/2024.
//

#ifndef TESTING_CALENDARIO_H
#define TESTING_CALENDARIO_H
#include <bits/stdc++.h>
#include "Giorno.h"
#include "Evento.h"

using namespace std;

class Calendario {
private:
    string directory;
public:
    Calendario(string directory);
    void aggiungiEvento(Evento evento);
    void rimuoviEvento(string nomeEvento);
    void modificaEvento(string evento);
    void visualizzaEventoDaStringa(string stringaRicerca);
    vector<Evento> cercaAttivita(string attivitaCercata);
    void visualizzaEventiGiornoCorrente();
    void visualizzaEventiGiornoSuccessivo();
    void visualizzaEventiSettimanaSuccessiva();
    void visualizzaEventiSettimanaCorrente();
    int ottieniGiornoSettimana(int giorno, int mese, int anno);

    string generaNomeFile(int giorno, int mese, int anno);
    void ottieniSettimanaSuccessiva(int giorno, int mese, int anno);
    void ottieniGiornoSuccessivo(int giorno, int mese, int anno);
    void ottieniDataCorrente(int& giorno, int& mese, int& anno);
    int giornoDelMese(int mese, int anno);
};


#endif //TESTING_CALENDARIO_H
