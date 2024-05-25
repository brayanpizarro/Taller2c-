#pragma once
#include <iostream>
#include <string>
using namespace std;

class cliente{
    private:
    string nombre;
    string rut;
    int edad;
    bool embarazo;
    bool discapacidad;
    public:
    cliente(string _nombre,string _rut);
    string getNombre();
    string getRut();
    void setNombre(string _nombre);
    void setRut(string _rut);
    ~cliente();
};