#include <iostream>
#include <fstream>
#include <string>
#include "client.h"

using namespace std;

Client::Client()
{
	this->cod_client = -1;
	this->parola = "";
	this->nume_client = "";
	this->prenume_client = "";
	this->debit.Actualizare_Status(0);
	this->debit.Actualizare_Suma(-1);
	this->credit.Actualizare_Status(0);
	this->credit.Actualizare_Suma(-1);
	this->depozit.Actualizare_Status(1);
	this->depozit.Actualizare_Suma(0);
}

void Client::Citire_Client(string cod_client, string parola, string nume_client, string prenume_client, int status_debit, float suma_debit, int status_credit, float suma_credit, float suma_depozit)
{
	this->cod_client = cod_client;
	this->parola = parola;
	this->nume_client = nume_client;
	this->prenume_client = prenume_client;
	this->debit.Actualizare_Status(status_debit);
	this->debit.Actualizare_Suma(suma_debit);
	this->credit.Actualizare_Status(status_credit);
	this->credit.Actualizare_Suma(suma_credit);
	this->depozit.Actualizare_Suma(suma_depozit);
}

void Client::Afisare_Client()
{
	cout << "Cod client: " << cod_client << endl;
	cout << "Nume client: " << nume_client << " " << prenume_client << endl;
	cout << "Informatii cont debit: ";
	if (debit.Afisare_Status())
	{
		cout << "exista, suma de ";
		cout << debit.Afisare_Suma() << " lei." << endl;
	}
	else
		cout << "nu exista."<<endl;

	cout << "Informatii cont credit: ";
	if (credit.Afisare_Status()==1)
	{
		cout << "exista, datoreaza suma de ";
		cout << credit.Afisare_Suma() << " lei." << endl;
	}
	else
	{
		if (credit.Afisare_Status() == -1)
		{
			cout << "blocat, datoreaza suma de ";
			cout << credit.Afisare_Suma() << " lei." << endl;
		}
		else
		{
			cout << "nu exista." << endl;
		}
	}

	cout << "Informatii depozit dobanda fixa: suma de "<<depozit.Afisare_Suma()<<" lei."<<endl<<endl;

}

void Client::Afisare_In_Fisier()
{
	ofstream of;
	of.open("clienti.txt", std::ios::app);

	of << cod_client << " " << parola << " " << nume_client << " " << prenume_client << " " << debit.Afisare_Status() << " " << debit.Afisare_Suma() << " " << credit.Afisare_Status() << " " << credit.Afisare_Suma() << " " << depozit.Afisare_Suma();
	of << endl;
}

bool Client::Verificare_Login(string cod, string parola)
{
	if (cod==this->cod_client && parola==this->parola)
		return true;
	return false;
}

bool Client::Verificare_Cod(string cod)
{
	if (cod == this->cod_client)
		return true;
	return false;
}

void Client::Afisare_Cod()
{
	cout << this->cod_client;
}

void Client::Actualizare_Cod(std::string cod)
{
	this->cod_client = cod;
}

int Client::Status_Cont(string tip_cont)
{
	if (tip_cont == "debit")
		return this->debit.Afisare_Status();

	if (tip_cont == "credit")
		return this->credit.Afisare_Status();

	return -1;
}

void Client::Actualizare_Status_Cont(string tip_cont, int status)
{
	if (tip_cont == "debit")
		this->debit.Actualizare_Status(status);

	if (tip_cont == "credit")
		this->credit.Actualizare_Status(status);
}

float Client::Afisare_Suma_Cont(string tip_cont)
{
	if (tip_cont == "debit")
		return this->debit.Afisare_Suma();

	if (tip_cont == "credit")
		return this->credit.Afisare_Suma();

	if(tip_cont == "depozit")
		return this->depozit.Afisare_Suma();

	return -1;
}

void Client::Actualizare_Suma_Cont(string tip_cont, float suma)
{
	if (tip_cont == "debit")
		this->debit.Actualizare_Suma(suma);

	if (tip_cont == "credit")
		this->credit.Actualizare_Suma(suma);

	if (tip_cont == "depozit")
		this->depozit.Actualizare_Suma(suma);
}

//administrator

Administrator::Administrator()
{
	Citire_Client("ADMIN", "parola_admin", "", "", 0, 0, 0, 0, 0);
}

void Administrator::Lista_Clienti(Administrator administrator, Client clienti[], int nr_clienti)
{
	string parola;
	cout << "Introduceti parola: ";
	cin >> parola;
	cout << endl;

	if(administrator.Verificare_Login("ADMIN",parola))
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