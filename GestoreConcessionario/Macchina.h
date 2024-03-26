#include <bits/stdc++.h>
using namespace std;

#ifndef GESTORECONCESSIONARIO_MACCHINA_H
#define GESTORECONCESSIONARIO_MACCHINA_H


class Macchina {
private:
    string targa, marca, modello;
    int cilindrata, qntMagazzino, numero;
    double costo;

public:
    void chiediInfo();
    void stampaInfo();

    //Getter
    string getTarga();
    string getMarca();
    string getModello();

    int getCilindrata();
    double getCosto();
    int getQntMagazzino();
    int getNumero();
};


#endif //GESTORECONCESSIONARIO_MACCHINA_H
