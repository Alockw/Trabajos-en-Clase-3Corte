#include <iostream>
#include <queue>
#include <string>
#include <limits> // Necesario para limpiar el buffer de entrada

using namespace std;

class SistemaTexto {
private:
    queue<string> originalesIniciales; // Cola para almacenar las versiones originales iniciales (antes de modificaciones)
    queue<string> textosOriginales; // Cola para almacenar las versiones originales
    queue<string> textosModificados; // Cola para almacenar las versiones modificadas

public:
    // Función para agregar una nueva versión del texto
    void agregarVersion(const string& texto) {
        if (textosModificados.empty()) {
            originalesIniciales.push(texto); // Agrega el texto inicial a la cola de versiones originales iniciales
        }
        textosOriginales.push(texto); // Agrega el texto original a la cola de textos originales
        textosModificados.push(texto); // Agrega el texto original a la cola de textos modificados
    }

    // Función para mostrar las versiones originales iniciales (antes de modificaciones)
    void mostrarVersionesOriginalesIniciales() const {
        if (!originalesIniciales.empty()) {
            cout << "Versiones originales iniciales:" << endl;
            queue<string> temp = originalesIniciales;
            while (!temp.empty()) {
                cout << temp.front() << endl;
                temp.pop();
            }
        } else {
            cout << "No hay versiones originales iniciales guardadas." << endl;
        }
    }

    // Función para mostrar la última versión original del texto (después de modificaciones)
    void mostrarUltimaVersionOriginal() const {
        if (!textosOriginales.empty()) {
            cout << "Última versión original del texto: " << textosOriginales.back() << endl;
        } else {
            cout << "No hay versiones originales guardadas." << endl;
        }
    }

    // Función para mostrar la última versión modificada del texto
    void mostrarUltimaVersionModificada() const {
        if (!textosModificados.empty()) {
            cout << "Última versión modificada del texto: " << textosModificados.back() << endl;
        } else {
            cout << "No hay versiones modificadas guardadas." << endl;
        }
    }

    // Función para modificar la última versión del texto
    void modificarTexto(const string& nuevoTexto) {
        if (!textosOriginales.empty()) {
            textosOriginales.push(nuevoTexto); // Agrega el nuevo texto como la última versión original
            textosModificados.push(nuevoTexto); // Agrega el nuevo texto como la última versión modificada
            cout << "Texto modificado correctamente." << endl;
        } else {
            cout << "No hay texto para modificar." << endl;
        }
    }
};

void mostrarMenu(SistemaTexto& sistemaTexto) {
    int opcion;
    string texto;
    do {
        cout << "\n*************************************" << endl;
        cout << "\t MENÚ DE TEXTO" << endl;
        cout << "*************************************" << endl;
        cout << "\n\n\t (1) Agregar texto" << endl;
        cout << "\t (2) Mostrar versiones originales iniciales" << endl;
        cout << "\t (3) Mostrar ultima versión original" << endl;
        cout << "\t (4) Modificar texto" << endl;
        cout << "\t (5) Mostrar ultima versión modificada" << endl;
        cout << "\t (6) Salir" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        // Limpiar el buffer después de leer la opción
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                cout << "Ingrese el texto a agregar: ";
                getline(cin, texto);
                sistemaTexto.agregarVersion(texto);
                break;
            case 2:
                sistemaTexto.mostrarVersionesOriginalesIniciales();
                break;
            case 3:
                sistemaTexto.mostrarUltimaVersionOriginal();
                break;
            case 4:
            cout << "Ingrese el nuevo texto: ";
                getline(cin, texto);
                sistemaTexto.modificarTexto(texto);
                break;
            case 5:
                sistemaTexto.mostrarUltimaVersionModificada();
                break;
            case 6:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 6);
}

int main() {
    SistemaTexto sistemaTexto;

    mostrarMenu(sistemaTexto);

    return 0;
}
