#ifndef AYP2_PLANTILLA_TP2_2C2023_DESTINO_H
#define AYP2_PLANTILLA_TP2_2C2023_DESTINO_H
#include "Evento.hpp"
#include <string>
#include "Interacciones.h"
#include "Cola.hpp"

const std::string JUGADOR_DESORIENTADO  = "Desorientado";
const std::string JUGADOR_PRECAVIDO  = "Precavido";
const std::string JUGADOR_ASUSTADO  = "Asustado";
const std::string JUGADOR_NO_DETERMINADO  = "No determinado";

const std::string SUCESO_DESORIENTADO  = "Aumento de factores ambientales";
const std::string SUCESO_PRECAVIDO  = "Aumento en la cantidad de enemigos";
const std::string SUCESO_ASUSTADO  = "Evento Pyramid Head adelantado.";
const std::string SUCESO_NO_DETERMINADO  = "Comportamiento aún no definido.";

const int MIN_APERTURAS_MAPA = 5;
const int MAX_GUARDADOS = 8;
const int MIN_GUARDADOS = 5;


class Destino {
private:
    int cantidad_guardados = 0;
    int cantidad_aperturas_de_mapa = 0;
    int reductor_guardados = 0;
    int reductor_aperturas_de_mapa = 0;
    Cola<Evento>* eventos;

    //Pre:-
    //Post:Cuenta la cantidad de eventos agregados a la cola.
    void contabilizar_eventos();

    //Pre-
    //Post:Si la cola esta vacio, vuelve las cantidades de guardados y apertura a 0.
    //     Si no reduce la cantidades de guardados y aperturas segun las veces que se contaron hasta la definicion de destino.
    void reducir_contadores_eventos();

    //Pre:-
    //Post:Define el destino del jugador dependiendo de la cantidad de eventos agregados.
    //     Devuelve que tipo de jugador es.
    std::string definir_perfil_jugador();

public:
    //Constructor.
    Destino();

    //Pre:-
    //Post:Agrega un evento, ingresado por el usuario.
    void agregar_evento();

    //Pre:-
    //Post:Define el destino  del jugador segun su perfil.
    std::string definir_destino();

    //Pre:Recibe un string con el perfil del jugador.
    //Post:Muestra un suceso dependiendo del tipo de perfil del jugador.
    void mostrar_sucesos(std::string perfil_jugador);

    //Destructor.
    ~Destino();

};

#endif
