#include <iostream>
#include <vector>
#include <chrono>

class Emprestimo {
public: 
    Emprestimo() {
        multa = 0;
        dtaEntrada = std::chrono::system_clock::now();
        dtaSaida = dtaEntrada + std::chrono::hours(24*7*4);
    }
    ~Emprestimo() {};
    void setMulta(float _multa) {
        multa = _multa;
    }
    std::string getDtaSaida() {
        std::time_t dtaSaida2 = std::chrono::system_clock::to_time_t(dtaSaida);
        return std::ctime(&dtaSaida2);
    }
    std::string getDtaEntrada() {
        std::time_t dtaEntrada2 = std::chrono::system_clock::to_time_t(dtaEntrada);
        return std::ctime(&dtaEntrada2);
    }
    float getMulta() {
        return multa;
    }
protected:
    std::chrono::time_point<std::chrono::system_clock> dtaSaida;
    std::chrono::time_point<std::chrono::system_clock> dtaEntrada;
    float multa;
};