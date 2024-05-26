#include <iostream>
#include <vector>
#include <chrono>
#include "book.hpp"

class Emprestimo {
public:
    Emprestimo(Livro livro) {
        multa = 0;
        dtaEntrada = std::chrono::system_clock::now();
        dtaSaida = dtaEntrada + std::chrono::hours(24 * 7 * 4);
        livro.available = false;
        dtaSaida = dtaEntrada + std::chrono::hours(24 * 7 * 4);
        livro.available = false;
    }
    ~Emprestimo() {};
    void setMulta(float _multa) {
        multa = _multa;
    }
    void setLivroEmprestado(std::string _livroEmprestado) {
        livroEmprestado = _livroEmprestado;
    }
    std::string getLivroEmprestado() {
        return livroEmprestado;
    }
    std::string getDtaSaida() {
        std::time_t dtaSaida2 = std::chrono::system_clock::to_time_t(dtaSaida);
        char buffer[50];
        ctime_s(buffer, sizeof(buffer), &dtaSaida2);
        return std::string(buffer);
    }
    std::chrono::time_point<std::chrono::system_clock> getDtaEntrada() {
        return dtaEntrada;
    }
    float getMulta() {
        return multa;
    }
protected:
    std::chrono::time_point<std::chrono::system_clock> dtaSaida;
    std::chrono::time_point<std::chrono::system_clock> dtaEntrada;
    std::string livroEmprestado;
    float multa;
};