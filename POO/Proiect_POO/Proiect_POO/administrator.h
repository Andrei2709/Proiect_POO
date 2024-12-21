#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "client.h"


class Administrator : protected Client
{
public:

    Administrator();
    void Lista_Clienti(Administrator administrator, Client clienti[], int nr_clienti);
    void Salvare_Date(Client clienti[], int nr_clienti, int utilizatori_stersi);

private:

};

#endif