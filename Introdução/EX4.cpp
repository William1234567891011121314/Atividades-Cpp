#include <iostream>

class Aluno{
    public:
        void setNota(int select, int _nota) {
            switch(select){
                case 1:
                    nota1 = _nota;
                    break;
                case 2:
                    nota2 = _nota;
                    break;
                case 3:
                    nota3 = _nota;
                    break;
            }
        }
        void setNome(std::string novonome){
            nome = novonome;
        }
        void setMatricula(int nova){
            matricula = nova;
        }
        float calcmedia() {
            return (nota1 + nota2 + nota3) / 3;
        }
    private:
        std::string nome;
        int matricula;
        float nota1;
        float nota2;
        float nota3;
};

int main() {
    Aluno aluno;
    int auxMat;
    float auxN1, auxN2, auxN3;
    std::string auxNome;
    std::cout << "Digite o nome do aluno: ";
    std::cin >> auxNome;
    aluno.setNome(auxNome);
    std::cout << "Digite a matrícula do aluno: ";
    std::cin >> auxMat;
    aluno.setMatricula(auxMat);
    std::cout << "Digite a primeira nota do aluno: ";
    std::cin >> auxN1;
    std::cout << "Digite a segunda nota do aluno: ";
    std::cin >> auxN2;
    std::cout << "Digite a terceira nota do aluno: ";
    std::cin >> auxN3;
    aluno.setNota(1, auxN1);
    aluno.setNota(2, auxN2);
    aluno.setNota(3, auxN3);
    std::cout << "A média final do aluno é de: " << aluno.calcmedia();
    if(aluno.calcmedia() >= 6){
        std::cout << "\nO aluno foi aprovado!";
    } else {
        std::cout << "\nO aluno foi reprovado!";
    }
    return 0;
};