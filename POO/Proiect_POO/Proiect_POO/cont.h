#ifndef CONT_H
#define CONT_H

class Cont
{
private:

	int status; // 0 - nu exista cont; 1 - exista cont; -1 - cont blocat
	float suma;

public:

	Cont();
	void Actualizare_Status(int status);
	void Actualizare_Suma(float suma);
	int Afisare_Status();
	float Afisare_Suma();

};

#endif