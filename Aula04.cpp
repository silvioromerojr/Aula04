/*PROGRAMACAO CIENTÍFICA - PEL216
 ALUNO: Silvio Romero de Araújo Júnior  RA: 118324-3
 PROFESSOR: Reinaldo Bianchi
 RELATORIO 4 - Métodos Numéricos: Descida de Gradiente
 PROGRAMA PARA O MÉTODO DE DESCIDA DE GRADIENTE*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MAX_ITERA 100   // Número máximo de iterações
#define ALFA 0.01       // Critério de convergência

//Função que se deseja encontrar o mínimo
double f(double x){
    //return ((x * x * x) - (2 * x * x) + 2);
    return x * x;
}

//Derivada da Função
double df(double x){
    //return ((3 * x * x) - (4 * x));
    return 2 * x;
}

int main(){
    double x[MAX_ITERA] = {2};  // Ponto de início da avaliação da função (x0)
    double grad[MAX_ITERA];     // Valor do Gradiente no ponto xi
    double y[MAX_ITERA];        // Valor da função no ponto xi
    double beta=0.1;            // Taxa de aprendizagem (beta)
    int i;                      // Número de iterações
    cout << "Ponto Inicial (x0): 2\n";
    
    
    //Laço incremento da taxa de aprendizagem (beta)
    for (beta=0.1 ; beta <= 1.0 ; beta += 0.1){
            cout << "\nTaxa de Aprendizagem (Beta): " <<  beta;
        
            //Laço para cálculo iterativo dos mínimos locais
            for(i = 0; i < MAX_ITERA ; i++){
                grad[i] = df(x[i]);  // Cálculo do Gradiente no Ponto xi
                y[i] = f(x[i]);      //
                cout << fixed;
                //Testa o critério convergência
                if(abs(grad[i]) < ALFA){
                    break;
                }
            
                x[i+1] = x[i] - beta * grad[i]; //Avaliação de f(x) no novo ponto x(i + 1)
            
        }
        
        //Testa se foi possível encontrar o mínimo local com o número de iteracões definido em MAX_ITERA
        if(i == MAX_ITERA){
            
            cout << "\nNão foi possível encontrar o mínimo da função com o número de iterações definido.\n\n";
        }
        
        else{
            
            cout << "\nMínimo Local = " << y[i] << "\t" << "No ponto: " << x[i] << "\nEncontrado na iteração: "  << i + 1 << endl;
        }
    }
    return 0;
}
