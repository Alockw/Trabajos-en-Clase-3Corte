#include <iostream>
#include <queue>
#include <string>
#include <limits> 

using namespace std;

struct Cita {
    string cedula;
    string hora;
    string tipo;
};

int main() {
    queue<Cita> colaCitas;
    bool agregarCita = true;
    char respuesta;

    do {
        Cita nuevaCita;
        cout << "Ingresa la cédula del cliente para la cita: ";
        getline(cin, nuevaCita.cedula);
        cout << "Ingresa la hora de la cita: ";
        getline(cin, nuevaCita.hora);
        cout << "Ingresa el tipo de la cita: ";
        getline(cin, nuevaCita.tipo);

        // Agregar la cita a la cola
        colaCitas.push(nuevaCita);

        cout << "¿Desea agregar otra cita? (s/n): ";
        cin >> respuesta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpieza del buffer
        agregarCita = (respuesta == 's' || respuesta == 'S');
    } while (agregarCita);

    // Mostrar las citas en la cola en el orden en que se ingresaron
    cout << "\nCitas en la cola (orden de entrada):\n";
    while (!colaCitas.empty()) {
        Cita citaFrente = colaCitas.front();
        cout << "Cédula: " << citaFrente.cedula << "\n";
        cout << "Hora de la cita: " << citaFrente.hora << "\n";
        cout << "Tipo de cita: " << citaFrente.tipo << "\n\n";
        colaCitas.pop();
    }

    return 0;
}
//es una cola ya que el primero que haya pedido cita es el que aparecera en el sistema como para entrar a la cita 