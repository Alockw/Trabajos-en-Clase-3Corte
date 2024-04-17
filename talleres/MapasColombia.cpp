//punto 1 
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Definición de Conjunto
set<string> conjunto;

// Operaciones Básicas de Conjuntos
void agregarElemento(const string& elemento) {
    conjunto.insert(elemento);
}

void eliminarElemento(const string& elemento) {
    conjunto.erase(elemento);
}

bool verificarElemento(const string& elemento) {
    return conjunto.find(elemento) != conjunto.end();
}

int obtenerTamaño() {
    return conjunto.size();
}

void imprimirElementos() {
    for (const string& elemento : conjunto) {
        cout << elemento << " ";
    }
    cout << endl;
}

// Definición de Mapa
map<string, pair<string, string>> mapaColombia;

// Operaciones Básicas de Mapas
void agregarParClaveValor(const string& clave, const string& valor1, const string& valor2) {
     mapaColombia.insert({clave, make_pair(valor1, valor2)});
}

string accederValor(const string& clave) {
    if (mapaColombia.find(clave) != mapaColombia.end()) {
        return mapaColombia[clave].first; // Retorna la capital
    }
    return "";
}

void modificarValor(const string& clave, const string& nuevoValor) {
     if (mapaColombia.find(clave) != mapaColombia.end()) {
         mapaColombia.insert({clave, {mapaColombia[clave].first, nuevoValor}});
     }
}

void eliminarParClaveValor(const string& clave) {
    mapaColombia.erase(clave);
}

bool verificarClave(const string& clave) {
    return mapaColombia.find(clave) != mapaColombia.end();
}

int obtenerTamañoMapa() {
    return mapaColombia.size();
}

void imprimirParesClaveValor() {
    for (const auto& par : mapaColombia) {
        cout << par.first << ": " << par.second.first << ", " << par.second.second << endl;
    }
}

// Funciones Específicas para el Mapa de Colombia
pair<string, string> obtenerCapitalYClima(const string& departamento) {
    if (mapaColombia.find(departamento) != mapaColombia.end()) {
        return mapaColombia[departamento];
    }
    return {"", ""};
}

vector<string> obtenerCiudadesPorClima(const string& clima) {
    vector<string> ciudades;
    for (const auto& par : mapaColombia) {
        if (par.second.second == clima) {
            ciudades.push_back(par.first);
        }
    }
    return ciudades;
}

// Ejemplo de uso
int main() {
    // Ejemplo de uso del conjunto
    agregarElemento("Antioquia");
    agregarElemento("Bogota");
    agregarElemento("Cundinamarca");
    imprimirElementos();

    // Ejemplo de uso del mapa de Colombia
    agregarParClaveValor("Antioquia", "Medellin", "Templado");
    agregarParClaveValor("Bogota", "Bogota", "Frio");
    agregarParClaveValor("Cundinamarca", "Bogota", "Templado");
    imprimirParesClaveValor();

    // Ejemplo de uso de las funciones específicas
    auto capitalYClima = obtenerCapitalYClima("Antioquia");
    cout << "Capital y Clima de Antioquia: " << capitalYClima.first << ", " << capitalYClima.second << endl;

    auto ciudadesTemplado = obtenerCiudadesPorClima("Templado");
    cout << "Ciudades con clima Templado: ";
    for (const auto& ciudad : ciudadesTemplado) {
        cout << ciudad << " ";
    }
    cout << endl;

    return 0;
}