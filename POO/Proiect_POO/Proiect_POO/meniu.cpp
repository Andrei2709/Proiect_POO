#include <iostream>
#include <fstream>
#include <string>
#include "client.h"

using namespace std;

bool Revenire_Meniu_Principal()
{
    cout << "Doriti sa reveniti la meniul principal?" << endl<<endl;
    cout << "< 1 > Da" << endl << "< 2 > Nu" << endl << endl;
    cout << "Optiunea dumneavoastra: ";
    int raspuns;
    cin >> raspuns;
    cout << endl;
    while (raspuns != 1 && raspuns != 2)
    {
        cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        cin >> raspuns;
        cout << endl;
    }
    if (raspuns == 1)
        return true;
    else
    {
        cout << "Va multumim ca ati ales serviciile noastre. O zi buna!";
        return false;
    }
}

int Submeniu_Login(Client clienti[], int nr_clienti)
{
    int ok_login = 0, client_activ;
    while (ok_login == 0)
    {
        string cod,parola;
        cout << "Introduceti codul de client: ";
        cin >> cod;
        cout << endl;
        cout << "Introduceti parola: ";
        cin >> parola;
        cout << endl;
        client_activ = 0;
        while (client_activ < nr_clienti) // verificare combinatie cod+parola
        {
            if (clienti[client_activ].Verificare_Login(cod,parola))
            {
                ok_login = 1;
            }
            if (ok_login)
                break;
            client_activ++;
        }
        if (ok_login)
            break;
        cout << "Combinatia codului de client si a parolei nu se potrivesc. Va rugam sa reincercati." << endl << endl;
    }

    return client_activ;
}

void Submeniu_Debit(Client clienti[], int nr_clienti, int client_activ)
{
    if (clienti[client_activ].Status_Cont("debit"))
    {
        int optiune_debit, ok_opt_debit = 0;
        system("cls");
        cout << "<Cont de debit> Selectati optiunea dorita:" << endl << endl;
        cout << "< 1 > Interogare sold" << endl << "< 2 > Retragere numerar" << endl << "< 3 > Depunere numerar" << endl << "< 4 > Inchidere cont debit" << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        cin >> optiune_debit;
        cout << endl;

        while (ok_opt_debit == 0)
        {

            switch (optiune_debit)
            {
            case 1:
            {
                system("cls");
                ok_opt_debit = 1;

                cout << "Suma din contul dumneavoastra de debit este de ";
                float suma_debit = clienti[client_activ].Afisare_Suma_Cont("debit");
                cout << suma_debit << " lei." << endl << endl;

                break;
            }

            case 2:
            {
                system("cls");
                ok_opt_debit = 1;

                float suma_debit = clienti[client_activ].Afisare_Suma_Cont("debit");

                float suma_retrasa = 0;
                while (suma_retrasa<1 || suma_retrasa>suma_debit)
                {
                    cout << "Introduceti suma pe care doriti sa o retrageti: ";
                    cin >> suma_retrasa;
                    cout << endl;
                    if (suma_retrasa > 0 && suma_retrasa <= suma_debit)
                        break;
                    cout << "Introduceti o suma valida." << endl << endl;
                }
                cout << "Suma a fost retrasa cu success." << endl << endl;
                clienti[client_activ].Actualizare_Suma_Cont("debit",suma_debit - suma_retrasa);

                break;
            }

            case 3:
            {
                system("cls");
                ok_opt_debit = 1;

                float suma_debit = clienti[client_activ].Afisare_Suma_Cont("debit");

                float suma_depusa = 0;
                while (suma_depusa < 1)
                {
                    cout << "Introduceti suma pe care doriti sa o depuneti: ";
                    cin >> suma_depusa;
                    cout << endl;
                    if (suma_depusa > 0)
                        break;
                    cout << "Introduceti o suma valida." << endl << endl;
                }
                cout << "Suma a fost depusa cu success." << endl << endl;
                clienti[client_activ].Actualizare_Suma_Cont("debit",suma_debit + suma_depusa);

                break;
            }

            case 4:
            {
                system("cls");
                ok_opt_debit = 1;

                cout << "<Inchidere cont debit> Tastati 1 pentru a confirma." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                int opt_inchidere_debit;
                cin >> opt_inchidere_debit;
                cout << endl;
                if (opt_inchidere_debit == 1)
                {
                    clienti[client_activ].Actualizare_Status_Cont("debit", 0);
                    cout << "Contul de debit a fost inchis cu succes." << endl << endl;
                }
                break;
            }

            default:
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_debit;
                cout << endl;
            }

            }
        }

    }
    else
    {
        system("cls");
        cout << "Nu exista un cont de debit asociat contului dumneavoastra. Doriti sa creati unul?" << endl << endl;
        cout << "< 1 > Da" << endl << "< 2 > Nu" << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        int optiune_creare_debit, ok_opt_cr_deb = 0;
        cin >> optiune_creare_debit;
        cout << endl;

        while (ok_opt_cr_deb == 0)
        {
            switch (optiune_creare_debit)
            {
            case 1:
            {
                ok_opt_cr_deb = 1;

                clienti[client_activ].Actualizare_Status_Cont("debit", 0);
                clienti[client_activ].Actualizare_Suma_Cont("debit",0);
                cout << "Contul de debit a fost creat cu success" << endl << endl;

                break;
            }

            case 2:
            {
                ok_opt_cr_deb = 1;
                break;
            }

            default:
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_creare_debit;
                cout << endl;
            }

            }
        }

    }
}

