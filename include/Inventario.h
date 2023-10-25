#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include "Lector.h"
#include "Lista_de.hpp"
#include "Interacciones.h"

class Inventario {
private:
    const size_t CANTIDAD_MAXIMA = 15;
    Lista_de<Item*> inventario;
    const size_t NO_ENCONTRADO = 16;

    //Pre: Recibe un string con el nombre del item.
    //Post: Devuelve el indice donde se encuentra el inventario.Caso contrario devuelve 16.
    size_t buscar_item(std::string nombre);

public:
    //Contructor.
    Inventario();

    //Pre: -
    //Post: Devuelve TRUE en caso de que el inventario este lleno, caso contrario devuelve FALSE.
    bool inventario_lleno();

    //Pre:-
    //Post: Agrega el item al inventario,en caso de haber espacio.
    void agregar_item();

    //Pre:-
    //Post: Elimina la primera aparicion del item dentro del inventario.
    void eliminar_item();

    //Pre:-
    //Post: Muestra los items guardados en el inventario.
    void consultar_inventario();

    //Pre:-
    //Post: Guarda el inventario en un savefile.
    void guardar_inventario(std::string rutaArchivo);

    //Pre:Recibe la ruta donde se encuentra el archivo savefile.csv.
    //Post:Carga el inventario guardado en el archivo savefile.csv.
    void cargar_inventario_desde_archivo(std::string ruta_archivo);

    //Destructor.
    ~Inventario();
};

#endif
