#include <iostream>
#define pi 3.14

class Circulo {
  public:
    float area(float raio) const{
      return pi * raio * raio;
    }
    float perimetro(float raio) const{
      return 2 * raio * pi;
    }
  private:
    float raio;
};

int main() {
  Circulo raio;
  float r;
  std::cout << "Digite o raio do circulo: ";
  std::cin >> r;
  std::cout << "A area do circulo é: " << raio.area(r) << "\nA area do circulo é: " << raio.perimetro(r);
}