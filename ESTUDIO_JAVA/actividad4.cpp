#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cctype>

std::string toLowerCase(const std::string& word) {
    std::string result;
    for (char c : word) result += std::tolower(c);
    return result;
}

void readWordsFromFile(const std::string& filename, std::vector<std::string>& words) {
    std::ifstream file(filename);
    std::string word;
    while (file >> word) {
        words.push_back(toLowerCase(word));
    }
    file.close();
}

int main() {
    std::vector<std::string> words;

    auto start = std::chrono::high_resolution_clock::now();

    readWordsFromFile("archivos_words.txt", words);
    readWordsFromFile("clases_words.txt", words);

    std::sort(words.begin(), words.end());

    std::ofstream consolidatedFile("consolidado.txt");
    for (const std::string& word : words) {
        consolidatedFile << word << '\n';
    }
    consolidatedFile.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::ofstream logFile("a4_matricula.txt");
    logFile << "Tiempo total de ejecución: " << elapsed.count() << " segundos\n";
    logFile.close();

    std::cout << "Proceso completado. Archivo consolidado y log creados.\n";
    return 0;
}
