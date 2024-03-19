/*
 * Come detto in precedenza, l'implementazione della classe studente viene fatto con .h
 * */
#include "studente.h"
#include <bits/stdc++.h>

//Andremo ad "implementare" dentro la classe le informazioni richieste, non è come un implements di Java ma lo possiamo intendere cosi, perche questi sono i metodi della classe come
//un getter e un setter
//metodo di risoluzione all'interno di una classe il :: -> operatore di risoluzione
// il C++ usera il :: per accedere ai membri di una classe o variabili di una classe da fuori la classe stessa
void studente::inputInformazioni() {
    /*
     * Qui andremo a chiedere le informazioni
     * */
    cout << "Inserisci il nome dello studente: ";
    cin >> nome;
    cout << "Inserisci il cognome dello studente: ";
    cin >> cognome;
    cout << "Inserisci l'età dello studente: ";
    cin >> eta;
    cout << "Inserisci la matrice dello studente: ";
    cin >> matrice;
    cout << "Inserisci il corso dello studente: ";
    cin >> corso;
    int numVoti;
    cout << "Quanti voti vuoi inserire per lo studente? ";
    cin >> numVoti;
    for (int i = 0; i < numVoti; i++) {
        int voto;
        cout << "Inserisci il voto " << i+1 << ": ";
        cin >> voto;
        voti.push_back(voto);
    }
}
float studente::calcolaMedia() {
    if (voti.empty()) {
        return 0.0;
    }
    int sum = 0;
    for (int voto : voti) {
        sum += voto;
    }
    return static_cast<float>(sum) / voti.size();
}
