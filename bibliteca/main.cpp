#include <iostream>

using namespace std;
struct livro
{
    char titulo[50];
    char autor [50];
    int paginas = 0;
    int ano_pub = 0;
    int id = 0;
    int quant_esto = 0;
    char nomes [100];
};
int cont = 0;

//Terminar escopo
void cadastro (struct livro livrovec[], int cont)
{
    int id = 0;
    char op[1];

        cout << "Digite o ID: ";
        cin >> livrovec[cont].id;
        for (int i = 0; i >=cont; i++)
        {
            if (livrovec[cont].id == livrovec[i].id)
                {
                        cout << "Digite a quantidade deste livro no estoque: ";
                        cin >> livrovec[cont].quant_esto;
                        if (livrovec[i].quant_esto > 10)
                            {
                                cout << "Limite atingido !";
                                return;
                            }



                }

                cout << "Digite o Titulo: ";
                cin.ignore();
                cin.getline(livrovec[cont].titulo,50);
                cout << "Digite o Autor: ";
                cin.getline(livrovec[cont].autor,50);
                cout << "Digite o numero de paginas : ";
                cin >> livrovec[cont].paginas;
                cout << "Digite o ano de publicacao: ";
                cin >> livrovec[cont].ano_pub;
               if (livrovec[cont].quant_esto == 0)
                cout << "Digite a quantidade deste livro no estoque: ";
                cin >> livrovec[cont].quant_esto;



            return;
        }


}

void consulta (struct livro livrovec[], int cont)

{

    cout << "Funcionou"<< endl;

}


void emprestimo (struct livro livrovec[], int cont)
{
    cout << "Agua mole pedra dura, tanto bate até q murta"<< endl;


}

void devolucao (struct livro livrovec[], int cont)
{

    cout << "Tio paulo, acorda tio paulo, voce precisa assinar "<< endl;


}

void remocao (struct livro livrovec[], int cont)
{

    cout << "To nem ai, to nem ai "<< endl;


}

int main()
{

    struct livro livrovec[cont];
    int op  =0;
    while (op !=6 ){
        cout<< "------------Seja Bem Vindo-----------"<< endl;
    cout << " "<<endl;
    cout << " "<<endl;
    cout << " "<<endl;

    cout << "Escolha a opcao desejada: "<< endl;
    cout << " "<<endl;
    cout << " 1. Cadastrar Livro \n "
            "2. Consultar Livro \n"
            " 3. Emprestimo de Livro \n"
            " 4. Devolucao de Livro \n"
            " 5. Remocao de Livro \n"
            " 6. Sair "<<endl;

    cout << "Digite aqui: ";
    cin >> op;


    if (op == 1)
    {
        cadastro(livrovec, cont);
    }

    if (op == 2)
    {
        if (cont == 0){

            cout << "Nao ha livros cadastrados"<< endl;
            continue;

        }

        else{
            consulta(livrovec, cont);

        }
    }

    if (op ==3)
    {
        emprestimo(livrovec, cont);
    }

    if (op ==4)
    {
        devolucao(livrovec, cont);
    }

    if (op ==5)
    {
        remocao(livrovec, cont);
    }


    }



}
