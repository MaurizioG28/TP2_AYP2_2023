#ifndef LISTA_DE_HPP
#define LISTA_DE_HPP

#include <exception>
#include <cstdlib>
#include "Nodo_de.hpp"

class Lista_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la lista.
    // Usar de la forma "throw lista_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw Lista_exception();
    //     }
};

template<typename T>
class Lista_de {
private:
    Nodo_de<T>* primer_nodo;
    Nodo_de<T>* ultimo_nodo;
    Nodo_de<T>* cursor;
    // Nota: pueden no utilizar el índice. Estado inicial / no válido = -1.
    // La lista es 0-indexed.
    int indice_cursor;
    size_t cantidad_datos;

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve un puntero al nodo asociado al índice deseado.
    Nodo_de<T>* obtener_nodo(size_t indice);

public:
    // Constructor.
    Lista_de();

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta(T dato);

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(T dato, size_t indice);

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos - 1, simplemente elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja(size_t indice);

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el primer dato en la lista.
    T primero();

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el último dato en la lista.
    T ultimo();

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve el dato en la posición deseada.
    T elemento(size_t indice);

    // Pre: -
    // Post: Devuelve true si se puede avanzar (esto es, que el cursor no sea nullptr).
    bool puede_avanzar();

    // Pre: Se debe poder avanzar.
    // Post: Devuelve el dato del cursor actual y luego lo mueve una posición en la dirección deseada.
    T avanzar(bool siguiente);

    // Pre: -
    // Post: Reinicia el cursor al principio o al final, según lo indicado.
    // Si la lista está vacía, se reinicia el cursor al estado inicial
    // (esto es, cursor = nullptr e indice_cursor = -1).
    void reiniciar_cursor(bool principio);

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Lista_de(const Lista_de& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista_de& l) = delete;

    // Destructor.
    ~Lista_de();
};

template <typename T>
Lista_de<T>::Lista_de():primer_nodo(nullptr),ultimo_nodo(nullptr),
                        cursor(nullptr), indice_cursor(-1),cantidad_datos(0) {}

template <typename T>
void Lista_de<T>::alta(T dato){
    Nodo_de<T>* nuevo_nodo = new Nodo_de<T>(dato, ultimo_nodo, nullptr);
    if (vacio()) {
        primer_nodo = nuevo_nodo;
        cursor = nuevo_nodo;
        indice_cursor = 0;
    } else {
        ultimo_nodo->cambiar_siguiente(nuevo_nodo);
        nuevo_nodo->cambiar_anterior(ultimo_nodo);
    }
    ultimo_nodo = nuevo_nodo;
    cantidad_datos++;
}


template<typename T>
T Lista_de<T>::baja() {
    if (vacio()){
        throw Lista_exception();
    }
    if(cursor == ultimo_nodo){
        cursor = nullptr;
    }
    T dato = ultimo_nodo->obtener_dato();
    Nodo_de<T>* nodo_a_eliminar = ultimo_nodo;
    if (cantidad_datos == 1){
        primer_nodo = nullptr;
        ultimo_nodo = nullptr;
    } else {
        ultimo_nodo = nodo_a_eliminar->obtener_anterior();
        ultimo_nodo->cambiar_siguiente(nullptr);
    }
    if (size_t(indice_cursor) == cantidad_datos - 1) {
        indice_cursor = -1;
    }
    cantidad_datos--;
    delete nodo_a_eliminar;
    return dato;
}

template <typename T>
void Lista_de<T>::alta(T dato, size_t indice){
    if (indice > cantidad_datos || indice < 0) {
        throw Lista_exception();
    }
    Nodo_de<T>* nuevo_nodo = new Nodo_de<T>(dato, nullptr, nullptr);
    if (vacio()) {
        primer_nodo = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
        cursor = nuevo_nodo;
        indice_cursor = 0;
    } else {
        if (indice == 0) {
            nuevo_nodo->cambiar_siguiente(primer_nodo);
            primer_nodo->cambiar_anterior(nuevo_nodo);
            primer_nodo = nuevo_nodo;
            indice_cursor++;
        } else if (indice == cantidad_datos) {
            ultimo_nodo->cambiar_siguiente(nuevo_nodo);
            nuevo_nodo->cambiar_anterior(ultimo_nodo);
            ultimo_nodo = nuevo_nodo;
        } else {
            Nodo_de<T>* nodo_anterior = obtener_nodo(indice - 1);
            Nodo_de<T>* nodo_siguiente = nodo_anterior->obtener_siguiente();
            nuevo_nodo->cambiar_anterior(nodo_anterior);
            nuevo_nodo->cambiar_siguiente(nodo_siguiente);
            nodo_anterior->cambiar_siguiente(nuevo_nodo);
            nodo_siguiente->cambiar_anterior(nuevo_nodo);
        }
    }
    cantidad_datos++;
}


