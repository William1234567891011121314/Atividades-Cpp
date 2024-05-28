#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <sstream>
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
        struct tm data;
        localtime_s(&data, &dtaSaida2);
        std::string dia = std::to_string(data.tm_mday);
        std::string mes = std::to_string(data.tm_mon);
        std::string ano = std::to_string(data.tm_year);
        return dia + "/" + mes + "/" + ano;
    }
    std::string getDtaEntrada() {
        std::time_t dtaEntrada2 = std::chrono::system_clock::to_time_t(dtaEntrada);
        struct tm data;
        localtime_s(&data, &dtaEntrada2);
        std::string dia = std::to_string(data.tm_mday);
        std::string mes = std::to_string(data.tm_mon);
        std::string ano = std::to_string(data.tm_year);
        return dia + "/" + mes + "/" + ano;
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