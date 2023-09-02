
#include <iostream>
#include <locale>
using namespace std;
struct idiomas {
    int cod_idioma;
    char desc[25];
    bool delet;

};
struct idiomasdex {
    int cod;
    int end;

};
struct licoes {
    int cod_licao;
    int cod_idioma;
    int total_nivel;
    bool delet;

};
struct licoesdex {
    int cod;
    int end;

};
struct exercicios {
    int cod_exercicio;
    int nivel_dificuldade;
    char perguntas[30]; 
    char resposta[30];
    float pontos;
    bool delet;
};
struct exerciciosdex {
    int cod;
    int end;


};
struct usuarios {
    int cod_usuario;
    char nome[30];
    int cod_idioma;
    int nivel_atual;
    float pontos_total;
    bool delet;
};
struct usuariosdex {
    int cod;
    int end;

};
void inseriridioma(idiomas duo [], idiomasdex lingo[], int g, int vet[]) {
    system("clear||cls");
    char fechar[2]; 
    cout << "-----------------------CADASTRAR IDIOMA-----------------------"<<endl;
    for (int i = vet[0];i < g; i++) {
        cout << "Por favor informe o código"<<endl;
        cin >> duo[i].cod_idioma;
        cout << "Por favor informe a descrição do idioma"<<endl;
        cin >> duo[i].desc;
        cin.ignore();
        cin.getline(duo[i].desc, 25);
        duo[i].delet = false;
        vet[0]++;
        cout << "Para caso deseje cadastrar outro idioma digite 'S' caso deseje finalizar a operação digite 'N' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }

}
void inserirlicao() {

}
void inserirexercicio() {

}
void inserirusuario() {

}
    int main()
{
        setlocale(LC_ALL, "portuguese");
        const int g = 10;
        int vet[4] = { 0 };
        int option = 0;
        idiomas idioma[g];
        idiomasdex idiomadex[g];
        while (true) {
            system("clear||cls");
            cout << "==============DUOLINGO==============" << endl;
            cout << "Para cadastrar algo digite 1" << endl;
            cin >> option;
            switch (option) {
            case 1:
                system("clear||cls");
                cout << "Para cadastrar idioma digite 1";
                cout << "Para sair digite 0";
                cin >> option;
                switch (option) {
                case 1:
                    inseriridioma(idioma, idiomadex, g, vet) {
                        break;
                case 0:
                    break;
                    }
                    break;
                }

            }

        };

}











// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
