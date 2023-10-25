#ifndef VECTOR_TESTS_INTERACCIONES_H
#define VECTOR_TESTS_INTERACCIONES_H

#include <iostream>
#include <string>
#include "Inventario.h"
#include "Destino.h"

class Interacciones {
private:
    //Pre: Recibe un string con el tipo de item ingresado.
    //Post: Devuelve true si es un tipo de item valido,caso contrario devuelve false.
    bool es_tipo_de_item_valido(std::string tipo);

    //Pre: Recibe un string con el tipo de evento ingresado.
    //Post: Devuelve true si es un tipo de evento valido,caso contrario devuelve false.
    bool es_tipo_de_evento_valido(std::string tipo);

public:
    //Contructor.
    Interacciones();

    //Pre:-
    //Post: Consulta al usuario que item, y tipo de item valido de item quiere agregar al inventario.
    void consultar_item_para_agregar(std::string& nombre,std::string& tipo);

    //Pre:-
    //Post: Consulta al usuario el nombre del item que desea borrar del inventario.
    void consultar_item_para_borrar(std::string& nombre);

    //Pre:-
    //Post: Consulta al usuario que evento va agregar al destino y devuelve un evento valido.
    Evento consultar_evento_para_agregar();


};

#endif
