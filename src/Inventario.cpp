#include "Inventario.h"



using namespace std;

Inventario::Inventario() = default;

void Inventario::consultar_inventario() {
    cout << "--------------------------" << endl;
    cout << " || INVENTARIO || " << endl;
    for (size_t i = 0; i < inventario.tamanio(); i++) {
        Item* item = inventario.elemento(i);
        item->listar_informacion();
        cout << endl;
    }
    cout << "ESTADO DEL INVENTARIO:" << inventario.tamanio() << "/" << this->CANTIDAD_MAXIMA << "." << endl;
    cout << "--------------------------" << endl;
}

bool Inventario::inventario_lleno() {
    return (inventario.tamanio() < CANTIDAD_MAXIMA);
}

size_t Inventario::buscar_item(string nombre) {
    for (size_t i = 0; i < inventario.tamanio(); i++) {
        if (inventario.elemento(i)->operator==(nombre)) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

void Inventario::agregar_item() {
    if (inventario_lleno()) {
        string nombre;
        string tipo;
        Interacciones interacciones;
        interacciones.consultar_item_para_agregar(nombre,tipo);
        Item* nuevo_item = new Item(nombre,tipo);
        inventario.alta(nuevo_item);
    } else {
        cout << "El inventario esta lleno. No se puede agregar mas items." << endl;
    }
}

void Inventario::eliminar_item() {
    string nombre_item;
    Interacciones interacciones;
    interacciones.consultar_item_para_borrar(nombre_item);
    size_t posicion = buscar_item(nombre_item);
    if (this->inventario.tamanio() > 0) {
        if (posicion != NO_ENCONTRADO) {
            Item* item_a_eliminar;
            item_a_eliminar = inventario.baja(posicion);
            delete item_a_eliminar;
        } else {
            cout << "Error de inventario.No se encontro el item." << endl;
        }
    } else {
        cout << "Error de inventario.El inventario esta vacio." << endl;
    }
}

void Inventario::guardar_inventario(std::string ruta_archivo) {
    Lector lector;
    lector.escribir_archivo(this->inventario, ruta_archivo);
}

void Inventario::cargar_inventario_desde_archivo(string ruta_archivo){
    Lector lector;
    lector.leer_archivo(this->inventario, ruta_archivo);
}

Inventario::~Inventario() {
    for (size_t i = 0; i < this->inventario.tamanio(); i++) {
        delete inventario.elemento(i);
    }
}




