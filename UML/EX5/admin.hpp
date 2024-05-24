#include <iostream>
#include <vector>
#include "users.hpp"

class Admin : public Usuario {
public:
    Admin() {};
    ~Admin() {};
	void userOpc(std::vector<Usuario*> userVector, std::vector<Livro*> books, int bookId) {
        int opc;
        std::string titulobook;
        bool rep = true;
        while(rep) {
            std::cout << "Digite a opção desejada:\n1 - listar empréstimos\n2 - Verificar livros disponíveis\n3 - Pegar livro\n4 - listar meus dados\n5 - Adicionar um livro\n6 - Remover um livro\n7 - Sair";
            std::cin >> opc;
            switch (opc) {
            case 1:
            {
                listarEmprestimo();
                break;
            }
            case 2:
            {
                for (int i = 0; i < sizeof(books); i++) {
                    if (books[i]->available) {
                        std::cout << "Título: " << books[i]->titulo << "\nData de publicação: " << books[i]->dtaPublic << "\nISBN: " << books[i]->isbn << "\nEditora: " << books[i]->editora << "\nGênero: " << "\n==============\n";
                    }
                }
                break;
            }
            case 3:
            {
                std::cout << "Digite o livro desejado: ";
                std::cin >> titulobook;
                for (int i = 0; i < books.size(); i++) {
                    if (titulobook == books[i]->titulo) {
                        makeEmprestimo(*books[i]);
                        std::cout << "Empréstimo realizado com sucesso!\n";
                        break;
                    }
                }
            }
            case 4:
            {
                std::cout << "Nome: " << nome << "\nCPF: " << cpf << "\n";
            }
            case 5:
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
                Livro* newlivro = new Livro();
                newlivro->titulo = titulo;
                newlivro->dtaPublic = dtaPublic;
                newlivro->isbn = isbn;
                newlivro->editora = editora;
                newlivro->id = bookId;
                ++bookId;
                books.push_back(newlivro);
                std::cout << "Cadastro realizado com sucesso!";
                break;
            }
            case 6:
            {
                int _bookId;
                std::cout << "Digite o id do livro a ser removido: ";
                std::cin >> _bookId;
                bool del = false;
                for (int i = 0; i < sizeof(books); i++) {
                    if (_bookId == books[i]->id) {
                        books[i]->~Livro();
                        std::cout << "Livro removido com sucesso!";
                        del = true;
                    }
                }
                if (!del) {
                    std::cout << "Não existe nenhum livro com este ID.";
                }
                break;
            }
            case 7:
            {
                rep = false;
                break;
            }
            }
        }
	}
};