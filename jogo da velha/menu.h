void tabela(char mesa[3][3]){
system("cls");
printf("\t      (1)   (2)   (3)\n\n");
printf("\t(A)    %c  |  %c  |  %c\n",mesa[0][0],mesa[0][1],mesa[0][2]);
printf("\t      ---------------\n");
printf("\t(B)    %c  |  %c  |  %c\n",mesa[1][0],mesa[1][1],mesa[1][2]);
printf("\t      ---------------\n");
printf("\t(C)    %c  |  %c  |  %c\n\n\n",mesa[2][0],mesa[2][1],mesa[2][2]);
}//tabela que mostra o andar do jogo.

void placar(int pw,int pcw,int v){
    printf("\t             |PLACAR|\n\n");
    printf("\t      player    pc     velha \n");
    printf("\t        %d       %d       %d   \n\n",pw,pcw,v);
}//mostra a pontuação do jogo.


void menu(int *x,int *y,int *z,char *sp,char *sc){
    system("cls");
    int cont=0;
    do{//laço do lup "menu".

    char a[50],b[50],c[50];//variaveis de cntrole//

    while(cont<1){//lup que assegura uma escolha compatível.
        printf("\t        MENU\n\n");
        printf("escolha com que simbolo jogar: 'x' ou 'o'\n");
        scanf("%s",&a);
        if(strcmp(a,"x")==0 || strcmp(a,"X")==0){
            *x=1;
            *sp='X';
            *sc='O';
            cont++;
        }else if (strcmp(a,"o")==0 || strcmp(a,"O")==0 || strcmp(a,"0")==0){  //alterna entre jogar com 'x' ou 'o'.
            *x=2;
            *sp='O';
            *sc='X';
            cont++;
        }
    system("cls");
    }
    while(cont<2){
        printf("\t        MENU\n\n");
        printf("esolha quem jogara primeiro:'p' ou 'c'\n");
        printf("p-> player.\n");
        printf("c-> computador.\n");
        scanf("%s",&b);
        if(strcmp(b,"p")==0 || strcmp(b,"P")==0){
            *y=1;
            cont++;
        }else if (strcmp(b,"c")==0 || strcmp(b,"C")==0){  //alterna na ordem de jogada.
            *y=2;
            cont++;
        }
    system("cls");
    }
    while(cont<3){
        printf("\t        MENU\n\n");
        printf("escolha a dificuldade:'f','m' ou 'd'\n");
        printf("f-> f%ccil.\n",160);
        printf("m-> m%cdio.\n",130);
        printf("d-> dif%ccil.\n",161);
        scanf("%s",&c);
        if (strcmp(c,"f")==0 || strcmp(c,"F")==0){
            *z=1;
            cont++;
        }else if (strcmp(c,"m")==0 || strcmp(c,"M")==0){
            *z=2;
            cont++;                 //alterna a dificuldade do jogo.
        }else if (strcmp(c,"d")==0 || strcmp(c,"D")==0){
            *z=3;
            cont++;
        }
        system("cls");
        }
    }while(cont<3);
}

