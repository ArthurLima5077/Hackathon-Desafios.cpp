#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> pilha;
    string expressao;
    int valida = 1; // 1 significa VALIDA, 0 significa INVALIDA

    cout << "Digite a expressao matematica: ";
    getline(cin, expressao); 

    for (int i = 0; i < expressao.length(); i++) {
        
        // Testa a abertura de um por um
        if (expressao[i] == '(') {
            pilha.push(expressao[i]);
        }
        else if (expressao[i] == '[') {
            pilha.push(expressao[i]);
        }
        else if (expressao[i] == '{') {
            pilha.push(expressao[i]);
        }
        
        // Testa o fechamento de um por um (repetindo a mesma logica)
        else if (expressao[i] == ')') {
            if (pilha.size() == 0) {
                valida = 0;
                break;
            } else if (pilha.top() == '(') {
                pilha.pop();
            } else {
                valida = 0;
                break;
            }
        }
        else if (expressao[i] == ']') {
            if (pilha.size() == 0) {
                valida = 0;
                break;
            } else if (pilha.top() == '[') {
                pilha.pop();
            } else {
                valida = 0;
                break;
            }
        }
        else if (expressao[i] == '}') {
            if (pilha.size() == 0) {
                valida = 0;
                break;
            } else if (pilha.top() == '{') {
                pilha.pop();
            } else {
                valida = 0;
                break;
            }
        }
    }

    // Se a pilha ainda tem coisa dentro, deu erro
    if (pilha.size() > 0) {
        valida = 0;
    }

    cout << "\nExpressao: " << expressao << endl;
    
    // Testa a variável int 
    if (valida == 1) {
        cout << "Resultado: VALIDA (Balanceamento correto)" << endl;
    } else {
        cout << "Resultado: INVALIDA (Problema nos (), [] ou {})" << endl;
    }

    return 0;
}
