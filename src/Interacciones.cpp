#include "Interacciones.h"

using  namespace std;


Interacciones::Interacciones() {}

bool Interacciones::es_tipo_de_item_valido(string tipo) {
    return (tipo == TIPO_PUZZLE || tipo == TIPO_CURATIVO || tipo == TIPO_MUNICION);
}

bool Interacciones::es_tipo_de_evento_valido(string nuevo_evento) {
    return (nuevo_evento == ACCION_GUARDADO || nuevo_evento == ACCION_APERTURA_MAPA);
}

Evento Interacciones::consultar_evento_para_agregar() {
    string nuevo_evento;
    cout << "Ingrese el tipo de evento.Debe ingresar: " << ACCION_APERTURA_MAPA << " o " << ACCION_GUARDADO << "." << endl;
    cin.ignore();
    getline(cin,nuevo_evento);
    while (!es_tipo_de_evento_valido(nuevo_evento)) {
        cout << "ERROR: debe ingresar una opcion valida: " << ACCION_APERTURA_MAPA <<  " o " << ACCION_GUARDADO << "." << endl;
        getline(cin,nuevo_evento);
    }
    Evento evento(nuevo_evento);
    return evento;
}

void Interacciones::consultar_item_para_agregar(std::string &nombre, std::string &tipo) {
    cout << "Ingrese el nombre del item: ";
    cin.ignore();
    getline(cin,nombre);
    cout << "Ingrese el tipo de item.Debe ingresar " << TIPO_MUNICION << ", " << TIPO_CURATIVO << " o " << TIPO_PUZZLE << "." << endl;
    cout << "Tipo: ";
    getline(cin,tipo);
    while (!es_tipo_de_item_valido(tipo)) {
        cout << "ERROR: debe ingresar una opcion valida:" << TIPO_MUNICION << ", " << TIPO_CURATIVO << " o " << TIPO_PUZZLE << "." << endl;
        cout << "Tipo: ";
        getline(cin,tipo);
    }
}

void Interacciones::consultar_item_para_borrar(std::string &nombre) {
    cin.ignore();
    cout << "Ingrese el nombre del item: ";
    getline(cin,nombre);
}

