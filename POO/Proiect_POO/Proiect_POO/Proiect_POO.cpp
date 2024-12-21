#include <iostream>
#include <fstream>
#include <string>
#include "client.h"
#include "banca.h"

using namespace std;

int nr_clienti;

int main()
{
    Banca banca;

    banca.Citire_Lista_Clienti();

   //ofstream fout("TEST.txt");
   //fout << nr_clienti << endl;

    banca.Meniu_Principal();
    
    return 0;
}

