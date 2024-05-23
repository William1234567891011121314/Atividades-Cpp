#include <iostream>
#include <vector>
#include "loan.hpp"


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
    void makeEmprestimo(Livro novoLivro) {
        Emprestimo* _emprestimo = new Emprestimo(novoLivro);
        _emprestimo->setLivroEmprestado(novoLivro.titulo);
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
    void listarEmprestimo() {
        for (int i = 0; i < sizeof(emprestimo); i++) {
            std::cout << "Título do livro: " << emprestimo[i]->getLivroEmprestado() << "Data de saída: " << emprestimo[i]->getDtaSaida() << "Data de entrega: " << emprestimo[i]->getDtaEntrada() << "\n==============\n";
        }
    }
private:
    std::string cpf;
    std::string login;
    std::string senha;
    std::vector<Emprestimo*> emprestimo;
};