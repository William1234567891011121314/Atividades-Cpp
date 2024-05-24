#include <iostream>
#include <vector>
#include "loan.hpp"

class Usuario {
public:
    Usuario() {}
    ~Usuario() {}
    bool isAdmin;
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
        Emprestimo _emprestimo = Emprestimo(novoLivro);
        _emprestimo.setLivroEmprestado(novoLivro.titulo);
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
        for (int i = 0; i < emprestimo.size(); i++) {
            std::cout << "Titulo do livro: " << emprestimo[i].getLivroEmprestado() << "\nData de saida: " << emprestimo[i].getDtaSaida() << "\nData de entrega: " << emprestimo[i].getDtaEntrada() << "\n==============\n";
        }
    }
    bool adminOpc(std::vector<Livro>& books, int bookId) {
        int opc;
        std::cin >> opc;
        std::string titulobook;
        switch (opc) {
        case 1:
        {
            listarEmprestimo();
            return true;
            break;
        }
        case 2:
            for (int i = 0; i < books.size(); i++) {
                if (books[i].available) {
                    std::cout << "Titulo: " << books[i].titulo << "\nData de publicacao: " << books[i].dtaPublic << "\nISBN: " << books[i].isbn << "\nEditora: " << books[i].editora << "\n==============\n";
                }
            }
            return true;
            break;
        case 3:
            std::cout << "Digite o livro desejado: ";
            std::cin >> titulobook;
            for (int i = 0; i < books.size(); i++) {
                if (titulobook == books[i].titulo) {
                    makeEmprestimo(books[i]);
                    std::cout << "Emprestimo realizado com sucesso!\n";
                    break;
                }
            }
            return true;
        case 4:
            std::cout << "Nome: " << nome << "\nCPF: " << cpf << "\n";
            break;
        case 5:
            return false;
            break;
        case 6:
        {
            std::string titulo;
            std::string dtaPublic;
            std::string isbn;
            std::string editora;
            std::vector<std::string> genero;
            std::cout << "Digite o titulo do livro: ";
            std::cin >> titulo;
            std::cout << "Digite a data de publicacao do livro: ";
            std::cin >> dtaPublic;
            std::cout << "Digite o ISBN do livro: ";
            std::cin >> isbn;
            std::cout << "Digite a editora do livro: ";
            std::cin >> editora;
            Livro newlivro;
            newlivro.titulo = titulo;
            newlivro.dtaPublic = dtaPublic;
            newlivro.isbn = isbn;
            newlivro.editora = editora;
            newlivro.id = bookId;
            ++bookId;
            books.push_back(newlivro);
            std::cout << "Cadastro realizado com sucesso!\n";
            return true;
            break;
        }
        case 7:
        {
            int _bookId;
            std::cout << "Digite o id do livro a ser removido: ";
            std::cin >> _bookId;
            bool del = false;
            for (int i = 0; i < sizeof(books); i++) {
                if (_bookId == books[i].id) {
                    books[i].~Livro();
                    std::cout << "Livro removido com sucesso!";
                    del = true;
                }
            }
            if (!del) {
                std::cout << "Nao existe nenhum livro com este ID.";
            }
            break;
            return true;
        }
        }
    }
    void userOpc(std::vector<Usuario> &userVector, std::vector<Livro> &books, int bookId) {
        int opc;
        bool rep = true;
        while (rep) {    
            if (isAdmin) {
                std::cout << "Digite a opcao desejada:\n1 - listar emprestimos\n2 - Verificar livros disponiveis\n3 - Pegar livro\n4 - listar meus dados\n5 - Sair\n6 - Adicionar livro\n7 - Remover livro\n";
                rep = adminOpc(books, bookId);
            }
            else {
                std::cout << "Digite a opcao desejada:\n1 - listar emprestimos\n2 - Verificar livros disponiveis\n3 - Pegar livro\n4 - listar meus dados\n5 - Sair\n";
                std::cin >> opc;
                std::string titulobook;
                switch (opc) {
                case 1:
                    listarEmprestimo();
                    break;
                case 2:
                    for (int i = 0; i < sizeof(books); i++) {
                        if (books[i].available) {
                            std::cout << "Titulo: " << books[i].titulo << "\nData de publicacao: " << books[i].dtaPublic << "\nISBN: " << books[i].isbn << "\nEditora: " << books[i].editora  << "\n==============\n";
                        }
                    }
                    break;
                case 3:
                    std::cout << "Digite o livro desejado: ";
                    std::cin >> titulobook;
                    for (int i = 0; i < books.size(); i++) {
                        if (titulobook == books[i].titulo) {
                            makeEmprestimo(books[i]);
                            std::cout << "Empréstimo realizado com sucesso!\n";
                            break;
                        }
                    }
                case 4:
                    std::cout << "Nome: " << nome << "\nCPF: " << cpf << "\n";
                    break;
                case 5:
                    rep = false;
                default:
                    break;
                }
            }
        }
    }
protected:
    std::string cpf;
    std::string login;
    std::string senha;
    std::vector<Emprestimo> emprestimo;
};