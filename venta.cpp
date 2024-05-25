#include "venta.h"
#include "producto.h"
#include "cliente.h"
#include <string>
#include <cstdlib>
using namespace std;

venta::venta(cliente* _comprador):comprador(_comprador){
    this->id=rand()% 1000+1;
}
int venta::getId(){
    return id;
}
int venta::getTotal(){
    int total=0;
    queue<producto> copia=compras;
    while(!copia.empty()){
        total+=copia.front().getPrecio();
        copia.pop();
    }
    return total;
}
void venta::insertarProducto(producto& p){
    compras.push(p);
}
void venta::eliminarProducto(string codigo){
    queue<producto>copia;
    while(!copia.empty()){
        producto actual=compras.front();
        compras.pop();
        if(actual.getCodigo()==codigo){
            
        }else{
            copia.push(actual);
        }
    }
    compras=copia;
}
void venta::generarBoleta(){
    queue<producto> copia=compras;
    cout<<"Boleta:"<<id<<endl;
    cout<<"Cliente:"<<comprador.getNombre()<<" Rut:"<<comprador.getRut()<<endl;
    while (!copia.empty()){
        producto actual=copia.front();
        cout<<actual.getNombre()<<" $"<<actual.getPrecio()<<endl;
        copia.pop();
    }
    cout<<"Total: "<<getTotal()<<endl;
}
venta::~venta(){}