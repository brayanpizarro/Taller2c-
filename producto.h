#pragma once
#include <iostream>
#include <string>
using namespace std;
class producto{
    private:
    string nombre;
    string codigo;
    public:
    producto(string nombre,string codigo);
    string getNombre();
    string getCodigo();
    void setNombre(string _nombre);
    void setCodigo(string _codigo);
    ~producto();
};