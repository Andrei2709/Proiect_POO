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
	this->debit.status = 0;
	this->debit.suma = -1;
	this->credit.status = 0;
	this->credit.suma = -1;
	this->suma_depozit = 0;
}

void Client::Citire_Client(std::string cod_client, std::string nume_client, std::string prenume_client, int status_debit, float suma_debit, int status_credit, float suma_credit, float suma_depozit)
{
	this->cod_client = cod_client;
	this->nume_client = nume_client;
	this->prenume_client = prenume_client;
	this->debit.status = status_debit;
	this->debit.suma = suma_debit;
	this->credit.status = status_credit;
	this->credit.suma = suma_credit;
	this->suma_depozit = suma_depozit;
}

void Client::Afisare_Client()
{
	cout << "Cod client: " << cod_client << endl;
	cout << "Nume client: " << nume_client << " " << prenume_client << endl;
	cout << "Informatii cont debit: ";
	if (debit.status)
	{
		cout << "exista, suma de ";
		cout << debit.suma << " lei." << endl;
	}
	else
		cout << "nu exista."<<endl;

	cout << "Informatii cont credit: ";
	if (credit.status==1)
	{
		cout << "exista, datoreaza suma de ";
		cout << credit.suma << " lei." << endl;
	}
	else
	{
		if (credit.status == -1)
		{
			cout << "blocat, datoreaza suma de ";
			cout << credit.suma << " lei." << endl;
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

	of << cod_client << " " << nume_client << " " << prenume_client << " " << debit.status << " " << debit.suma << " " << credit.status << " " << credit.suma<< " "<<suma_depozit;
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
	return this->debit.status;
}

int Client::Status_Credit()
{
	return this->credit.status;
}

void Client::Actualizare_Status_Debit(int status)
{
	this->debit.status = status;
}

void Client::Actualizare_Status_Credit(int status)
{
	this->credit.status = status;
}

float Client::Afisare_Suma_Debit()
{
	return this->debit.suma;
}

float Client::Afisare_Suma_Credit()
{
	return this->credit.suma;
}

float Client::Afisare_Suma_Depozit()
{
	return this->suma_depozit;
}

void Client::Actualizare_Suma_Debit(float suma)
{
	this->debit.suma = suma;
}

void Client::Actualizare_Suma_Credit(float suma)
{
	this->credit.suma = suma;
}

void Client::Actualizare_Suma_Depozit(float suma)
{
	this->suma_depozit = suma;
}