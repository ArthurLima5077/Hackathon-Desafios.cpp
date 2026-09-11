#include <iostream>
#include <stack>
#include <string>

using namespace std;

void vizualizarHistorico(stack<string> p) {
    if (p.empty()) {
        cout << "Historico vazio." << endl;
        return;
    }
    cout << "--- Historico de Acoes (Mais recentes no topo) ---" << endl;
    while (!p.empty()) {
        cout << "- " << p.top() << endl;
        p.pop();
    }
    cout << "--------------------------------------------------" << endl;
}
int main() {
    stack<string> historico;
    int opcao;
    string acao;
    do {
        cout << "\n==== MENU ====" << endl;
        cout << "1 - Registrar acao" << endl;
        cout << "2 - Desfazer ultima acao" << endl;
        cout << "3 - Mostrar ultima acao" << endl;
        cout << "4 - Vizualizar historico" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Descreva a acao: ";
                cin.ignore();
                getline(cin, acao);
                historico.push(acao);
                cout << "Acao registrada!" << endl;
                break;
                
            case 2:
                if (!historico.empty()) {
                    cout << "Desfazendo: " << historico.top() << endl;
                    historico.pop();
                } else {
                    cout << "Nao ha acoes para desfazer!" << endl;
                }
                break;
                
            case 3:
                if (!historico.empty()) {
                    cout << "Ultima acao: " << historico.top() << endl;
                } else {
                    cout << "Nenhum historico disponivel." << endl;
                }
                break;
                
            case 4:
                vizualizarHistorico(historico);
                break;
                
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);
    
    return 0;

}
