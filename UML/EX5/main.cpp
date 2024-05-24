#include <iostream>
#include <vector>
#include <locale>
#include "admin.hpp"
#define juros = 2;


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

void cadastroUsuario(std::vector<Usuario*>& userVector, std::string adminPasswd) {
    std::string login;
    std::string senha;
    std::string confsenha;
    std::string cpf;
    std::string nome;
    char isAdmin;
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
    
    std::cout << "Você é admin? (S/N)";
    std::cin >> isAdmin;
    if (isAdmin == 's' || isAdmin == 'S') {
        std::string passwd;
        std::cout << "Digite a senha de administrador: ";
        std::cin >> passwd;
        if (passwd == adminPasswd) {
            Admin* newuser = new Admin();
            newuser->setLogin(login);
            newuser->setSenha(senha);
            newuser->setCpf(cpf);
            newuser->nome = nome;
            userVector.push_back(newuser);
        }
        else {
            std::cout << "Senha incorreta! Cadastrando como usuário comum.";
            Usuario* newuser = new Usuario();
            newuser->setLogin(login);
            newuser->setSenha(senha);
            newuser->setCpf(cpf);
            newuser->nome = nome;
            userVector.push_back(newuser);
        }
    }
    else {
        Usuario* newuser = new Usuario();
        newuser->setLogin(login);
        newuser->setSenha(senha);
        newuser->setCpf(cpf);
        newuser->nome = nome;
        userVector.push_back(newuser);
    }
}

void mazeopc(std::vector<Usuario*> userVector, std::vector<Livro*> books, int bookId, std::string adminPasswd) {
    int userId = -1;
    while (userId == -1) {
        if (logOpc() == 1) {
            userId = loginUsuario(userVector);
        }
        else {
            cadastroUsuario(userVector, adminPasswd);
        }
    }
    userVector[userId]->userOpc(userVector, books, bookId);
}

int main() {
    std::vector<Livro*> books;
    std::vector<Usuario*> userVector;
    int bookId = 0;
    const std::string adminPasswd = "admin";
    std::locale::global(std::locale("pt_BR.UTF-8"));
    std::cout << "** Bem-Vindo ao Library2000! **\n\n";
    mazeopc(userVector, books, bookId, adminPasswd);
    return 0;
}