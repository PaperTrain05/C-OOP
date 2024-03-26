
#include "Macchina.h"

string Macchina::getTarga() {
    return targa;
}
string Macchina::getMarca() {
    return marca;
}
string Macchina::getModello() {
    return modello;
}

int Macchina::getCilindrata() {
    return cilindrata;
}
double Macchina::getCosto() {
    return costo;
}
int Macchina::getQntMagazzino() {
    return qntMagazzino;
}
int Macchina::getNumero() {
    return numero;
}

void Macchina::chiediInfo() {
    cout << "Inserisci il numero: ";
    cin >> numero;
    cout << "Inserisci la targa: ";
    cin >> targa;
    cout<<"Marca: ";
    cin >> marca;
    cout<<"Modello: ";
    cin >> modello;
    cout<<"Cilindrata: ";
    cin >> cilindrata;
    cout<<"Costo: ";
    cin >> costo;
    if(costo < 10000.00) {
        cout<<"Costo troppo basso, devi acquistare un veicolo per 10000.00$" << endl;
        cin >> costo;
    }
    cout<<"Qnt in magazzino: ";
    cin >> qntMagazzino;
}
void Macchina::stampaInfo() {
    cout << "Numero: " << numero << endl;
    cout << "Targa: " << targa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modello: " << modello << endl;
    cout << "Cilindrata: " << cilindrata << endl;
    cout << "Costo: " << costo << endl;
    cout << "Qnt. in magazzino: " << qntMagazzino << endl;
}