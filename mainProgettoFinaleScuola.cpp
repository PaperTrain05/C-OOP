#include <bits/stdc++.h>

using namespace std;

// Definizione della struct Evento
struct Evento {
    string nome; // Nome dell'evento
    string descrizione; // Descrizione dell'evento
    string ora; // Ora dell'evento
};

// Definizione della struct Giorno
struct Giorno {
    vector<Evento> eventi; // Lista degli eventi del giorno
};

// Funzione per leggere gli eventi da file e aggiungerli alla lista dei eventi di un giorno
void leggiEventiDaFile(string nomeFile, Giorno giorno) {
    ifstream file(nomeFile); // Apriamo il file in lettura
    if (file.is_open()) { // Se il file è stato aperto correttamente
        string nome, descrizione, ora; // Variabili temporanee per leggere i dati da file
        while (file >> nome >> descrizione >> ora) { // Continuiamo a leggere finché ci sono dati
            Evento evento = {nome, descrizione, ora}; // Creiamo un evento con i dati letti
            giorno.eventi.push_back(evento); // Aggiungiamo l'evento alla lista dei eventi del giorno
        }
        file.close(); // Chiudiamo il file
    } else {
        cout << "Impossibile aprire il file." << std::endl; // Se non è stato possibile aprire il file, stampiamo un messaggio di errore
    }
}

// Funzione per generare il nome del file in base al giorno, mese e anno
string generaNomeFile(int giorno, int mese, int anno) {
    return to_string(giorno) + "-" + to_string(mese) + "-" + to_string(anno) + ".txt"; // Restituiamo il nome del file nel formato "giorno-mese-anno.txt"
}

// Funzione per ottenere la data corrente e salvarla nei parametri giorno, mese e anno
void ottieniDataCorrente(int giorno, int mese, int anno) {
    time_t now = time(0); // Otteniamo il tempo corrente
    tm* timeinfo = localtime(&now); // Convertiamo il tempo in una struttura tm
    giorno = timeinfo->tm_mday; // Salviamo il giorno corrente
    mese = timeinfo->tm_mon + 1; // Salviamo il mese corrente (+1 perché gennaio ha indice 0)
    anno = timeinfo->tm_year + 1900; // Salviamo l'anno corrente (1900 perché l'anno restituito è il numero di anni trascorsi dal 1900)
    //il -> come se fosse un . nelle struct o classi possiamo farlo anche con ->
}

// Funzione per leggere gli eventi del giorno corrente da file
void leggiEventiGiornoCorrente(Giorno giorno) {
    int giornoCorrente, meseCorrente, annoCorrente; // Variabili per salvare la data corrente
    ottieniDataCorrente(giornoCorrente, meseCorrente, annoCorrente); // Otteniamo la data corrente
    string nomeFile = generaNomeFile(giornoCorrente, meseCorrente, annoCorrente); // Generiamo il nome del file
    leggiEventiDaFile(nomeFile, giorno); // Leggiamo gli eventi da file
}

// Funzione per salvare gli eventi su file
void salvaEventiSuFile(string nomeFile, Giorno giorno) {
    ofstream file(nomeFile); // Apriamo il file in scrittura
    if (file.is_open()) { // Se il file è stato aperto correttamente
        for(auto evento : giorno.eventi) { // Per ogni evento nella lista degli eventi del giorno
            file << evento.nome << " " << evento.descrizione << " " << evento.ora << endl; // Scriviamo nome, descrizione e ora dell'evento sul file
        }
        file.close(); // Chiudiamo il file
    } else {
        cout << "Impossibile aprire il file." << endl; // Se non è stato possibile aprire il file, stampiamo un messaggio di errore
    }
}

// Funzione per mostrare il menu dell'applicazione
void mostraMenu() {
    cout << "Menu:\n";
    cout << "1. Aggiungi evento\n";
    cout << "2. Rimuovi evento\n";
    cout << "3. Visualizza eventi del giorno corrente\n";
    cout << "0. Esci\n";
    cout << "Scelta: ";
}

int main() {
    Giorno giornoCorrente; // Creiamo un giorno per rappresentare il giorno corrente
    leggiEventiGiornoCorrente(giornoCorrente); // Leggiamo gli eventi del giorno corrente da file

    int scelta; // Variabile per salvare la scelta dell'utente
    do { // Ciclo per mostrare il menu e gestire le scelte dell'utente
        mostraMenu(); // Mostriamo il menu
        cin >> scelta; // Leggiamo la scelta dell'utente
        switch (scelta) { // Switch per gestire le diverse opzioni
            case 1: { // Opzione per aggiungere un evento
                string nome, descrizione, ora; // Variabili per salvare i dati dell'evento
                cout << "Inserisci il nome dell'evento: "; // Prompt per il nome dell'evento
                cin >> nome; // Leggiamo il nome dell'evento
                cout << "Inserisci la descrizione dell'evento: "; // Prompt per la descrizione dell'evento
                cin >> descrizione; // Leggiamo la descrizione dell'evento
                cout << "Inserisci l'ora dell'evento: "; // Prompt per l'ora dell'evento
                cin >> ora; // Leggiamo l'ora dell'evento
                Evento evento = {nome, descrizione, ora}; // Creiamo un evento con i dati inseriti
                giornoCorrente.eventi.push_back(evento); // Aggiungiamo l'evento alla lista dei eventi del giorno
                break; // Usciamo dallo switch
            }
            case 2: { // Opzione per rimuovere un evento
                int indice; // Variabile per salvare l'indice dell'evento da rimuovere
                cout << "Inserisci l'indice dell'evento da rimuovere: "; // Prompt per l'indice dell'evento da rimuovere
                cin >> indice; // Leggiamo l'indice dell'evento da rimuovere
                if (indice >= 0 && indice < giornoCorrente.eventi.size()) { // Se l'indice è valido
                    giornoCorrente.eventi.erase(giornoCorrente.eventi.begin() + indice); // Rimuoviamo l'evento dalla lista
                } else { // Se l'indice non è valido
                    cout << "Indice non valido." << endl; // Stampiamo un messaggio di errore
                }
                break;
            }
            case 3: // Opzione per visualizzare gli eventi del giorno corrente
                for(auto evento : giornoCorrente.eventi) { // Per ogni evento nella lista degli eventi del giorno
                    cout << "Nome: " << evento.nome << " Descrizione: " << evento.descrizione << " Ora: " << evento.ora << endl; // Stampiamo nome, descrizione e ora dell'evento
                }
                break;
            case 0:
                cout << "Uscita dal programma." << endl;
                break;
            default:
                cout << "Scelta non valida. Riprova." << endl;
                break;
        }
    } while (scelta != 0); // Continuiamo finché la scelta dell'utente non è 0

    // Salvataggio degli eventi su file

    // Variabili per salvare la data corrente
    int giornoSalvataggio, meseSalvataggio, annoSalvataggio;
    // Otteniamo la data corrente
    ottieniDataCorrente(giornoSalvataggio, meseSalvataggio, annoSalvataggio);

    // Generiamo il nome del file
    string nomeFileSalvataggio = generaNomeFile(giornoSalvataggio, meseSalvataggio, annoSalvataggio);
    // Salviamo gli eventi su file
    salvaEventiSuFile(nomeFileSalvataggio, giornoCorrente);

    return 0; // Usciamo dal programma
}
