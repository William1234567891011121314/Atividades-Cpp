#include <iostream>
#include <vector>

class Livro {
public:
    Livro() {
        available = true;
    }
    ~Livro() {}
    std::string titulo;
    std::string dtaPublic;
    std::string isbn;
    std::string editora;
    std::string genero = {};
    bool available;
};