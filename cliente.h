#pragma once
#include <string>
using namespace std;
class Cliente {
private:
    int codigo;
    string nombre;
    string tipo;

public:
    Cliente(int codigo, string& nombre, string& tipo);

    int getCodigo();
    string getNombre();
    string getTipo();
    void setCodigo(int codigo);
};