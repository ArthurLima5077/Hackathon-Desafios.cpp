#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct impressao {
    string usuario;
    int numeropag;
    string arquivo;
};
int main() {
    queue<impressao> filaImpressao;
    int opcao;

    do {
        cout << "\n============================\n";
        cout << "     FILA DE IMPRESSAO\n";
        cout << " 1 - Adicionar trabalho de impressao" << endl;
        cout << " 2 - imprimir proximo trabalho" << endl;
        cout << " 3 - mostrar os trabalhos na fila" << endl;
        cout << " 4 - mostrar paginas aguardando impressao" << endl;
        cout << " 5 - cancelar trabalho" << endl;
        cout << " 0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Digitação do usuário, número de páginas e nome do arquivo
        if (opcao == 1) {

            impressao impresso;

            cout << "Digite o nome do usuario: ";
            cin >> impresso.usuario;
          
            cout << "Digite o numero de paginas do trabalho: ";
            cin >> impresso.numeropag;
          
            cout << "Digite o nome do arquivo: ";
            cin >> impresso.arquivo;

            filaImpressao.push(impresso);

            cout << "Trabalho de impressao adicionado a fila!" << endl;
        }

        // imprimir o próximo trabalho da fila
        else if (opcao == 2) {

            if (filaImpressao.empty()) {

                cout << "\nA fila de impressao esta vazia. "
                     << "Nenhum trabalho para imprimir." << endl;

            } else {

                impressao proximoTrabalho = filaImpressao.front();

                filaImpressao.pop();

                cout << "\nImprimindo trabalho de impressao:" << endl;
                cout << "Usuario: " << proximoTrabalho.usuario << endl;
                cout << "Numero de paginas: "
                     << proximoTrabalho.numeropag << endl;
                cout << "Arquivo: "
                     << proximoTrabalho.arquivo << endl;

                cout << "Trabalho de impressao concluido!" << endl;
            }
        }

        // Exibição dos trabalhos na fila
        else if (opcao == 3) {

            if (filaImpressao.empty()) {

                cout << "\nA fila de impressao esta vazia." << endl;

            } else {

                cout << "\nTrabalhos na fila de impressao:" << endl;

                queue<impressao> copiaFila = filaImpressao;

                while (!copiaFila.empty()) {

                    impressao trabalho = copiaFila.front();

                    copiaFila.pop();

                    cout << "Usuario: " << trabalho.usuario
                         << ", Numero de paginas: "
                         << trabalho.numeropag
                         << ", Arquivo: "
                         << trabalho.arquivo << endl;
                }
            }
        }

        // calcular páginas
        else if (opcao == 4) {

            int totalPaginas = 0;

            queue<impressao> copiaFila = filaImpressao;

            while (!copiaFila.empty()) {

                impressao trabalho = copiaFila.front();

                totalPaginas += trabalho.numeropag;

                copiaFila.pop();
            }

            cout << "\nTotal de paginas aguardando impressao: "
                 << totalPaginas << endl;
        }

        // cancelar trabalho
        else if (opcao == 5) {

            string nomeArquivo;
            cout << "Digite o nome do arquivo a ser cancelado: ";
            cin >> nomeArquivo;

            queue<impressao> copiaFila;

            bool encontrado = false;

            while (!filaImpressao.empty()) {

                impressao trabalho = filaImpressao.front();

                filaImpressao.pop();

                if (trabalho.arquivo == nomeArquivo) {

                    encontrado = true;
                    cout << "Trabalho de impressao cancelado!"
                         << endl;

                } else {

                    copiaFila.push(trabalho);
                }
            }

            if (!encontrado) {

                cout << "Arquivo nao encontrado na fila de impressao."
                     << endl;
            }

            filaImpressao = copiaFila;
        }

        else if (opcao != 0) {

            cout << "Opcao invalida. Digite novamente." << endl;
        }

    } while (opcao != 0);

    cout << "Saindo do programa..." << endl;

    return 0;
}
