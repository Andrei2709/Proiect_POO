#ifndef CLIENT_H
#define CLIENT_H

#include "cont.h"
#include <string>

class Client
{
public:

	Client();
	void Citire_Client(std::string cod_client, std::string nume_client, std::string prenume_client, int status_debit, float suma_debit, int status_credit, float suma_credit, float suma_depozit);
	void Afisare_Client();
	void Afisare_In_Fisier();
	bool Verificare_Cod(std::string cod);
	void Afisare_Cod();
	void Actualizare_Cod(std::string cod);
	int Status_Debit();
	int Status_Credit();
	void Actualizare_Status_Debit(int status);
	void Actualizare_Status_Credit(int status);
	float Afisare_Suma_Debit();
	float Afisare_Suma_Credit();
	float Afisare_Suma_Depozit();
	void Actualizare_Suma_Debit(float suma);
	void Actualizare_Suma_Credit(float suma);
	void Actualizare_Suma_Depozit(float suma);

private:

	std::string cod_client;
	std::string nume_client;
	std::string prenume_client;
	
	Cont debit;
	Cont credit;
	float suma_depozit;

};

#endif


