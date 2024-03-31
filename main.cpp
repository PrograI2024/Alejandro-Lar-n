#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "Gestor_de_Calificaciones.h"

void MostrarNotas(Cuatrimestre1 *gestor);
void IngresarNotas(Cuatrimestre1 *gestor);
std::vector<std::string> materia;
float notas[4];


void Menu(){
    std::cout << "Gestor de Calificaciones - Ingenieria Informatica" << std::endl;
    std::cout << "(1) Ingresar Notas" << std::endl;
    std::cout << "(2) Mostrar Notas" << std::endl;
    std::cout << "(3) Salir del Programa" << std::endl;
}

int main(){
    int change;
    Cuatrimestre1 *gestor;
    gestor = new Cuatrimestre1();
    gestor->SetMaterias("Matematica", "Programacion 1", "Logica", "Fisica", "Teconologias de la Informacion y Comunicacion");

    do {
    Menu();
    std::cin >> change;
        switch (change){
            case 1:
                IngresarNotas(gestor);
                break;
            case 2:
                MostrarNotas(gestor);
                break;
            case 3:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Por favor, seleccione nuevamente." << std::endl;
                break;
            }

                // Preguntar al usuario si desea regresar al menú principal
        if (change != 3) {
            char backChoice;
            std::cout << "" << std::endl;
            std::cout << "Desea volver al menu principal (S/N): ";
            std::cin >> backChoice;
            if (backChoice != 'S' && backChoice != 's') {
                change = 3; // Salir del bucle si no desea volver al menú
            }
        }

    } while (change != 3);

    delete gestor;
    return 0;
}

void MostrarNotas(Cuatrimestre1 *gestor){
    materia = gestor->GetMaterias();
    std::cout << "Materias del Primer Cuatrimestre: " << std::endl;
    for (int i = 0; i < materia.size(); i++){
        std::cout << "Materia: " << materia[i] << " ------------- " << " Nota: " << notas[i] << std::endl;
    }
}

void IngresarNotas(Cuatrimestre1 *gestor){
    gestor->SetNotas();
    for (int i = 0; i < 5; i++) {
        notas[i] = gestor->GetNota(i);
    }
}
