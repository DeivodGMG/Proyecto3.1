#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct GestorInventario {
    string object;
};

vector<GestorInventario> inventario;

int main() {
    int opcion;
    do {
        cout << "---------------------------------" << endl;
        cout << "** Gestion de un inventario personal **" << endl;
        cout << "1. Agregar un articulo" << endl;
        cout << "2. Mostrar inventario" << endl;
        cout << "3. Buscar articulo" << endl;
        cout << "4. Actualizar un articulo" << endl;
        cout << "5. Eliminar un articulo" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para ignorar el salto de línea después de la opción

        switch (opcion) {
        case 1: {
            cout << "---------------------------------" << endl;
            cout << "** Agregar un item **" << endl;
            cout << "Ingrese el nombre del objeto: ";
            string nombre;
            getline(cin, nombre);
            inventario.push_back({nombre});
            break;
        }
        case 2: {
            cout << "---------------------------------" << endl;
            cout << "** Mostrar inventario **" << endl;
            for (size_t i = 0; i < inventario.size(); i++) {
                cout << i + 1 << ". " << inventario[i].object << endl;
            }
            break;
        }
        case 3: {
            cout << "---------------------------------" << endl;
            cout << "** Buscar articulo **" << endl;
            cout << "Ingrese el nombre del articulo: ";
            string buscar;
            getline(cin, buscar);
            bool encontrado = false;
            for (size_t i = 0; i < inventario.size(); i++) {
                if (inventario[i].object == buscar) {
                    cout << "El articulo " << inventario[i].object << " se encuentra en la posicion " << i + 1 << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Articulo no encontrado." << endl;
            }
            break;
        }
        case 4: {
            cout << "---------------------------------" << endl;
            cout << "** Actualizar objeto **" << endl;
            cout << "Ingrese el nombre del objeto: ";
            string actualizar;
            getline(cin, actualizar);
            bool encontrado = false;
            for (size_t i = 0; i < inventario.size(); i++) {
                if (inventario[i].object == actualizar) {
                    cout << "Ingrese el nuevo nombre del objeto: ";
                    string nuevoNombre;
                    getline(cin, nuevoNombre);
                    inventario[i].object = nuevoNombre;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Articulo no encontrado." << endl;
            }
            break;
        }
        case 5: {
            cout << "---------------------------------" << endl;
            cout << "** Eliminar un item **" << endl;
            cout << "Ingrese el nombre del objeto: ";
            string eliminar;
            getline(cin, eliminar);
            bool encontrado = false;
            for (size_t i = 0; i < inventario.size(); i++) {
                if (inventario[i].object == eliminar) {
                    inventario.erase(inventario.begin() + i);
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "Articulo no encontrado." << endl;
            }
            break;
        }
        case 6:
        cout << "---------------------------------" << endl;
            cout << "Salir" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 6);
    cout << "Gracias por usar el sistema de gestion de inventario :v" << endl;
    return 0;
}