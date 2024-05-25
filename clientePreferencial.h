#pragma once
#include "cliente.h"
#include <iostream>
#include <string>
using namespace std;
class clientePreferecial:public cliente{
    private:
    int edad;
    bool embarazo;
    bool discapacidad;
    public:
    clientePreferecial(string nombre,string rut,int edad,bool embarazo,bool discapacidad);
    int getEdad();
    bool getEmbarazo();
    bool getDiscapacidad();
    void setEdad(int edad);
    void setEmbarazo(bool embarazo);
    void setDiscapacidad(bool discapacidad);
    ~clientePreferecial();
};