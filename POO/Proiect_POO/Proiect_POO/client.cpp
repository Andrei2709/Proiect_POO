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
}

void Client::Citire_Client(std::string cod_client, std::string nume_client, std::string prenume_client, int status_debit, int suma_debit, int status_credit, int suma_credit)
{
	this->cod_client = cod_client;
	this->nume_client = nume_client;
	this->prenume_client = prenume_client;
	this->debit.status = status_debit;
	this->debit.suma = suma_debit;
	this->credit.status = status_credit;
	this->credit.suma = suma_credit;
}

void Client::Afisare_Client()
{
	cout << cod_client << " " << nume_client << " " << prenume_client << " " << debit.status << " " << debit.suma << " " << credit.status <<" "<<credit.suma;
	cout << endl;
}

void Client::Afisare_In_Fisier()
{
	ofstream of;
	of.open("clienti.txt", std::ios::app);

	of << cod_client << " " << nume_client << " " << prenume_client << " " << debit.status << " " << debit.suma << " " << credit.status << " " << credit.suma;
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

int Client::Afisare_Suma_Debit()
{
	return this->debit.suma;
}

int Client::Afisare_Suma_Credit()
{
	return this->credit.suma;
}

void Client::Actualizare_Suma_Debit(int suma)
{
	this->debit.suma = suma;
}

void Client::Actualizare_Suma_Credit(int suma)
{
	this->credit.suma = suma;
}
