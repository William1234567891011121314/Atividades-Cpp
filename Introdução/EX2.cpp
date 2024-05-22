#include <iostream>

class ContaBancaria {
    public:
        void dep(){
            float depvl;
            std::cout << "Você tem R$" << sal << " na sua conta.\n" << "Valor a ser depositado: ";
            std::cin >> depvl;
            sal += depvl;
            std::cout << "Você depositou R$" << depvl << " na sua conta.\n" << "Agora você tem R$" << sal;
        };
        void saq(){
            float saqvl;
            std::cout << "Você tem R$" << sal << " na sua conta.\n" << "Valor a ser sacado: ";
            std:: cin >> saqvl;
            if(saqvl > sal){
                std::cout << "Você não tem saldo suficiente para realizar esta operação.";
                return;
            } else {
                sal -= saqvl;
                std::cout << "Você sacou R$" << saqvl << " na sua conta.\n" << "Agora você tem R$" << sal;
            }
        };
        void definirnome(std::string nm){
            nome = nm;
        };
        void definirnumconta(int num){
            numconta = num;
        };
    private:
        int sal = 0;
        int numconta;
        std::string nome;
};

int main() {
    ContaBancaria conta;
    std::string nm;
    char fun, aux;
    int num;
    std::cout << "Digite o seu nome:";
    std::cin >> nm;
    conta.definirnome(nm);
    std::cout << "Digite o número da sua conta:";
    std::cin >> num;
    conta.definirnumconta(num);
    do {
        std::cout << "Digite a função requerida (S para saque e D para depósito): ";
        std::cin >> fun;
        if(fun == 'S'){
            conta.saq();
        } else {
            conta.dep();
        };
        std::cout << "\nVocê quer continuar o programa? (S/N)";
        std::cin >> aux;
        if(aux == 'S'){
            aux = 1;
        } else {
            aux = 0;
        };
    } while(aux);
    return 0;
};