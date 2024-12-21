#ifndef BANCA_H
#define BANCA_H

#include "client.h"
#include "administrator.h"

class Banca
{
public:

	void Citire_Lista_Clienti();
	void Meniu_Principal();
	bool Revenire_Meniu_Principal();
	int Revenire_Meniu_Principal_Text(std::string tip_meniu);
	void Submeniu_Login();
	void Submeniu_Debit();
	void Submeniu_Credit();
	void Submeniu_Depozit();
	void Submeniu_Inregistrare();

private:

	int nr_clienti;
	int client_activ;
	Client clienti[100];
	Administrator administrator;

};

#endif