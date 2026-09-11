#include <iostream>
#include <string>
using namespace std;

struct cliente{

    string nome;
    string pedido;
};


int main() {

    cliente clientes[3];

    //cadastro dos clientes
    for(int i = 0; i < 3; i++){
        cout << "Digite o nome do cliente " << i + 1 << ": ";
        cin >> clientes[i].nome;
        cout << "Digite o pedido do cliente " << i + 1 << ": ";
        cin >> clientes[i].pedido;

        cout << endl;
    }

    // Mostrar antes da ordenação
    cout << "Clientes antes da ordenacao: " << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Cliente: " << clientes[i].nome << ", Pedido: " << clientes[i].pedido << endl;
    }

   //Soluction Sort
    for (int i = 0; i < 3 - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < 3; j++){
            if (clientes[j].nome < clientes[menor].nome) {
                menor = j;
            }

            swap(clientes[i], clientes[menor]);

        }

    
} 

    cout << "\n=== Ordenação dos pedidos ===" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Cliente: " << clientes[i].nome << ", Pedido: " << clientes[i].pedido << endl;
    }


    return 0;

}
