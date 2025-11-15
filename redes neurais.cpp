// importar bibliotacas básicas do c++
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

class MLP {
  private:
    int entradas;
    int ocultas;
    int saidas;
    double bias;
    vector<vector<double>> pesos_entradas_para_ocultas;
    vector<vector<double>> pesos_ocultas_para_saidas;

  public:
    MLP(int entradas, int ocultas, int saidas) {
      this->entradas = entradas;
      this->ocultas = ocultas;
      this->saidas = saidas;
      this->bias = 1.0;
      // inicializar pesos com valores aleatórios
      pesos_entradas_para_ocultas.resize(entradas, vector<double>(ocultas));
      pesos_ocultas_para_saidas.resize(ocultas, vector<double>(saidas));
      inicializar_pesos();
    }

    // 1 - Atribui pesos para cada conexão entre camadas
    void inicializar_pesos() {
      for (int i = 0; i < entradas; i++) {
        for (int j = 0; j < ocultas; j++) {
          pesos_entradas_para_ocultas[i][j] = ((double) rand() / RAND_MAX);
        }
      }

      for (int i = 0; i < ocultas; i++) {
        for (int j = 0; j < saidas; j++) {
          pesos_ocultas_para_saidas[i][j] = ((double) rand() / RAND_MAX);
        }
      }
    }

    // 2 - Propagação para frente
    vector<double> feedpropagation(const vector<double>& entrada) {
      vector<double> ocultas_ativadas(ocultas);
      vector<double> saidas_ativadas(saidas);

      // Calcular ativações da camada oculta
      for (int j = 0; j < ocultas; j++) {
        double soma = 0.0;
        for (int i = 0; i < entradas; i++){
          soma += entrada[i] * pesos_entradas_para_ocultas[i][j];
        }

        soma += bias;
        ocultas_ativadas[j] = relu(soma);
      }

      // Calcular ativações da camada de saída
      for (int j = 0; j < saidas; j++) {
        double soma = 0.0;
        for (int i = 0; i < ocultas; i++) {
          soma += ocultas_ativadas[i] * pesos_ocultas_para_saidas[i][j];
        }
        soma += bias;
        saidas_ativadas[j] = sigmoid(soma);
      }
    }

    // 3 - função de ativação ReLU
    double relu(double x) {
      return x > 0 ? x : 0;
    }

    // 4 - Função de ativação sigmóide
    double sigmoid (double x) {
      return 1 / (1 + exp(-x));
    }

    double sigmoid_derivada(double fx) {
      return fx * (1 - fx);
    }

    // 5 - função de calculo do erro
    double erro_quadratico_medio(const vector<double>& real, const vector<double>& estimado) {
      double erro = 0.0;
      for (size_t i = 0; i < real.size(); i++) {
        erro += pow(real[i] - estimado[i], 2) / 2;
      }
      return erro;
    }

    // 6 - função de retorno do erro para ajustar os pesos
    vector<double> backpropagation(const vector<double> &entrada, const vector<double>&){

    }
};