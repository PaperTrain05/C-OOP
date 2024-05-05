#include "libs/Calendario.h"
#include <bits/stdc++.h>

using namespace std;

/*
 * Introduzioni alle classi:
 * avete presente le struct dove è uan struttura dati "custom" dove possiamo solo lavorare con i dati e basta?
 * Bene abbiamo anche le Classi che includono i dati che siano custom o meno e anche funzioni per accederci o per modificare e "giocarci" con i dati
 *
 * Questo sistema viene chiamato OOP:
 * Object Oriented Programming (Include Java, C++, Python, C#, PHP, Object-C, Ruby, GOLand)
 * https://en.wikipedia.org/wiki/Object-oriented_programming
 *
 * Allora parliamo anche del poliformismo:
 * in generale il poliformismo ovvero un'oggetto puo assumere diverse forme
 * Fin qui non avete capito cos'e ancora:
 * https://it.wikipedia.org/wiki/Polimorfismo
 *
 * Quindi:
 * Si pensi al diverso comportamento che assumono un uomo, una scimmia e un canguro quando eseguono l'azione del camminare.
 * L'uomo camminerà in modo eretto, la scimmia in maniera decisamente più goffa e curva mentre il canguro interpreterà tale azione saltellando..
 * Riferendoci ad un sistema software ad oggetti, il polimorfismo indicherà l'attitudine di un oggetto a mostrare più implementazioni per una singola funzionalità.
 *
 * Un esempio in C++:
 * class Albero {
 *     public:
 *         void cresce {
 *             cout << "Sta crescendo l'albero!!" << endl;
 *         }
 * }
 * Qui andremo ad "Implementare" la classe Albero che fara di riferimento come classe madre per Abere (Quindi come per esempio io sono Maschio ma sono un uomo)
 * quindi significa classe Uomo che verra "implementata" nella classe Maschio e Donna PUNTO.
 * class Abete : public Albero {
 *     public:
 *         void cresce {
 *             cout << "Sta crescendo l'albero di Abete!!" << endl;
 *          }
 *
 * }
 *
 * nel main invece andremo a creare un oggetto chiamato Albero al = new Abete();
 * al->cresce();
 * tramite il passaggio andremo a far cresce non l'albero ma l'abete quindi la classe che si appoggia a Albero.
 * Output:
 * Sta crescendo l'albero di Abete!!
 * */

/*
 * Come avete visto ho anche usato i "package" ma non è proprio cosi, perchè è raro usare i package ormai neanche più insegnati
 * per un occhio che gli da fastidio il disordine dentro un progetto ho decido di fare un "package alla Java" con it\mameli_alemanno\calendario
 * ecco poi creando il package api, libs, manger e il main.cpp esterno ai sotto package del calendario
 * E per lo più per organizzazione non per altro.
 * */

/*
 * ios:app signifa imput e output append significa che
 *  i nuovi dati scritti vengono aggiunti alla fine del file anziché sovrascrivere il contenuto esistente.
 *  Questo è utile quando si desidera aggiungere dati a un file esistente senza cancellare o modificare ciò che è già presente.
 * */

void visualizzaMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Aggiungi evento" << endl;
    cout << "2. Rimuovi evento" << endl;
    cout << "3. Modifica evento" << endl;
    cout << "4. Visualizza eventi del giorno corrente" << endl;
    cout << "5. Visualizza eventi della settimana corrente" << endl;
    cout << "6. Visualizza eventi del giorno successivo" << endl;
    cout << "7. Visualizza eventi della settimana successiva" << endl;
    cout << "8. Visualizza evento in base alla ricerca" << endl;
    cout << "0. Esci" << endl;
}

