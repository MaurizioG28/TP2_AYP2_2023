#include "Menu.h"


using namespace std;

Menu::Menu(string titulo, string opciones[], int numero_opciones) {
    this->titulo = titulo;
    this->numero_opciones = numero_opciones;
    for (int i = 0; i < numero_opciones; ++i) {
        this->opciones[i] = opciones[i];
    }
}

void Menu::mostrar_opciones() {
    for (int i = 0; i < numero_opciones; ++i) {
        cout << i + 1 << ". " << opciones[i] << endl;
    }
}

bool Menu::es_numero(string opcion) {
    istringstream iss(opcion);
    int numero;
    iss >> numero;
    return !iss.fail() && iss.eof();
}

int Menu::seleccionar_opcion_menu() {
    string eleccion;
    bool seleccion_valida = false;
    while (!seleccion_valida) {
        cout << "-----" << titulo << "-----" << std::endl;
        mostrar_opciones();
        std::cout << "Elija una opcion: ";
        std::cin >> eleccion;
        if (es_numero(eleccion)) {
            int numero_eleccion = stoi(eleccion);
            if (numero_eleccion >= 1 && numero_eleccion <= numero_opciones) {
                seleccion_valida = true;
                return numero_eleccion;
            } else {
                cout << "Opción no valida. Intente de nuevo." << endl;
            }
        } else {
            cout << "Opcion no valida. Debe ingresar un numero." << endl;
            cout  << endl;
        }
    }

    return -1;
}


int Menu::ejecutar_menu(){
    return seleccionar_opcion_menu();
}





