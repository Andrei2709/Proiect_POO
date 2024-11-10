#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client
{
public:

	Client();
	void Citire_Client(std::string cod_client, std::string nume_client, std::string prenume_client, int status_debit, int suma_debit, int status_credit, int suma_credit);
	void Afisare_Client();
	void Afisare_In_Fisier();
	bool Verificare_Cod(std::string cod);
	void Afisare_Cod();
	void Actualizare_Cod(std::string cod);
	int Status_Debit();
	int Status_Credit();
	void Actualizare_Status_Debit(int status);
	void Actualizare_Status_Credit(int status);
	int Afisare_Suma_Debit();
	int Afisare_Suma_Credit();
	void Actualizare_Suma_Debit(int suma);
	void Actualizare_Suma_Credit(int suma);

private:

	std::string cod_client;
	std::string nume_client;
	std::string prenume_client;

	class Cont
	{
	private:
		int status; // 0 - nu exista cont; 1 - exista cont; -1 - cont blocat
		int suma;

		friend class Client;

	public:
		Cont()
		{
			this->status = -1;
			this->suma = -1;
		}
		Cont(int status) : status(status) {}
	};
	
	Cont debit;
	Cont credit;

};

#endif


