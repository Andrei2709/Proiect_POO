#include "cont.h"

Cont::Cont()
{
	this->status = 0;
	this->suma = -1;
}

void Cont::Actualizare_Status(int status)
{
	this->status = status;
}

void Cont::Actualizare_Suma(float suma)
{
	this->suma = suma;
}

int Cont::Afisare_Status()
{
	return this->status;
}

float Cont::Afisare_Suma()
{
	return this->suma;
}
