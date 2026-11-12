#include <iostream>
#include <queue>
#include <string>
#include <limits>
using namespace std;

void mostrarCola(queue<string> personas) {
    if (personas.empty()) {
        cout << "La cola esta vacia.\n";
        return;
    }
    cout << "Personas en espera (primero a ultimo):\n";
    int turno = 1;
    while (!personas.empty()) {
        cout << turno++ << ". " << personas.front() << "\n";
        personas.pop();
    }
}

int main() {
    queue<string> cola;
    int opcion;
    string nombre;

    do {
        cout << "\n--- SISTEMA DE TURNOS FIFO ---\n";
        cout << "1. Agregar persona\n";
        cout << "2. Atender primera persona\n";
        cout << "3. Ver quien sigue\n";
        cout << "4. Mostrar cola\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un numero valido.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Nombre de la persona: ";
                getline(cin, nombre);
                if (nombre.empty()) {
                    cout << "El nombre no puede estar vacio.\n";
                } else {
                    cola.push(nombre);
                    cout << nombre << " entro a la cola.\n";
                }
                break;
            case 2:
                if (cola.empty()) cout << "No hay personas para atender.\n";
                else {
                    cout << "Atendiendo a: " << cola.front() << "\n";
                    cola.pop();
                }
                break;
            case 3:
                if (cola.empty()) cout << "No hay personas en espera.\n";
                else cout << "Siguiente: " << cola.front() << "\n";
                break;
            case 4:
                mostrarCola(cola);
                break;
            case 5:
                cout << "Programa finalizado.\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
    return 0;
}
