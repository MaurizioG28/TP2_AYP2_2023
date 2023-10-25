
#ifndef VECTOR_TESTS_LECTOR_H
#define VECTOR_TESTS_LECTOR_H
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ostream>
#include <iostream>
#include "Item.hpp"
#include "Lista_de.hpp"

class Lector {
private:
    const int CANT_PARAMETROS = 2;
    const int NOMBRE = 0;
    const int TIPO = 1;

    //Pre:Recibe una referencia una a linea.
    //Post: Devuelve un puntero a item con la informacion de la linea.
    Item *crear_item_desde_linea(const std::string& linea);

public:
    //Constructor vacio.
    Lector();

    // Pre: Recibe una referencia a una lista de punteros a item de la clase inventario y la ruta del archivo para leer.
    // Post: Lee la informacion que se encuentra en la ruta pasada y la guarda en el vector.
    void leer_archivo(Lista_de<Item*>& inventario, std::string nombre_archivo);

    // Pre: Recibe una referencia a una lista de punteros a item de la clase inventario y la ruta del archivo para leer.
    // Post: Escribe la informacion del inventario en el archivo csv.
    void escribir_archivo(Lista_de<Item*>& inventario, std::string nombre_archivo);
};

#endif
