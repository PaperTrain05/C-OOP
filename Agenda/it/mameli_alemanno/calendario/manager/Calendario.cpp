//
// Created by mamel on 05/05/2024.
//

#include "../libs/Calendario.h"
#include <bits/stdc++.h>
#include "../libs/Giorno.h"
#include "../libs/Evento.h"

using namespace std;
/*
 * Classe: Calendario
 * Scopo: Gestisce il calendario degli eventi.
 * Membri dati:
 *  - directory: La directory in cui sono salvati i file del calendario.
 * Costruttore:
 *  - Calendario: Inizializza l'oggetto calendario con la directory specificata.
 */
Calendario::Calendario(string directory) {
    this->directory = directory;
}

/*
 * Funzione membro: ottieniDataCorrente
 * Scopo: Ottiene la data corrente e la salva nei parametri giorno, mese e anno.
 * Parametri:
 *  - giorno: Variabile per salvare il giorno corrente.
 *  - mese: Variabile per salvare il mese corrente.
 *  - anno: Variabile per salvare l'anno corrente.
 * Cosa fa la funzione:
 * Questa funzione ottiene la data corrente e la salva nei parametri specificati.
 */
void Calendario::ottieniDataCorrente(int& giorno, int& mese, int& anno) {
    time_t now = time(0);
    tm* timeinfo = localtime(&now);
    giorno = timeinfo->tm_mday;
    mese = timeinfo->tm_mon + 1;
    anno = timeinfo->tm_year + 1900;
}

/*
 * Funzione membro: ottieniGiornoSuccessivo
 * Scopo: Calcola il giorno successivo alla data corrente.
 * Parametri:
 *  - giorno: Il giorno corrente.
 *  - mese: Il mese corrente.
 *  - anno: L'anno corrente.
 * Cosa fa la funzione:
 * Questa funzione calcola il giorno successivo alla data corrente.
 */
void Calendario::ottieniGiornoSuccessivo(int giorno, int mese, int anno) {
    giorno++;
    if (giorno > 31) {
        giorno = 1;
        mese++;
        if (mese > 12) {
            mese = 1;
            anno++;
        }
    }
}

/*
 * Funzione membro: ottieniSettimanaSuccessiva
 * Scopo: Calcola la data corrispondente a una settimana dopo la data corrente.
 * Parametri:
 *  - giorno: Il giorno corrente.
 *  - mese: Il mese corrente.
 *  - anno: L'anno corrente.
 * Cosa fa la funzione:
 * Questa funzione calcola la data corrispondente a una settimana dopo la data corrente.
 */
void Calendario::ottieniSettimanaSuccessiva(int giorno, int mese, int anno) {

    giorno += 7;
    if (giorno > giornoDelMese(mese, anno)) {
        giorno = 1;
        mese++;
        if (mese > 12) {
            mese = 1;
            anno++;
        }
    }
}

/*
 * Funzione membro: generaNomeFile
 * Scopo: Genera il nome del file per una data specifica.
 * Parametri:
 *  - giorno: Il giorno.
 *  - mese: Il mese.
 *  - anno: L'anno.
 * Cosa fa la funzione:
 * Questa funzione genera il nome del file per una data specifica nel formato "giorno-mese-anno.txt".
 */
string Calendario::generaNomeFile(int giorno, int mese, int anno) {
    return to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno) + ".txt";
}

/*
 * Funzione membro: aggiungiEvento
 * Scopo: Aggiunge un evento al calendario.
 * Parametri:
 *  - evento: L'evento da aggiungere al calendario.
 * Cosa fa la funzione:
 * Questa funzione aggiunge un evento al file corrispondente alla data corrente nel calendario.
 * Prima di aggiungere l'evento, verifica se esiste già un file per la data corrente. Se il file non
 * esiste, crea un nuovo file nella directory del calendario. Successivamente, scrive l'evento nel file,
 * aggiungendolo alla fine del contenuto già presente. Se il file non può essere aperto o creato,
 * stampa un messaggio di errore.
 */
