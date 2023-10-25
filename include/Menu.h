#ifndef MENU_H
#define MENU_H
#include <string>
#include <iostream>
#include <sstream>

class Menu {
private:
    std::string titulo;
    static const int MAXIMO_OPCIONES = 10;
    std::string opciones[MAXIMO_OPCIONES];
    int numero_opciones;

    //Pre:Recibe una cadena.
    //Post:Devuelve True en caso de que sea un numero, sino devuelve false.
    bool es_numero(std::string opcion);

    //Pre:-
    //Post:Permite al usuario seleccionar una opcion valida.
    int seleccionar_opcion_menu();

    //Pre:-
    //Post:Muestra las opciones del menu.
    void mostrar_opciones();

public:
    // Constructor que recibe el título del menú , un vector estatico de strings con las opciones del menu
    // y el numero de opciones.
    Menu(std::string titulo, std::string opciones[], int numero_pciones);

    //Pre:-
    //Post:Ejecuta el menu y devuelve un entero con la opcion valida seleccionada, sino devuelve -1.
    int ejecutar_menu();
};


#endif
