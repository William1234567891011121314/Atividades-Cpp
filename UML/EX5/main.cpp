#include <iostream>
#include <vector>
#include <locale>
#include "users.hpp"
#define juros = 2;

int logOpc() {
    int opc;
    std::cout << "Digite uma opção:\n1 - Entrar\n2 - Cadastrar";
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
                    std::cout << "Você está logado como: " << userVector[i]->nome;
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
    std::cout << "Digite a sua senha:\n";
    std::cin >> senha;
    std::cout << "Confirme a sua senha:\n";
    std::cin >> confsenha;
    std::cout << "Digite o seu CPF:\n";
    std::cin >> cpf;
    std::cout << "Digite o seu nome:\n";
    std::cin >> nome;
    if (confsenha == senha) {
        Usuario* newuser = new Usuario();
        newuser->setLogin(login);
        newuser->setSenha(senha);
        newuser->setCpf(cpf);
        newuser->nome = nome;
        userVector.push_back(newuser);
    }
}

void userOpc(int userId) {
    int opc;
    std::cout << "Digite a opção desejada:\n1 - listar empréstimos\n2 - Verificar livros disponíveis\n3 - Pegar livro\n5 - listar meus dados\n";
    std::cin >> opc;
    int 
    switch (opc){
        case 1:
            userVector[userId]->makeEmprestimo(userId);
    default:
        break;
    }
}

void mazeopc() {
    int userId = -1;
    while (userId != -1) {
        if (logOpc() == 1) {
            userId = loginUsuario(userVector);
        }
        else {
            cadastroUsuario(userVector);
        }
    }
    userOpc(userId);
}

int main() {
    std::locale::global(std::locale("pt_BR.UTF-8"));
    std::cout << "** Bem-Vindo ao Library2000! **\n\n";
    mazeopc();
    return 0;
}