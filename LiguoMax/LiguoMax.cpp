
/*Imagine que você foi contratado para criar um aplicativo de aprendizado de idiomas chamado "LingoMax". O aplicativo deve atender a pessoas que desejam aprender e praticar diferentes idiomas. Os usuários podem selecionar o idioma que desejam aprender e percorrer lições progressivas, incluindo vocabulário, exercícios gramaticais e testes de compreensão.

Para simular a estrutura de arquivos indexados, utilizaremos struct. Sendo assim, você deve:

Criar uma struct chamada Idiomas com as seguintes informações: Codigo, Descricao

Criar uma struct chamada Lições com as seguintes informações: Cod_Licao, Cod_Idioma, Total_Níveis

Criar uma struct chamada Exercícios com as seguintes informações: Cod_Exercicio, Nível_Dificuldade, Descricao, Resposta_Correta, Pontuação

Criar uma struct chamada Usuarios com as seguintes informações: Codigo, Nome, Código do Idioma de Aprendizado, Nível_Atual, Pontuação_Total

1) O programa deverá possuir funções específicas para a inclusão de novos dados nas tabelas, exclusão de dados, leitura exaustiva e reorganização das tabelas.

2) Ao manipular os dados da tabela Lições:

2.1) Ao informar/mostrar Cod_Idioma, o programa deverá exibir a descrição do Idioma

3) Ao manipular os dados da tabela Usuarios:

3.1) Ao informar o Código do Idioma de Aprendizado, o programa deverá exibir a Descrição do Idioma

4) O programa deverá permitir que os usuários pratiquem exercícios:

4.1) Os usuários somente poderão praticar exercícios com Nível de Dificuldade menor ou igual ao seu Nível Atual

4.2) Se o usuário responder o exercício corretamente, o programa deverá somar a Pontuação do exercício na Pontuação_Total do usuário

4.3) Se o usuário errar a resposta do exercício, o programa deverá subtrair 10% do valor da Pontuação do exercício na Pontuação_Total do usuário

4.4) Se o usuário atingir 100 pontos em determinado nível, ele poderá ser promovido ao próximo nível, adicionando uma unidade ao seu Nível_Atual

4.5) Se o usuário atingir o Total de Níveis da Lição, então terá concluído o estudo do idioma e poderá receber o Certificado de Proficiência

5) O programa deverá emitir o ranqueamento dos usuários, de acordo com a Pontuação_Total de cada um.*/
#include <iostream>
#include <locale>
#include <fstream>
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


