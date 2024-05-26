#include "Producto.h"
using namespace std;
Producto::Producto(int codigo,string& nombre,string& categoria,string& subCategoria, float precio, int stock)
    : codigo(codigo), nombre(nombre), categoria(categoria), subCategoria(subCategoria), precio(precio), stock(stock) {}

int Producto::getCodigo(){
    return codigo;
}

string Producto::getNombre(){
    return nombre;
}

string Producto::getCategoria()  {
    return categoria;
}

string Producto::getSubCategoria()  {
    return subCategoria;
}

float Producto::getPrecio()  {
    return precio;
}

int Producto::getStock()  {
    return stock;
}

void Producto::setStock(int newStock) {
    stock = newStock;
}
