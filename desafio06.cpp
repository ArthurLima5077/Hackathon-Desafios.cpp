*código 6*
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Paciente {
    string nome;
    int idade;
    int prioridade;
};

class FilaHospital {
private:
    queue<Paciente> filas[3];

public:
    void adicionarPaciente() {
        Paciente paciente;

        cout << "\nNome: ";
        cin.ignore();
        getline(cin, paciente.nome);

        cout << "Idade: ";
        cin >> paciente.idade;

        cout << "Prioridade (1 = maior, 3 = menor): ";
        cin >> paciente.prioridade;

        if (paciente.idade < 0) {
            cout << "Idade invalida!\n";
            return;
        }

        if (paciente.prioridade < 1 || paciente.prioridade > 3) {
            cout << "Prioridade invalida! Use valores de 1 a 3.\n";
            return;
        }

        // A prioridade 1 fica no índice 0,
        // prioridade 2 no índice 1 e prioridade 3 no índice 2.
        filas[paciente.prioridade - 1].push(paciente);

        cout << "Paciente adicionado com sucesso!\n";
    }

    void proximoAtendimento() {
        // Verifica primeiro a maior prioridade.
        for (int i = 0; i < 3; i++) {
            if (!filas[i].empty()) {
                Paciente paciente = filas[i].front();
                filas[i].pop();

                cout << "\n--- Proximo Atendimento ---\n";
                cout << "Nome: " << paciente.nome << endl;
                cout << "Idade: " << paciente.idade << endl;
                cout << "Prioridade: " << paciente.prioridade << endl;

                return;
            }
        }

        cout << "\nNao ha pacientes aguardando atendimento.\n";
    }

    void listarPacientes() {
        cout << "\n--- Pacientes na Fila ---\n";

        bool vazia = true;

        for (int i = 0; i < 3; i++) {
            if (!filas[i].empty()) {
                vazia = false;

                // Faz uma cópia para listar sem remover os pacientes.
                queue<Paciente> copia = filas[i];

                while (!copia.empty()) {
                    Paciente paciente = copia.front();
                    copia.pop();

                    cout << "Nome: " << paciente.nome
                         << " | Idade: " << paciente.idade
                         << " | Prioridade: " << paciente.prioridade
                         << endl;
                }
            }
        }

        if (vazia) {
            cout << "A fila esta vazia.\n";
        }
    }
};

int main() {
    FilaHospital fila;
    int opcao;

    do {
        cout << "\n============================\n";
        cout << "     TRIAGEM DE HOSPITAL\n";
        cout << "============================\n";
        cout << "1 - Adicionar paciente\n";
        cout << "2 - Proximo atendimento\n";
        cout << "3 - Listar pacientes\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                fila.adicionarPaciente();
                break;

            case 2:
                fila.proximoAtendimento();
                break;

            case 3:
                fila.listarPacientes();
                break;

            case 0:
                cout << "\nPrograma encerrado.\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while (opcao != 0);

    return 0;
}