void Submeniu_Credit(Client clienti[], int nr_clienti, int client_activ)
{
    if (clienti[client_activ].Status_Cont("credit"))
    {
        int optiune_credit, ok_opt_credit = 0;
        system("cls");
        cout << "<Cont de credit> Selectati optiunea dorita:" << endl << endl;
        cout << "< 1 > Interogare suma datorata" << endl << "< 2 > Retragere numerar" << endl << "< 3 > Depunere numerar" << endl << "< 4 > Meniu data" << endl << "< 5 > Inchidere cont credit" << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        cin >> optiune_credit;
        cout << endl;

        while (ok_opt_credit == 0)
        {

            switch (optiune_credit)
            {
            case 1: // suma datorata
            {
                system("cls");
                ok_opt_credit = 1;

                float suma_credit = clienti[client_activ].Afisare_Suma_Cont("credit");

                if (suma_credit != 0 && clienti[client_activ].Status_Cont("credit") == 1)
                {
                    cout << "Suma datorata este de ";
                    cout << suma_credit << " lei. Aceasta trebuie platita in maxim 6 luni." << endl << endl;
                }
                else
                {
                    if (suma_credit != 0 && clienti[client_activ].Status_Cont("credit") == -1)
                    {
                        cout << "Contul dumneavoastra a fost blocat pentru neachitarea datoriei. Va rugam achitati suma datorata de ";
                        cout << suma_credit;
                        cout << " lei pentru deblocare." << endl << endl;
                    }
                    else
                    {
                        cout << "Nu aveti nicio datorie." << endl << endl;
                    }
                }

                break;
            }

            case 2: // retragere cu comision 5%
            {
                system("cls");
                ok_opt_credit = 1;

                float suma_credit = clienti[client_activ].Afisare_Suma_Cont("credit");

                if (clienti[client_activ].Status_Cont("credit") == 1)
                {
                    float suma_retrasa = 0;
                    while (suma_retrasa < 1 || suma_retrasa>1000000)
                    {
                        cout << "Introduceti suma pe care doriti sa o retrageti (maxim 1.000.000 lei): ";
                        cin >> suma_retrasa;
                        cout << endl;
                        if (suma_retrasa > 0 && suma_retrasa <= 1000000)
                            break;
                        cout << "Introduceti o suma valida." << endl << endl;
                    }
                    cout << "Suma a fost retrasa cu success." << endl << endl;
                    clienti[client_activ].Actualizare_Suma_Cont("credit",suma_credit + 1.05f * suma_retrasa);
                }
                else
                {
                    cout << "Contul dumneavoastra a fost blocat pentru neachitarea datoriei." << endl << endl;
                }

                break;
            }

            case 3: // depunere 
            {
                system("cls");
                ok_opt_credit = 1;

                float suma_credit = clienti[client_activ].Afisare_Suma_Cont("credit");

                if (suma_credit == 0)
                {
                    cout << "Nu trebuie sa achitati nicio datorie." << endl << endl;
                    break;
                }

                float suma_depusa = 0;
                while (suma_depusa < 1 || suma_depusa > suma_credit)
                {
                    cout << "Introduceti suma pe care doriti sa o depuneti: ";
                    cin >> suma_depusa;
                    cout << endl;
                    if (suma_depusa > 0 && suma_depusa <= suma_credit)
                        break;
                    cout << "Introduceti o suma valida." << endl << endl;
                }

                clienti[client_activ].Actualizare_Suma_Cont("credit",suma_credit - suma_depusa);

                if (clienti[client_activ].Status_Cont("credit") == 1)
                {
                    cout << "Suma a fost depusa cu success." << endl << endl;
                }
                else
                {
                    if (clienti[client_activ].Afisare_Suma_Cont("credit") == 0)
                    {
                        cout << "Suma a fost depusa cu success. Contul dumneavoastra a fost deblocat" << endl << endl;
                        clienti[client_activ].Actualizare_Status_Cont("credit",1);
                    }

                }

                break;
            }

            case 4: // meniu data
            {
                system("cls");
                ok_opt_credit = 1;

                cout << "<Meniu data> Doriti sa treaca 6 luni? Tastati 1 pentru cazul afirmativ." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                int opt_data;
                cin >> opt_data;

                if (opt_data == 1)
                {
                    float suma_credit = clienti[client_activ].Afisare_Suma_Cont("credit");
                    if (suma_credit != 0 && clienti[client_activ].Status_Cont("credit") == 1)
                    {
                        clienti[client_activ].Actualizare_Status_Cont("credit", -1);
                    }
                }
                cout << endl;
                break;
            }

            case 5: // stergere cont credit
            {
                system("cls");
                ok_opt_credit = 1;


                if (clienti[client_activ].Status_Cont("credit") == 1)
                {

                    if (clienti[client_activ].Afisare_Suma_Cont("credit") == 0)
                    {
                        cout << "<Inchidere cont credit> Tastati 1 pentru a confirma." << endl << endl;
                        cout << "Optiunea dumneavoastra: ";
                        int opt_inchidere_credit;
                        cin >> opt_inchidere_credit;
                        cout << endl;
                        if (opt_inchidere_credit == 1)
                        {
                            clienti[client_activ].Actualizare_Status_Cont("credit", 0);
                            cout << "Contul de credit a fost inchis cu succes." << endl << endl;
                        }
                    }
                    else
                    {
                        cout << "Achitati datoria pentru a putea efectua inchiderea." << endl << endl;
                    }
                }
                else
                {
                    cout << "Contul dumneavoastra de credit a fost blocat. Achitati datoria pentru a putea efectua inchiderea." << endl << endl;
                }

                break;
            }

            default:
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_credit;
                cout << endl;
            }

            }
        }

    }
    else
    {
        system("cls");
        cout << "Nu exista un cont de credit asociat contului dumneavoastra. Doriti sa creati unul?" << endl << endl;
        cout << "< 1 > Da" << endl << "< 2 > Nu" << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        int optiune_creare_credit, ok_opt_cr_cred = 0;
        cin >> optiune_creare_credit;
        cout << endl;

        while (ok_opt_cr_cred == 0)
        {
            switch (optiune_creare_credit)
            {
            case 1:
            {
                ok_opt_cr_cred = 1;

                clienti[client_activ].Actualizare_Status_Cont("credit", 1);
                clienti[client_activ].Actualizare_Suma_Cont("credit",0);
                cout << "Contul de credit a fost creat cu success" << endl << endl;

                break;
            }

            case 2:
            {
                ok_opt_cr_cred = 1;
                break;
            }

            default:
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_creare_credit;
                cout << endl;
            }

            }
        }

    }
}

