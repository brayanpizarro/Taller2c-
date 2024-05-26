#pragma once
#include <vector>
#include "Cliente.h"
#include "Producto.h"
using namespace std;
class Boleta{
    private:
        int codigo;
        Cliente cliente;
        vector<Producto> productos;
        float total;
        
    public:
    Boleta(int codigo,Cliente& cliente,vector<Producto>& productos);
    
    int getCodigo();
    Cliente getCliente();
    std::vector<Producto> getProductos();
    float getTotal();
    float calcularTotal();
};