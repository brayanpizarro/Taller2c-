#pragma once
#include "Cliente.h"
using namespace std;
class ClientePreferencial : public Cliente {
private:
    string tipoPreferencial;

public:
    ClientePreferencial(int id,string& nombre,string& tipo,string& tipoPreferencial);

    string getTipoPreferencial();

};