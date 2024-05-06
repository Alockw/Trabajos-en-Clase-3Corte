#include <iostream>
#include <queue>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

// Estructura para almacenar información del usuario
struct Usuario {
    string nombre;
    int posicionActual = 0; // Posición actual en la cola
    bool haCompradoBoleta = false; // Indica si el usuario ha comprado la boleta
};

// Función para agregar un usuario a la cola
void agregarUsuario(queue<Usuario>& cola, const string& nombre) {
    Usuario nuevoUsuario = {nombre};
    cola.push(nuevoUsuario);
}

// Función para mostrar la posición actual de un usuario en la cola
void mostrarPosicionActual(queue<Usuario>& cola, const string& nombre) {
    queue<Usuario> temp; // cola temporal para mantener los elementos mientras buscamos
    bool encontrado = false; // indicador para verificar si el usuario se encontró
    int posicion = 0; // contador para llevar el seguimiento de la posición

    // Mover elementos de la cola original a la temporal y buscar el usuario
    while (!cola.empty()) {
        Usuario& usuario = cola.front();
        if (usuario.nombre == nombre) {
            cout << "El usuario " << nombre << " esta en la posición " << posicion + 1 << " de la cola." << endl;
            usuario.posicionActual = posicion;
            encontrado = true;
        }
        temp.push(usuario);
        cola.pop();
        posicion++;
    }

    // Mover elementos de la cola temporal a la original
    while (!temp.empty()) {
        cola.push(temp.front());
        temp.pop();
    }
}

// Función para simular el paso del tiempo y la atención de los usuarios
void simularTiempo(queue<Usuario>& cola) {
    while (!cola.empty()) {
        Usuario& usuario = cola.front();
        auto inicio = chrono::high_resolution_clock::now();

        // Simulación de tiempo de espera
        this_thread::sleep_for(chrono::seconds(2)); // Ajusta este valor según sea necesario
        cola.pop(); // Remover el usuario de la cola
    }
}

int main() {
    queue<Usuario> colaUsuarios;
    int tiempoPromedio = 2; // Tiempo promedio de atención por usuario (segundos)

    // Bucle para permitir múltiples entradas de usuarios
    char opcion;
    do {
        cout << "¿Desea unirse a la cola? (s/n): ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer para evitar problemas con getline

        if (opcion == 's' || opcion == 'S') {
            string nombre;
            cout << "Ingrese su nombre: ";
            getline(cin, nombre);
            agregarUsuario(colaUsuarios, nombre);
            mostrarPosicionActual(colaUsuarios, nombre);

            // Simulación del tiempo que tomaría llegar al puesto 1 de la fila
            int tiempoTotal = colaUsuarios.size() * tiempoPromedio;
            cout << "Tiempo estimado para llegar al puesto 1 de la fila: " << tiempoTotal << " segundos." << endl;
        }

    } while (opcion == 's' || opcion == 'S');

    // Simular el paso del tiempo y la atención de los usuarios
    simularTiempo(colaUsuarios);

    return 0;
}
