#include <bits/stdc++.h>
#include "Macchina.h"

using namespace std;

int main() {
    int n; //var di qnt di macchine
    list<Macchina> machines;
    cout<<"Inserisci quante macchine hai nel magazzino: " << endl;
    cin>>n;

    for(int i = 0; i <= n; i++) {
        Macchina nuovaMacchina;
        nuovaMacchina.chiediInfo();
        machines.push_back(nuovaMacchina);
    }

    for(auto macchina : machines) {
        string fileName = macchina.getMarca() + "_" + macchina.getModello() + ".txt";

        ofstream outFile(fileName);
        if(outFile.is_open()) {
            outFile << "Numero: " << macchina.getNumero() << endl;
            outFile << "Targa: " << macchina.getTarga() << endl;
            outFile << "Marca: " << macchina.getMarca() << endl;
            outFile << "Modello: " << macchina.getModello() << endl;
            outFile << "Cilindrata: " << macchina.getCilindrata() << endl;
            outFile << "Costo: " << macchina.getCosto() << endl;
            outFile << "Qnt. in magazzino: " << macchina.getQntMagazzino() << endl;
        }
    }

    for(auto macchinina : machines) {
        macchinina.stampaInfo();
    }
    machines.clear();
    return 0;
}
