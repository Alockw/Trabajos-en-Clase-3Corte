#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Llamada {
    string nombre;
    string numero;
};

class ListaLlamadas {
private:
    queue<Llamada> cola;
    vector<Llamada> llamadas;

public:
    void agregarLlamada(const Llamada& llamada) {
        cola.push(llamada);
        llamadas.push_back(llamada);
    }

    void mostrarLlamadas() {
        for (int i = llamadas.size() - 1; i >= 0; --i) {
            cout << "Nombre: " << llamadas[i].nombre << ", Numero: " << llamadas[i].numero << endl;
        }
    }
};

int main() {
    ListaLlamadas listaLlamadas;

    int opcion = 1; // Inicializa opcion antes de usarla
    do {
        Llamada llamada;
        cout << "Ingrese el nombre de la persona (o '1' para salir): ";
        cin >> llamada.nombre;
        if (llamada.nombre == "1") // Verifica si el usuario quiere salir
            break;
        cout << "Ingrese el numero de la llamada: ";
        cin >> llamada.numero;
        listaLlamadas.agregarLlamada(llamada);
        cout << "¿Desea agregar otra llamada? (1 para si, 2 para no): ";
        cin >> opcion;
    } while (opcion == 1);

    // Mostrar las llamadas en orden de recencia a antigüedad
    listaLlamadas.mostrarLlamadas();

    return 0;
}
