#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Produto {
    int codigo;
    string nome;
    double preco;
    int estoque;
};

// criterio:
// 1 = preço crescente
// 2 = nome alfabético
// 3 = estoque decrescente
// ---------------------------------------------------------

bool deveTrocar(Produto a, Produto b, int criterio)
{

    if (criterio == 1)
    {
        // Ordena do menor preço para o maior
        return a.preco > b.preco;
    }

    if (criterio == 2)
    {
        // Ordena o nome em ordem alfabética
        return a.nome > b.nome;
    }

    if (criterio == 3)
    {
        // Ordena do maior estoque para o menor
        return a.estoque < b.estoque;
    }

    return false;
}

// ---------------------------------------------------
// INSERTION SORT
// 
// O algoritmo percorre a lista e insere cada elemento
// na posição correta em relação aos elementos anteriores.
long long insertionSort(Produto lista[], int n, int criterio) {
    
    long long comparacoes = 0;

    // Começamos pelo segundo elemento,
    // pois o primeiro já pode ser considerado ordenado.
    for (int i = 1; i < n; i++)
    {

        Produto atual = lista[i];

        int j = i - 1;

        // Move os elementos maiores para a direita
        while (j >= 0)
        {

            comparacoes++;

            if (deveTrocar(lista[j], atual, criterio))
            {
                lista[j + 1] = lista[j];
                j--;
            }
            else
            {
                break;
            }
        }

        // Coloca o elemento na posição correta
        lista[j + 1] = atual;
    }

    return comparacoes;
}

// ---------------------------------------------------------
// SELECTION SORT
//
// O algoritmo procura o menor/maior elemento restante
// e coloca esse elemento na posição atual.
// A comparação muda de acordo com o critério escolhido.
long long selectionSort(Produto lista[], int n, int criterio)
{

    long long comparacoes = 0;

    for (int i = 0; i < n - 1; i++)
    {

        int posicao = i;

        // Procura o próximo elemento que deve ocupar
        // a posição atual.
        for (int j = i + 1; j < n; j++)
        {

            comparacoes++;

            if (deveTrocar(lista[posicao], lista[j], criterio))
            {
                posicao = j;
            }
        }

        // Realiza a troca somente se encontrou
        // um elemento diferente para colocar na posição.
        if (posicao != i)
        {

            Produto temp = lista[i];
            lista[i] = lista[posicao];
            lista[posicao] = temp;
        }
    }

    return comparacoes;
}

// ---------------------------------------------------------
// Função para mostrar os produtos
// ---------------------------------------------------------
void mostrarProdutos(Produto lista[], int n)
{

    cout << "\n";
    cout << left << setw(10) << "Codigo" << setw(20) << "Nome" << setw(12) << "Preco" << setw(10) << "Estoque" << endl;

    cout << "----------------------------------------------------\n";

    for (int i = 0; i < n; i++)
    {

        cout << left
            << setw(10) << lista[i].codigo
            << setw(20) << lista[i].nome
            << setw(12) << fixed << setprecision(2) << lista[i].preco
            << setw(10) << lista[i].estoque
            << endl;
    }
}

// ---------------------------------------------------------
// Função principal
// ---------------------------------------------------------
int main()
{

    int n;

    cout << "\n\nQuantidade de produtos: ";
    cin >> n;

    Produto lista[n];

    // ---------------------------------------------
    // Entrada dos produtos
    for (int i = 0; i < n; i++)
    {

        cout << "\nProduto " << i + 1 << endl;

        cout << "Codigo: ";
        cin >> lista[i].codigo;

        cout << "Nome: ";
        cin >> lista[i].nome;

        cout << "Preco: ";
        cin >> lista[i].preco;

        cout << "Estoque: ";
        cin >> lista[i].estoque;
    }

    // ---------------------------------------------
    // Escolha do critério de ordenação
    int criterio;

    cout << "\n===== CRITERIO DE ORDENACAO =====\n";
    cout << "1 - Preco crescente\n";
    cout << "2 - Nome alfabetico\n";
    cout << "3 - Estoque decrescente\n";
    cout << "Escolha: ";
    cin >> criterio;

    // ---------------------------------------------
    // Criamos duas cópias da lista original.
    // Isso é importante porque queremos comparar
    // os dois algoritmos utilizando exatamente
    // a mesma entrada.
    // ---------------------------------------------

    Produto listaInsertion[n];
    Produto listaSelection[n];

    for (int i = 0; i < n; i++) {
        listaInsertion[i] = lista[i];
        listaSelection[i] = lista[i];
    }

    // ---------------------------------------------
    // Executa o Insertion Sort
    long long comparacoesInsertion =
        insertionSort(listaInsertion, n, criterio);

    // ---------------------------------------------
    // Executa o Selection Sort
    long long comparacoesSelection =
        selectionSort(listaSelection, n, criterio);

    // ---------------------------------------------
    // Mostra o resultado do Insertion Sort
    cout << "\n\n===== RESULTADO - INSERTION SORT =====\n";

    mostrarProdutos(listaInsertion, n);
    cout << "\nNumero de comparacoes: "
        << comparacoesInsertion << endl;

    // ---------------------------------------------
    // Mostra o resultado do Selection Sort
    cout << "\n\n===== RESULTADO - SELECTION SORT =====\n";
    mostrarProdutos(listaSelection, n);

    cout << "\nNumero de comparacoes: "
        << comparacoesSelection << endl;

    // ---------------------------------------------
    // Comparação entre os algoritmos
    cout << "\n\n===== COMPARACAO =====\n";
    if (comparacoesInsertion < comparacoesSelection) {
        cout << "Insertion Sort realizou menos comparacoes.\n"
            << endl;
    }
    else if (comparacoesSelection < comparacoesInsertion) {
        cout << "Selection Sort realizou menos comparacoes.\n"
            << endl;
    }
    else {
        cout << "Os dois algoritmos realizaram a mesma "
            << "quantidade de comparacoes.\n"
            << endl;
    }

    return 0;
}
