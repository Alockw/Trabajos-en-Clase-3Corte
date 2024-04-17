#include <iostream>
#include <algorithm>
using namespace std;
#include <set>

/*Estructuras de datos fundamentales en programación.
Permiten almacenar y organizar datos de manera eficiente.
Conjuntos: Colecciones de elementos únicos sin un orden definido.
Mapas: Asocian claves únicas con valores.

Utilizamos la clase set*/

int main()
{
    // Declarando el conjunto
    set<string> frutas;

    /* Operaciones comunes
    insert(): Agregar un elemento al conjunto.
    erase(): Eliminar un elemento del conjunto.
    find(): Buscar un elemento en el conjunto.
    add():*/

    frutas.insert("arandanos");
    frutas.insert("uvas");
    frutas.insert("cerezas");
    frutas.insert("sandia");
    // impresion del conjunto
    cout << "Conjunto de frutas:" << endl;
    for (const string &fruta : frutas)
    {
        cout << fruta << endl;
    }

    frutas.insert("mango");
    // impresion del conjunto
    cout << "Conjunto de frutas:" << endl;
    for (const string &fruta : frutas)
    {
        cout << fruta << endl;
    }
    frutas.erase("cerezas");
    // impresion del conjunto
    cout << "Conjunto de frutas:" << endl;
    for (const string &fruta : frutas)
    {
        cout << fruta << endl;
    }

    // vector<string> frutas_vector(frutas.begin(), frutas.end());
    string buscar = "arandanos";
    string buscar2 = "cerezas";
    // Buscar elementos
    auto iterador = frutas.find(buscar);
    auto iterador2 = frutas.find(buscar2);
    // Verificar si existe el elemento.
    if (iterador != frutas.end())
    {
        cout << "Se encontró el elemento '" << buscar << " en el conjunto de frutas";
    }
    else
    {
        cout << "No se encontró el elemento '" << buscar << " en el conjunto de frutas";
    }
    if (iterador2 != frutas.end())
    {
        cout << "Se encontró el elemento '" << buscar2 << " en el conjunto de frutas";
    }
    else
    {
        cout << "No se encontró el elemento '" << buscar2 << " en el conjunto de frutas";
    }
    // tamaño del conjunto
    frutas.size();
    // limpiar el conjunto
    frutas.clear();
    // vaciar el conjunto
    frutas.empty();
    // conjunto de canciones de reproducción van a tener 3 canciones y luego agregan una mas, eliminan dos y buscan una.
    // Juan Felipe
    set<string> canciones;
    // tiene que tener 3 canciones
    canciones.insert("Viva la vida");
    canciones.insert("Yellow");
    canciones.insert("Fix you");
    // imprimir
    //  se agrega una
    canciones.insert("Paradise");
    // se eliminan dos
    canciones.erase("Yellow");
    // se busca una
    string buscarCancion = "Viva la vida";
    auto itCancion = canciones.find(buscarCancion);
    if (itCancion != canciones.end())
    {
        cout << buscarCancion << " encontrado" << endl;
    }
    else
    {
        cout << buscarCancion << " no encontrado" << endl;
    }

    // Carlos

    set<string> cancioness;
    cancioness.insert("asd");
    cancioness.insert("asdf");
    cancioness.insert("asdfg");
    string cancion;
    // agregar 1 cancion
    cout << "Ingrese una cancion para agregar al conjunto: ";
    cin >> cancion;
    canciones.erase("asd");
    cout << "Ingrese una cancion para buscar del conjunto: ";
    cin >> cancion;

    if (canciones.find(cancion) != cancioness.end())
    {
        cout << "La cancion " << cancion << " se encuentra en el conjunto." << endl;
    }
    else
    {
        cout << "La cancion " << cancion << " no se encuentra en el conjunto." << endl;
    }

    // Operaciones de intersección, unión y diferencia

    set<int> conjuntoA = {1, 2, 3, 4, 5};
    set<int> conjuntoB = {3, 4, 5, 6, 7};
    // INTERSECCIÓN
    set<int> interseccion;
    for (int elemento : conjuntoA)
    {
        if (conjuntoB.count(elemento))
        {
            interseccion.insert(elemento);
        }
        cout << elemento << " ";
    }
    for (int elemento : interseccion)
    {
        cout << elemento << " ";
    }

    // UNIÓN

    set<int> unionConjuntos= conjuntoA;
    unionConjuntos.insert(conjuntoB.begin(), conjuntoB.end());
    cout << "Unión: ";
    for (int elemento : unionConjuntos)
    {
        cout << elemento << " ";
    }

    // Diferencia conjunto A-conjunto B
    set<int> diferencia;
    set_difference(conjuntoA.begin(),conjuntoA.end(),conjuntoB.begin(),conjuntoB.end(), inserter(diferencia,diferencia.begin()));
// imprimir conjunto de la diferencia
    for (auto it = diferencia.begin(); it != diferencia.end(); ++it) {
        cout << *it << " ";
    }

    
    return 0;
}