#include <iostream>
#include <fstream>
#include <string>
#include "client.h"

using namespace std;

Client::Client()
{
	this->cod_client = -1;
	this->nume_client = "";
	this->prenume_client = "";
	this->debit.Actualizare_Status(0);
	this->debit.Actualizare_Suma(-1);
	this->credit.Actualizare_Status(0);
	this->credit.Actualizare_Suma(-1);
	this->suma_depozit = 0;
}

void Client::Citire_Client(std::string cod_client, std::string nume_client, std::string prenume_client, int status_debit, float suma_debit, int status_credit, float suma_credit, float suma_depozit)
{
	this->cod_client = cod_client;
	this->nume_client = nume_client;
	this->prenume_client = prenume_client;
	this->debit.Actualizare_Status(status_debit);
	this->debit.Actualizare_Suma(suma_debit);
	this->credit.Actualizare_Status(status_credit);
	this->credit.Actualizare_Suma(suma_credit);
	this->suma_depozit = suma_depozit;
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

	cout << "Informatii depozit dobanda fixa: suma de "<<suma_depozit<<" lei."<<endl<<endl;


}

void Client::Afisare_In_Fisier()
{
	ofstream of;
	of.open("clienti.txt", std::ios::app);

	of << cod_client << " " << nume_client << " " << prenume_client << " " << debit.Afisare_Status() << " " << debit.Afisare_Suma() << " " << credit.Afisare_Status() << " " << credit.Afisare_Suma() << " "<<suma_depozit;
	of << endl;
}

bool Client::Verificare_Cod(string cod)
{
	if (cod==this->cod_client)
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

int Client::Status_Debit()
{
	return this->debit.Afisare_Status();
}

int Client::Status_Credit()
{
	return this->credit.Afisare_Status();
}

void Client::Actualizare_Status_Debit(int status)
{
	this->debit.Actualizare_Status(status);
}

void Client::Actualizare_Status_Credit(int status)
{
	this->credit.Actualizare_Status(status);
}

float Client::Afisare_Suma_Debit()
{
	return this->debit.Afisare_Suma();
}

float Client::Afisare_Suma_Credit()
{
	return this->credit.Afisare_Suma();
}

float Client::Afisare_Suma_Depozit()
{
	return this->suma_depozit;
}

void Client::Actualizare_Suma_Debit(float suma)
{
	this->debit.Actualizare_Suma(suma);
}

void Client::Actualizare_Suma_Credit(float suma)
{
	this->credit.Actualizare_Suma(suma);
}

void Client::Actualizare_Suma_Depozit(float suma)
{
	this->suma_depozit = suma;
}