void Submeniu_Depozit(Client clienti[], int nr_clienti, int client_activ)
{
    if (clienti[client_activ].Status_Cont("debit") == 1)
    {
        int optiune_depozit, ok_opt_depozit = 0;
        float suma_depozit = clienti[client_activ].Afisare_Suma_Cont("depozit");
        system("cls");
        cout << "<Depozit cu dobanda fixa 5%/an> Suma depozitata: "<<suma_depozit<<" lei. Selectati optiunea dorita : " << endl << endl;
        cout << "< 1 > Depunere" << endl << "< 2 > Meniu data" << endl << endl;
        cout << "Optiunea dumneavoastra: ";
        cin >> optiune_depozit;
        cout << endl;

        while (ok_opt_depozit == 0)
        {

            switch (optiune_depozit)
            {

            case 1: // depunere 
            {
                system("cls");
                ok_opt_depozit = 1;

                float suma_debit = clienti[client_activ].Afisare_Suma_Cont("debit");
                float suma_depozit = clienti[client_activ].Afisare_Suma_Cont("depozit");

                if (suma_debit == 0)
                {
                    cout << "Soldul contului dumneavoastra de debit este nul. Nu puteti efectua un depozit." << endl << endl;
                    break;
                }

                float suma_depusa = 0;
                while (suma_depusa < 1 || suma_depusa > suma_debit)
                {
                    cout << "Introduceti suma pe care doriti sa o depuneti: ";
                    cin >> suma_depusa;
                    cout << endl;
                    if (suma_depusa > 0 && suma_depusa <= suma_debit)
                        break;
                    cout << "Introduceti o suma valida." << endl << endl;
                }

                clienti[client_activ].Actualizare_Suma_Cont("depozit",suma_depozit + suma_depusa);
                clienti[client_activ].Actualizare_Suma_Cont("debit",suma_debit - suma_depusa);
                cout << "Suma a fost depusa cu success." << endl << endl;


                break;
            }

            case 2: // meniu data
            {
                system("cls");
                ok_opt_depozit = 1;

                cout << "<Meniu data> Doriti sa treaca un an? Tastati 1 pentru cazul afirmativ." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                int opt_data;
                cin >> opt_data;

                if (opt_data == 1)
                {
                    cout << endl;
                    float suma_debit = clienti[client_activ].Afisare_Suma_Cont("debit");
                    float suma_depozit = clienti[client_activ].Afisare_Suma_Cont("depozit");
                    clienti[client_activ].Actualizare_Suma_Cont("debit",suma_debit + 1.05f * suma_depozit);
                    clienti[client_activ].Actualizare_Suma_Cont("depozit",0);
                    cout << "Depozitul dumneavoastra a generat ";
                    cout << 0.05 * suma_depozit << " de lei care au fost adaugati in contul de debit." << endl;
                }
                cout << endl;
                break;
            }


            default:
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_depozit;
                cout << endl;
            }

            }
        }

    }
    else
    {
        cout << "Pentru a putea accesa depozitul cu dobanda fixa trebuie sa aveti un cont de debit." << endl << endl;
    }
}