template<typename T>
T Lista_de<T>::baja(size_t indice) {
    if (cantidad_datos == 0 || indice < 0 || indice >= cantidad_datos) {
        throw Lista_exception();
    }
    T dato_eliminado;
    Nodo_de<T>* nodo_a_eliminar;
    if (indice == 0) {
        nodo_a_eliminar = primer_nodo;
        dato_eliminado = nodo_a_eliminar->obtener_dato();
        primer_nodo = nodo_a_eliminar->obtener_siguiente();
        if (cursor == nodo_a_eliminar) {
            cursor = cursor->obtener_siguiente();
            indice_cursor ++;
        }
    } else if (indice == cantidad_datos - 1) {
        nodo_a_eliminar = ultimo_nodo;
        dato_eliminado = nodo_a_eliminar->obtener_dato();
        ultimo_nodo = nodo_a_eliminar->obtener_anterior();
        if (cursor == nodo_a_eliminar) {
            cursor = cursor->obtener_anterior();
        }
    } else {
        nodo_a_eliminar = obtener_nodo(indice);
        dato_eliminado = nodo_a_eliminar->obtener_dato();
        Nodo_de<T>* nodo_anterior = nodo_a_eliminar->obtener_anterior();
        Nodo_de<T>* nodo_siguiente = nodo_a_eliminar->obtener_siguiente();
        nodo_anterior->cambiar_siguiente(nodo_siguiente);
        nodo_siguiente->cambiar_anterior(nodo_anterior);
        if (cursor == nodo_a_eliminar) {
            cursor = nodo_anterior;
        }
    }
    indice_cursor--;
    delete nodo_a_eliminar;
    cantidad_datos--;
    return dato_eliminado;
}

template <typename T>
T Lista_de<T>::primero() {
    if (vacio()){
        throw Lista_exception();
    }
    cursor = primer_nodo;
    reiniciar_cursor(true);
    return cursor->obtener_dato();
}

template <typename T>
T Lista_de<T>::ultimo() {
    if (vacio()){
        throw Lista_exception();
    }
    cursor = ultimo_nodo;
    reiniciar_cursor(false);
    return cursor->obtener_dato();
}

template <typename T>
T Lista_de<T>::elemento(size_t indice) {
    if(indice >= cantidad_datos || indice < 0){
        throw Lista_exception();
    }
    cursor = obtener_nodo(indice);
    indice_cursor = int(indice);
    return  cursor->obtener_dato();
}

template <typename T>
bool Lista_de<T>::puede_avanzar() {
    return (cursor != nullptr);
}

template <typename T>
T Lista_de<T>::avanzar(bool siguiente){
    if(!puede_avanzar()){
        throw Lista_exception();
    }
    T dato = cursor->obtener_dato();
    if(siguiente){
        cursor = cursor->obtener_siguiente();
        indice_cursor ++;
    }else{
        cursor = cursor->obtener_anterior();
        indice_cursor --;
    }
    return dato;
}

template <typename T>
void Lista_de<T>::reiniciar_cursor(bool principio) {
    if(vacio()){
        cursor = nullptr;
        indice_cursor = -1;
    } else {
        if (principio){
            cursor = primer_nodo;
            indice_cursor = 0;
        } else {
            cursor = ultimo_nodo;
            indice_cursor = cantidad_datos -1;
        }
    }
}

template <typename T>
size_t Lista_de<T>::tamanio() {
    return cantidad_datos;
}

template <typename T>
bool Lista_de<T>::vacio() {
    return (cantidad_datos == 0);
}

template <typename T>
Lista_de<T>::~Lista_de(){
    while (!vacio()){
        baja();
    }
}

template <typename T>
Nodo_de<T>* Lista_de<T>::obtener_nodo(size_t indice){
    if (indice < 0 || indice >= cantidad_datos) {
        throw Lista_exception();
    }
    if (int(indice) == indice_cursor) {
        return cursor;
    } else if (int(indice) < indice_cursor) {
        while (indice_cursor > int(indice) ) {
            avanzar(false);
        }
    } else {
        while (indice_cursor < int(indice) ) {
            avanzar(true);
        }
    }
    return cursor;
}



#endif