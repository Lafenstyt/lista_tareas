#include <iostream>
#include <string>
using namespace std;


void mostrarTareas(const string tareas[], int numTareas) {
    if (numTareas == 0) {
        cout << "La lista de tareas está vacía." << endl;
        return;
    }
    cout << "Lista de tareas:" << endl;
    for (int i = 0; i < numTareas; i++) {
        cout << (i + 1) << ". " << tareas[i] << endl;
    }
}


int main() {
    string tareas[100]; 
    int numTareas = 0;
    int opcion;

    while (true) {
        cout << "\nMenú de tareas:" << endl;
        cout << "1. Agregar tarea" << endl;
        cout << "2. Eliminar tarea" << endl;
        cout << "3. Mostrar tareas" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                if (numTareas < 100) {
                    cout << "Ingrese la tarea a agregar: ";
                    getline(cin, tareas[numTareas]);
                    numTareas++;
                } else {
                    cout << "La lista de tareas está llena." << endl;
                }
                break;
            case 2:
                if (numTareas > 0) {
                    int tareaEliminar;
                    cout << "Ingrese el número de la tarea a eliminar (1-" << numTareas << "): ";
                    cin >> tareaEliminar;
                    cin.ignore(); 

                    if (tareaEliminar >= 1 && tareaEliminar <= numTareas) {
                        for (int i = tareaEliminar - 1; i < numTareas - 1; i++) {
                            tareas[i] = tareas[i + 1];
                        }
                        numTareas--;
                        cout << "Tarea eliminada." << endl;
                    } else {
                        cout << "Número de tarea no válido." << endl;
                    }
                } else {
                    cout << "No hay tareas para eliminar." << endl;
                }
                break;
            case 3:
                mostrarTareas(tareas, numTareas);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                return 0; 
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
                break;
        }
    }
}
