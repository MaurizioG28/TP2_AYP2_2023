#include "Destino.h"

using namespace std;

Destino::Destino() {
    eventos = new Cola<Evento>();
}

void Destino::agregar_evento() {
    Interacciones interacciones;
    eventos->alta(interacciones.consultar_evento_para_agregar());
}

void Destino::reducir_contadores_eventos() {
    if(eventos->vacio()){
        cantidad_guardados = 0;
        cantidad_aperturas_de_mapa = 0;
    }else{
        cantidad_guardados -= reductor_guardados;
        cantidad_aperturas_de_mapa -= reductor_aperturas_de_mapa;
    }
    reductor_guardados = 0;
    reductor_aperturas_de_mapa = 0;

}

void Destino::contabilizar_eventos() {
    while (!eventos->vacio() && cantidad_guardados <= MAX_GUARDADOS) {
        Evento evento_desacolado = eventos->baja();
        if (evento_desacolado == ACCION_APERTURA_MAPA) {
            cantidad_aperturas_de_mapa++;
            reductor_aperturas_de_mapa++;
        } else if (evento_desacolado == ACCION_GUARDADO) {
            cantidad_guardados++;
            reductor_guardados++;
        }
    }
}

string Destino::definir_perfil_jugador(){
    if ((cantidad_aperturas_de_mapa > cantidad_guardados) && (cantidad_aperturas_de_mapa > MIN_APERTURAS_MAPA) && (cantidad_guardados < MAX_GUARDADOS)) {
        return JUGADOR_DESORIENTADO;
    } else if ((cantidad_guardados > cantidad_aperturas_de_mapa) && (cantidad_guardados > MIN_GUARDADOS) && (cantidad_guardados < MAX_GUARDADOS)) {
        return JUGADOR_PRECAVIDO;
    } else if (cantidad_guardados >= MAX_GUARDADOS) {
        return JUGADOR_ASUSTADO;
    } else {
        return JUGADOR_NO_DETERMINADO;
    }
}

string Destino::definir_destino() {
    contabilizar_eventos();
    string perfil = definir_perfil_jugador();
    reducir_contadores_eventos();
    return perfil;
}

void Destino::mostrar_sucesos(string perfil_jugador) {
    if (perfil_jugador == JUGADOR_DESORIENTADO) {
        cout << SUCESO_DESORIENTADO << endl;
    } else if (perfil_jugador == JUGADOR_PRECAVIDO) {
        cout << SUCESO_PRECAVIDO << endl;
    }else if (perfil_jugador ==  JUGADOR_ASUSTADO) {
        cout << SUCESO_ASUSTADO << endl;
    } else {
        cout <<SUCESO_NO_DETERMINADO << endl;
    }
}


Destino::~Destino() {
    delete eventos;
}