int Submeniu_Inregistrare(Client clienti[], int nr_clienti)
{
    int ok_inregistrare = 0;
    while (ok_inregistrare == 0)
    {
        string cod_client_nou;

        cout << "Introduceti codul de client dorit (format din 4 majuscule): ";
        cin >> cod_client_nou;
        cout << endl;

        int ok_cod_nou = 1;
        for (int i = 0; i < nr_clienti; i++)
        {
            if (clienti[i].Verificare_Cod(cod_client_nou) || cod_client_nou.length() != 4)
            {
                ok_cod_nou = 0;
                break;
            }

        }

        if (ok_cod_nou == 0 || (cod_client_nou[0] < 'A' || cod_client_nou[0] > 'Z') || (cod_client_nou[1] < 'A' || cod_client_nou[1] > 'Z') || (cod_client_nou[2] < 'A' || cod_client_nou[2] > 'Z') || (cod_client_nou[3] < 'A' || cod_client_nou[3] > 'Z'))
        {
            cout << "Cod invalid sau deja exista. ";
        }
        else
        {
            ok_inregistrare = 1;

            cout << "Introduceti o parola pentru contul dumneavoastra: ";
            string parola_client_nou;
            cin >> parola_client_nou;
            cout << endl;
            cout << "Introduceti numele dumneavoastra: ";
            string nume_client_nou;
            cin >> nume_client_nou;
            cout << endl;
            cout << "Introduceti prenumele dumneavoastra: ";
            string prenume_client_nou;
            cin >> prenume_client_nou;
            cout << endl;


            clienti[nr_clienti].Citire_Client(cod_client_nou, parola_client_nou, nume_client_nou, prenume_client_nou, 0, 0, 0, 0, 0);
            nr_clienti++;
            cout << "Contul dumneavoastra a fost creat cu success." << endl << endl;
        }

    }

    return nr_clienti;
}

