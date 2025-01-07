#include <iostream>
#include <string>
#include "client.h"
#include "banca.h"

using namespace std;

int nr_clienti;

int main()
{
    Banca banca;

    banca.Citire_Lista_Clienti(); // citire din fisier 

    banca.Meniu_Principal(); // PAROLA ADMIN = parola_admin
    
    return 0;
}

