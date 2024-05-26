#include "Cliente.h"
using namespace std;
Cliente::Cliente(int codigo,string& nombre,string& tipo)
    : codigo(codigo), nombre(nombre), tipo(tipo) {}

int Cliente::getCodigo() {
    return codigo;
}

string Cliente::getNombre() {
    return nombre;
}

string Cliente::getTipo() {
    return tipo;
}
void Cliente::setCodigo(int codigo) {
    this -> codigo = codigo;
}