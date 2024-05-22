#include <iostream>

class Funcionario {
protected:
    std::string nome;
    float sal;
    std::string cargo;
public:
    float salcalc(float tax, float benef) {
        sal -= (sal * tax) + benef;
        return sal;
    }
    void setAll(std::string _nome, float _sal, std::string _Cargo) {
        nome = _nome;
        sal = _sal;
        cargo = _Cargo;
    }
    void addAumento(double valor) {
        sal += valor;
    }
    float ganhoAnual() {
        return sal * 12;
    }
};

class Assistente : public Funcionario {
public:
    void setMatricula(int novMat) {
        matricula = novMat;
    }
    int getMatricula() {
        return matricula;
    }
    void getDados() {
        std::cout << "Nome: " << nome << "\nSalário: " << "\nCargo: " << cargo << "\nMatrícula: " << matricula;
    }
    int matricula;
};

class Tecnico : public Assistente {
public:
    void setBonus(float novoBonus) {
        bonus = novoBonus;
    }
    float getBonus() {
        return bonus;
    }
    void getDados() {
        std::cout << "Nome: " << nome << "\nSalário: " << "\nCargo: " << cargo << "\nMatrícula: " << matricula << "\nBônus: " << bonus;
    }
    float salcalc(float tax, float benef) {
        sal -= (sal * tax) + benef + bonus;
        return sal;
    }
private:
    float bonus;
};

class Administrativo : public Assistente {
public:
    int getTurno() {
        return turno;
    }
    void setTurno(int novoTurno) {
        turno = novoTurno;
    }
    int getNoturno() {
        return addNoturno;
    }
    void setNoturno(float noturno) {
        addNoturno = noturno;
    }
    float salCalc(float tax, float benef) {
        sal -= (sal * tax) + benef + addNoturno;
        return sal;
    }
    void getDados() {
        std::cout << "Nome: " << nome << "\nSalário: " << sal<< "\nCargo: " << cargo << "\nMatrícula: " << matricula << "\nAdicional noturno: " << addNoturno;
    }
private:
    int turno;
    float addNoturno;
};

void cadastrarFuncionario(char opc) {
    Administrativo aa1;
    Tecnico at1;
    std::string auxNome;
    int auxCargo;
    float auxSal, auxTax, auxBenef, auxBonus;
    std::cout << "**Cadastro de funcionário**\n\nDigite o nome: \n";
    std::cin >> auxNome;
    std::cout << "Digite o salário: ";
    std::cin >> auxSal;
    std::cout << "Digite o percentual de imposto (sem %): ";
    std::cin >> auxTax;
    auxTax = auxTax / 100;
    std::cout << "Digite o valor total dos benefícios: ";
    std::cin >> auxBenef;
    std::cout << "Digite o cargo: \n1 - Assistente técnico\n2 - Assistente administrativo\n";
    std::cin >> auxCargo;
    switch (auxCargo) {
    case 1:
        at1.setAll(auxNome, auxSal, "Assistente Técnico");
        at1.salcalc(auxTax, auxBenef);
        std::cout << "Digite o bônus salarial: ";
        std::cin >> auxBonus;
        at1.setBonus(auxBonus);
        break;
    case 2:
        int auxMat;
        float auxNotur;
        aa1.setAll(auxNome, auxSal, "Assistente administrativo");
        std::cout << "Digite a sua matrícula: ";
        std::cin >> auxMat;
        std::cout << "Digite o valor do adicional noturno: ";
        std::cin >> auxNotur;
        aa1.setNoturno(auxNotur);
        aa1.setMatricula(auxMat);
        aa1.salcalc(auxTax, auxBenef);
    }
}

void modificarFuncionario() {
    Administrativo aa1;
    Tecnico at1;
    int opcint;
    double auxAumento;
    std::cout << "\nInsira a função desejada: \n\n1 - Manipular assistente técnico\n2 - Manipular assistente administrativo\n";
    std::cin >> opcint;
    std::cout << "\nInsira a função desejada: \n\n1 - Mostrar salário anual\n2 - Aumentar salário\n3 - Exibir dados\n";
    if (opcint == 1) {
        std::cin >> opcint;
        switch (opcint) {
        case 1:
            std::cout << "O salário anual é de: " << at1.ganhoAnual();
            break;
        case 2:
            std::cout << "Digite o aumento: ";
            std::cin >> auxAumento;
            at1.addAumento(auxAumento);
            break;
        case 3:
            at1.getDados();
            break;
        default:
            std::cout << "Opção inválida!";
        }
    }
    else {
        std::cin >> opcint;
        switch (opcint) {
        case 1:
            std::cout << "O salário anual é de: " << aa1.ganhoAnual();
            break;
        case 2:
            std::cout << "Digite o aumento: ";
            std::cin >> auxAumento;
            aa1.addAumento(auxAumento);
            break;
        case 3:
            aa1.getDados();
            break;
        default:
            std::cout << "Opção inválida!";
        }
    }
}

int main() {
    char cont, opc;
    do {
        do{
            std::cout << "Você deseja cadastrar um novo funcionário?\n";
            std::cin >> opc;
            cadastrarFuncionario(opc);
        } while(opc != 's' || opc != 'S');
        do{
            std::cout << "Deseja modificar algum funcionário? (S/N)\n";
            std::cin >> opc;
            modificarFuncionario();
        } while (opc == 's' || opc == 'S');
        std::cout << "\nVocê quer continuar o programa? (S/N): ";
        std::cin >> cont;
        if (cont == 's' || cont == 'S') {
        cont = 1;
        }
        else {
        cont = 0;
        }
    } while (cont);
    return 0;
};