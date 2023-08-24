
#include <iostream>
using namespace std;
struct idiomas {
    int cod_idioma;
    char desc[30];

};
struct idiomasdex {
    int cod;
    int end;

};
struct licoes {
    int cod_licao;
    int cod_idioma;
    int total_nivel;


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

};
struct usuariosdex {
    int cod;
    int end;

};
void inseriridioma() {

}
void inserirlicao() {

}
void inserirexercicio() {

}
void inserirusuario() {

}
    int main()
{
    std::cout << "Hello World!\n";
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
