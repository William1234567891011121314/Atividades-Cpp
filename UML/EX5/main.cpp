#include <iostream>
#include <vector>
#include <locale>
#include "users.hpp"
#define juros = 2;

std::vector<Livro> books;

int logOpc() {
    int opc;
    std::cout << "Digite uma opção:\n1 - Entrar\n2 - Cadastrar\n";
    std::cin >> opc;
    return opc;
}

int loginUsuario(std::vector<Usuario*>& userVector) {
    std::string login;
    std::string senha;
    std::cout << "Digite o seu login:\n";
    std::cin >> login;
    bool logon = false;
    bool pass = false;
    for (int i = 0; i < userVector.size(); i++) {
        if (userVector[i]->getLogin() == login) {
            logon = true;
            do {
                std::cout << "Digite a sua senha:\n";
                std::cin >> senha;
                if (userVector[i]->getSenha() == senha) {
                    std::cout << "==================\n\nVocê está logado como: " << userVector[i]->nome << "\n\n==================\n";
                    pass = true;
                    return i;
                }
                else {
                    std::cout << "\nSenha incorreta!\n";
                }
            } while (true);
        }
    }
    if (!logon) {
        std::cout << "Não há nenhum usuário com este login.";
        loginUsuario(userVector);
    }
}

void cadastroUsuario(std::vector<Usuario*>& userVector) {
    std::string login;
    std::string senha;
    std::string confsenha;
    std::string cpf;
    std::string nome;
    std::cout << "Digite o seu login:\n";
    std::cin >> login;
    std::cout << "Digite o seu CPF:\n";
    std::cin >> cpf;
    std::cout << "Digite o seu nome:\n";
    std::cin >> nome;
    do {
        std::cout << "Digite a sua senha:\n";
        std::cin >> senha;
        std::cout << "Confirme a sua senha:\n";
        std::cin >> confsenha;
    } while (senha != confsenha);
    Usuario* newuser = new Usuario();
    newuser->setLogin(login);
    newuser->setSenha(senha);
    newuser->setCpf(cpf);
    newuser->nome = nome;
    userVector.push_back(newuser);
}

void userOpc(int userId, std::vector<Usuario*> userVector) {
    int opc;
    std::cout << "Digite a opção desejada:\n1 - listar empréstimos\n2 - Verificar livros disponíveis\n3 - Pegar livro\n4 - listar meus dados\n";
    std::cin >> opc;
    std::string titulobook;
    switch (opc) {
        case 1:
            userVector[userId]->listarEmprestimo();
            break;
        case 2:
            for (int i = 0; i < sizeof(books); i++) {
                if (books[i].available) {
                    std::cout << "Título: " << books[i].titulo << "\nData de publicação: " << books[i].dtaPublic << "\nISBN: " << books[i].isbn << "\nEditora: " << books[i].editora << "\nGênero: " << books[i].genero << "\n==============\n";
                }
            }
        case 3:
            std::cout << "Digite o livro desejado: ";
            std::cin >> titulobook;
            for (int i = 0; i < books.size(); i++) {
                if (titulobook == books[i].titulo) {
                    userVector[userId]->makeEmprestimo(books[i]);
                    std::cout << "Empréstimo realizado com sucesso!\n";
                    break;
                }
            }
        case 4:
            std::cout << "Nome: " << userVector[userId]->nome << "\nCPF: " << userVector[userId]->getCpf() << "\n";
            break;
        default:
            break;
    }
}

void mazeopc(std::vector<Usuario*> userVector) {
    int userId = -1;
    while (userId == -1) {
        if (logOpc() == 1) {
            userId = loginUsuario(userVector);
        }
        else {
            cadastroUsuario(userVector);
        }
    }
    userOpc(userId, userVector);
}

int main() {
    std::vector<Usuario*> userVector;
    std::locale::global(std::locale("pt_BR.UTF-8"));
    std::cout << "** Bem-Vindo ao Library2000! **\n\n";
    mazeopc(userVector);
    return 0;
}