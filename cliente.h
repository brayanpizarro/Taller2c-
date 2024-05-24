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
    cliente(string _nombre,string _rut,bool _embarazo,bool _discapacidad);
    string getNombre();
    string getRut();
    bool getEmbarazo();
    bool getDiscapacidad();
    void setNombre(string _nombre);
    void setRut(string _rut);
    void setEmbarazo(bool _embarazo);
    void setDiscapacidad(bool _discapacidad);
    ~cliente();
};