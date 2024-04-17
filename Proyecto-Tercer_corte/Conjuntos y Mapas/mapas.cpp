#include <iostream>
using namespace std;
#include <map>

// Utilizamos la clase map
// Clave:Valor
int main()
{
    map<int, string> frutas;
    frutas[1] = "arandanos";
    frutas[2] = "uvas";
    frutas[3] = "cerezas";
    frutas[4] = "sandia";
    for (const auto &par : frutas)
    {

        int clave = par.first();
        string valor = par.second();
        cout << "Clave:" << clave << " Valor:" << valor << endl;
    }

    /*
    insert(): Agregar un par clave-valor al mapa.
    erase(): Eliminar un par clave-valor del mapa.
    find(): Buscar una clave en el mapa.
    */

    string nombre = "cerezas";
    auto it = frutas.find(nombre);
    if (it != frutas.end())
    {
        cout << "Se encontró el elemento '" << nombre << " en el conjunto de frutas";
    }
    else
    {
        cout << "No se encontró el elemento '" << nombre << " en el conjunto de frutas";
    }

    string fruit = "uvas";
    frutas.erase(fruit);

    /*
    map<string, int> mapa1 = {{"Juan", 25}, {"María", 30}};
    map<string, int> mapa2 = {{"Cristian", 20}, {"Paula", 19}};

    Unir mapa2 a mapa1
    mapa1.insert(mapa2.begin(), mapa2.end());*/

    return 0;
}