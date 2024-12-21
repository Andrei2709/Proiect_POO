#ifndef CLIENT_H
#define CLIENT_H

#include "cont.h"
#include <string>

class Client
{
public:

	Client();
	void Citire_Client(std::string cod_client, std::string parola, std::string nume_client, std::string prenume_client, int status_debit, float suma_debit, int status_credit, float suma_credit, float suma_depozit);
	void Afisare_In_Fisier();
	void Afisare_Client();
	bool Verificare_Login(std::string cod, std::string parola);
	bool Verificare_Cod(std::string cod);
	void Afisare_Cod_Si_Nume();
	void Actualizare_Cod(std::string cod);
	int Status_Cont(std::string tip_cont);
	void Actualizare_Status_Cont(std::string tip_cont, int status);
	float Afisare_Suma_Cont(std::string tip_cont);
	void Actualizare_Suma_Cont(std::string tip_cont, float suma);

private:

	std::string cod_client;
	std::string parola;
	std::string nume_client;
	std::string prenume_client;

	Cont debit;
	Cont credit;
	Cont depozit;

};

#endif


