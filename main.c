#include <stdio.h>
#include <stdlib.h>

#define MAXVOO 50
#define MAXPASSAGEIRO 2048
#define MAXSTRING 255
#define MAXCHARDATA 10
#define MAXCHARHORA 5
#define MAXCHARIDENTIDADE 13 /*MG-99.999.999*/
#define MAXCHARTELEFONE 15 /*038 9.9999-9999*/
#define MAXCHARSEXO 1 /*F ou M*/
#define MAXPASSAGEM 61440
#define OPSAIR 4
#define OPVOLTAR 6

/* SUBSTITUI O system("pause") da biblioteca do windows
getchar();
scanf("c\n")
*/

int main()
{
    /*DECLARACOES VARIAVEIS*/
    int op = 0; /*opcao escolhida pelo usuario*/
        /*indice controlador de numeracao dos vetores, auto-increment*/
    int indiceVoo = 1;
    int indicePassageiro = 1;
    int indicePassagem = 1;
        /*fim controlador de numeracao*/
    char *msgOp = "";
        /*ATRIBUTOS DO VOO*/
    int idVoo[MAXVOO];
    int numeroAeronave[MAXVOO];
    char empresaVoo[MAXVOO][MAXSTRING];
    char origemVoo[MAXVOO][MAXSTRING];
    char destinoVoo[MAXVOO][MAXSTRING];
    char dataPartidaVoo[MAXVOO][MAXCHARDATA];
    char horaPartidaVoo[MAXVOO][MAXCHARHORA];
    int qtdePassageirosVoo[MAXVOO];
        /*FIM ATRIBUTOS DO VOO*/

        /*ATRIBUTOS PASSAGEIRO*/
    int idPassageiro[MAXPASSAGEIRO];
    char nomePasageiro[MAXPASSAGEIRO][MAXSTRING];
    char identididadePassageiro[MAXCHARIDENTIDADE];
    char enderecoPassageiro[MAXPASSAGEIRO][MAXSTRING];
    char telefonePassageiro[MAXPASSAGEIRO][MAXCHARTELEFONE];
    char sexoPasageiro[MAXPASSAGEIRO][MAXCHARSEXO];
        /*FIM ATRIBUTOS PASSAGEIRO*/

        /*ATRIBUTOS PASSAGEM*/
    int numeroPassagem[MAXPASSAGEM];
    int identificadorPassageiro[MAXPASSAGEM];
    int identificadorVoo[MAXPASSAGEM];
    float valorPassagem[MAXPASSAGEM];
    char dataVendaPassagem[MAXPASSAGEM][MAXCHARDATA];
        /*FIM ATRIBUTOS PASSAGEM*/

    /*FIM VARIAVEIS*/
    /*FUNCOES*/
    void clean_stdin(void)/*substitui o fflush(stdin)*/
    {
        int c;
        do {
            c = getchar();
        } while (c != '\n' && c != EOF);
    }
    void imprimeCabecalhoMenuPrincipal(){
        system("clear");
        printf("AEROPORTO\n\n");
        printf("1 - Voos\n");
        printf("2 - Passageiros\n");
        printf("3 - Passagens\n");
        printf("4 - Sair\n");
        if(msgOp != "")
            printf("%s\n",msgOp);
        msgOp = "";
    }
    void imprimeCabecalhoSubMenu(){
        printf("1 - Inclusao\n");
        printf("2 - Alteracao\n");
        printf("3 - Exclusao\n");
        printf("4 - Consulta\n");
        printf("5 - Relatorio\n");
        printf("6 - Voltar ao menu principal\n");
        if(msgOp != "")
            printf("%s\n",msgOp);
        msgOp = "";
    }
    void imprimeCabecalhoVoos(){
        system("clear");
        printf("AEROPORTO/VOOS\n\n");
        imprimeCabecalhoSubMenu();
    }
    void imprimeCabecalhoPassageiros(){
        system("clear");
        printf("AEROPORTO/PASSAGEIROS\n");
        imprimeCabecalhoSubMenu();
    }
    void imprimeCabecalhoPassagens(){
        system("clear");
        printf("AEROPORTO/PASSAGENS\n\n");
        imprimeCabecalhoSubMenu();
    }
    int totalVoosCadastrados(){
        int aux = 0;
        for(int i = 0; i < MAXVOO; i++){
            if(idVoo[i] != NULL){
                aux++;
            }
        }
        return aux;
    }
    void limpaVetores(){
        for (int i = 0; i < MAXVOO; i++){
            idVoo[i] = NULL;
            numeroAeronave[i] = NULL;
            empresaVoo[i][0] = '\0';
            destinoVoo[i][0] = '\0';
            dataPartidaVoo[i][0] = '\0';
            horaPartidaVoo[i][0] = '\0';
            qtdePassageirosVoo[i] = 0;
        }
        for (int i = 0; i < MAXPASSAGEIRO; i++){
            idPassageiro[i] = NULL;
        }
        for (int i = 0; i < MAXPASSAGEM; i++){
            numeroPassagem[i] = NULL;
        }
    }
    int pegaVooLivre(){
        for(int i = 0; i < MAXVOO; i++){
            if (idVoo[i] == NULL)
                return i;
        }
        return -1;
    }
    int pegaAeronavePeloNumero(int num){
        for(int i = 0; i < MAXVOO; i++){
            if (idVoo[i] != NULL && numeroAeronave[i] == num){
                return i;
            }
        }
        return -1;
    }
    int pegaAeronavePeloNumeroComExcecao(int num, int idExcecao){
        for(int i = 0; i < MAXVOO; i++){
            if (idVoo[i] != NULL && numeroAeronave[i] == num && idVoo[i] != idExcecao){
                return i;
            }
        }
        return -1;
    }
    int pegaVooPeloIdentificador(int num){
        for(int i = 0; i < MAXVOO; i++){
            if (idVoo[i] != NULL && idVoo[i] == num){
                return i;
            }
        }
        return -1;
    }
    void imprimirVoo(int id, char *msg){
        if(msg != ""){
            system("clear");
            printf("AEROPORTO/VOO/MOSTRAR/%d\n\n",idVoo[id]);
        }
        printf("Identificador do voo: %d\n",idVoo[id]);
        printf("Numero da aeronave: %d\n",numeroAeronave[id]);
        printf("Nome da empresa: %s\n",empresaVoo[id]);
        printf("Origem do voo: %s\n",origemVoo[id]);
        printf("Destino do voo: %s\n",destinoVoo[id]);
        printf("Data da partida: %s\n",dataPartidaVoo[id]);
        printf("Hora da partida: %s\n",horaPartidaVoo[id]);
        printf("Quantidade de passageiros: %d\n",qtdePassageirosVoo[id]);
        if(msg != ""){
            printf("\n");
            printf("Voo %s com sucesso...\n",msg);
            printf("Pressione enter para voltar...");
            clean_stdin();
        }
        //char *c;
        //scanf("%c",&c);
    }

    void imprimeRelatorioVoo(){
        if(totalVoosCadastrados() == 0){
            printf("Nenhum voo cadastrado...\n");
            printf("Pressione enter para voltar.");
            getchar();
            scanf("c\n");
            return;
        }
        int max = 0;
        system("clear");
        printf("AEROPORTO/VOO/RELATORIO\n\n");
        for(int i = 0; i < MAXVOO; i++){
            if(idVoo[i] != NULL){
                max++;
                imprimirVoo(i,"");
                printf("===================================================================\n");
            }
        }
        printf("Total de %d voos cadastrados.\n",max);
        printf("Pressione enter para voltar...");
        getchar();
        scanf("c\n");
    }
    void deleteVoo(){
        if(totalVoosCadastrados() == 0){
            printf("Nenhum voo cadastrado...\n");
            printf("Pressione enter para voltar.");
            getchar();
            scanf("c\n");
            return;
        }
        int num = 0;
        system("clear");
        printf("AEROPORTO/VOO/EXCLUIR\n\n");
        while(1){
            printf("Digite o identificador do voo: ");
            scanf("%d", &num);
            int id = pegaVooPeloIdentificador(num);
            if(id != -1){
                idVoo[id] = NULL;
                numeroAeronave[id] = NULL;
                empresaVoo[id][0] = '\0';
                destinoVoo[id][0] = '\0';
                dataPartidaVoo[id][0] = '\0';
                horaPartidaVoo[id][0] = '\0';
                qtdePassageirosVoo[id] = 0;
                printf("Voo excluido com sucesso.\n");
                printf("Pressione enter para voltar.");
                getchar();
                scanf("c\n");
                break;
            }else{
                printf("Identificador nao encontrado.\n");
            }
        }
    }
    void cadastroFakeVoos(int num){
        if(num <= MAXVOO){
            int i = 0;
            for(i = 0; i < num; i++){
                idVoo[i] = i+1;
                numeroAeronave[i] = i+1;
                empresaVoo[i][0] = '1';
                destinoVoo[i][0] = '1';
                origemVoo[i][0] = '1';
                dataPartidaVoo[i][0] = '1';
                horaPartidaVoo[i][0] = '1';
                qtdePassageirosVoo[i] = i+1;
            }
            indiceVoo = i+1;
        }
    }
    void cadastrarVoo(){
        system("clear");
        printf("AEROPORTO/VOO/CADASTRAR\n\n");
        int numAero = 0;
        int indice = pegaVooLivre();
        if(indice == -1){
            printf("Cadastro de voos ja atingiu o limite de %d registrados\n",MAXVOO);
            return;
        }
        idVoo[indice] = indiceVoo;
        printf("Identificador do Voo: %d\n", indiceVoo);
        do{
            printf("Digite o numero da aeronave: ");
            scanf("%d", &numAero);
            clean_stdin();
            if(pegaAeronavePeloNumero(numAero) != -1)
                printf("Duplicidade! Este numero de areonave ja esta cadastrado.\n");
        }while(pegaAeronavePeloNumero(numAero) != -1);
        numeroAeronave[indice] = numAero;
        printf("Digite o nome da empresa: ");
        char c;
        int i;
        scanf("%s", empresaVoo[indice]);
        i = strlen(empresaVoo[indice]);
        do
        {
            scanf("%c", &c);
            empresaVoo[indice][i++] = c;
        } while (c != '\n');
        empresaVoo[indice][i - 1] = 0;
        printf("Digite a origem do voo: ");
        scanf("%s", origemVoo[indice]);
        i = strlen(origemVoo[indice]);
        do
        {
            scanf("%c", &c);
            origemVoo[indice][i++] = c;
        } while (c != '\n');
        origemVoo[indice][i - 1] = 0;
        printf("Digite a destino do voo: ");
        scanf("%s", destinoVoo[indice]);
        i = strlen(destinoVoo[indice]);
        do
        {
            scanf("%c", &c);
            destinoVoo[indice][i++] = c;
        } while (c != '\n');
        destinoVoo[indice][i - 1] = 0;
        printf("Digite a data da partida: ");
        scanf("%s",dataPartidaVoo[indice]);
        i = strlen(dataPartidaVoo[indice]);
        do
        {
            scanf("%c", &c);
            dataPartidaVoo[indice][i++] = c;
        } while (c != '\n');
        dataPartidaVoo[indice][i - 1] = 0;
        printf("Digite a hora da partida: ");
        scanf("%s",horaPartidaVoo[indice]);
        i = strlen(horaPartidaVoo[indice]);
        do
        {
            scanf("%c", &c);
            horaPartidaVoo[indice][i++] = c;
        } while (c != '\n');
        horaPartidaVoo[indice][i - 1] = 0;
        printf("Digite a quantidade de passageiros: ");
        scanf("%d", &qtdePassageirosVoo[indice]);
        clean_stdin();
        //getchar();
        indiceVoo++;
        imprimirVoo(indice,"cadastrado");
    }
    void editarVoo(){
        if(totalVoosCadastrados() == 0){
            printf("Nenhum voo cadastrado...\n");
            printf("Pressione enter para voltar.");
            getchar();
            scanf("c\n");
            return;
        }
        system("clear");
        printf("AEROPORTO/VOO/EDITAR\n\n");
        int num = 0;
        int indice = 0;
        int numAero = 0;

        do{
            printf("Digite o identificador do voo: ");
            scanf("%d", &num);
            clean_stdin();
            indice = pegaVooPeloIdentificador(num);
            if(indice == -1){
                printf("Identificador nao encontrado.\n");
            }
        }while(indice == -1);
        printf("Identificador do Voo: %d\n", idVoo[indice]);
        printf("Numero da areonave = %d. Deseja alterar? (s/n): ",numeroAeronave[indice]);
        char r;
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            do{
                printf("Digite o numero da aeronave: ");
                scanf("%d", &numAero);
                clean_stdin();
                if(pegaAeronavePeloNumeroComExcecao(numAero, idVoo[indice]) != -1)
                    printf("Duplicidade! Este numero de areonave ja esta cadastrado.\n");
            }while(pegaAeronavePeloNumeroComExcecao(numAero, idVoo[indice]) != -1);
            numeroAeronave[indice] = numAero;
        }
        printf("Nome da empresa = %s. Deseja alterar? (s/n): ",empresaVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            int i;
            char c;
            printf("Digite um novo nome para empresa: ");
            scanf("%s", empresaVoo[indice]);
            i = strlen(empresaVoo[indice]);
            do
            {
                scanf("%c", &c);
                empresaVoo[indice][i++] = c;
            } while (c != '\n');
            empresaVoo[indice][i - 1] = 0;
        }
        printf("Origem do voo = %s. Deseja alterar? (s/n): ",origemVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            int i;
            char c;
            printf("Digite a nova origem do voo: ");
            scanf("%s", origemVoo[indice]);
            i = strlen(origemVoo[indice]);
            do
            {
                scanf("%c", &c);
                origemVoo[indice][i++] = c;
            } while (c != '\n');
            origemVoo[indice][i - 1] = 0;
        }
        printf("Destino do voo = %s. Deseja alterar? (s/n): ",destinoVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            int i;
            char c;
            printf("Digite o novo destino do voo: ");
            scanf("%s", destinoVoo[indice]);
            i = strlen(destinoVoo[indice]);
            do
            {
                scanf("%c", &c);
                destinoVoo[indice][i++] = c;
            } while (c != '\n');
            destinoVoo[indice][i - 1] = 0;
        }
        printf("Data da partida = %s. Deseja alterar? (s/n): ",dataPartidaVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            int i;
            char c;
            printf("Digite a nova data: ");
            scanf("%s", dataPartidaVoo[indice]);
            i = strlen(dataPartidaVoo[indice]);
            do
            {
                scanf("%c", &c);
                dataPartidaVoo[indice][i++] = c;
            } while (c != '\n');
            dataPartidaVoo[indice][i - 1] = 0;
        }
        printf("Hora da partida = %s. Deseja alterar? (s/n): ",horaPartidaVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            int i;
            char c;
            printf("Digite a nova hora da partida: ");
            scanf("%s", horaPartidaVoo[indice]);
            i = strlen(horaPartidaVoo[indice]);
            do
            {
                scanf("%c", &c);
                horaPartidaVoo[indice][i++] = c;
            } while (c != '\n');
            horaPartidaVoo[indice][i - 1] = 0;
        }
        printf("Quantidade de passageiros = %d. Deseja alterar? (s/n): ",qtdePassageirosVoo[indice]);
        r = '0';
        scanf("%c",&r);
        clean_stdin();
        if(r == 's'){
            printf("Digite o numero de passageiros: ");
            scanf("%d", &qtdePassageirosVoo[indice]);
            clean_stdin();
        }
        imprimirVoo(indice,"atualizado");
    }
    void consultarVoo(){
        if(totalVoosCadastrados() == 0){
            printf("Nenhum voo cadastrado...\n");
            printf("Pressione enter para voltar.");
            getchar();
            scanf("c\n");
            return;
        }
        int num = 0;
        system("clear");
        printf("AEROPORTO/VOO/CONSULTAR\n\n");
        while(1){
            printf("Digite o identificador do voo: ");
            scanf("%d", &num);
            int id = pegaVooPeloIdentificador(num);
            if(id != -1){
                printf("\n");
                imprimirVoo(id,"");
                printf("=================================================================\n");
                printf("Pressione enter para voltar.");
                getchar();
                scanf("c\n");
                break;
            }else{
                printf("Identificador nao encontrado.\n");
            }
        }
    }
    /*FIM FUNCOES*/

    /*INICIO DA APLICACAO*/
    limpaVetores();
    //cadastroFakeVoos(10);
    do{
        imprimeCabecalhoMenuPrincipal();
        scanf("%d",&op);
        switch(op){
        case 1:
            do{
                imprimeCabecalhoVoos();
                scanf("%d",&op);
                switch(op){
                case 1:
                    cadastrarVoo();
                    break;
                case 2:
                    editarVoo();
                    break;
                case 3:
                    deleteVoo();
                    break;
                case 4:
                    consultarVoo();
                    break;
                case 5:
                    imprimeRelatorioVoo();
                    break;
                default:
                    msgOp = "Opcao invalida";
                }
            }while(op != OPVOLTAR);
            msgOp="";
            break;
        case 2:
            do{
                imprimeCabecalhoPassageiros();
                scanf("%d",&op);
            }while(op != OPVOLTAR);
            break;
        case 3:
            do{
                imprimeCabecalhoPassagens();
                scanf("%d",&op);
            }while(op != OPVOLTAR);
            break;
        case OPSAIR:
            system("clear");
            printf("AEROPORTO\n\n");
            printf("Aplicacao finalizada com sucesso!\n");
            break;
        default:
            msgOp = "Opcao invalida";
            //break;
        }
    }while(op != OPSAIR);
    /*FIM APLICACAO*/
    return 0;
}