int main() {
    //getenv("APPDATA") restituisce la directory dell'applicazione
    //https://en.cppreference.com/w/cpp/utility/program/getenv
    //cos'e getenv?
    //Viene usato per prendere una cartella in base all'OS
    string directory = getenv("APPDATA");

    string directoryDef = directory + "\\Calendario";

    if(!filesystem::exists(directoryDef)) {
        //Andremo ad usare un try catch per creare un nuova directory, se non esiste.
        //il filesystem è un namespace integrato nel std:
        //https://en.cppreference.com/w/cpp/filesystem
        //https://en.cppreference.com/w/cpp/filesystem/create_directory
        //https://en.cppreference.com/w/cpp/filesystem/filesystem_error
        //il filesystem_error è un tipo di errore generato da filesystem::create_directory
        //che si segnera se c'e stato un errore
        //perche il try catch significa prova 1 sola volta se riesce ok non ha fallito quindi nessuno
        //excezione generato se fallisce invece quindi viene generato un filesystem_error.
        try {
            filesystem::create_directory(directoryDef);
        } catch (const filesystem::filesystem_error& e) {
            cout << "Errore durante la creazione della directory: " << e.what() << endl;
        }
    }

    // Creazione di un oggetto Calendario
    Calendario calendario2(directoryDef);

    // Mostra gli eventi del giorno corrente
    cout << "Eventi del giorno corrente:" << endl;
    calendario2.visualizzaEventiGiornoCorrente();

    visualizzaMenu();

    int scelta;
    do {
        cout << "Scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1: {
                string nome, descrizione, ora;
                cout << "Inserisci il nome dell'evento: ";
                cin >> nome;
                cout << "Inserisci la descrizione dell'evento: ";
                cin >> descrizione;
                cout << "Inserisci l'ora dell'evento: ";
                cin >> ora;

                // Creazione dell'evento
                Evento evento(nome, descrizione, ora);

                // Aggiunta dell'evento al calendario
                calendario2.aggiungiEvento(evento);

                cout<<"";
                visualizzaMenu();
                break;
            }

            case 2: {
                string nomeEvento;
                cout << "Inserisci il nome dell'evento da rimuovere: ";
                cin >> nomeEvento;
                calendario2.rimuoviEvento(nomeEvento);

                cout<<"";
                visualizzaMenu();
                break;
            }

            case 3: {
                string stringaRicerca;
                // Modifica evento
                cout << "Inserisci la stringa di ricerca per individuare l'evento da modificare: ";
                cin >> stringaRicerca;
                calendario2.modificaEvento(stringaRicerca);

                cout<<"";
                visualizzaMenu();
                break;
            }

            case 4:
                // Visualizza eventi del giorno corrente
                cout << "Eventi del giorno corrente:" << endl;
                calendario2.visualizzaEventiGiornoCorrente();

                cout<<"";
                visualizzaMenu();
                break;

            case 5:
                // Visualizza eventi della settimana corrente
                cout << "Eventi della settimana corrente:" << endl;
                calendario2.visualizzaEventiSettimanaCorrente();

                cout<<"";
                visualizzaMenu();
                break;

            case 6:
                // Visualizza eventi del giorno successivo
                cout << "Eventi del giorno successivo:" << endl;
                calendario2.visualizzaEventiGiornoSuccessivo();

                cout<<"";
                visualizzaMenu();
                break;

            case 7:
                // Visualizza eventi della settimana successiva
                cout << "Eventi della settimana successiva:" << endl;
                calendario2.visualizzaEventiSettimanaSuccessiva();

                cout<<"";
                visualizzaMenu();
                break;

            case 8: {
                // Visualizza evento in base alla ricerca
                string stringaRicerca;
                cout << "Inserisci la stringa di ricerca per individuare l'evento da visualizzare: ";
                cin >> stringaRicerca;
                calendario2.visualizzaEventoDaStringa(stringaRicerca);

                cout<<"";
                visualizzaMenu();

                break;
            }

            case 0:
                cout << "Uscita dal programma." << endl;
                break;

            default:
                cout << "Scelta non valida. Riprova." << endl;
                break;
        }
    } while (scelta != 0);

    return 0;
}