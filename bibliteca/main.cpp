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

int conta = 0;

//Terminar escopo
void cadastro (struct livro livrovec[], int conta)
{


        cout << "Digite o ID: ";
        cin >> livrovec[conta].id;
        for (int i = 0; i > conta; i++)
        {
            if (livrovec[conta].id == livrovec[i].id)
                {
                    cout << "Livro ja cadastrado"<<endl;
                        return;
                }

        }

                cout << "Digite a quantidade deste livro no estoque: ";
                        cin >> livrovec[conta].quant_esto;
                        if (livrovec[conta].quant_esto > 10)
                            {
                                cout << "Limite atingido !";
                                return;
                            }

                cout << "Digite o Titulo: ";
                cin.ignore();
                cin.getline(livrovec[conta].titulo,50);
                cout << "Digite o Autor: ";
                cin.getline(livrovec[conta].autor,50);
                cout << "Digite o numero de paginas : ";
                cin >> livrovec[conta].paginas;
                cout << "Digite o ano de publicacao: ";
                cin >> livrovec[conta].ano_pub;
               if (livrovec[conta].quant_esto == 0)
                cout << "Digite a quantidade deste livro no estoque: ";
                cin >> livrovec[conta].quant_esto;



            return;


}

void consulta (struct livro livrovec[], int conta)

{

    cout << "Funcionou"<< endl;

}


void emprestimo (struct livro livrovec[], int conta)
{
    cout << "Agua mole pedra dura, tanto bate at� q murta"<< endl;


}

void devolucao (struct livro livrovec[], int conta)
{

    cout << "Tio paulo, acorda tio paulo, voce precisa assinar "<< endl;


}

void remocao (struct livro livrovec[], int conta)
{

    cout << "To nem ai, to nem ai "<< endl;


}

int main()
{

    struct livro livrovec[conta];
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
        conta++;
        cadastro(livrovec, conta);
    }

    if (op == 2)
    {
        if (conta == 0){

            cout << "Nao ha livros cadastrados"<< endl;
            continue;

        }

        else{
            consulta(livrovec, conta);

        }
    }

    if (op ==3)
    {
        emprestimo(livrovec, conta);
    }

    if (op ==4)
    {
        devolucao(livrovec, conta);
    }

    if (op ==5)
    {
        remocao(livrovec, conta);
    }


    }



}
