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


void Meniu_Principal(Client clienti[], int nr_clienti)
{
    int optiune_princ,ok_optiune_princ = 0;

    system("cls");
    cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
    cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > MENIU DATA" << endl << endl;
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

            int ok_login = 0,client_activ;
            while (ok_login == 0)
            {
                string cod;
                cout << "Introduceti codul de client: ";
                cin >> cod;
                cout << endl;
                client_activ = 0;
                while (client_activ < nr_clienti) // verificare cod
                {
                    if (clienti[client_activ].Verificare_Cod(cod))
                    {
                        ok_login = 1;
                    }
                    if (ok_login)
                        break;
                    client_activ++;
                }
                if (ok_login)
                    break;
                cout << "Codul de client nu a fost gasit. Va rugam sa reincercati." << endl<<endl;
            }

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
                    
                    if (clienti[client_activ].Status_Debit())
                    {
                        int optiune_debit, ok_opt_debit = 0;
                        system("cls");
                        cout << "<Cont de debit> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Interogare sold" << endl << "< 2 > Retragere numerar" << endl << "< 3 > Depunere numerar" << endl << endl;
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
                                int suma_debit = clienti[client_activ].Afisare_Suma_Debit();
                                cout <<suma_debit<< " lei."<<endl<<endl;

                                break;
                            }
                            
                            case 2:
                            {
                                system("cls");
                                ok_opt_debit = 1;

                                int suma_debit = clienti[client_activ].Afisare_Suma_Debit();

                                int suma_retrasa=0;
                                while (suma_retrasa<1 || suma_retrasa>suma_debit)
                                {
                                    cout << "Introduceti suma pe care doriti sa o retrageti: ";
                                    cin >> suma_retrasa;
                                    cout << endl;
                                    if (suma_retrasa>0 && suma_retrasa<=suma_debit)
                                        break;
                                    cout << "Introduceti o suma valida." << endl << endl;
                                }
                                cout << "Suma a fost retrasa cu success."<<endl<<endl;
                                clienti[client_activ].Actualizare_Suma_Debit(suma_debit - suma_retrasa);

                                break;
                            }

                            case 3:
                            {
                                system("cls");
                                ok_opt_debit = 1;

                                int suma_debit = clienti[client_activ].Afisare_Suma_Debit();

                                int suma_depusa = 0;
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
                                clienti[client_activ].Actualizare_Suma_Debit(suma_debit + suma_depusa);

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
                        cout << "Nu exista un cont de debit asociat contului dumneavoastra. Doriti sa creati unul?" << endl<<endl;
                        cout << "< 1 > Da" << endl << "< 2 > Nu" << endl<<endl;
                        cout << "Optiunea dumneavoastra: ";
                        int optiune_creare_debit, ok_opt_cr_deb=0;
                        cin >> optiune_creare_debit;
                        cout << endl;

                        while (ok_opt_cr_deb == 0)
                        {
                            switch (optiune_creare_debit)
                            {
                            case 1:
                            {
                                ok_opt_cr_deb = 1;

                                clienti[client_activ].Actualizare_Status_Debit(1);
                                clienti[client_activ].Actualizare_Suma_Debit(0);
                                cout << "Contul de debit a fost creat cu success" << endl<<endl;

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

                    if (clienti[client_activ].Status_Credit())
                    {
                        int optiune_credit, ok_opt_credit = 0;
                        system("cls");
                        cout << "<Cont de credit> Selectati optiunea dorita:" << endl << endl;
                        cout << "< 1 > Interogare suma datorata" << endl << "< 2 > Retragere numerar" << endl << "< 3 > Depunere numerar" <<endl<<"< 4 > Meniu data"<< endl << endl;
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

                                int suma_credit = clienti[client_activ].Afisare_Suma_Credit();

                                if (suma_credit != 0 && clienti[client_activ].Status_Credit() == 1)
                                {
                                    cout << "Suma datorata este de ";
                                    cout << suma_credit << " lei. Aceasta trebuie platita in maxim 6 luni." << endl << endl;
                                }
                                else
                                {
                                    if (suma_credit != 0 && clienti[client_activ].Status_Credit() == -1)
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

                                int suma_credit = clienti[client_activ].Afisare_Suma_Credit();

                                if (clienti[client_activ].Status_Credit() == 1)
                                {
                                    int suma_retrasa = 0;
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
                                    clienti[client_activ].Actualizare_Suma_Credit(suma_credit + 1.05 * suma_retrasa);
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

                                int suma_credit = clienti[client_activ].Afisare_Suma_Credit();

                                if (suma_credit == 0)
                                {
                                    cout << "Nu trebuie sa achitati nicio datorie." << endl << endl;
                                    break;
                                }

                                int suma_depusa = 0;
                                while (suma_depusa < 1 || suma_depusa > suma_credit)
                                {
                                    cout << "Introduceti suma pe care doriti sa o depuneti: ";
                                    cin >> suma_depusa;
                                    cout << endl;
                                    if (suma_depusa > 0 && suma_depusa <= suma_credit)
                                        break;
                                    cout << "Introduceti o suma valida." << endl << endl;
                                }

                                clienti[client_activ].Actualizare_Suma_Credit(suma_credit - suma_depusa);

                                if (clienti[client_activ].Status_Credit() == 1)
                                {
                                    cout << "Suma a fost depusa cu success." << endl << endl;
                                }
                                else
                                {
                                    if (clienti[client_activ].Afisare_Suma_Credit() == 0)
                                    {
                                        cout << "Suma a fost depusa cu success. Contul dumneavoastra a fost deblocat" << endl << endl;
                                        clienti[client_activ].Actualizare_Status_Credit(1);
                                    }

                                }

                                break;
                            }

                            case 4: // meniu data
                            {
                                system("cls");
                                ok_opt_credit = 1;

                                cout << "<Meniu data> Doriti sa treaca 6 luni? Tastati 1 pentru cazul afirmativ." << endl<<endl;
                                cout << "Optiunea dumneavoastra: ";
                                int opt_data;
                                cin >> opt_data;

                                if (opt_data == 1)
                                {
                                    int suma_credit = clienti[client_activ].Afisare_Suma_Credit();
                                    if (suma_credit != 0 && clienti[client_activ].Status_Credit() == 1)
                                    {
                                        clienti[client_activ].Actualizare_Status_Credit(-1);
                                    }
                                }
                                cout << endl;
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

                        while (ok_opt_cr_cred== 0)
                        {
                            switch (optiune_creare_credit)
                            {
                            case 1:
                            {
                                ok_opt_cr_cred = 1;

                                clienti[client_activ].Actualizare_Status_Credit(1);
                                clienti[client_activ].Actualizare_Suma_Credit(0);
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



                    if (Revenire_Meniu_Principal())
                        ok_optiune = 0;

                    break;
                }

                case 4: // inchidere cont
                {
                    ok_optiune = 1;



                    if (Revenire_Meniu_Principal())
                        ok_optiune = 0;

                    break;
                }

                case 5: // meniu principal
                {
                    ok_optiune = 1;


                    if (Revenire_Meniu_Principal())
                        ok_optiune = 0;

                    ok_optiune = 0;
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

            int ok_inregistrare = 0;
            while (ok_inregistrare == 0)
            {
                string cod;
                char c1, c2, c3;

                cout << "Introduceti codul de client dorit (format din 3 majuscule): ";
                cin >> c1>>c2>>c3;
                cout << endl;

                
            }


            if (Revenire_Meniu_Principal())
            {
                ok_optiune_princ = 0;
                system("cls");
                cout << "<Meniu principal> Selectati optiunea dorita:" << endl << endl;
                cout << "< 1 > Log-in" << endl << "< 2 > Inregistrare client nou" << endl << "< 3 > MENIU DATA" << endl << endl;
                cout << "Optiunea dumneavoastra: ";
                cin >> optiune_princ;
                cout << endl;
            }

            break;
        }

        case 3: // MENIU DATA
        {
            ok_optiune_princ = 1;
            system("cls");

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

}

