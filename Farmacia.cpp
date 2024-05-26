#include "Farmacia.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
void Farmacia::agregarProducto( Producto& producto){
    productos[producto.getCategoria()].push_back(producto);
}


void Farmacia::eliminarProducto(int codigo) {
    for (auto& categoria : productos) {
        auto& listaProductos = categoria.second;
        listaProductos.erase(
            remove_if(listaProductos.begin(), listaProductos.end(),
                           [codigo]( Producto& producto) { return producto.getCodigo() == codigo; }),
            listaProductos.end());
    }
}
Producto Farmacia::buscarProducto(int codigo){
    for (auto& categoria : productos) {
        auto& listaProductos = categoria.second;
        for (Producto producto: listaProductos){
            if(producto.getCodigo()==codigo){
                return producto;
            }
        }
    }
    throw runtime_error("Producto no encontrado");
}
void Farmacia::agregarCliente( Cliente& cliente) {
    clientes.push(cliente);
}

Cliente Farmacia::atenderCliente() {
    if (!clientes.empty()) {
        Cliente cliente = clientes.front();
        clientes.pop();
        return cliente;
    }
    throw runtime_error("No hay clientes en la fila.");
}

Boleta Farmacia::generarBoleta( Cliente& cliente,  vector<Producto>& productos) {
    int codigo = boletas.size() + 1;
    Boleta boleta(codigo, cliente, productos);
    boletas.push_back(boleta);
    return boleta;
}


void Farmacia::mostrarProductos(){
    for ( auto& categoria : productos) {
        cout << "Categoria: " << categoria.first << endl;
        for ( auto& producto : categoria.second) {
            cout << "Codigo: " << producto.getCodigo() << ", Nombre: " << producto.getNombre() 
                      << ", SubCategoria: " << producto.getSubCategoria() << ", Precio: " << producto.getPrecio() 
                      << ", Stock: " << producto.getStock() << endl;
        }
        cout << endl;
    }
}

void Farmacia::guardarDatos() {
    // Guardar productos
    ofstream productosFile("productos.txt");
    for ( auto& categoria : productos) {
        for ( auto& producto : categoria.second) {
            productosFile << producto.getCodigo() << "," << producto.getNombre() << "," << producto.getCategoria() << ","
                          << producto.getSubCategoria() << "," << producto.getPrecio() << "," << producto.getStock() << endl;
        }
    }
    productosFile.close();

// Guardar clientes
    ofstream clientesFile("clientes.txt");
    queue<Cliente> tempClientes = clientes;
    while (!tempClientes.empty()) {
        Cliente cliente = tempClientes.front();
        tempClientes.pop();
        clientesFile << cliente.getCodigo() << "," << cliente.getNombre() << "," << cliente.getTipo() << endl;
    }
    clientesFile.close();

 ofstream boletasFile("boletas.txt");
    for ( auto& boleta : boletas) {
        boletasFile << boleta.getCodigo() << "," << boleta.getCliente().getCodigo() << "," << boleta.getTotal() << endl;
        for ( auto& producto : boleta.getProductos()) {
            boletasFile << producto.getCodigo() << ",";
        }
        boletasFile << endl;
    }
    boletasFile.close();
}

void Farmacia::cargarDatos() {
    // Cargar productos
    ifstream productosFile("productos.txt");
    string linea;
    while (getline(productosFile, linea)) {
        istringstream ss(linea);
        string codigo, nombre, categoria, subCategoria, precio, stock;
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, categoria, ',');
        getline(ss, subCategoria, ',');
        getline(ss, precio, ',');
        getline(ss, stock, ',');
        Producto producto(stoi(codigo), nombre, categoria, subCategoria, stof(precio), stoi(stock));
        agregarProducto(producto);
    }
    productosFile.close();
    
}