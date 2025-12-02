#include <iostream>
#include "neural.hpp"

int main()
{
  MLP mlp(3, 5, 2, 0.01, 1000);
  // Chega o mouse na frente do init_weights pra ver o que aparece.
  mlp.init_weights();

  std::cout << "Hello, Ebsments!" << std::endl;
  return 0;
}
