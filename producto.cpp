#include "producto.h"
#include <string>

using namespace std;

producto::producto(string _nombre,string _codigo,int _precio,string _categoria,string _subCategoria){
    this->nombre=_nombre;
    this->codigo=_codigo;
    this->precio=_precio;
    this->categoria=_categoria;
    this->subCategoria=_subCategoria;
}
string producto::getNombre(){
    return nombre;
}
string producto::getCodigo(){
    return codigo;
}
int producto::getPrecio(){
    return precio;
}
string producto::getCategoria(){
    return categoria;
}
string producto::getSubCategoria(){
    return subCategoria;
}
void producto::setNombre(string _nombre){
    this->nombre=_nombre;
}
void producto::setCodigo(string _codigo){
    this->codigo=_codigo;
}
void producto::setCategoria(string _categoria){
    this->categoria=_categoria;
}
void producto::setSubCategoria(string _subCategoria){
    this->subCategoria=_subCategoria;
}
producto::~producto(){}