#include <iostream>
#include <vector>
#include <windows.h>
#include <locale>
#include "users.hpp"
#define juros = 2;


int logOpc() {
    int opc;
    std::cout << "Digite uma opção:\n1 - Entrar\n2 - Cadastrar\n3 - Sair\n";
    std::cin >> opc;
    return opc;
}

int loginUsuario(std::vector<Usuario> &userVector) {
    std::string login;
    std::string senha;
    std::cout << "Digite o seu login:\n";
    std::cin >> login;
    bool logon = false;
    bool pass = false;
    for (int i = 0; i < userVector.size(); i++) {
        if (userVector[i].getLogin() == login) {
            logon = true;
            do {
                std::cout << "Digite a sua senha:\n";
                std::cin >> senha;
                if (userVector[i].getSenha() == senha) {
                    std::cout << "==================\n\nVocê está logado como: " << userVector[i].nome << "\n\n==================\n";
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

void cadastroUsuario(std::vector<Usuario> &userVector, std::string adminPasswd) {
    std::string login;
    std::string senha;
    std::string confsenha;
    std::string cpf;
    std::string nome;
    char opcIsAdmin;
    bool onlogin;
    do {
        onlogin = false;
        std::cout << "Digite o seu login:\n";
        std::cin >> login;
        for (int i = 0; i < userVector.size(); i++) {
            if (userVector[i].getLogin() == login) {
                std::cout << "Este login já existe!\n";
                onlogin = true;
            }
        }
    } while (onlogin);
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
    std::cin >> opcIsAdmin;
    bool boolIsAdmin = false;
    if (opcIsAdmin == 's' || opcIsAdmin == 'S') {
        std::string passwd;
        std::cout << "Digite a senha de administrador: ";
        std::cin >> passwd;
        if (passwd == adminPasswd) {
            boolIsAdmin = true;
        }
        else {
            boolIsAdmin = false;
        }
    }
    Usuario newuser;
    newuser.setLogin(login);
    newuser.setSenha(senha);
    newuser.setCpf(cpf);
    newuser.nome = nome;
    newuser.isAdmin = boolIsAdmin;
    userVector.push_back(newuser);
}

void mazeOpc(std::vector<Usuario> &userVector, std::vector<Livro> &books, int &bookId, std::string adminPasswd) {
    int userId = -1;
    int intlogOpc;
    while (userId == -1) {
        intlogOpc = logOpc();
        if (intlogOpc == 1) {
            userId = loginUsuario(userVector);
            userId = userVector.at(userId).userOpc(userVector, books, bookId);
        }
        else if (intlogOpc == 2) {
            cadastroUsuario(userVector, adminPasswd);
        }
        else {
            break;
        }
    }
}

int main() {
    //std::locale::global(std::locale("pt_BR.utf-8"));
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<Livro> books;
    std::vector<Usuario> userVector;
    int bookId = 0;
    const std::string adminPasswd = "admin";
    std::cout << "** Bem-Vindo ao Library2000!";
    SetConsoleTextAttribute(h, 6);
    std::cout << " Agora em unicode!";
    SetConsoleTextAttribute(h, 7);
    std::cout << " **\n\n";
    mazeOpc(userVector, books, bookId, adminPasswd);
    return 0;
}