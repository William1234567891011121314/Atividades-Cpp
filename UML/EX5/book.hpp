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
    std::string titulo;
    std::string dtaPublic;
    std::string isbn;
    std::string editora;
    std::vector<std::string> genero;
    int id;
    bool available;
};