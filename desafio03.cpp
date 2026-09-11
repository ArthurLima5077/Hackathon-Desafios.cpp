#include <iostream>
#include <string>

using namespace std;

// Estrutura para armazenar informações de um jogador
struct jogador{
    string nome;
    int pontuacao;
};

int main() {

    jogador jogadores[3];

    //cadastro dos jogadores
    for(int i = 0; i < 3; i++){
        cout << "Digite o nome do jogador " << i + 1 << ": ";
        cin >> jogadores[i].nome;
        cout << "Digite a pontuacao do jogador " << i + 1 << ": ";
        cin >> jogadores[i].pontuacao;
   
        cout << endl;
    }

    // Mostrar antes da ordenação
    cout << "Jogadores antes da ordenacao: " << endl;
    for(int i = 0; i < 3; i++){
        cout << "Nome: " << jogadores[i].nome << ", Pontuacao: " << jogadores[i].pontuacao << endl;
    }   

    //Insertion Sort
      // Insertion Sort
    for (int i = 1; i < 3; i++) {

        jogador atual = jogadores[i];

        int j = i - 1;

        while (j >= 0 && jogadores[j].pontuacao <atual.pontuacao) {

            jogadores[j + 1] = jogadores[j];

            j--;
        }

        jogadores[j + 1] = atual;
    }

    // Mostrar depois da ordenacao
    cout << "\n=== DEPOIS DA ORDENACAO ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << jogadores[i].nome << " - "
             << jogadores[i].pontuacao << " pontos" << endl;
    }

    // Verificar empate
    cout << "\n=== VERIFICANDO EMPATES ===" << endl;

    for (int i = 0; i < 3 - 1; i++) {

        if (jogadores[i].pontuacao == jogadores[i + 1].pontuacao) {

            cout << "Empate entre "
                 << jogadores[i].nome
                 << " e "
                 << jogadores[i + 1].nome
                 << "!" << endl;

            cout << "Sera necessario aplicar um criterio de desempate."
                 << endl;
        }
    }

    return 0;
}
