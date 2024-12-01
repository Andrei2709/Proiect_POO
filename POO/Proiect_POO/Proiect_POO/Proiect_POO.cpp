#include <iostream>
#include <fstream>
#include <string>
#include "client.h"
#include "meniu.h"
using namespace std;

int nr_clienti;

int main()
{
    ifstream fin("clienti.txt"); // system("cls");
    fin >> nr_clienti; // numarul de clienti

    Client clienti[100]; // vector de tipul Client
    string cod_client = "";
    string parola = "";
    string nume_client = "";
    string prenume_client = "";
    int status_debit = 0;
    float suma_debit = 0;
    int status_credit = 0; 
    float suma_credit = 0;
    float suma_depozit = 0;

    for (int i = 0; i < nr_clienti; i++)
    {  
        fin >> cod_client >> parola >> nume_client >> prenume_client >> status_debit >> suma_debit >> status_credit >> suma_credit >> suma_depozit; // detaliile fiecarui client
        clienti[i].Citire_Client(cod_client, parola, nume_client, prenume_client, status_debit, suma_debit, status_credit, suma_credit, suma_depozit); // sunt memorate
    }

   //ofstream fout("TEST.txt");
   //fout << nr_clienti << endl;

    Meniu_Principal(clienti,nr_clienti);

    
    return 0;
}

