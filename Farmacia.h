#pragma once
#include <vector>
#include <queue>
#include <unordered_map>
#include "Producto.h"
#include "Cliente.h"
#include "Boleta.h"

using namespace std;
class Farmacia{
    private:
        unordered_map<string, vector<Producto>> productos;
        queue<Cliente> clientes;
        vector<Boleta> boletas;
    
    public:
        void agregarProducto(Producto& producto);
        void eliminarProducto(int codigo);
        Producto buscarProducto(int codigo);
        void agregarCliente(Cliente& cliente);
        Cliente atenderCliente();
        void eliminarStock(vector<Producto>& listaCompra);
        Boleta generarBoleta(Cliente& cliente,vector<Producto>& productos);
        void guardarDatos();
        void cargarDatos();
        void mostrarProductos();
};        
        
