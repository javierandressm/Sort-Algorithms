#include "utils.hpp"
#include <fstream>
#include <iostream>

vector<string> readDataset(const string& filename) {
    vector<string> words;
    ifstream file;

    vector<string> paths = {
        filename,
        "../" + filename,
        "../../" + filename,
        "dataset.txt",
        "../dataset.txt",
        "../../dataset.txt"
    };

    for (const auto& path : paths) {
        file.open(path);
        if (file.is_open()) {
            cout << "Archivo encontrado en: " << path << "\n";
            break;
        }
    }

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo: " << filename << "\n";
        cerr << "Rutas intentadas: dataset.txt, ../dataset.txt, ../../dataset.txt\n";
        return words;
    }

    string w;
    while (file >> w) {
        words.push_back(w);
    }

    file.close();

    if (words.empty()) {
        cerr << "Error: El archivo esta vacio.\n";
    }

    return words;
}

bool isSorted(const vector<string>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

size_t estimateVectorMemory(const vector<string>& data) {
    size_t total = sizeof(vector<string>) + data.capacity() * sizeof(string);
    for (const auto& s : data) {
        total += s.capacity() * sizeof(char);
    }
    return total;
}

