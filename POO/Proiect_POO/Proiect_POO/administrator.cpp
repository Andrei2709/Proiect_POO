#include <iostream>
#include <fstream>
#include <string>
#include "administrator.h"

using namespace std;

Administrator::Administrator()
{
    Citire_Client("ADMIN", "parola_admin", "", "", 0, 0, 0, 0, 0); // PAROLA ADMIN = parola_admin
}

void Administrator::Lista_Clienti(Administrator administrator, Client clienti[], int nr_clienti)
{
    string parola;
    cout << "Introduceti parola: ";
    cin >> parola;
    cout << endl;

    if (administrator.Verificare_Login("ADMIN", parola))
        for (int i = 0; i < nr_clienti; i++)
        {
            clienti[i].Afisare_Client();
        }
    else
    {
        cout << "Parola incorecta. ";
    }
}

void Administrator::Salvare_Date(Client clienti[], int nr_clienti, int utilizatori_stersi)
{
    ofstream fout("clienti.txt");
    fout << nr_clienti - utilizatori_stersi << endl;

    for (int i = 0; i < nr_clienti; i++)
    {
        if (clienti[i].Verificare_Cod("0000") == 0)
            clienti[i].Afisare_In_Fisier();
    }
}