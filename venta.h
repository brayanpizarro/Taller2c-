#pragma once
#include <iostream>
#include <string>
#include "producto.h"
#include "cliente.h"
#include <queue>

class venta{
    private:
    int id;
    cliente* comprador;
    queue<producto> compras;
    public:
    venta(cliente* _comprador);
    int getId();
    int getTotal();
    void insertarProducto(producto& p);
    void eliminarProducto(string codigo);
    void generarBoleta();
    ~venta();

};