//IDIOMA
void idiomaindex(idiomas idioma[], idiomasdex idiomadex[], int i, int vet[]) {
    int fim = vet[0] - 1;
    for (; fim >= 0 && idiomadex[fim].cod > idioma[i].cod_idioma; fim--) { //vai passar todo mundo que for maior uma pra tas
        idiomadex[fim + 1] = idiomadex[fim];
    }
    idiomadex[fim + 1].cod = idioma[i].cod_idioma;
    idiomadex[fim + 1].end = i;
}
void inseriridioma(idiomas idioma[], idiomasdex idiomadex[], int g, int vet[]) {
    system("clear||cls");
    char fechar[2];
    cout << "-----------------------CADASTRAR IDIOMA-----------------------" << endl;
    for (int i = vet[0];i < g; i++) {
        cout << "Por favor informe o codigo" << endl;
        cin >> idioma[i].cod_idioma;
        cout << "Por favor informe a descrição do idioma" << endl;
        cin >> idioma[i].desc;
        idiomaindex(idioma, idiomadex, i, vet);
        idioma[i].delet = false;
        vet[0]++;
        cout << "Para caso deseje cadastrar outro idioma digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }

}


//LICAO
void licaoindex(licoes licao[], licoesdex licaodex[], int i, int vet[]) {
    int fim = vet[1] - 1;
    for (; fim >= 0 && licaodex[fim].cod > licao[i].cod_licao; fim--) {
        licaodex[fim + 1] = licaodex[fim];
    }
    licaodex[fim + 1].cod = licao[i].cod_licao;
    licaodex[fim + 1].end = i;
}
void inserirlicao(licoes licao[], licoesdex licaodex[], int g, int vet[]) {
    system("clear||cls");
    char fechar[2];
    cout << "-----------------------CADASTRAR LIÇÃO-----------------------" << endl;
    for (int i = vet[1];i < g; i++) {
        cout << "Por favor informe o codigo" << endl;
        cin >> licao[i].cod_licao;
        cout << "Por favor informe o codigo do idioma" << endl;
        cin >> licao[i].cod_idioma;
        cout << "Por favor informe o total do nivel" << endl;
        cin >> licao[i].total_nivel;
        licaoindex(licao, licaodex, i, vet);
        licao[i].delet = false;
        vet[1]++;
        cout << "Para caso deseje cadastrar outra licao digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}


//exercicio
void exindex(exercicios ex[], exerciciosdex exdex[], int i, int vet[]) {
    int fim = vet[2] - 1;
    for (; fim >= 0 && exdex[fim].cod > ex[i].cod_exercicio; fim--) {
        exdex[fim + 1] = exdex[fim];
    }
    exdex[fim + 1].cod = ex[i].cod_exercicio;
    exdex[fim + 1].end = i;
}
void inserirexercicio(exercicios ex[], exerciciosdex exdex[], int g, int vet[]) {
    system("clear||cls");
    char fechar[2];
    cout << "-----------------------CADASTRAR EXERCICIO-----------------------" << endl;
    for (int i = vet[2];i < g; i++) {
        cout << "Por favor informe o codigo do exercicio" << endl;
        cin >> ex[i].cod_exercicio;
        cout << "Por favor informe o nivel de dificuldade do exercicio" << endl;
        cin >> ex[i].nivel_dificuldade;
        cout << "Por favor digite aqui sua pergunta" << endl;
        cin >> ex[i].perguntas;
        cout << "Por favor digite a resposta correta para a pergunta anterior" << endl;
        cin >> ex[i].resposta;
        cout << "Por favor digite quantos pontos vale essa pergunta" << endl;
        cin >> ex[i].pontos;
        exindex(ex, exdex, i, vet);
        ex[i].delet = false;
        vet[2]++;
        cout << "Para caso deseje cadastrar outras perguntas digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}
/*
struct usuarios {
    int cod_usuario;
    char nome[30];
    int cod_idioma;
    int nivel_atual;
    float pontos_total;
    bool delet;
};
*/

//usuario
void usuarioindex(usuarios usuario[],  usuariosdex usuariodex[], int i, int vet[]) {
    int fim = vet[2] - 1;
    for (; fim >= 0 && usuariodex[fim].cod > usuario[i].cod_usuario; fim--) {
        usuariodex[fim + 1] = usuariodex[fim];
    }
    usuariodex[fim + 1].cod = usuario[i].cod_usuario;
    usuariodex[fim + 1].end = i;
}
void inserirusuario(usuarios usuario[],  usuariosdex usuariodex[], int g, int vet[]) {
    system("clear||cls");
    char fechar[3];
    cout << "-----------------------CADASTRAR USUARIO-----------------------" << endl;
    for (int i = vet[2];i < g; i++) {
        cout << "Por favor informe o codigo do usuario" << endl;
        cin >> usuario[i].cod_usuario;
        cout << "Por favor informe o nome do usuario" << endl;
        cin >> usuario[i].nome;
        cout << "Por favor digite o codigo do idioma" << endl;
        cin >> usuario[i].cod_idioma;
        cout << "Por favor digite o nivel atual que voce esta" << endl;
        cin >> usuario[i].nivel_atual;
        cout << "Por favor digite quantos pontos atuais voce esta" << endl;
        cin >> usuario[i].pontos_total;
        usuarioindex(usuario, usuariodex, i, vet);
        usuario[i].delet = false;
        vet[3]++;
        cout << "Para caso deseje cadastrar outro usuario digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    const int g = 10;
    int vet[4] = { 0 };
    int option = 0;
    idiomas idioma[g];
    idiomasdex idiomadex[g];
    usuarios usuario[g];
    usuariosdex usuariodex[g];
    licoes licao[g];
    licoesdex licaodex[g];
    exercicios ex[g];
    exerciciosdex exdex[g];
    while (true) {
        system("clear||cls");
        cout << "==============DUOLINGO==============" << endl;
        cout << "Para cadastrar algo digite 1" << endl;
        cin >> option;
        switch (option) {
        case 1:
            system("clear||cls");
            cout << "Para cadastrar >idioma< digite 1" << endl;
            cout << "Para cadastrar >liçao< digite 2" << endl;
            cout << "Para cadastrar >exercicio< digite 3" << endl;
            cout << "Para cadastrar >usuarios< digite 4" << endl;
            cout << "Para sair digite 0" << endl;
            cin >> option;
            switch (option) {
            case 1:
                inseriridioma(idioma, idiomadex, g, vet);
                break;
            case 2:
                inserirlicao(licao, licaodex, g, vet);
                break;
            case 3:
                inserirexercicio(ex, exdex, g, vet);
                break;
            case 4:
                inserirusuario(usuario, usuariodex, g, vet);
                break;
            case 5:
                for (int i = 0; i < vet[1]; i++) {
                    cout << idiomadex[i].cod << endl;
                    cout << idiomadex[i].end << endl;
                    cout << "============================="<<endl;
                    /*
                    cout << licaodex[i].cod << endl;
                    cout << licaodex[i].end << endl;
                    cout << "=============================" << endl;
                    */
                }
                cin >> option;
                break;
            case 0:
                break;
            }
            break;


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