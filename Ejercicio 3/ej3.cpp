#include "ej3.h"

void Clase2::asociar_doubles(const string& etiqueta, const vector<double>& v){
    etiqueta_doubles = etiqueta;
    vec_doubles = &v;
}

void Clase2::asociar_palabras(const string& etiqueta, const vector<string>& p){
    etiqueta_palabras = etiqueta;
    palabras = &p;
}

void Clase2::asociar_listas(const string& etiqueta, const vector<vector<int>>& l){
    etiqueta_listas = etiqueta;
    listas = &l;
}

string Clase2::construir_json_string() const{
    ostringstream oss;

    oss << "{";

    oss << " \"" << etiqueta_doubles << "\" : [";
    for(size_t i = 0; i < vec_doubles -> size(); ++i){
        oss << (*vec_doubles)[i];                           // desreferenciar para poder imprimir
        if (i != vec_doubles -> size() - 1) oss << ", ";
    }
    oss << "]," << endl;

    oss << "  \"" << etiqueta_palabras << "\" : [";
    for(size_t i = 0; i < palabras -> size(); ++i){
        oss << "\"" << (*palabras)[i] << "\"";
        if (i != palabras -> size() - 1) oss << ", ";
    }
    oss << "]," << endl;

    oss << "  \"" << etiqueta_listas << "\" : [\n";
    for(size_t i = 0; i < listas -> size(); ++i){
        oss << "          [";
        for (size_t j = 0; j < (*listas)[i].size(); ++j) {
            oss << (*listas)[i][j];
            if (j != (*listas)[i].size() - 1) oss << ", ";
        }
        oss << "]";
        if (i != listas -> size() - 1) oss << "," << endl;
    }

    oss << "\n          ]" << endl;

    oss << "}" << endl;

    return oss.str();
}

void Clase2::guardar_json_archivo() const{
    ofstream archivo("datos.json");
    if (!archivo.is_open()){
            cout << "Error al crear el archivo" << endl;
        return;
    }
    archivo << construir_json_string();
    archivo.close();
}