void Meniu_Principal(Client clienti[], int nr_clienti)
{
    int optiune_princ,ok_optiune_princ = 0;
    int utilizatori_stersi = 0;
    Administrator administrator;

    system("cls");
    cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
    cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > Administrator" << endl<< "< 4 > Inchidere program" << endl << endl;
    cout << "Optiunea dumneavoastra: ";
    cin >> optiune_princ;
    cout << endl;

    while (ok_optiune_princ == 0)
    {
        switch (optiune_princ)
        {

        case 1: // log-in -> meniu client
        {
            ok_optiune_princ = 1;
            system("cls");

            int client_activ = Submeniu_Login(clienti, nr_clienti); // functie login

            int optiune, ok_optiune = 0;

            system("cls");
            cout << "<Meniu client> <Cod client: ";
            clienti[client_activ].Afisare_Cod();
            cout << "> Selectati optiunea dorita:" << endl << endl;
            cout << "< 1 > Informatii cont debit" << endl << "< 2 > Informatii cont credit" << endl << "< 3 > Informatii depozit" << endl;
            cout << "< 4 > Inchidere cont" << endl << "< 5 > Intoarcere la meniul principal" << endl << endl;
            cout << "Optiunea dumneavoastra: ";
            cin >> optiune;
            cout << endl;

            while (ok_optiune == 0)
            {      

                switch (optiune)
                {

                case 1: // informatii cont debit
                {
                    ok_optiune = 1;
                    
                    Submeniu_Debit(clienti, nr_clienti,client_activ); // functie cont debit
                    
                    if (Revenire_Meniu_Principal())
                    {
                        ok_optiune = 0;
                        system("cls");
                        cout << "<Meniu client> <Cod client: ";
                        clienti[client_activ].Afisare_Cod();
                        cout << "> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Informatii cont debit" << endl << "< 2 > Informatii cont credit" << endl << "< 3 > Informatii depozit" << endl;
                        cout << "< 4 > Inchidere cont" << endl << "< 5 > Intoarcere la meniul principal" << endl << endl;
                        cout << "Optiunea dumneavoastra: ";
                        cin >> optiune;
                        cout << endl;
                    }
                    break;
                }
                
                case 2: // informatii cont credit
                {
                    ok_optiune = 1;

                    Submeniu_Credit(clienti, nr_clienti, client_activ); // functie cont credit

                    if (Revenire_Meniu_Principal())
                    {
                        ok_optiune = 0;
                        system("cls");
                        cout << "<Meniu client> <Cod client: ";
                        clienti[client_activ].Afisare_Cod();
                        cout << "> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Informatii cont debit" << endl << "< 2 > Informatii cont credit" << endl << "< 3 > Informatii depozit" << endl;
                        cout << "< 4 > Inchidere cont" << endl << "< 5 > Intoarcere la meniul principal" << endl << endl;
                        cout << "Optiunea dumneavoastra: ";
                        cin >> optiune;
                        cout << endl;
                    }

                    break;
                }

                case 3: // informatii depozit 
                {
                    ok_optiune = 1;

                    Submeniu_Depozit(clienti, nr_clienti, client_activ); // functie depozit

                    if (Revenire_Meniu_Principal())
                    {
                        ok_optiune = 0;
                        system("cls");
                        cout << "<Meniu client> <Cod client: ";
                        clienti[client_activ].Afisare_Cod();
                        cout << "> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Informatii cont debit" << endl << "< 2 > Informatii cont credit" << endl << "< 3 > Informatii depozit" << endl;
                        cout << "< 4 > Inchidere cont" << endl << "< 5 > Intoarcere la meniul principal" << endl << endl;
                        cout << "Optiunea dumneavoastra: ";
                        cin >> optiune;
                        cout << endl;
                    }

                    break;
                }

                case 4: // inchidere cont
                {
                    ok_optiune = 1;

                    int sters = 1;
                    if (clienti[client_activ].Status_Cont("debit") == 0 && clienti[client_activ].Status_Cont("credit") == 0)
                    {
                        system("cls");
                        cout << "Doriti sa inchideti definitiv contul? Tastati 1 in caz afirmativ."<<endl<<endl;
                        cout << "Optiunea dumneavoastra: ";
                        int opt_inchidere;
                        cin >> opt_inchidere;
                        if (opt_inchidere == 1)
                        {
                            clienti[client_activ].Actualizare_Cod("0000");
                            utilizatori_stersi++;
                            cout << endl;
                            cout << "Contul dumneavoastra a fost sters cu succes." << endl<< endl ;

                            ok_optiune_princ = 0;

                            system("cls");
                            cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
                            cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > Administrator" << endl << "< 4 > Inchidere program" << endl << endl;
                            cout << "Optiunea dumneavoastra: ";
                            cin >> optiune_princ;
                            cout << endl;
                        }

                    }
                    else
                    {
                        cout << "Pentru a putea sterge definitiv contul dumneavoastra trebuie sa inchideti initial conturile de credit si/sau debit." << endl << endl;

                        if (Revenire_Meniu_Principal())
                        {
                            ok_optiune = 0;
                            system("cls");
                            cout << "<Meniu client> <Cod client: ";
                            clienti[client_activ].Afisare_Cod();
                            cout << "> Selectati optiunea dorita:" << endl << endl;
                            cout << "< 1 > Informatii cont debit" << endl << "< 2 > Informatii cont credit" << endl << "< 3 > Informatii depozit" << endl;
                            cout << "< 4 > Inchidere cont" << endl << "< 5 > Intoarcere la meniul principal" << endl << endl;
                            cout << "Optiunea dumneavoastra: ";
                            cin >> optiune;
                            cout << endl;
                        }
                    }

                    break;
                }

                case 5: // meniu principal
                {
                    ok_optiune = 1;


                    if (Revenire_Meniu_Principal())
                    {
                        ok_optiune_princ = 0;
                        system("cls");
                        cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > Administrator" << endl << "< 4 > Inchidere program"<< endl << endl;
                        cout << "Optiunea dumneavoastra: ";
                        cin >> optiune_princ;
                        cout << endl;
                    }

                    break;
                }

                default:
                {
                    cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                    cout << "Optiunea dumneavoastra: ";
                    cin >> optiune;
                    cout << endl;

                    break;
                }

                }

            }

            break;
        }

        case 2: // inregistrare client nou
        {
            ok_optiune_princ = 1;
            system("cls");

            cout << "<Meniu inregistrare client nou>" << endl << endl;

            nr_clienti = Submeniu_Inregistrare(clienti, nr_clienti);

            if (Revenire_Meniu_Principal())
            {
                ok_optiune_princ = 0;
                system("cls");
                cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
                cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > Administrator" << endl << "< 4 > Inchidere program" << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_princ;
                cout << endl;
            }

            break;
        }

        case 3: // administrator
        {
            ok_optiune_princ = 1;
            system("cls");

            administrator.Lista_Clienti(administrator, clienti, nr_clienti); // afisare lista clienti

            if (Revenire_Meniu_Principal())
            {
                ok_optiune_princ = 0;
                system("cls");
                cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
                cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > Administrator" << endl << "< 4 > Inchidere program" << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_princ;
                cout << endl;
            }

            break;
        }

        case 4: // iesire program
        {
            ok_optiune_princ = 1;
            break;
        }

        default: //optiuni invalide
        {
            while (optiune_princ != 1 && optiune_princ != 2 && optiune_princ != 3)
            {
                cout << "Va rugam sa alegeti o optiune disponibila." << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_princ;
                cout << endl;
            }
            break;
        }

        }
    }

   // scriere in fisier 

    administrator.Salvare_Date(clienti, nr_clienti, utilizatori_stersi);
   
}

