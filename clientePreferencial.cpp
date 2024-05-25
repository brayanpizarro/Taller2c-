#include "clientePreferencial.h"
#include <string>
using namespace std;

clientePreferecial::clientePreferecial(string _nombre,string _rut,int _edad,bool _embarazo,bool _discapacidad):cliente(_nombre,_rut){
this->edad=_edad;
this->embarazo=_embarazo;
this->discapacidad=_discapacidad;
}
int clientePreferecial::getEdad(){
    return edad;
}
bool clientePreferecial::getEmbarazo(){
    return embarazo;
}
bool clientePreferecial::getDiscapacidad(){
    return discapacidad;
}
void clientePreferecial::setEdad(int _edad){
    this->edad=_edad;
}
void clientePreferecial::setEmbarazo(bool _embarazo){
    this->embarazo=_embarazo;
}
void clientePreferecial::setDiscapacidad(bool _discapacidad){
    this->discapacidad=_discapacidad;
}
clientePreferecial::~clientePreferecial(){}
