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

void cadastro(struct livro livrovec[], int &conta)
{


    cout << "Digite o ID: ";
    cin >> livrovec[conta].id;
    for (int i = 0; i < conta; i++) {
        if (livrovec[conta].id == livrovec[i].id) {
            cout << "Livro já cadastrado" << endl;
            return;
        }
    }

    cout << "Digite a quantidade deste livro no estoque: ";
    cin >> livrovec[conta].quant_esto;

    if (livrovec[conta].quant_esto > 10) {
        cout << "Limite atingido!" << endl;
        return;
    }

    cout << "Digite o Titulo: ";
    cin.ignore();
    cin.getline(livrovec[conta].titulo, 50);
    cout << "Digite o Autor: ";
    cin.getline(livrovec[conta].autor, 50);
    cout << "Digite o numero de paginas: ";
    cin >> livrovec[conta].paginas;
    cout << "Digite o ano de publicacao: ";
    cin >> livrovec[conta].ano_pub;

    conta++;
    cout << "Livro cadastrado com sucesso!" << endl;

}

void consulta (struct livro livrovec[], int conta)

{
    char titulo [50];
    char opid [5];
    int id = 0;
    int op = 0;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << "O que voce gostaria de fazer ? " << endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << ""<< endl;
    cout << "1. Listar todos os livros \n"
            "2. Buscar livro"<< endl;
    cout << " "<<endl;
    cout << "Digite aqui: ";
    cin >> op;
    cin.ignore();

    if (op == 1)
    {
        for ( int i = 0; i < conta; i++)
        {

            cout << "ID: " << livrovec[i].id<<endl;
            cout << "Livro: " << livrovec[i].titulo<<endl;
            cout << "Autor: " << livrovec[i].autor<<endl;
            cout << "Publicacao: "<< livrovec[i].ano_pub<<endl;
            cout << "Quantidade no estoque: "<< livrovec[i].quant_esto<<endl;
            cout << " " << endl;
        }
        return;
    }
//arrumar cin das strings
    else if (op == 2)
    {
        cout << "Pesquisar com ID (S/N): ";
        cin.getline(opid,2);

        if(toupper(opid [0])== 'S')
        {
            cout << "Digite o ID: ";
            cin >> id;
            for (int i = 0; i < conta; i++) {
                if (id == livrovec[i].id) {
                    cout << "O livro é o: "<< livrovec[i].titulo << endl;
                    return;
                }
            }

        cout << "Livro nao encontrado !" << endl;
        return;


        }
        else if (toupper(opid [0])== 'N')
        {
           cout << "Digite o Nome do livro: ";
            cin.getline(titulo, 50);
            for (int i = 0; i < conta; i++)
            {
                if (titulo == livrovec[i].titulo)
                {
                    cout << "O livro encontrado !" << endl;
                    return;
                }
            }

            cout << "Livro nao encontrado !"<< endl;
            return;
        }

    }

}


void emprestimo (struct livro livrovec[], int conta)
{
    int id;
    cout << "Digite o ID: ";
            cin >> id;
            cin.ignore();
            for (int i = 0; i < conta; i++)
            {
                if (id == livrovec[i].id)
                {
                    if (livrovec[i].quant_esto != 0)
                    {
                        cout << "Nome do associado: ";
                        cin.getline(livrovec[i].nomes, 100);
                        livrovec[i].quant_esto--;
                        cout << "Emprestimo realizado com sucesso"<< endl;
                        return;
                    }
                    else
                    {
                        cout << "Nao ha este livro no estoque !"<<endl;
                        return;
                    }

                }
            }

 }
void devolucao (struct livro livrovec[], int conta)
{

 int id;
    cout << "Digite o ID: ";
            cin >> id;
            cin.ignore();
            for (int i = 0; i < conta; i++)
            {
                if (id == livrovec[i].id)
                {
                    if (livrovec[i].quant_esto != 0)
                    {
                        livrovec[i].quant_esto++;
                        cout << "Devolucao realizado com sucesso"<< endl;
                        return;
                    }
                    else
                    {
                        cout << "Não há livros no estoque !"<<endl;
                        return;
                    }

                }
            }


}

void remocao (struct livro livrovec[], int conta)
{
    char op [2];
    int id;
    cout << "Digite o ID: ";
    cin >> id;
    cin.ignore();
    for (int i = 0; i < conta; i++)
    {
        if (id == livrovec[i].id)
        {
            cout << "Livro encontrado !"<<endl;
            cout << "Deseja excluir ? (S/N)";
            cin.getline(op,2);

            if(toupper(op [0])== 'S')
            {
                for (int j = i; j < conta - 1; j++) {
                    livrovec[j] = livrovec[j + 1]; // Move os livros para a esquerda
                }
                conta--; // Diminui o número de livros
                cout << "Livro removido!";
                return;
            }
            else if (toupper(op [0])== 'N')
            {
                cout << "Processo cancelado !"<< endl;
                return;
            }
        }




    }
}





int main()
{

    struct livro livrovec[100];
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

        cadastro(livrovec, conta);
    }

    if (op == 2)
    {
        if (conta == 0)
            {

                cout << "Nao ha livros cadastrados"<< endl;
                continue;

            }

        else
            {
                consulta(livrovec, conta);

            }
    }

    if (op ==3)
    {
        if (conta == 0)
            {

                cout << "Nao ha livros cadastrados"<< endl;
                continue;

            }

        else
            {
                emprestimo(livrovec, conta);

            }

    }

    if (op ==4)
    {
        if (conta == 0)
            {

                cout << "Nao ha livros cadastrados"<< endl;
                continue;

            }

        else
            {
                devolucao(livrovec, conta);

            }

    }

    if (op ==5)
    {
        if (conta == 0)
            {

                cout << "Nao ha livros cadastrados"<< endl;
                continue;

            }

        else
            {
                remocao(livrovec, conta);

            }

    }


    }



}
