// punto 2
#include <iostream>
#include <map>
#include <string>
using namespace std;

// Mapa anidado para almacenar las notas de los estudiantes
map<string, map<string, double>> notasEstudiantes;

// Función para registrar una nota
void registrarNota(const string &estudiante, const string &asignatura, double nota)
{
    notasEstudiantes.insert({estudiante, {{asignatura, nota}}});
}

// Función para mostrar la nota de un estudiante en una asignatura específica
void mostrarNota(const string &estudiante, const string &asignatura)
{
    auto itEstudiante = notasEstudiantes.find(estudiante);
    if (itEstudiante != notasEstudiantes.end())
    {
        auto itAsignatura = itEstudiante->second.find(asignatura);
        if (itAsignatura != itEstudiante->second.end())
        {
            cout << "La nota de " << estudiante << " en " << asignatura << " es: " << itAsignatura->second << endl;
        }
        else
        {
            cout << "No se encontró la nota para el estudiante " << estudiante << " en la asignatura " << asignatura << endl;
        }
    }
    else
    {
        cout << "No se encontró el estudiante " << estudiante << endl;
    }
}

// Función para calcular el promedio de notas de un estudiante en todas las asignaturas
double calcularPromedioEstudiante(const string &estudiante)
{
    double suma = 0.0;
    int contador = 0;
    auto itEstudiante = notasEstudiantes.find(estudiante);
    if (itEstudiante != notasEstudiantes.end())
    {
        for (const auto &asignaturaNota : itEstudiante->second)
        {
            suma += asignaturaNota.second;
            contador++;
        }
    }
    return contador > 0 ? suma / contador : 0.0;
}

// Función para calcular el promedio de notas de una asignatura para todos los estudiantes
double calcularPromedioAsignatura(const string &asignatura)
{
    double suma = 0.0;
    int contador = 0;
    for (const auto &estudianteNotas : notasEstudiantes)
    {
        auto itAsignatura = estudianteNotas.second.find(asignatura);
        if (itAsignatura != estudianteNotas.second.end())
        {
            suma += itAsignatura->second;
            contador++;
        }
    }
    return contador > 0 ? suma / contador : 0.0;
}

int main()
{
    // Ejemplo de uso
    registrarNota("Juan", "Matemáticas", 8.5);
    registrarNota("Juan", "Física", 7.0);
    registrarNota("Ana", "Matemáticas", 9.0);
    registrarNota("Ana", "Física", 8.0);

    mostrarNota("Juan", "Matemáticas");
    mostrarNota("Ana", "Física");

    cout << "Promedio de Juan: " << calcularPromedioEstudiante("Juan") << endl;
    cout << "Promedio de Física: " << calcularPromedioAsignatura("Física") << endl;

    return 0;
}