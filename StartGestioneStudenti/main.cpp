/*
 * Libreria che include le librerie di C++ (Vector, String, List, Set ecc)
 * */
#include <bits/stdc++.h>
/*
 * Ad ogni creazione di un classe si creera un .h e un .cpp, per integrare la classe nel main e o altre classi useremo l'include del .h della classe
 * */
#include "studente.h"
using namespace std;

/*
 * Fase progettazione:
 * 1) Andremo a creare una classe per lo studente che conterra le informazioni necessarie
 * 2) Andremo a creare una lista (come se fosse un namanger ma sara una list)
 * 3) Andremo a chiedere le informazioni all'utente con il metodo contenuto dentro la classe studente.inputInformazioni()
 * 4) Andremo dopo aver chiesto le informazioni le andremo a creare un .txt dentro la cartella del progetto mettendo le informazioni richieste
 * 5) Andremo a mostrare la media piu alta
 *
 * */

int main() {
    int numStudenti;
    cout << "Quanti studenti vuoi creare? ";
    cin >> numStudenti;

    list<studente> listaStudenti;
    for (int i = 0; i < numStudenti; i++) {
        studente nuovoStudente;
        nuovoStudente.inputInformazioni();
        listaStudenti.push_back(nuovoStudente);
    }
    //forEach per la lista dove andra a creare un .txt dentro la cartella del progetto usando fstream
    //sara fatto quando andremo a salvare tutti i dati dentro la lista
    for (auto studente : listaStudenti) {
        string filename = studente.cognome + "_" + studente.nome + "_" + studente.matrice + ".txt";

        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Nome: " << studente.nome << endl;
            outFile << "Cognome: " << studente.cognome << endl;
            outFile << "Matricola: " << studente.matrice << endl;
            outFile << "Voti:";
            for (int voto : studente.voti) {
                outFile << " " << voto;
            }
            outFile << endl;
            outFile << "Media: " << studente.calcolaMedia() << endl; //tanto restituira la media in float senza f (non mi ricordo se in C++ ci sara cio)

            outFile.close();
        } else {
            cout << "Unable to create file: " << filename << endl;
        }
    }

    // Stampare lo studente con la media piu alta
    studente bestStudent;
    float highestAverage = 0.0;


    for (auto studente : listaStudenti) {
        float currentAverage = studente.calcolaMedia();
        /*
         * Qui succedera che a partire partira da 0 quindi il primo avra la media piu alta ALL'INIZIO
         * quindi setteremo la media piu alta, poi facciamo scorrere e vedremo se la media e piu alta rispetto alla precedente
         * se è piu alta la setta e cosi via salvandosi chi è lo studente con la media piu alta e la media che ha avuto quel studente
         * */
        if (currentAverage > highestAverage) {
            highestAverage = currentAverage;
            bestStudent = studente;
        }
    }

    cout << "Lo studente con la media voti piu alta e: " << bestStudent.nome << " con una media di: " << highestAverage << endl;

    return 0;
}
