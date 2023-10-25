#include "Jugador.h"


using namespace std;

Jugador::Jugador(string ruta_archivo) {
    this->inventario_jugador.cargar_inventario_desde_archivo(ruta_archivo);
}

void Jugador::destino() {
    string opciones[] = {"Agregar evento.",
                         "Definir destino.",
                         "Mostrar Sucesos.",
                         "Volver a menu principal."
                        };
    string nombre_menu = " MENU DESTINO ";
    Menu menu_destino(nombre_menu, opciones, size(opciones));
    int opcion = 0;
    while (opcion != 4) {
        cout << endl;
        opcion = menu_destino.ejecutar_menu();
        switch (opcion) {
            case 1:
                cout << "--------------------------" << endl;
                destino_jugador.agregar_evento();
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 2:
                cout << "--------------------------" << endl;
                this-> perfil_jugador = destino_jugador.definir_destino();
                cout << "Destino definido. El jugador es: " << this->perfil_jugador << endl;
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 3:
                cout << "--------------------------" << endl;
                destino_jugador.mostrar_sucesos(this->perfil_jugador);
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 4:
                break;
            default:
                cout << "Opción no válida. Introduce un número del 1 al 4." << endl;
                break;
        }
    }
}

void Jugador::inventario(string ruta_archivo) {
    string opciones[] = {"Agregar item.",
                         "Eliminar item.",
                         "Mostrar inventario.",
                         "Volver a menu principal.."
    };
    string nombre_menu = " MENU INVENTARIO ";
    Menu menu_inventario(nombre_menu, opciones, size(opciones));
    int opcion = 0;
    while (opcion != 4) {
        opcion = menu_inventario.ejecutar_menu();
        switch (opcion) {
            case 1:
                cout << "--------------------------" << endl;
                inventario_jugador.agregar_item();
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 2:
                cout << "--------------------------" << endl;
                inventario_jugador.eliminar_item();
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 3:
                cout << "--------------------------" << endl;
                inventario_jugador.consultar_inventario();
                cout << "--------------------------" << endl;
                cout << endl;
                break;
            case 4:
                inventario_jugador.guardar_inventario(ruta_archivo);
                break;
            default:
                cout << "Opción no válida. Introduce un número del 1 al 4." << endl;
                break;
        }
    }
    cout << "--------------------------" << endl;
}



