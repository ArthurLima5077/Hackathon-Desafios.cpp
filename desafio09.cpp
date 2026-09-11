#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<string> pilhaVoltar;
    stack<string> pilhaAvancar;
    
    // Variável para armazenar a página em que estamos no momento
    string paginaAtual = "Home"; 
    
    int opcao;
    string novaPagina;

    do {
        // Exibe a página atual no topo do menu, cumprindo o requisito de mostrar após cada comando
        cout << "\n======================================" << endl;
        cout << "Navegador - PAGINA ATUAL: [" << paginaAtual << "]" << endl;
        cout << "======================================" << endl;
        
        cout << "1 - VISITAR nova pagina" << endl;
        cout << "2 - VOLTAR" << endl;
        cout << "3 - AVANCAR" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o nome ou URL da pagina: ";
                cin.ignore();
                getline(cin, novaPagina);
                
                // 1. Guarda a página atual no histórico de voltar
                pilhaVoltar.push(paginaAtual);
                
                // 2. Vai para a nova página
                paginaAtual = novaPagina;
                
                // 3. Ao visitar nova página, a pilha de avanço deve ser limpa
                while (!pilhaAvancar.empty()) {
                    pilhaAvancar.pop();
                }
                
                cout << "Visitando nova pagina..." << endl;
                break;
                
            case 2:
                if (!pilhaVoltar.empty()) {
                    // Salva a página atual na pilha de avançar antes de sair dela
                    pilhaAvancar.push(paginaAtual);
                    
                    // A página atual vira a que estava no topo do histórico de voltar
                    paginaAtual = pilhaVoltar.top();
                    pilhaVoltar.pop();
                } else {
                    cout << "Erro: Nao ha historico para voltar!" << endl;
                }
                break;
                
            case 3:
                if (!pilhaAvancar.empty()) {
                    // Salva a página atual na pilha de voltar antes de avançar
                    pilhaVoltar.push(paginaAtual);
                    
                    // A página atual vira a que estava no topo da pilha de avançar
                    paginaAtual = pilhaAvancar.top();
                    pilhaAvancar.pop();
                } else {
                    cout << "Erro: Nao ha paginas para avancar!" << endl;
                }
                break;
                
            case 0:
                cout << "Saindo do navegador..." << endl;
                break;
                
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);
    
    return 0;
}
