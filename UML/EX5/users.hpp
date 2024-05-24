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
    void userOpc(std::vector<Usuario*> userVector, std::vector<Livro*> books, int bookId) {
        int opc;
        std::cout << "Digite a opção desejada:\n1 - listar empréstimos\n2 - Verificar livros disponíveis\n3 - Pegar livro\n4 - listar meus dados\n";
        std::cin >> opc;
        std::string titulobook;
        switch (opc) {
        case 1:
            listarEmprestimo();
            break;
        case 2:
            for (int i = 0; i < sizeof(books); i++) {
                if (books[i]->available) {
                    std::cout << "Título: " << books[i]->titulo << "\nData de publicação: " << books[i]->dtaPublic << "\nISBN: " << books[i]->isbn << "\nEditora: " << books[i]->editora << "\nGênero: " << "\n==============\n";
                }
            }
            break;
        case 3:
            std::cout << "Digite o livro desejado: ";
            std::cin >> titulobook;
            for (int i = 0; i < books.size(); i++) {
                if (titulobook == books[i]->titulo) {
                    makeEmprestimo(*books[i]);
                    std::cout << "Empréstimo realizado com sucesso!\n";
                    break;
                }
            }
        case 4:
            std::cout << "Nome: " << nome << "\nCPF: " << cpf << "\n";
            break;
        default:
            break;
        }
    }
protected:
    std::string cpf;
    std::string login;
    std::string senha;
    std::vector<Emprestimo*> emprestimo;
};
