#include "cliente.h"
#include <string>
using namespace std;

cliente::cliente(string _nombre,string _rut,bool _embarazo,bool _discapacidad){
    this->nombre=_nombre;
    this->rut=_rut;
    this->embarazo=_embarazo;
    this->discapacidad=_discapacidad;
}
string cliente::getNombre(){
    return nombre;
}
string cliente::getRut(){
    return rut;
}
bool cliente::getEmbarazo(){
    return embarazo;
}
bool cliente::getDiscapacidad(){
    return discapacidad;
}
void cliente::setNombre(string _nombre){
    this->nombre=_nombre;
}
void cliente::setRut(string _rut){
    this->rut=_rut;
}
void cliente::setEmbarazo(bool _embarazo){
    this->embarazo=_embarazo;
}
void cliente::setDiscapacidad(bool _discapacidad){
    this->discapacidad=_discapacidad;
}
cliente::~cliente(){}
