#include "Menu.h"
#include "iostream"
#include "Jugador.h"
using namespace std;

const string RUTA_ARCHIVO = "save_file.csv";

int main() {
    string opciones[] = {"Operar sobre Inventario",
                         "Operar sobre Destino.",
                         "Salir."
                        };
    string nombreMenu = "MENU PRINCIPAL";
    Menu menuPrincipal(nombreMenu, opciones, size(opciones));
    Jugador jugador(RUTA_ARCHIVO);
    int opcion = 0;
    while (opcion != 3) {
        opcion = menuPrincipal.ejecutar_menu();
        switch (opcion) {
            case 1:
                jugador.inventario(RUTA_ARCHIVO);
                cout << "Guardando inventario.Por favor espere."<< endl;
                cout << "Guardando exitoso!"<< endl;
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 2:
                jugador.destino();
                break;
            case 3:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Introduce un número del 1 al 3." << endl;
                break;
        }
    }
    return 0;
}