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
#include <stdio.h>
#include<string.h>
#include<iomanip>



using namespace std;
#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"
struct idiomas {
    int cod_idioma;
    char desc[25];
    int status;

};
struct idiomasdex {
    int cod;
    int end;

};
struct licoes {
    int cod_licao;
    int cod_idioma;
    int total_nivel;
    int status;

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
    int status;
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
    int status;
};
struct usuariosdex {
    int cod;
    int end;

};


//*****************************IDIOMA*****************************
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
    printf(VERDE"-----------------------CADASTRAR IDIOMA-----------------------" RESET "\n");
    //cout << "-----------------------CADASTRAR IDIOMA-----------------------" << endl;
    for (int i = vet[0]; i < g; i++) {
        cout << "Por favor informe o codigo" << endl;
        cin >> idioma[i].cod_idioma;
        cout << "Por favor informe a descrição do idioma" << endl;
        cin >> idioma[i].desc;
        idiomaindex(idioma, idiomadex, i, vet);
        idioma[i].status = 0;
        vet[0]++;
        cout << "Para caso deseje cadastrar outro idioma digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }

}
void exaustivaidioma(struct idiomas idioma[], idiomasdex idiomadex[], int vet[]) {
    printf(VERDE"-----------------------LISTAGEM IDIOMA-----------------------" RESET "\n");
    cout << endl;
    printf(VERDE"Para sair digite 0" RESET "\n");

    for (int k = 0; k < vet[0]; k++) {
        int i = idiomadex[k].end;
        if (idioma[i].status == 0) {
            cout << "\nCodigo: " << idioma[i].cod_idioma;
            cout << "\tDesc: " << idioma[i].desc;
            cout << endl;

        }
    }
}
void buscaaleatidioma(struct idiomasdex idiomadex[], idiomas idioma[], int vet[]) {
    int cod;

    cout << "qual código você deseja excluir" << endl;
    cin >> cod;
    int i = 0, f = vet[0];
    int m = (i + f) / 2;
    for (; f >= i && cod != idiomadex[m].cod; m = (i + f) / 2) {
        if (cod > idiomadex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = idiomadex[m].end;
    if ((cod == idiomadex[m].cod) && idioma[i].status == 0) {
        idioma[i].status = 1;
        cout << "\n\n Idioma Excluido com Sucesso" << endl;
    }
    else
        cout << "Idioma nao cadastrado" << endl;

}
int buscaidioma(struct idiomasdex idiomadex[], idiomas idioma[], int vet[], int cod) {
    
    int i = 0, f = vet[0];
    int m = (i + f) / 2;
    for (; f >= i && cod != idiomadex[m].cod; m = (i + f) / 2) {
        if (cod > idiomadex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idiomadex[m].cod) {
        return idiomadex[m].end;
    }
    else
        return -1;
}

    void consulta_idioma(idiomas idioma[], int posic) {
        if (posic < 0) {
            cout << "Idioma não cadastrado, por favor refaça seu cadastro!" << endl;
        }
        else {
            if ((idioma[posic].status==0)) {
                cout << "O idioma escolhido foi: " << idioma[posic].desc << endl;
            }
            else {
                cout << "Idioma não cadastrado!" << endl;
                
            }
        }
    }

void reorganizar_idioma(struct idiomasdex idiomadex[], struct idiomasdex novoidiomadex[], struct idiomas idioma[], struct idiomas novoidioma[], int len[]) {
    int j = -1;

    for (int k = 0; k < len[0]; k++) {
        int i = idiomadex[k].end;
        if (idioma[i].status==0) {
            j++;
            novoidioma[j].cod_idioma = idioma[i].cod_idioma;
            strcpy_s(novoidioma[j].desc, idioma[i].desc);
            novoidioma[j].status = 0;
            novoidiomadex[j].cod = idioma[i].cod_idioma;
            novoidiomadex[j].end = i;
        }
    }
    for (int l = 0; l < len[0]; l++) {
        idioma[l].cod_idioma = NULL;
        strcpy_s(idioma[l].desc, "");
        idioma[l].status = 0;
        idiomadex[l].cod = NULL;
        idiomadex[l].end = NULL;
    len[0] = j + 1;
    }
    for (int l = 0; l < len[0]; l++) {
        idioma[l].cod_idioma = novoidioma[l].cod_idioma;
        strcpy_s(idioma[l].desc, novoidioma[l].desc);
        idioma[l].status = novoidioma[l].status;
        idiomadex[l].cod = novoidiomadex[l].cod;
       idiomadex[l].end = novoidiomadex[l].end;
    }
}






//*****************************LIÇÃO*****************************
void licaoindex(licoes licao[], licoesdex licaodex[], int i, int vet[]) {
    int fim = vet[1] - 1;
    for (; fim >= 0 && licaodex[fim].cod > licao[i].cod_licao; fim--) {
        licaodex[fim + 1] = licaodex[fim];
    }
    licaodex[fim + 1].cod = licao[i].cod_licao;
    licaodex[fim + 1].end = i;
}
void inserirlicao(licoes licao[], licoesdex licaodex[], int g, int vet[], idiomas idioma [], idiomasdex idiomadex []) {
    system("clear||cls");
    char fechar[2];
    printf(VERDE"-----------------------CADASTRAR LIÇÃO-----------------------" RESET "\n");
    //cout << "-----------------------CADASTRAR LIÇÃO-----------------------" << endl;
    for (int i = vet[1]; i < g; i++) {
        cout << "Por favor informe o codigo" << endl;
        cin >> licao[i].cod_licao;
        cout << "Por favor informe o codigo do idioma" << endl;
        cin >> licao[i].cod_idioma;
      consulta_idioma(idioma, buscaidioma(idiomadex, idioma, vet, licao[i].cod_idioma)); //idioma na posicao busca .ddex             
        cout << "Por favor informe o total do nivel" << endl;
        cin >> licao[i].total_nivel;
        licaoindex(licao, licaodex, i, vet);
        licao[i].status = false;
        vet[1]++;
        cout << "Para caso deseje cadastrar outra licao digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}
/*
struct licoes {
    int cod_licao;
    int cod_idioma;
    int total_nivel;
    int status;

};
*/
void exaustivalicao(licoes licao[], licoesdex licaodex[], int vet[]) {
    printf(VERDE"-----------------------LISTAGEM LIÇÃO-----------------------" RESET "\n");
    cout << endl;
    printf(VERDE"Para sair digite 0" RESET "\n");
    for (int k = 0; k < vet[1]; k++) {
        int i = licaodex[k].end;
        if (licao[i].status == 0) {
            cout << "\nCodigo da Licao: " << licao[i].cod_licao;
            cout << "\tCodigo do Idioma: " << licao[i].cod_idioma;
            cout << endl;
            cout << "Totais de niveis da licao: " << licao[i].total_nivel;
            cout << endl;
        }
    }
}

void buscaaleatlicao(licoesdex licaodex[], licoes licao[], int vet[]) {
    int cod;
    cout << "qual código você deseja excluir" << endl;
    cin >> cod;
    int i = 0, f = vet[1];
    int m = (i + f) / 2;
    for (; f >= i && cod != licaodex[m].cod; m = (i + f) / 2) {
        if (cod > licaodex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = licaodex[m].end;
    if ((cod == licaodex[m].cod) && licao[i].status == 0) {
        licao[i].status = 1;
        cout << "\n\n Lição Excluido com Sucesso" << endl;
    }
    else
        cout << "Lição nao cadastrado" << endl;

}


void reorganizar_licao(struct licoesdex licaoindex[], struct licoesdex novolicaodex[], struct licoes licao[], struct licoes novalicao[], int vet[]) {
    int j = -1;

    for (int k = 0; k < vet[1]; k++) {
        int i = licaoindex[k].end;
        if (licao[i].status == 0) {
            j++;
            novalicao[j].cod_licao = licao[i].cod_licao;
            novalicao[j].cod_idioma = licao[i].cod_idioma;
            novalicao[j].total_nivel = licao[i].total_nivel;
            novalicao[j].status = 0;
            novolicaodex[j].cod = novalicao[j].cod_licao;
            novolicaodex[j].end = j;
        }
    }
    for (int l = 0; l < vet[1]; l++) {
        licao[l].cod_licao = NULL;
        licao[l].cod_idioma = NULL;
        licao[l].total_nivel = NULL;
        licao[l].status = 0;
        licaoindex[l].cod = NULL;
        licaoindex[l].end = NULL;
    }
    vet[1] = j + 1;
    for (int l = 0; l < vet[1]; l++) {
        licao[l].cod_licao = novalicao[l].cod_licao;
        licao[l].cod_idioma = novalicao[l].cod_idioma;
        licao[l].total_nivel = novalicao[l].total_nivel;
        licao[l].status = novalicao[l].status;
        licaoindex[l].cod = novolicaodex[l].cod;
        licaoindex[l].end = novolicaodex[l].end;
    }
}



//*****************************EXERCÍCIO*****************************
void exindex(exercicios ex[], exerciciosdex exdex[], int i, int vet[]) {
    int fim = vet[2] - 1;
    for (; fim >= 0 && exdex[fim].cod > ex[i].cod_exercicio; fim--) { //3 maior que 1 entao entra no for
        exdex[fim + 1] = exdex[fim];
    }
    exdex[fim + 1].cod = ex[i].cod_exercicio; //caso nao seja vai receber o atual maior 
    exdex[fim + 1].end = i;
}
void inserirexercicio(exercicios ex[], exerciciosdex exdex[], int g, int vet[]) {
    system("clear||cls");
    char fechar[2];
    printf(VERDE"-----------------------CADASTRAR EXERCICIO-----------------------" RESET "\n");
    // cout << "-----------------------CADASTRAR EXERCICIO-----------------------" << endl;
    for (int i = vet[2]; i < g; i++) {
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
        ex[i].status = 0;
        vet[2]++;
        cout << "Para caso deseje cadastrar outras perguntas digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}
void exaustivaex(exercicios ex[], exerciciosdex exdex[], int vet[]) {
    printf(VERDE"-----------------------LISTAGEM EXERCÍCIO-----------------------" RESET "\n");
    cout << endl;
    printf(VERDE"Para sair digite 0" RESET "\n");
    for (int k = 0; k < vet[2]; k++) {
        int i = exdex[k].end;

        if (ex[i].status == 0) {
            cout << "\nCodigo do exercicio: " << ex[i].cod_exercicio;
            cout << "\tO nivel da dificuldade é: " << ex[i].nivel_dificuldade;
            cout << endl;
            cout << "A pergunta é: " << ex[i].perguntas;
            cout << endl;
            cout << "A resposta é: " << ex[i].resposta;
            cout << endl;
            cout << "A quantidade de pontos que vale essa pergunta é : " << ex[i].pontos;
            cout << endl;

        }
    }
}

void buscaaleatex(exerciciosdex exdex[], exercicios ex[], int vet[]) {
    int cod;
    cout << "qual código você deseja excluir" << endl;
    cin >> cod;
    int i = 0, f = vet[0];
    int m = (i + f) / 2;
    for (; f >= i && cod != exdex[m].cod; m = (i + f) / 2) {
        if (cod > exdex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = exdex[m].end;
    if ((cod == exdex[m].cod) && ex[i].status == 0) {
        ex[i].status = 1;
        cout << "\n\n Exercício Excluido com Sucesso" << endl;
    }
    else
        cout << "Exercício nao cadastrado" << endl;

}
void reorganizar_exercicio(struct exerciciosdex exdex[], struct exerciciosdex novoexdex[], struct exercicios ex[], struct exercicios novoex[], int vet[]) {
    int j = -1;

    for (int k = 0; k < vet[2]; k++) {
        int i = exdex[k].end;
        if (ex[i].status==0) {
            j++;
            novoex[j].cod_exercicio = ex[i].cod_exercicio;
            novoex[j].nivel_dificuldade = ex[i].nivel_dificuldade;
            novoex[j].pontos = ex[i].pontos;
            strcpy_s(novoex[j].perguntas, ex[i].perguntas);
            strcpy_s(novoex[j].resposta, ex[i].resposta);
            novoex[j].status = 0;
            novoexdex[j].cod = novoex[i].cod_exercicio;
            novoexdex[j].end = i;
        }
    }
    for (int l = 0; l < vet[2]; l++) {
        ex[l].cod_exercicio = NULL;
        ex[l].nivel_dificuldade = NULL;
        ex[l].pontos = NULL;
        strcpy_s(ex[l].perguntas, "");
        strcpy_s(ex[l].resposta, "");
        ex[l].status = 0;
        exdex[l].cod = NULL;
        exdex[l].end = NULL;
    }
    vet[2] = j + 1;
    for (int l = 0; l < vet[2]; l++) {
        ex[l].cod_exercicio = novoex[l].cod_exercicio;
        ex[l].nivel_dificuldade = novoex[l].nivel_dificuldade;
        ex[l].pontos = novoex[l].pontos;
        strcpy_s(ex[l].perguntas, novoex[l].perguntas);
        strcpy_s(ex[l].resposta, novoex[l].resposta);
        ex[l].status= novoex[l].status;
        exdex[l].cod = novoexdex[l].cod;
        exdex[l].end = novoexdex[l].end;
    }
}

int buscaex(exerciciosdex exdex[], exercicios ex[], int vet[], int cod) {

    int i = 0, f = vet[0];
    int m = (i + f) / 2;
    for (; f >= i && cod != exdex[m].cod; m = (i + f) / 2) {
        if (cod > exdex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == exdex[m].cod) {
        return exdex[m].end;
    }
    else
        return -1;
}

void consultaex(exercicios ex[], int posic) {
    if (posic < 0) {
        cout << "Idioma não cadastrado, por favor refaça seu cadastro!" << endl;
    }
    else {
        if ((ex[posic].status == 0)) {
            cout << "O idioma escolhido foi: " << ex[posic].cod_exercicio << endl;
        }
        else {
            cout << "Idioma não cadastrado, por favor  refaça seu cadastro!" << endl;

        }
    }
}



//*****************************USUARIO*****************************
void usuarioindex(usuarios usuario[], usuariosdex usuariodex[], int i, int vet[]) {
    int fim = vet[3] - 1;
    for (; fim >= 0 && usuariodex[fim].cod > usuario[i].cod_usuario; fim--) {
        usuariodex[fim + 1] = usuariodex[fim];
    }
    usuariodex[fim + 1].cod = usuario[i].cod_usuario;
    usuariodex[fim + 1].end = i;
}
void inserirusuario(usuarios usuario[], usuariosdex usuariodex[], int g, int vet[], idiomas idioma [], idiomasdex idiomadex[]) {
    system("clear||cls");
    char fechar[3];
    printf(VERDE"-----------------------CADASTRAR USUARIO-----------------------" RESET "\n");
    // cout << "-----------------------CADASTRAR USUARIO-----------------------" << endl;
    for (int i = vet[3]; i < g; i++) {
        cout << "Por favor informe o codigo do usuario" << endl;
        cin >> usuario[i].cod_usuario;
        cout << "Por favor informe o nome do usuario" << endl;
        cin >> usuario[i].nome;
        cout << "Por favor digite o codigo do idioma" << endl;
        cin >> usuario[i].cod_idioma;
        consulta_idioma(idioma, buscaidioma(idiomadex, idioma, vet, usuario[i].cod_idioma)); //idioma na posicao busca .ddex 
        cout << "Por favor digite o nivel atual que voce esta" << endl;
        cin >> usuario[i].nivel_atual;
        cout << "Por favor digite quantos pontos atuais voce esta" << endl;
        cin >> usuario[i].pontos_total;
        usuarioindex(usuario, usuariodex, i, vet);
        usuario[i].status = 0;
        vet[3]++;
        cout << "Para caso deseje cadastrar outro usuario digite 's' caso deseje finalizar a operação digite 'n' ";
        cin >> fechar;
        if (strcmp(fechar, "n") == 0) {
            return;
        }

    }
}
void exaustivausuario(usuarios usuario[], usuariosdex usuariodex[], int vet[]) {
    printf(VERDE"-----------------------LISTAGEM USUÁRIO-----------------------" RESET "\n");
    cout << endl;
    printf(VERDE"Para sair digite 0" RESET "\n");
    for (int k = 0; k < vet[3]; k++) {
        int i = usuariodex[k].end;
        if (usuario[i].status == 0) {
            cout << "\nCodigo do usuario: " << usuario[i].cod_usuario;
            cout << "\tNome do usuario: " << usuario[i].nome;
            cout << endl;
            cout << "O codigo do idioma: " << usuario[i].cod_idioma;
            cout << endl;
            cout << "O nivel atual: " << usuario[i].nivel_atual;
            cout << endl;
            cout << "A quantidade de pontos atuais: : " << usuario[i].pontos_total;
            cout << endl;

        }
    }
}
void buscaaleatusuario(usuariosdex usuariodex[], usuarios usuario[], int vet[]) {
    int cod;
    cout << "qual código você deseja excluir" << endl;
    cin >> cod;
    int i = 0, f = vet[3];
    int m = (i + f) / 2;
    for (; f >= i && cod != usuariodex[m].cod; m = (i + f) / 2) {
        if (cod > usuariodex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    i = usuariodex[m].end;
    if ((cod == usuariodex[m].cod) && usuario[i].status == 0) {
        usuario[i].status = 1;
        cout << "\n\n Usuario Excluido com Sucesso" << endl;
    }
    else
        cout << "Usuario nao cadastrado" << endl;

}
void reorganizar_usuario(usuariosdex usuariodex[], usuariosdex novousuariodex[],  usuarios usuario[],  usuarios novousuario[], int vet[]) {
    int j = -1;

    for (int k = 0; k < vet[3]; k++) {
        int i = usuariodex[k].end;
        if (usuario[i].status==0) {
            j++;
            novousuario[j].cod_usuario = usuario[i].cod_usuario;
            novousuario[j].cod_idioma = usuario[i].cod_idioma;
            novousuario[j].nivel_atual = usuario[i].nivel_atual;
            novousuario[j].pontos_total = usuario[i].pontos_total;
            strcpy_s(novousuario[j].nome, usuario[i].nome);
            novousuario[j].status = NULL;
            novousuariodex[j].cod = novousuario[i].cod_usuario;
            novousuariodex[j].end = i;
        }
    }
    for (int l = 0; l < vet[3]; l++) {
        usuario[l].cod_usuario = NULL;
        usuario[l].cod_idioma = NULL;
        usuario[l].nivel_atual = NULL;
        usuario[l].pontos_total = NULL;
        strcpy_s(usuario[l].nome, "");
        usuario[l].status = NULL;
        usuariodex[l].cod = NULL;
        usuariodex[l].end = NULL;
    }
    vet[3] = j + 1;
    for (int l = 0; l < vet[3]; l++) {
        usuario[l].cod_usuario = novousuario[l].cod_usuario;
        usuario[l].cod_idioma = novousuario[l].cod_idioma;
        usuario[l].nivel_atual = novousuario[l].nivel_atual;
        usuario[l].pontos_total = novousuario[l].pontos_total;
        strcpy_s(usuario[l].nome, novousuario[l].nome);
        usuario[l].status = novousuario[l].status;
        usuariodex[l].cod = novousuariodex[l].cod;
        usuariodex[l].end = novousuariodex[l].end;
    }
}
int buscausuario(usuariosdex usuariodex[], usuarios usuario[], int vet[], int cod) {

    int i = 0, f = vet[0];
    int m = (i + f) / 2;
    for (; f >= i && cod != usuariodex[m].cod; m = (i + f) / 2) {
        if (cod > usuariodex[m].cod)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == usuariodex[m].cod) {
        return usuariodex[m].end;
    }
    else
        return -1;
}

void consultausuario(usuarios usuario[], int posic) {
    if (posic < 0) {
        cout << "Idioma não cadastrado, por favor refaça seu cadastro!" << endl;
    }
    else {
        if ((usuario[posic].status == 0)) {
            cout << "O usuário escolhido foi: " << usuario[posic].nome << endl;
        }
        else {
            cout << "Usuario não cadastrado, por favor  refaça seu cadastro!" << endl;

        }
    }
}

//**********************************EXERCICIOS**********************************
void praticarex(exercicios ex[], exerciciosdex exdex[], usuarios usuario [], usuariosdex usuariodex[], int g, int vet []) {
    int y;
    int excod;
    int enderuser;
    char resposta[30];
    int endex;
    int palmeiras;
    system("clear||cls");
    
    printf(VERDE"-----------------------PRATICAR EXERCICIO-----------------------" RESET "\n");
      
        cout << "Digite seu código de usuario" << endl;
        cin >> y;
        enderuser = buscausuario(usuariodex, usuario, vet, y);
       consultausuario(usuario, buscausuario(usuariodex, usuario, vet,y)); //idioma na posicao busca .ddex
        cout << "Digite seu código de exercicio para começar a praticar" << endl;
         cin >> excod;
        consultaex(ex, buscaex(exdex, ex, vet, excod)); //idioma na posicao busca .ddex 
       endex = buscaex(exdex, ex, vet, excod);
       

   
    
      if (usuario[enderuser].nivel_atual>=ex[endex].nivel_dificuldade) {
          cout << ex[endex].perguntas;
          cin >> resposta;
          if (strcmp(resposta, ex[endex].resposta) == 0) {
              usuario[enderuser].pontos_total = usuario[enderuser].pontos_total + ex[endex].pontos;
              if (usuario[enderuser].pontos_total >= 100) {
                  usuario[enderuser].pontos_total = usuario[enderuser].pontos_total - 100;
                  usuario[enderuser].nivel_atual++;
                  
              }
              cout << "você acertou agora você tem " << usuario[enderuser].pontos_total << " pontos"<<endl;
              cin >>palmeiras;
          }
          else {
              usuario[enderuser].pontos_total = usuario[enderuser].pontos_total - (ex[endex].pontos * 0.1);
              cout << "voce errou, estuda mais"<<endl;
              cout << "você agora você tem " << usuario[enderuser].pontos_total << " pontos" << endl;
              cin >> palmeiras;
              
          }
      }
      else {
          cout << "Seu usuario ainda não está nesse nível, pratique mais."<<endl;
          return;
      }
      
}
//*****************************rankeamento*****************************
/*
void ranking(exercicios ex[], exerciciosdex exdex[], usuarios usuario[], usuariosdex usuariodex[], int g, int vet[]) {
    system("clear||cls");
    printf(VERDE"-----------------------RANK-----------------------" RESET "\n");
    int maior = 0;
    const int h = 10000;
    usuarios vetaux[h];
    int t = 0;
    
 
   
    for(int i=0; i < g; i++) {
        if (t == 0) {
            vetaux[i + 1].pontos_total = usuario[i].pontos_total;

        }
        else {
            vetaux[i].pontos_total = usuario[i].pontos_total;

            for (int j=0; j < t; j--) {
                if (usuario[i].pontos_total < vetaux[j].pontos_total) {
                    vetaux[i + 1].pontos_total = vetaux[i].pontos_total;
                    vetaux[0].cod_usuario = usuario[i].cod_usuario;
                    vetaux[0].cod_idioma = usuario[i].cod_idioma;
                    vetaux[0].nivel_atual = usuario[i].nivel_atual;
                    vetaux[0].pontos_total = usuario[i].pontos_total;
                }
            }
            cout << usuario[i].cod_usuario << endl;
            cin >> maior;
        }
    
    }
}

*/
void ordenarPorPontuacao(usuarios usuario[], int vet[]) {
    for (int i = 0; i < vet[3] - 1; i++) {
        for (int j = 0; j < vet[3] - i - 1; j++) {
            if (usuario[j].pontos_total < usuario[j + 1].pontos_total) {
                // Cria variável temporária para armazenar o usuário atual
                usuarios temp = usuario[j];
                // Copie o próximo usuário para a posição atual
                usuario[j] = usuario[j + 1];
                // Copie o usuário temporário (anterior) para a próxima posição
                usuario[j + 1] = temp;
            }
        }
    }
}


// Função para exibir o ranking dos usuários
void exibirRanking(usuarios usuario[], int vet[]) {
    // Ordena os usuários pelo campo Pontuação_Total
    ordenarPorPontuacao(usuario, vet);

    // Exibe o ranking em ordem decrescente
    printf(VERDE"-----------------------RANK-----------------------" RESET "\n");
    printf("%-10s%-20s%-15s%-15s\n", "Posição", "Nome", "Pontuação Total", "Nível Atual");

    for (int i = 0; i < vet[3]; i++) {
        printf("%-10d%-20s%-15.2f%-15d\n", i + 1, usuario[i].nome, usuario[i].pontos_total, usuario[i].nivel_atual);
    }
}

//*****************************MENU*****************************
int main()
{
  //  setlocale(LC_ALL, "pt_BR.UTF-8");
    const int g = 10;
    int vet[4] = { 0 };
    int option = 0;
    int pausa;
    //char op;
    idiomas idioma[g];
    idiomas novoidioma[g];
    idiomasdex idiomadex[g];
    idiomasdex novoidiomadex[g];

    usuarios usuario[g];
    usuariosdex usuariodex[g];
    usuarios novousuario[g];
    usuariosdex novousuariodex[g];

    licoes licao[g];
    licoesdex licaodex[g];
    licoes novalicao[g];
    licoesdex novalicaodex[g];

    exercicios ex[g];
    exerciciosdex exdex[g];
    exercicios novoex[g];
    exerciciosdex novoexdex[g];

    while (true) {
        system("clear||cls");
        //cout << "==============DUOLINGO==============" << endl;
        printf(VERDE"==============SASALINGO==============" RESET "\n");
        cout << "Para cadastrar algo digite 1" << endl;
        cout << "Para listagem de informações digite 2" << endl;
        cout << "Para exclusão de dados digite 3" << endl;
        cout << "Para ja seja cadastrado e queira praticar 4" << endl;
        cout << "Para acessar o rank 5" << endl;

        cin >> option;
        switch (option) {
        case 1:
            system("clear||cls");
            printf(VERDE"==============SASALINGO==============" RESET "\n");
            cout << "Para cadastrar >idioma< digite 1" << endl;
            cout << "Para cadastrar >lição< digite 2" << endl;
            cout << "Para cadastrar >exercicio< digite 3" << endl;
            cout << "Para cadastrar >usuarios< digite 4" << endl;
            cout << "Para sair digite 0" << endl;
            cin >> option;
            switch (option) {
            case 1:
                inseriridioma(idioma, idiomadex, g, vet);
                break;
            case 2:
                inserirlicao(licao, licaodex, g, vet, idioma, idiomadex);
                break;
            case 3:
                inserirexercicio(ex, exdex, g, vet);
                break;
            case 4:
                inserirusuario(usuario, usuariodex, g, vet, idioma, idiomadex);
                break;
           
            case 0:
                break;
            }
            break;
        case 2:
            printf(VERDE"=============LISTAGEM DE INFOS=================" RESET "\n");
            //cout<<"=============LISTAGEM DE INFORMAÇÕES================="<<endl;
            cout << "PARA LISTAR >IDIOMA< DIGITE 1" << endl;
            cout << "PARA LISTAR >LICAO< DIGITE 2" << endl;
            cout << "PARA LISTAR >EXERCICIO< DIGITE 3" << endl;
            cout << "PARA LISTAR >USUARIO< DIGITE 4" << endl;
            cout << "PARA SAIR DIGITE 0" << endl;
            cin >> option;

            switch (option) {
            case 1:
                system("clear||cls");
                exaustivaidioma(idioma, idiomadex, vet);
                cin >> pausa;
                break;
            case 2:
                system("clear||cls");
                exaustivalicao(licao, licaodex, vet);
                cin >> pausa;
                break;
            case 3:
                system("clear||cls");
                exaustivaex(ex, exdex, vet);
                cin >> pausa;
                break;
            case 4:
                system("clear||cls");
                exaustivausuario(usuario, usuariodex, vet);
                cin >> pausa;
                break;
            case 0:
                break;

            }

            break;
        case 3:
            printf(VERDE"=============EXCLUSÃO DE DADOS=================" RESET "\n");
            //cout<<"=============LISTAGEM DE INFORMAÇÕES================="<<endl;
            cout << "PARA EXCLUIR >IDIOMA< DIGITE 1" << endl;
            cout << "PARA EXCLUIR >LICAO< DIGITE 2" << endl;
            cout << "PARA EXCLUIR >EXERCICIO< DIGITE 3" << endl;
            cout << "PARA EXCLUIR >USUARIO< DIGITE 4" << endl;
            cout << "PARA SAIR DIGITE 0" << endl;
            cout << endl;
            cin >> option;
            switch (option) {
            case 1:
                buscaaleatidioma(idiomadex, idioma, vet);
                reorganizar_idioma(idiomadex, novoidiomadex, idioma, novoidioma, vet);
                cin >> pausa;
                break;
            case 2:
                buscaaleatlicao(licaodex, licao, vet);
                reorganizar_licao(licaodex, novalicaodex, licao, novalicao, vet);
                cin >> pausa;
                break;
            case 3:
                buscaaleatex(exdex, ex, vet);
                reorganizar_exercicio(exdex, novoexdex, ex, novoex, vet);
                cin >> pausa;
                break;
            case 4:
                buscaaleatusuario(usuariodex, usuario, vet);
                reorganizar_usuario(usuariodex, novousuariodex, usuario, novousuario, vet);
                cin >> pausa;
                break;
           
            case 0:
                break;
            }
            break;
        case 4:
            printf(VERDE"=============PRATICAR EXERCICIOS=================" RESET "\n");
            //cout<<"=============LISTAGEM DE INFORMAÇÕES================="<<endl;
            cout << "JA SOU CADASTRADO 1" << endl;
            cout << "NÃO TENHO CADASTRO 2" << endl;
            cout << "PARA SAIR DIGITE 0" << endl;
            cout << endl;
            cin >> option;
            switch (option) {
            case 1:
                praticarex(ex, exdex, usuario, usuariodex,  g, vet);
                break;
            case 2:
                inserirusuario(usuario, usuariodex, g, vet, idioma, idiomadex); 
                break;
            case 3:
                break;
            }
            break;
        case 5:
            printf(VERDE"===============RANK=================" RESET "\n");
            cout << "PARA VER RANK DIGITE 1" << endl;
           
            cout << "PARA SAIR DIGITE 0" << endl;
            cout << endl;
            cin >> option;
            switch (option) {
            case 1:
                //ranking(ex, exdex, usuario, usuariodex, g, vet);
                exibirRanking( usuario, vet);
                cin >> pausa;
                break;
            case 2:
                break;
            }
        }

    }; //fim do switch
    // return 0;//console
} //fim do main



/*
inicio int main(console
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
    */







    // Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
    // Depurar programa: F5 ou menu Depurar > Iniciar Depuração

    // Dicas para Começar: 
    //   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
    //   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
    //   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
    //   4. Use a janela Lista de Erros para exibir erros
    //   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
    //   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln