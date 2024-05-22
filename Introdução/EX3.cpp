#include <iostream>

class Retangulo {
    public:
        float area(){
            return alt * lar;
        }
        float per(){
            return 2*(alt+lar);
        }
        void setAlt(float a){
            alt=a;
        };
        void setLar(float l){
            lar=l;
        }
    private:
        float alt, lar;
};

int main() {
    Retangulo meuretangulo;
    float auxalt, auxlar;
    std::cout << "Digite a altura do retângulo: ";
    std::cin >> auxalt;
    std::cout << "Digite a largura do retângulo: ";
    std::cin >> auxlar;
    meuretangulo.setAlt(auxalt);
    meuretangulo.setLar(auxlar);
    std::cout << "A área do retângulo é: " << meuretangulo.area() << "\nO perímetro do retângulo é: " << meuretangulo.per();
    return 0;
};