void Calendario::aggiungiEvento(Evento evento) {
    int giorno, mese, anno;
    this->ottieniDataCorrente(giorno, mese, anno);
    string nomeFile = this->generaNomeFile(giorno, mese, anno);
    string filePath = directory + "/" + nomeFile;

    // Verifica se il file esiste già
    ifstream verificaFile(filePath);
    if (!verificaFile.is_open()) {
        // Se il file non esiste, crea un nuovo file
        ofstream nuovoFile(filePath);
        if (!nuovoFile.is_open()) {
            cout << "Impossibile creare il file per il giorno corrente." << endl;
            return;
        }
        nuovoFile.close();
    }
    verificaFile.close();

    // Aggiunge l'evento al file
    ofstream file(filePath, ios::app);
    if (file.is_open()) {
        file << evento.getNome() << " " << evento.getDescrizione() << " " << evento.getOra() << endl;
        file.close();
        cout << "Evento aggiunto con successo." << endl;
    } else {
        cout << "Impossibile aprire il file." << endl;
    }
}

/*
 * Funzione membro: rimuoviEvento
 * Scopo: Rimuove un evento dal calendario.
 * Parametri:
 *  - nomeEvento: Il nome dell'evento da rimuovere.
 * Cosa fa la funzione:
 * Questa funzione rimuove un evento dal file corrispondente alla data corrente nel calendario.
 * 1. Viene ottenuta la data corrente utilizzando la funzione ottieniDataCorrente e generato il nome del file corrispondente utilizzando la funzione generaNomeFile.
 * 2. Viene aperto il file corrispondente alla data corrente in modalità lettura utilizzando ifstream.
 * 3. Se il file viene aperto correttamente, viene inizializzata una variabile lines che conterrà tutte le righe del file.
 * 4. Viene inizializzata una variabile booleana eventoTrovato che sarà utilizzata per verificare se l'evento è stato trovato nel file.
 * 5. Viene iterato attraverso tutte le righe del file. Per ogni riga, viene cercata la presenza del nome dell'evento utilizzando la funzione find.
 * 6. Se il nome dell'evento non viene trovato nella riga, la riga viene aggiunta al vettore lines. Se invece viene trovato, la variabile eventoTrovato viene impostata a true.
 * 7. Una volta finito l'iterazione, il file viene chiuso.
 * 8. Se l'evento è stato trovato (eventoTrovato è true), viene aperto il file corrispondente alla data corrente in modalità scrittura utilizzando ofstream.
 * 9. Le righe del vettore lines, che ora non contengono più l'evento da rimuovere, vengono scritte sul file.
 * 10. Infine, il file viene chiuso e viene stampato un messaggio di successo se l'evento è stato rimosso, altrimenti viene stampato un messaggio di errore.
 * 11. Se il file non viene aperto correttamente, viene stampato un messaggio di errore.
 */
void Calendario::rimuoviEvento(string nomeEvento) {
    int giorno, mese, anno;
    this->ottieniDataCorrente(giorno, mese, anno);
    string nomeFile = this->generaNomeFile(giorno, mese, anno);
    ifstream inFile(directory + "/" + nomeFile);
    if (inFile.is_open()) {
        vector<string> lines;
        string line;
        bool eventoTrovato = false;
        while (getline(inFile, line)) {
            size_t found = line.find(nomeEvento);
            if (found == string::npos) {

                lines.push_back(line);
            } else {
                eventoTrovato = true;
            }
        }
        inFile.close();

        if (eventoTrovato) {

            ofstream outFile(directory + "/" + nomeFile);
            for (auto l : lines) {
                outFile << l << endl;
            }
            outFile.close();
            cout << "Evento rimosso con successo." << endl;
        } else {
            cout << "Evento non trovato." << endl;
        }
    } else {
        cout << "Impossibile aprire il file." << endl;
    }
}

/*
 * Funzione membro: visualizzaEventiGiornoCorrente
 * Scopo: Visualizza gli eventi del giorno corrente.
 * Cosa fa la funzione:
 * Questa funzione visualizza gli eventi dal file corrispondente alla data corrente.
 */
void Calendario::visualizzaEventiGiornoCorrente() {
    int giorno, mese, anno;
    this->ottieniDataCorrente(giorno, mese, anno);
    string nomeFile = this->generaNomeFile(giorno, mese, anno);
    ifstream file(directory + "/" + nomeFile);
    if (file.is_open()) {
        string nome, descrizione, ora;
        while (file >> nome >> descrizione >> ora) {
            cout << "Nome: " << nome << " || Descrizione: " << descrizione << " || Ora: " << ora << endl;
        }
        file.close();
    } else {
        cout << "Non ci sono eventi per il giorno corrente." << endl;
    }
}

