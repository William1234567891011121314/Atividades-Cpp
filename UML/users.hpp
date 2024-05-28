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
    void devolverLivro(int empresId) {
        emprestimo[empresId].~Emprestimo();

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
            std::cout << "Título do livro: " << emprestimo[i].getLivroEmprestado() << "\nData de saída: " << emprestimo[i].getDtaSaida() << "\nData de entrega: " << emprestimo[i].getDtaEntrada() << "\n==============\n";
        }
    }
    void searchBookByTitle(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        std::string searchTitulo;
        std::cout << "Digite o título do livro que você proucura: ";
        std::cin >> searchTitulo;
        std::cout << "Livros disponíveis com este título:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).titulo == searchTitulo) {
                availableBooks.at(i).printBookInformation();
            }
        }
    }
    void searchBookByAuthor(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        std::string searchAuthor;
        std::cout << "Digite o nome completo do autor que você proucura: ";
        std::cin >> searchAuthor;
        std::cout << "Livros disponíveis produzidos por este autor:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).author == searchAuthor) {
                availableBooks.at(i).printBookInformation();
            }
        }
    }
    void searchBookByPublicationDate(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        std::string searchDtaPub;
        std::cout << "Digite a data de publicação que você proucura com a seguinte formatação dd/mm/aaaa: ";
        std::cin >> searchDtaPub;
        std::cout << "Livros disponíveis publicados nesta data:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).dtaPublic == searchDtaPub) {
                availableBooks.at(i).printBookInformation();
            }
        }
    }
    void searchBookByIsbn(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        std::string searchIsbn;
        std::cout << "Digite o ISBN do livro que você proucura com a devida formatação: ";
        std::cin >> searchIsbn;
        std::cout << "Livro disponível com este ISBN:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).isbn == searchIsbn) {
                availableBooks.at(i).printBookInformation();
                break;
            }
        }
    }
    void searchBookByPublishingCompany(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        std::string searchEditora;
        std::cout << "Digite a editora do livro que você proucura: ";
        std::cin >> searchEditora;
        std::cout << "Livros disponíveis desta editora:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).editora == searchEditora) {
                availableBooks.at(i).printBookInformation();
            }
        }
    }
    void searchBookById(std::vector<Livro>& availableBooks, std::vector<Livro>& books) {
        int searchId;
        std::cout << "Digite o ID do livro que você proucura:\n";
        std::cin >> searchId;
        std::cout << "Livro disponível com este ID:\n";
        for (int i = 0; i < availableBooks.size(); i++) {
            if (availableBooks.at(i).id == searchId) {
                availableBooks.at(i).printBookInformation();
            }
        }
    }
    void adminOpc(std::vector<Livro>& books, int& bookId, int opc) {
        bool emp = false;
        std::string titulobook;
        switch (opc) {
        case 7:
        {
            std::string titulo;
            std::string dtaPublic;
            std::string isbn;
            std::string editora;
            std::vector<std::string> genero;
            std::cout << "Digite o título do livro: ";
            std::cin >> titulo;
            std::cout << "Digite a data de publicação do livro: ";
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
            break;
        }
        case 8:
            int _bookId;
            std::cout << "Digite o ID do livro a ser removido: ";
            std::cin >> _bookId;
            bool del = false;
            int x;
            for (int i = 0; i < books.size(); i++) {
                if (_bookId == books[i].id) {
                    x = i;
                    books[i].~Livro();
                    std::cout << "Livro removido com sucesso!\n";
                    del = true;
                    break;
                }
            }
            if (!del) {
                std::cout << "Não existe nenhum livro com este ID.";
            }
            else {
                books.erase(books.begin() + x);
            }
            break;
        }
    }
    int userOpc(std::vector<Usuario>& userVector, std::vector<Livro>& books, int& bookId) {
        int opc;
        bool rep = true;
        while (rep) {
            std::cout << "Digite a opção desejada:\n1 - Listar empréstimos\n2 - Pesquisar livro\n3 - Realizar empréstimo\n4 - listar meus dados\n5 - Logoff\n6 - Devolver livro";
            if (isAdmin) {
                std::cout << "7 - Adicionar livro\n8 - Remover livro\n";
            }
            std::cin >> opc;
            if (isAdmin) {
                adminOpc(books, bookId, opc);
            }
            std::string titulobook;
            switch (opc) {
            case 1:
                listarEmprestimo();
                break;
            case 2:
            {
                int crit;
                std::vector<Livro> availableBooks;
                for (int i = 0; i < books.size(); i++) {
                    if (books[i].available) {
                        availableBooks.push_back(books[i]);
                    }
                }
                bool search = true;
                while (search) {
                    std::cout << "Você deseja pesquisar por qual critério?\n1 - Título\n2 - Autor\n3 - data de publicação\n4 - ISBN\n5 - Editora\n6 - ID do livro\n7 - Listar todos os livros disponíveis\n8 - Sair do buscador\n";
                    std::cin >> crit;
                    switch (crit) {
                    case 1:
                        searchBookByTitle(availableBooks, books);
                        break;
                    case 2:
                        searchBookByAuthor(availableBooks, books);
                        break;
                    case 3:
                        searchBookByPublicationDate(availableBooks, books);
                        break;
                    case 4:
                        searchBookByIsbn(availableBooks, books);
                        break;
                    case 5:
                        searchBookByPublishingCompany(availableBooks, books);
                        break;
                    case 6:
                        searchBookById(availableBooks, books);
                        break;
                    case 7:
                        for (int i = 0; i < availableBooks.size(); i++) {
                            availableBooks.at(i).printBookInformation();
                        }
                        break;
                    case 8:
                        search = false;
                        break;
                    default:
                        std::cout << "Opção inválida! Digite novamente:\n";
                        break;
                    }
                }
                break;
            }
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
                break;
            case 6:

            default:
                break;
            }
        }
        return -1;
    }
protected:
    std::string cpf;
    std::string login;
    std::string senha;
    std::vector<Emprestimo> emprestimo;
};