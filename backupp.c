#include <stdio.h>
#include <stdlib.h>

#define TAMANHOVETOR 50

int main()
{
    /*VARIAVEIS*/
    int indice = 1;
    int idVoo[TAMANHOVETOR], qtdeAssentos[TAMANHOVETOR];
    char *nomeVoo[TAMANHOVETOR];
    int op;
    char nome[TAMANHOVETOR][255];

    op = 0;
    int voo[50], aeronave[50];
    void printVoo(int id,char *msg){
    printf("Identificador do voo: %d\n",idVoo[id]);
    printf("Quantidade de assentos: %d\n",qtdeAssentos[id]);
    printf("Voo nome: %s\n",nome[id]);
    printf("Voo %s com sucesso\n",msg);
    printf("Tecle enter para retornar ao menu %c\n");
    getchar();
    scanf("c\n");
}
    void limparVetorVoo(){
    for(int i = 0; i < 50; i++){
        idVoo[i] = NULL;
        qtdeAssentos[i] = NULL;
    }
}
int pegaPosicaoLimpaNoVetorVoo(){
    for(int i = 0; i < 50;i++){
        if(idVoo[i] == NULL)
            return i;
    }
    return -1;
}
void excluirVoo(int id){
    idVoo[id] = NULL;
    qtdeAssentos[id] = NULL;
}

    int pegaPosicaoVooParaEditar(int cod){
    for(int i = 0; i < 50; i++){
        if(idVoo[i] == cod){
            return i;
        }
    }
    return -1;
}
    void atualizarVoo(){
    system("clear");
    printf("AEROPORTO/VOO/CADASTRAR\n");
    if(pegaPosicaoLimpaNoVetorVoo() < 0){
        printf("Limite maximo de 50 voos ja cadastrado...");
        return;
    }
    indice = pegaPosicaoLimpaNoVetorVoo();
    printf("Digite 6 para voltar \n");
    printf("Digite o identificador do voo: \n");
    scanf("%d",&idVoo[indice]);
    printf("Digite o quantidade de assentos do voo: \n");
    scanf("%d",&qtdeAssentos[indice]);
    if(qtdeAssentos[indice] == 6){
        excluirVoo(indice);
        return;
    }
    printVoo(indice,"atualizado");
    op = 1;

}


    void editarVoo(){
    int id = 0;
    system("clear");
    printf("AEROPORTO/VOO/EDITAR\n");
    printf("Digite o identificador do voo que deseja alterar: ");
    scanf("%d",&id);
    if(id > 0){
        if(pegaPosicaoVooParaEditar(id) > 0){
            atualizarVoo();
        }
    }
}
    int totalVooCadastrado(){
    int aux = 0;
    for(int i = 0; i < 50; i++){
        if(idVoo[i] != NULL)
            aux++;
    }
    return aux;
}
    void cabecalhoPrimario(){
    system("clear");
    printf("AEROPORTO\n");
    printf("Digite uma opcao\n");
    printf("1 - Voos\n");
    printf("2 - Aeronave\n");
    printf("3 - Passageiros\n");
    printf("4 - Banco\n");
    printf("5 - Sair\n");
    printf("Total de voo cadastrado: %d\n", totalVooCadastrado());
    scanf("%d",&op);
}
void cabecalhoCadastrarVoo(){
    system("clear");
    printf("AEROPORTO/VOO\n");
    printf("Digite uma opcao\n");
    printf("1 - Inlcuir\n");
    printf("2 - Editar\n");
    printf("3 - Excluir\n");
    printf("4 - Banco\n");
    printf("5 - Nada\n");
    printf("6 - Voltar\n");

}

void cadastrarVoo(){
    system("clear");
    printf("AEROPORTO/VOO/CADASTRAR\n");
    if(pegaPosicaoLimpaNoVetorVoo() < 0){
        printf("Limite maximo de 50 voos ja cadastrado...");
        return;
    }
    indice = pegaPosicaoLimpaNoVetorVoo();
    printf("Digite 6 para voltar \n");
    printf("Digite o identificador do voo: ");
    scanf("%d",&idVoo[indice]);
    printf("Digite o quantidade de assentos do voo: ");
    scanf("%d",&qtdeAssentos[indice]);
    if(qtdeAssentos[indice] == 6){
        excluirVoo(indice);
        return;
    }
    printf("Digite o nome do voo: ");
    //fflush(stdin);
    //getc(&nomeVoo[indice]);
    //scanf("%s",&nome[indice]);
    //printf("voo nome %s",nome[indice]);

char c;
int i;
scanf("%s", nome[indice]);
i = strlen(nome[indice]);      // length of user input till first space
do
{
scanf("%c", &c);
nome[indice][i++] = c;       // reading characters after first space (including it)
} while (c != '\n');     // until user hits Enter
nome[indice][i - 1] = 0;

  printf("%s\n",nome[indice]);
    printVoo(indice, "cadastrado");
    op = 1;

}




    while(1){
        if(op == 0){
            limparVetorVoo();
            cabecalhoPrimario();
        }else if(op == 1){
            cabecalhoCadastrarVoo();
            scanf("%d",&op);
            if(op == 6){
                op = 0;
            }else if(op == 1){
                cadastrarVoo();
            }else if(op == 2){
                editarVoo();
            }
        }else if(op == 5){
            printf("Aplicacao terminada com sucesso!\n");
            return 0;
        }else{
            printf("opcao invalida...\n");
            printf("Pressione enter para continuar...\n");
            getchar();
            scanf("c\n");
            cabecalhoPrimario();
        }
    }

    return 0;
}

