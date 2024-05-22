#include <iostream>
#include <vector>
#include "loan.hpp"
#include "book.hpp"

class Usuario {
public:
    Usuario() {}
    ~Usuario() {}
    std::string nome;
    std::string status;
    void setCpf(std::string _cpf) {
        cpf = _cpf;
    }
    void setLogin(std::string _login) {
        login = _login;
    }
    void setSenha(std::string _senha) {
        senha = _senha;
    }
    void makeEmprestimo(Livro novolivro) {
        Emprestimo* _emprestimo = new Emprestimo();
        emprestimo.push_back(_emprestimo);
    }
    std::string getCpf() {
        return cpf;
    }
    std::string getLogin() {
        return login;
    }
    std::string getSenha() {
        return senha;
    }
private:
    std::string cpf;
    std::string login;
    std::string senha;
    std::vector<Emprestimo*> emprestimo;
};

std::vector<Usuario*> userVector;