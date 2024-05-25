#include "cliente.h"
#include <string>
using namespace std;

cliente::cliente(string _nombre,string _rut){
    this->nombre=_nombre;
    this->rut=_rut;
}
string cliente::getNombre(){
    return nombre;
}
string cliente::getRut(){
    return rut;
}
void cliente::setNombre(string _nombre){
    this->nombre=_nombre;
}
void cliente::setRut(string _rut){
    this->rut=_rut;
}
cliente::~cliente(){}
