#include <iostream>
#include <vector>

class Livro {
public:
    Livro() {
        available = true;
    }
    ~Livro() {}
    void listarGeneros() {
        for (int i = 0; i < sizeof(genero); i++) {
            std::cout << genero[i];
        }
    }
    void printBookInformation() {
        std::cout << "\nTítulo: " << titulo << "\nData de publicação: " << dtaPublic << "\nISBN: " << isbn << "\nID: " << id << "\nEditora: " << editora << "\n==============\n";
    }
    std::string titulo;
    std::string dtaPublic;
    std::string isbn;
    std::string editora;
    std::vector<std::string> genero;
    std::string author;
    int id;
    bool available;
};