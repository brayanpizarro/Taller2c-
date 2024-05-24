#include "producto.h"
#include <string>

using namespace std;

producto::producto(string _nombre,string _codigo){
    this->nombre=_nombre;
    this->codigo=_codigo;
}
string producto::getNombre(){
    return nombre;
}
string producto::getCodigo(){
    return codigo;
}
void producto::setNombre(string _nombre){
    this->nombre=_nombre;
}
void producto::setCodigo(string _codigo){
    this->codigo=_codigo;
}
producto::~producto(){}