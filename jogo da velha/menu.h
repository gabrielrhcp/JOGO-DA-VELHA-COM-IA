void tabela(char mesa[3][3]){
system("cls");
printf("\t      (1)   (2)   (3)\n\n");
printf("\t(A)    %c  |  %c  |  %c\n",mesa[0][0],mesa[0][1],mesa[0][2]);
printf("\t      ---------------\n");
printf("\t(B)    %c  |  %c  |  %c\n",mesa[1][0],mesa[1][1],mesa[1][2]);
printf("\t      ---------------\n");
printf("\t(C)    %c  |  %c  |  %c\n\n\n",mesa[2][0],mesa[2][1],mesa[2][2]);
}

void placar(int pw,int pcw,int v){
    printf("                |PLACAR|\n\n");
    printf("     | player | |  pc  | | velha |\n");
    printf("     |   %d    | |  %d   | |   %d   |\n\n",pw,pcw,v);
}


void menu(int *x,int *y,int *z,char *sp,char *sc){
    system("cls");
    int cont=0;
    do{
    //variaveis de cntrole//
    char a,b,c;


    while(cont<1){
    printf("\t        MENU\n\n");
    printf("escolha com que simbolo jogar: 'x' ou 'o'\n");
    scanf("%c",&a);
    if(a=='x' || a=='X'){
        *x=1;
        *sp='X';
        *sc='O';
        cont++;
    }else if(a=='o' || a=='O'|| a=='0'){
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
    scanf("%c",&b);
    if(b=='p' || b=='P'){
        *y=1;
        cont++;
    }else if(b=='c'|| b=='C'){
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
    scanf("%c",&c);
    if(c=='f'|| c=='F'){
        *z=1;
        cont++;
    }else if(c=='m' || c=='M'){
        *z=2;
        cont++;
    }else if(c=='d' || c=='D'){
        *z=3;
        cont++;
    }
    system("cls");
    }
    }while(cont<3);
}

