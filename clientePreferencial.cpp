#include "ClientePreferencial.h"
using namespace std;
ClientePreferencial::ClientePreferencial(int id,string& nombre,string& tipo,string& tipoPreferencial)
    : Cliente(id, nombre, tipo), tipoPreferencial(tipoPreferencial) {}

string ClientePreferencial::getTipoPreferencial() {
    return tipoPreferencial;
}
