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
        cout << "No se pueden agregar más productos.\n";
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