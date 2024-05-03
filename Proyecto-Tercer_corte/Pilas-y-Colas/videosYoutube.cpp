#include <iostream>
#include <stack>
#include <string>
#include <limits>
using namespace std;

// Definición del struct para representar un video
struct Video {
    string nombre;
    int duracionMinutos;
};

int main() {
    stack<Video> pilaVideos;
    char respuesta;

    do {
        Video nuevoVideo;
        cout << "Ingresa el nombre del video: ";
        getline(cin, nuevoVideo.nombre);
        cout << "Ingresa la duracion en minutos del video: ";
        cin >> nuevoVideo.duracionMinutos;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Agregar el video a la pila
        pilaVideos.push(nuevoVideo);

        cout << "¿Quieres agregar otro video? (s/n): ";
        cin >> respuesta;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (respuesta == 's' || respuesta == 'S');

    // Mostrar los videos en la pila
    cout << "\nVideos en la lista de reproduccion:\n";
    while (!pilaVideos.empty()) {
        Video videoCima = pilaVideos.top();
        cout << "Nombre: " << videoCima.nombre << "\n";
        cout << "Duracion: " << videoCima.duracionMinutos << " minutos\n\n";
        pilaVideos.pop();
    }

    return 0;
}
//es una lista ya que el ultimo video que se agrega es el que sale de primeras 
