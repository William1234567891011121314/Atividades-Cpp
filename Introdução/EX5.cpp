#include <iostream>

class Funcionario{
    public:
        float salcalc(float tax, float benef){
            return sal - (sal * tax) + benef;
        }
        void setAll(std::string _nome, std::string _cargo, float _sal){
            nome = _nome;
            sal = _sal;
            cargo = _cargo;
        }
    private:
        std::string nome;
        float sal;
        std::string cargo;
};

int main() {
    Funcionario f1;
    std::string auxNome, auxCargo;
    float auxSal, auxTax, auxBenef;
    std::cout << "Digite o nome do funcionário: ";
    std::cin >> auxNome;
    std::cout << "Digite o salário do funcionário: ";
    std::cin >> auxSal;
    std::cout << "Digite o cargo do funcionário: ";
    std::cin >> auxCargo;
    f1.setAll(auxNome, auxCargo, auxSal);
    std::cout << "Digite o percentual de imposto (sem %): ";
    std::cin >> auxTax;
    auxTax = auxTax / 100;
    std::cout << "Digite o valor total dos benefícios: ";
    std::cin >> auxBenef;
    std::cout << "O salário líquido do funcionário é de: " << f1.salcalc(auxTax, auxBenef);
    return 0;
};