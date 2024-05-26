#pragma once
#include <string>
using namespace std;
class Producto {
private:
    int codigo;
    string nombre;
    string categoria;
    string subCategoria;
    float precio;
    int stock;

public:
    Producto(int codig,string& nombre,string& categoria,string& subCategoria, float precio, int stock);

    int getCodigo() ;
    string getNombre() ;
    string getCategoria() ;
    string getSubCategoria() ;
    float getPrecio() ;
    int getStock() ;
    void setStock(int newStock);
};