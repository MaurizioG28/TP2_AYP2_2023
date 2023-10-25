#ifndef AYP2_PLANTILLA_TP2_2C2023_JUGADOR_H
#define AYP2_PLANTILLA_TP2_2C2023_JUGADOR_H

#include "Menu.h"
#include "Destino.h"
#include "Inventario.h"

class Jugador {
private:
    Inventario inventario_jugador;
    Destino  destino_jugador;
    std::string perfil_jugador;


public:
    //Constructor del inventario debe recibir la ruta del archivo donde se va cargar el inventario.
    Jugador(std::string ruta_archivo);

    //Pre:-
    //Post: Interactua con el Destino del jugador.
    void destino();

    //Pre: Recibe la ruta del archivo save_file.csv.Para guardar el inventario del jugador.
    //Post: Interactura con el inventario del jugador.
    void inventario(std::string ruta_archivo);
};

#endif
