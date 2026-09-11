#include <iostream>

using namespace std;

int main() {
    int tempos[] = {10, 12, 11, 15, 13};
    int n = 5;
    
    // 1. Variável para guardar o número de comparações
    int comparacoes = 0; 

    cout << "Tempos em segundos antes da ordenacao: ";
    for (int i = 0; i < n; i++) {
        cout << tempos[i] << " ";
    }
    cout << endl; 

    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        
        for (int j = i + 1; j < n; j++) {
            // 2. Incrementa a cada vez que o 'if' abaixo for testado
            comparacoes++; 
            
            if (tempos[j] < tempos[menor]) {
                menor = j;
            }
        }
        
        int temp = tempos[i];
        tempos[i] = tempos[menor];
        tempos[menor] = temp;
    }

    cout << "Tempos em segundos depois da ordenacao: ";
    for (int i = 0; i < n; i++) {
        cout << tempos[i] << " ";
    }
    cout << endl;

    cout << "Quantidade de comparacoes realizadas: " << comparacoes << endl;

    return 0;
}
