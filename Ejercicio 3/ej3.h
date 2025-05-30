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
    vector<typename T::value_type> vec;

public:
    void agregar_datos(const T& datos){         // agrega datos del tipo T
        if constexpr (is_same<T, vector<double>>::value){        // si el tipo T es vector<double>
            for(double d : datos){                          // agrega cada double a vec
                vec.push_back(d);
            }
        } else if constexpr (is_same<T, vector<std::string>>::value){     // si el tipo T es vector<string>
            for(const string& s : datos){                       // agrega cada string a vec
                vec.push_back(s);
            }
        } else if constexpr (is_same<T, vector<std::vector<int>>>::value){    // si el tipo T es vector<vector<int>>
            for(const auto& fila : datos){                          // agrega cada sublista a vec
                vec.push_back(fila);
            }
        } else{
            cout << "Tipo de dato no reconocido" << endl;
        }
    }

    const vector<typename T::value_type>& obtener_vec() const {
        return vec;
    }
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