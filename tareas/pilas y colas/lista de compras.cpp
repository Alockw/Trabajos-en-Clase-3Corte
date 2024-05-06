#include <iostream>
#include <queue>

using namespace std;

class Mercado {
private:
    queue<string> productos; // Cola para almacenar los productos

public:
    // Función para agregar un producto al mercado
    void agregarProducto(const string& producto) {
        productos.push(producto);
    }

    // Función para eliminar el primer producto del mercado
    void eliminarProducto() {
        if (!productos.empty()) { // Verifica si la cola no está vacía
            productos.pop();
        } else {
            cout << "El mercado está vacío." << endl;
        }
    }

    // Función para eliminar un producto específico del mercado
    void eliminarProductoEspecifico(const string& producto) {
        queue<string> ref; // Cola auxiliar para almacenar temporalmente los elementos
        int s = productos.size();
        int cnt = 0;

        // Mover todos los elementos excepto el producto específico a la cola auxiliar
        while (!productos.empty() && productos.front() != producto) {
            ref.push(productos.front());
            productos.pop();
            cnt++;
        }

        // Si el producto no se encuentra, no se realiza ninguna acción
        if (productos.empty()) {
            cout << "Producto no encontrado!" << endl;
            while (!ref.empty()) {
                productos.push(ref.front());
                ref.pop();
            }
        } else {
            // Si el producto se encuentra, eliminarlo y reorganizar la cola
            productos.pop();
            while (!ref.empty()) {
                productos.push(ref.front());
                ref.pop();
            }
            int k = s - cnt - 1;
            while (k--) {
                string p = productos.front();
                productos.pop();
                productos.push(p);
            }
        }
    }

    // Función para mostrar todos los productos en el mercado
    void mostrarProductos() const {
        queue<string> copia = productos; // Hacer una copia para no modificar la original
        while (!copia.empty()) {
            cout << copia.front() << endl;
            copia.pop(); // Elimina el primer producto mostrado
        }
    }
};

int main() {
    Mercado mercado;

    // Agregar productos al mercado
    mercado.agregarProducto("Manzanas");
    mercado.agregarProducto("Naranjas");
    mercado.agregarProducto("Platanos");

    // Mostrar todos los productos en el mercado
    cout << "Productos en el mercado:" << endl;
    mercado.mostrarProductos();

    // Permitir al usuario agregar o eliminar productos
    int opcion;
    string producto;
    do {
        cout << "Ingrese \n 1 para agregar un producto, \n 2 para eliminar un producto, \n 3 para mostrar productos,\n 4 para salir: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del producto a agregar: ";
                cin >> producto;
                mercado.agregarProducto(producto);
                break;
            case 2:
                cout << "Ingrese el nombre del producto a eliminar: ";
                cin >> producto;
                mercado.eliminarProductoEspecifico(producto);
                break;
            case 3:
                cout << "Productos en el mercado:" << endl;
                mercado.mostrarProductos();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}
