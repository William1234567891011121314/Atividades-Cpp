#include <iostream>
#include <vector>
#include <locale>
#define juros;

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
    void setEmprestimo(Emprestimo* _emprestimo) {

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
    std::vector<Emprestimo> emprestimo;
};

std::vector<Usuario*> objectVector;

class Emprestimo {
public:
    void setDtaSaida(std::string _dtaSaida) {
        dtaSaida = _dtaSaida;
    }
    void setDtaEntrada(std::string _dtaEntrada) {
        dtaEntrada = _dtaEntrada;
    }
    void setMulta(float _multa) {
        multa = _multa;
    }
    std::string getDtaSaida() {
        return dtaSaida;
    }
    std::string getDtaEntrada() {
        return dtaEntrada;
    }
    float getMulta() {
        return multa;
    }
protected:
    std::string dtaSaida;
    std::string dtaEntrada;
    float multa;
};

class Livro {
public:
    std::string titulo;
    std::string dtaPublic;
    std::string isbn;
    std::string editora;
    std::string genero = {};
};

class Autor {
public:
    std::string nome;
    std::string dtaNasc;
};

int logOpc() {
    int opc;
    std::cout << "Digite uma opção:\n1 - Entrar\n2 - Cadastrar";
    std::cin >> opc;
    return opc;
}

int loginUsuario(std::vector<Usuario*>& objectVector) {
    std::string login;
    std::string senha;
    std::cout << "Digite o seu login:\n";
    std::cin >> login;
    bool logon = false;
    bool pass = false;
    for (int i = 0; i < objectVector.size(); i++) {
        if (objectVector[i]->getLogin() == login) {
            logon = true;
            do {
                std::cout << "Digite a sua senha:\n";
                std::cin >> senha;
                if (objectVector[i]->getSenha() == senha) {
                    std::cout << "Você está logado como: " << objectVector[i]->nome;
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
        loginUsuario(objectVector);
    }
}

void cadastroUsuario(std::vector<Usuario*>& objectVector) {
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
        objectVector.push_back(newuser);
    }
}

void userOpc(int userId) {
    int opc;
    std::cout << "Digite a opção desejada:\n1 - listar empréstimos\n2 - Verificar livros disponíveis\n3 - Pegar livro\n5 - listar meus dados\n";
    std::cin >> opc;
    switch (opc){
        case 1:
            objectVector[userId]->get
    default:
        break;
    }
}

void mazeopc() {
    int userId = -1;
    while (userId != -1) {
        if (logOpc() == 1) {
            userId = loginUsuario(objectVector);
        }
        else {
            cadastroUsuario(objectVector);
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