/*
 * Funzione membro: visualizzaEventiGiornoSuccessivo
 * Scopo: Visualizza gli eventi del giorno successivo.
 * Cosa fa la funzione:
 * Questa funzione visualizza gli eventi dal file corrispondente al giorno successivo alla data corrente.
 */
void Calendario::visualizzaEventiGiornoSuccessivo() {
    int giorno, mese, anno;
    this->ottieniDataCorrente(giorno, mese, anno);
    this->ottieniGiornoSuccessivo(giorno, mese, anno);
    string nomeFile = this->generaNomeFile(giorno, mese, anno);
    ifstream file(directory + "/" + nomeFile);
    if (file.is_open()) {
        string nome, descrizione, ora;
        while (file >> nome >> descrizione >> ora) {
            cout << "Nome: " << nome << " || Descrizione: " << descrizione << " || Ora: " << ora << endl;
        }
        file.close();
    } else {
        cout << "Non ci sono eventi per il giorno successivo." << endl;
    }
}

/*
 * Funzione membro: visualizzaEventiSettimanaSuccessiva
 * Scopo: Visualizza gli eventi della settimana successiva.
 * Cosa fa la funzione:
 * Questa funzione visualizza gli eventi dal file corrispondente alla settimana successiva alla data corrente.
 */
void Calendario::visualizzaEventiSettimanaSuccessiva() {
    int giorno, mese, anno;
    this->ottieniDataCorrente(giorno, mese, anno);
    this->ottieniSettimanaSuccessiva(giorno, mese, anno);
    string nomeFile = this->generaNomeFile(giorno, mese, anno);
    ifstream file(directory + "/" + nomeFile);
    if (file.is_open()) {
        string nome, descrizione, ora;
        while (file >> nome >> descrizione >> ora) {
            cout << "Nome: " << nome << " || Descrizione: " << descrizione << " || Ora: " << ora << endl;
        }
        file.close();
    } else {
        cout << "Non ci sono eventi per la settimana successiva." << endl;
    }
}

/*
 * Funzione membro: giornoDelMese
 * Scopo: Restituisce il numero di giorni per un dato mese e anno.
 * Parametri:
 *  - mese: Il numero del mese (1-12).
 *  - anno: L'anno per il quale si vuole conoscere il numero di giorni nel mese.
 * Cosa fa la funzione:
 * Questa funzione calcola il numero di giorni nel mese specificato, considerando anche se l'anno è bisestile.
 * Il mese di febbraio (case 2) viene gestito in modo speciale:
 * - Se l'anno è bisestile (divisibile per 4 ma non per 100, o divisibile per 400), febbraio ha 29 giorni.
 * - Se l'anno non è bisestile, febbraio ha 28 giorni.
 * Se il mese specificato è diverso da febbraio, la funzione restituisce il numero standard di giorni per quel mese.
 * In caso di mese non valido, la funzione restituisce 0.
 */
