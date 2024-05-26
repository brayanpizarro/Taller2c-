#include "Boleta.h"

Boleta::Boleta(int codigo,Cliente& cliente,vector<Producto>& productos)
    : codigo(codigo), cliente(cliente), productos(productos) {
    total = calcularTotal();
}

int Boleta::getCodigo(){
    return codigo;
}

Cliente Boleta::getCliente(){
    return cliente;
}

std::vector<Producto> Boleta::getProductos(){
    return productos;
}

float Boleta::getTotal(){
    return total;
}

float Boleta::calcularTotal() {
    float suma = 0;
    for (auto& producto : productos) {
        suma += producto.getPrecio();
    }
    return suma;
}