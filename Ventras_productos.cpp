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
        cout << i + 1 << ". " << productos[i].nombre << " | Precio: s/" << productos[i].precio << endl;
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
            cout << "Producto encontrado: " << productos[i].nombre << " | Precio: s/" << productos[i].precio << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado.\n";
    }
}
void actualizarProducto() {
    cin.ignore();
    string nombre;
    cout << "Nombre del producto a actualizar: ";
    getline(cin, nombre);
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            cout << "Nuevo nombre: ";
            getline(cin, productos[i].nombre);
            cout << "Nuevo precio: ";
            cin >> productos[i].precio;
            cout << "Producto actualizado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void eliminarProducto() {
    cin.ignore();
    string nombre;
    cout << "Nombre del producto a eliminar: ";
    getline(cin, nombre);
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            for (int j = i; j < numProductos - 1; j++) {
                productos[j] = productos[j + 1];
            }
            numProductos--;
            cout << "Producto eliminado.\n";
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void registrarVenta() {
    cin.ignore();
    string nombre;
    cout << "Nombre del producto vendido: ";
    getline(cin, nombre);

    int cantidad;
    cout << "Cantidad vendida: ";
    cin >> cantidad;

    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombre) {
            float total = cantidad * productos[i].precio;
            ventas[numVentas] = {contadorVentas++, nombre, cantidad, total};
            numVentas++;
            cout << "Venta registrada. Total: s/" << total << endl;
            return;
        }
    }
    cout << "Producto no encontrado.\n";
}

void listarVentas() {
    if (numVentas == 0) {
        cout << "No hay ventas registradas.\n";
        return;
    }

    cout << "\nVENTAS REALIZADAS:\n";
    for (int i = 0; i < numVentas; i++) {
        cout << "ID " << ventas[i].idVenta << " | "
             << ventas[i].producto << " | Cantidad: "
             << ventas[i].cantidad << " | Total: s/"
             << ventas[i].precioTotal << endl;
    }
}

void totalVentas() {
    float total = 0;
    for (int i = 0; i < numVentas; i++) {
        total += ventas[i].precioTotal;
    }
    cout << "Total de ventas realizadas: s/" << total << endl;
}

void mostrarMenu() {
    cout << "\n=== INVENTARIO DE PRODUCTOS Y VENTAS ===\n";
    cout << "A. Registrar nuevo producto\n";
    cout << "B. Listar productos\n";
    cout << "C. Buscar producto\n";
    cout << "D. Actualizar producto\n";
    cout << "E. Eliminar producto\n";
    cout << "F. Registrar venta\n";
    cout << "G. Listar ventas\n";
    cout << "H. Total de ventas\n";
    cout << "S. Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    char opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        opcion = toupper(opcion);

        switch (opcion) {
            case 'A': registrarProducto(); break;
            case 'B': listarProductos(); break;
            case 'C': buscarProducto(); break;
            case 'D': actualizarProducto(); break;
            case 'E': eliminarProducto(); break;
            case 'F': registrarVenta(); break;
            case 'G': listarVentas(); break;
            case 'H': totalVentas(); break;
            case 'S': cout << "Saliendo del programa...\n"; break;
            default: cout << "Opcion invalida.\n"; break;
        }

    } while (opcion != 'S');

    return 0;
}