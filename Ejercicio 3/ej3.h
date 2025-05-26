#ifndef EJ3_H
#define EJ3_H

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

template <typename T>       // como la clase está bajo un template, las implementaciones de los métodos hay que hacerlas en el .h
class Clase1{
private:
    vector<double> vec_doubles;
    vector<string> palabras;
    vector<vector<int>> listas;

public:
    void agregar_datos(const T& datos){         // agrega datos del tipo T
        if constexpr (is_same_v<T, vector<double>>){        // si el tipo T es vector<double>
            for(double d : datos){                          // agrega cada double a vec_doubles
                vec_doubles.push_back(d);
            }
        } else if constexpr (is_same_v<T, vector<string>>){     // si el tipo T es vector<string>
            for(const string& s : datos){                       // agrega cada string a palabras
                palabras.push_back(s);
            }
        } else if constexpr (is_same_v<T, vector<vector<int>>>){    // si el tipo T es vector<vector<int>>
            for(const auto& fila : datos){                          // agrega cada sublista a listas
                listas.push_back(fila);
            }
        } else{
            cout << "Tipo de dato no reconocido" << endl;
        }
    }

    const vector<double>& obtener_doubles() const { return vec_doubles; }
    const vector<string>& obtener_palabras() const { return palabras; }
    const vector<vector<int>>& obtener_listas() const { return listas; }
};

class Clase2{
private:
    string etiqueta_doubles;
    string etiqueta_palabras;
    string etiqueta_listas;

    const vector<double>* vec_doubles = nullptr;
    const vector<string>* palabras = nullptr;
    const vector<vector<int>>* listas = nullptr;

public:
    void asociar_doubles(const string& etiqueta, const vector<double>& v);
    void asociar_palabras(const string& etiqueta, const vector<string>& p);
    void asociar_listas(const string& etiqueta, const vector<vector<int>>& l);
    string construir_json_string() const;
    void guardar_json_archivo() const;
};

#endif