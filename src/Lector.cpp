#include "Lector.h"


using namespace std;

Lector::Lector() {}

Item* Lector::crear_item_desde_linea(const std::string &linea) {
    istringstream separar_linea(linea);
    string nombre, tipo;
    getline(separar_linea, nombre, ',');
    getline(separar_linea, tipo, ',');
    return new Item(nombre, tipo);
}

void Lector::leer_archivo(Lista_de<Item *> &inventario, std::string nombre_archivo) {
    ifstream archivo(nombre_archivo);
    string linea;
    string nombre;
    string tipo;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    } else {
        while (getline(archivo, linea)) {
            Item* item = crear_item_desde_linea(linea);
            if (item){
                inventario.alta(item);
            }
        }
        archivo.close();
    }
}

void Lector::escribir_archivo(Lista_de<Item*>&inventario, std::string nombre_archivo) {
    std::ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return;
    }
    for (size_t i = 0; i < inventario.tamanio(); i++) {
        Item* item = inventario.elemento(i);
        archivo << *item << endl;
    }
    archivo.close();
}





