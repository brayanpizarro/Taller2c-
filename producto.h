#pragma once
#include <iostream>
#include <string>
using namespace std;
class producto{
    private:
    string nombre;
    string codigo;
    int precio;
    string categoria;
    string subCategoria;
    public:
    producto(string nombre,string codigo,int precio,string categoria,string subCategoria);
    string getNombre();
    string getCodigo();
    int getPrecio();
    string getCategoria();
    string getSubCategoria();
    void setNombre(string _nombre);
    void setCodigo(string _codigo);
    void setPrecio(int precio);
    void setCategoria(string _categoria);
    void setSubCategoria(string _subCategoria);
    ~producto();
};