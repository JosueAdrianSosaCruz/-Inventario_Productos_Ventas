#include<iostream>
#include<string>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;
};

const int MaxiProductos = 100;
const int MaxiVentas = 100;

Producto productos[MaxiProductos];
int numProductos = 0;

Venta ventas[MaxiVentas];
int numVentas = 0;
int contadorVentas = 1;

void registrarProducto() {
    if (numProductos >= MaxiProductos) {
        cout << "No se pueden agregar mas productos.\n";
        return;
    }
    cin.ignore();
    cout << "Nombre del producto: ";
    getline(cin, productos[numProductos].nombre);
    cout << "Precio del producto: ";
    cin >> productos[numProductos].precio;
    numProductos++;
    cout << "Producto registrado.\n";
}

void listarProductos() {
    if (numProductos == 0) {
        cout << "No hay productos registrados.\n";
        return;
    }
    cout << "\nLISTADO DE PRODUCTOS:\n";
    for (int i = 0; i < numProductos; i++) {
        cout << i + 1 << ". " << productos[i].nombre << " | Precio: $" << productos[i].precio << endl;
    }
}

void buscarProducto() {
    cin.ignore();
    string nombre;
    cout << "Nombre del producto a buscar: ";
    getline(cin, nombre);
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            cout << "Producto encontrado: " << productos[i].nombre << " | Precio: $" << productos[i].precio << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}