int Calendario::giornoDelMese(int mese, int anno) {
    switch (mese) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

/*
 * Funzione membro: modificaEvento
 * Scopo: Modifica un evento esistente nel calendario.
 * Parametri:
 *  - stringaRicerca: La stringa di ricerca per individuare l'evento da modificare.
 * Cosa fa la funzione:
 * Questa funzione cerca gli eventi corrispondenti alla stringa di ricerca fornita dall'utente.
 * Se trova uno o più eventi corrispondenti, li visualizza e chiede all'utente di selezionare quale
 * evento desidera modificare. Successivamente, chiede all'utente quale attributo dell'evento desidera
 * modificare (nome, descrizione o ora) e aggiorna l'evento di conseguenza.
 */
void Calendario::modificaEvento(string stringaRicerca) {
    // Cerca l'evento da modificare utilizzando la stringa di ricerca
    vector<Evento> eventiTrovati = cercaAttivita(stringaRicerca);

    // Se non ci sono eventi corrispondenti alla ricerca, avvisa l'utente e ritorna
    if (eventiTrovati.empty()) {
        cout << "Nessun evento trovato corrispondente alla ricerca." << endl;
        return;
    }

    // Visualizza gli eventi trovati
    cout << "Eventi trovati:" << endl;
    for (auto evento : eventiTrovati) {
        cout << evento.getNome() << " - " << evento.getDescrizione() << " - " << evento.getOra() << endl;
    }

    // Chiedi all'utente di selezionare l'evento da modificare
    int indiceEvento;
    cout << "Seleziona l'indice dell'evento da modificare: ";
    cin >> indiceEvento;

    // Verifica che l'indice inserito sia valido
    if (indiceEvento < 0 || indiceEvento >= eventiTrovati.size()) {
        cout << "Indice non valido." << endl;
        return;
    }

    // Seleziona l'evento da modificare
    Evento eventoDaModificare = eventiTrovati[indiceEvento];

    // Chiedi all'utente cosa vuole modificare
    cout << "Cosa vuoi modificare? (1. Nome, 2. Descrizione, 3. Ora): ";
    int scelta;
    cin >> scelta;

    // Modifica l'evento in base alla scelta dell'utente
    string nuovaInformazione;
    switch (scelta) {
        case 1:
            cout << "Inserisci il nuovo nome: ";
            cin >> nuovaInformazione;
            eventoDaModificare.setNome(nuovaInformazione);
            break;
        case 2:
            cout << "Inserisci la nuova descrizione: ";
            cin >> nuovaInformazione;
            eventoDaModificare.setDescrizione(nuovaInformazione);
            break;
        case 3:
            cout << "Inserisci la nuova ora: ";
            cin >> nuovaInformazione;
            eventoDaModificare.setOra(nuovaInformazione);
            break;
        default:
            cout << "Scelta non valida." << endl;
            return;
    }

    cout << "Evento modificato con successo." << endl;
}

/*
 * Funzione membro: cercaAttivita
 * Scopo: Cerca un'attività corrispondente alla stringa di ricerca nei file .txt della directory del calendario.
 * Parametri:
 *  - attivitaCercata: La stringa di ricerca per l'attività.
 * Cosa fa la funzione:
 * Questa funzione cerca l'attività corrispondente alla stringa di ricerca nei file .txt presenti nella directory del calendario.
 * Per ciascun file .txt, legge ogni riga e verifica se la riga contiene la stringa di ricerca nel nome o nella descrizione dell'evento.
 * Se trova un match, aggiunge l'evento trovato al vettore eventiTrovati e alla fine restituisce il vettore contenente gli eventi trovati.
 */
vector<Evento> Calendario::cercaAttivita(string attivitaCercata) {
    vector<Evento> eventiTrovati;

    // Scandisce tutti i file .txt nella directory
    for (auto &entry : filesystem::directory_iterator(directory)) {
        if (entry.path().extension() == ".txt") {
            // Apre il file
            ifstream file(entry.path());
            if (file.is_open()) {
                string nome, descrizione, ora;
                // Legge ogni riga del file
                while (file >> nome >> descrizione >> ora) {
                    // Controlla se la riga contiene la stringa di ricerca
                    if (nome.find(attivitaCercata) != string::npos ||
                        descrizione.find(attivitaCercata) != string::npos) {
                        // Se trova un match, aggiunge l'evento trovato al vettore
                        eventiTrovati.push_back(Evento(nome, descrizione, ora));
                    }
                }
                file.close();
            } else {
                cout << "Impossibile aprire il file: " << entry.path() << endl;
            }
        }
    }

    return eventiTrovati;
}

/*
 * Funzione membro: visualizzaEventoDaStringa
 * Scopo: Visualizza gli eventi corrispondenti alla stringa di ricerca nei file .txt della directory del calendario.
 * Parametri:
 *  - stringaRicerca: La stringa di ricerca per l'evento.
 * Cosa fa la funzione:
 * Questa funzione cerca gli eventi corrispondenti alla stringa di ricerca nei file .txt presenti nella directory del calendario.
 * Per ciascun file .txt, legge ogni riga e verifica se la riga contiene la stringa di ricerca nel nome o nella descrizione dell'evento.
 * Se trova un match, stampa l'evento trovato.
 */
void Calendario::visualizzaEventoDaStringa(string stringaRicerca) {
// Cerca gli eventi corrispondenti alla stringa di ricerca utilizzando la funzione cercaAttivita
    vector<Evento> eventiTrovati = cercaAttivita(stringaRicerca);

    // Se non ci sono eventi corrispondenti alla ricerca, avvisa l'utente e ritorna
    if (eventiTrovati.empty()) {
        cout << "Nessun evento trovato corrispondente alla ricerca." << endl;
        return;
    }

    // Visualizza gli eventi trovati
    cout << "Eventi trovati:" << endl;
    for (auto evento : eventiTrovati) {
        cout << evento.getNome() << " - " << evento.getDescrizione() << " - " << evento.getOra() << endl;
    }
}

/*
 * Funzione membro: visualizzaEventiSettimana
 * Scopo: Visualizza gli eventi della settimana corrente presenti nei file .txt della directory del calendario.
 * Cosa fa la funzione:
 * Questa funzione ottiene la data corrente e calcola la data dell'inizio e della fine della settimana corrente.
 * Per ciascun giorno della settimana corrente, cerca gli eventi nei file .txt corrispondenti e li visualizza.
 */
void Calendario::visualizzaEventiSettimanaCorrente() {
    // Ottieni la data corrente
    int giorno, mese, anno;
    ottieniDataCorrente(giorno, mese, anno);

    // Ottieni il giorno della settimana corrente
    int giornoSettimana = ottieniGiornoSettimana(giorno, mese, anno);

    // Calcola il giorno iniziale e finale della settimana corrente
    int giornoInizioSettimana = giorno - giornoSettimana + 1;
    int giornoFineSettimana = giornoInizioSettimana + 6;

    // Visualizza gli eventi per ciascun giorno della settimana corrente
    for (int giornoCorrente = giornoInizioSettimana; giornoCorrente <= giornoFineSettimana; ++giornoCorrente) {
        // Genera il nome del file per il giorno corrente
        string nomeFile = generaNomeFile(giornoCorrente, mese, anno);

        // Verifica se il file per il giorno corrente esiste
        ifstream file(directory + "/" + nomeFile);
        if (file.is_open()) {
            // Visualizza gli eventi per il giorno corrente
            cout << "Eventi del " << giornoCorrente << "/" << mese << "/" << anno << ":" << endl;
            visualizzaEventiGiornoCorrente();

            // Chiudi il file
            file.close();
        } else {
            cout << "Impossibile aprire il file: " << directory + "/" + nomeFile << endl;
        }
    }
}

/*
 * Funzione membro: ottieniGiornoSettimana
 * Scopo: Calcola il giorno della settimana per una data specifica utilizzando l'algoritmo di Zeller.
 * Parametri:
 *  - giorno: Il giorno della data.
 *  - mese: Il mese della data.
 *  - anno: L'anno della data.
 * Return:
 *  - Il giorno della settimana (0 per Sabato, 1 per Domenica, ..., 6 per Venerdì).
 * Algoritmo di Zeller:
 * L'algoritmo di Zeller è un metodo per calcolare il giorno della settimana per una data specifica.
 * Si basa su una formula matematica che tiene conto del giorno, del mese e dell'anno della data.
 * L'algoritmo è diviso in tre parti:
 * 1. Calcolo del secolo: Si calcola il secolo corrispondente all'anno, utilizzato per determinare alcuni coefficienti.
 * 2. Calcolo del valore JDN (Julian Day Number): Si utilizza una formula per convertire la data in un valore numerico.
 *    Questo valore rappresenta il numero di giorni trascorsi dal 1 gennaio 4713 a.C. (giorno 0 della scala dei giorni giuliani).
 * 3. Applicazione dell'algoritmo di Zeller: Si applica la formula per ottenere il giorno della settimana.
 *    La formula restituisce un numero che rappresenta il giorno della settimana, dove 0 corrisponde a Sabato,
 *    1 a Domenica, e così via fino a 6 per Venerdì.
 */
int Calendario::ottieniGiornoSettimana(int giorno, int mese, int anno) {
    // Calcola il giorno della settimana utilizzando l'algoritmo di Zeller
    if (mese < 3) {
        mese += 12;
        anno--;
    }
    int K = anno % 100;
    int J = anno / 100;
    int h = (giorno + ((13 * (mese + 1)) / 5) + K + (K / 4) + (J / 4) + (5 * J)) % 7;

    // Il risultato h corrisponde al giorno della settimana, dove 0 = Sabato, 1 = Domenica, ..., 6 = Venerdì
    return h;
}