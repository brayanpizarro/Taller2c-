#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Farmacia.h"
#include "Cliente.h"
#include "ClientePreferencial.h"
#include "Producto.h"

#include <cstdlib> // Para rand() y srand()
#include <ctime>   // Para time()

using namespace std;
//Farmacia

int readFile(Farmacia& farmacia);
int addProduct(Farmacia& farmacia);
int addClient(Farmacia& farmacia, int num);
int attendClient(Farmacia& farmacia);


int main() {
    cout << "-- BIENVENIDO --"<< endl;
    srand(static_cast<unsigned>(time(0)));
    
    // Crear el sistema de farmacia
    cout << "Iniciando sistema de farmacia" << endl;
    Farmacia farmacia;
    
    // Cargar productos en la bodega
        if(readFile(farmacia) != 0){
            cerr << "Error no se pueden cargar los productos" << endl;
            return 1;
        }
        cout << "Productos Cargados exitosamente" << endl;
        
    
    cout << "Opciones de menu :" << endl;
    
    int opcion=0;
    int num=0;
    while (opcion!=4){
        cout << "1. Agregar más productos a bodega." << endl;
        cout << "2. Agregar cliente." << endl;
        cout << "3. Atender cliente." << endl;
        cout << "4. Salir." << endl;
        
        cin >> opcion;
        
        // Agregar más productos de bodega    
        if(opcion==1){
            addProduct(farmacia);
        }
        // Agregar clientes
        if (opcion==2){
            addClient(farmacia, num);
        }
        //atender a cliente
        if (opcion==3){
            attendClient(farmacia);//continear con la venta 
        }
        //Salida y guardado de datos
        if (opcion==4){
            farmacia.guardarDatos();
            cout << "Datos guardados exitosamente" << endl;
        }
    
    }
      
    return 0;
    
}

int attendClient(Farmacia& farmacia){
    bool compra=true;
    while (compra) {
        vector<Producto> listaProductos;
        try {
            Cliente cliente = farmacia.atenderCliente();
            cout << "Atendiendo al cliente: " << cliente.getNombre() << endl;

            farmacia.mostrarProductos();
            int codigo;
            cout<<"Elija el codigo del producto que desea agregar si termino -1"<<endl;
            cin>>codigo;
            while(codigo!=-1){
                Producto p=farmacia.buscarProducto(codigo);
                listaProductos.push_back(p);
                cout<<"Elija el codigo del producto que desea agregar si termino -1"<<endl;
                cin>>codigo;
            }
            Boleta boleta = farmacia.generarBoleta(cliente, listaProductos);
            cout << "Boleta generada para el cliente " << cliente.getNombre() << " con total: " << boleta.getTotal() << endl;
            compra=false;

        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            break;
        }
    }
    return 0;
}

int addClient(Farmacia& farmacia, int num){
    string tipo;
    //se prodria sacar el nombre
    string nombre;
    int opcion;
    
        cout << "-- Eliga tipo de cliente --" << endl;
        
        cout << "1. Cliente normal" << endl;
        cout << "2. Cliente preferencial" << endl;
        cin >> opcion;
        
        if(opcion==1){
            num++;
            tipo="Normal";
            cout << "Ingrese Nombre" << endl;
            cin >> nombre;
            Cliente cliente(num, nombre, tipo);
            farmacia.agregarCliente(cliente);
        }
        if(opcion ==2){
            int option2=0;
            cout << "--Tipo de prefercia--" << endl;
            cout << "1. Tercera edad" << endl;
            cout << "2. Discapacidad" << endl;
            cout << "3. Embarazada" << endl;
            cin >> option2;
            
            if(option2==1){
                num++;
                tipo="Tercera edad";
                cout << "Ingrese Nombre" << endl;
                cin >> nombre;
                Cliente cliente(num, nombre, tipo);
                farmacia.agregarCliente(cliente);
            }
            if(option2==2){
                num++;
                tipo="Discapacidad";
                cout << "Ingrese Nombre" << endl;
                cin >> nombre;
                Cliente cliente(num, nombre, tipo);
                farmacia.agregarCliente(cliente);
            }
            if(option2==3){
                num++;
                tipo="Embarazada";
                cout << "Ingrese Nombre" << endl;
                cin >> nombre;
                Cliente cliente(num, nombre, tipo);
                farmacia.agregarCliente(cliente);
            }

        }
        cout << "--Cliente ingresado--" << endl;
        cout << " " << endl;
        return 0;
    
}

int addProduct(Farmacia& farmacia){
    int codigo;
    std::string nombre;
    std::string categoria;
    std::string subCategoria;
    float precio;
    int stock;
    
        cout << "Codigo del producto" << endl;
        //buscar que el codigo no este repetido
        cin >> codigo;
        cout << "Nombre del producto" << endl;
        cin >> nombre;
        cout << "Categoria del producto" << endl;
        cin >> categoria;
        cout << "SubCategoria del producto" << endl;
        cin >> subCategoria;
        cout << "Precio del producto" << endl;
        cin >> precio;
        cout << "Stock del producto" << endl;
        cin >> stock;
        
        Producto producto(codigo, nombre, categoria, subCategoria, precio, stock);
        farmacia.agregarProducto(producto);
        
    cout << "-- Producto agregado --" << endl;
    cout << " " << endl;
       
    return 0;    
}

int readFile(Farmacia& farmacia) {
    ifstream myfile("Bodega.txt");
    if (!myfile.is_open()) {
        cerr << "Error: El archivo no se puede abrir" << endl;
        return 1;
    }

    string linea;
    while (getline(myfile, linea)) {
        istringstream ss(linea);
        string codigo, nombre, categoria, subCategoria, precio, stock;
        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, categoria, ',');
        getline(ss, subCategoria, ',');
        getline(ss, precio, ',');
        getline(ss, stock, ',');
        
        Producto producto(stoi(codigo), nombre, categoria, subCategoria, stof(precio), stoi(stock));
        farmacia.agregarProducto(producto);
    }

    myfile.close();
    return 0;
}