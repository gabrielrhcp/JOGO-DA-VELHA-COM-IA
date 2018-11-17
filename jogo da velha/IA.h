void player(char lal[3][3],int *f,int *num,int *l,int *c){
 char cord[5];
        printf("Informe a cordenada: (Ex:A1 ou b3)\n");
        scanf("%s",cord);

        //A//
        if(strcmp(cord,"a1")==0 || strcmp(cord,"A1")==0){*l=1;*c=1;}
        else if(strcmp(cord,"a2")==0 || strcmp(cord,"A2")==0){*l=1;*c=2;}
        else if(strcmp(cord,"a3")==0 || strcmp(cord,"A3")==0){*l=1;*c=3;}
        //B//
        if(strcmp(cord,"b1")==0 || strcmp(cord,"B1")==0){*l=2;*c=1;}
        else if(strcmp(cord,"b2")==0 || strcmp(cord,"B2")==0){*l=2;*c=2;}
        else if(strcmp(cord,"b3")==0 || strcmp(cord,"B3")==0){*l=2;*c=3;}
        //C//
        if(strcmp(cord,"c1")==0 || strcmp(cord,"C1")==0){*l=3;*c=1;}
        else if(strcmp(cord,"c2")==0 || strcmp(cord,"C2")==0){*l=3;*c=2;}
        else if(strcmp(cord,"c3")==0|| strcmp(cord,"C3")==0){*l=3;*c=3;}
        //GO_MENU//
        if (strcmp(cord,"m")==0 || strcmp(cord,"M")==0){*num=12;}
        //RESTART//
        if(strcmp(cord,"r")==0 || strcmp(cord,"R")==0){*num=13;}

        if(lal[*l-1][*c-1]!=' ' || (*c>3 || *c<1) || (*l>3 || *l<1)){
            *l=0;
            *c=0;
            tabela(lal);
        }else{
            if(*f==1 ){
                lal[*l-1][*c-1]='X';
             }else{
                lal[*l-1][*c-1]='O';
                 }
            *num +=1;
            tabela(lal);
         }
}

void pc(char velha[3][3],char simbC,char simbP,int *jogada, int *level){

    int prob,prob_max=0,aleat,ia_tatica;
    srand(time(NULL));
    prob=rand()%100;
    ia_tatica=rand()%5;
    if(*level==1){
       prob_max=49;
    }else if(*level==2){
       prob_max=74;
    }else if(*level==3){
       prob_max=94;
    }

    //JOGADAS BOAS
    if(prob>=0 && prob<=prob_max){

    //CHANCES DE VITORIA
        //LINHA 1
        if(velha[0][0]==' ' && velha[0][1]==simbC && velha[0][2]==simbC) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbC && velha[0][1]==' ' && velha[0][2]==simbC) {velha[0][1]=simbC;}
        else if(velha[0][0]==simbC && velha[0][1]==simbC && velha[0][2]==' ') {velha[0][2]=simbC;}
        //LINHA 2
        else if(velha[1][0]==' ' && velha[1][1]==simbC && velha[1][2]==simbC) {velha[1][0]=simbC;}
        else if(velha[1][0]==simbC && velha[1][1]==' ' && velha[1][2]==simbC) {velha[1][1]=simbC;}
        else if(velha[1][0]==simbC && velha[1][1]==simbC && velha[1][2]==' ') {velha[1][2]=simbC;}
        //LINHA 3
        else if(velha[2][0]==' ' && velha[2][1]==simbC && velha[2][2]==simbC) {velha[2][0]=simbC;}
        else if(velha[2][0]==simbC && velha[2][1]==' ' && velha[2][2]==simbC) {velha[2][1]=simbC;}
        else if(velha[2][0]==simbC && velha[2][1]==simbC && velha[2][2]==' ') {velha[2][2]=simbC;}
        //COLUNA 1
        else if(velha[0][0]==' ' && velha[1][0]==simbC && velha[2][0]==simbC) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbC && velha[1][0]==' ' && velha[2][0]==simbC) {velha[1][0]=simbC;}
        else if(velha[0][0]==simbC && velha[1][0]==simbC && velha[2][0]==' ') {velha[2][0]=simbC;}
        //COLUNA 2
        else if(velha[0][1]==' ' && velha[1][1]==simbC && velha[2][1]==simbC) {velha[0][1]=simbC;}
        else if(velha[0][1]==simbC && velha[1][1]==' ' && velha[2][1]==simbC) {velha[1][1]=simbC;}
        else if(velha[0][1]==simbC && velha[1][1]==simbC && velha[2][1]==' ') {velha[2][1]=simbC;}
        //COLUNA 3
        else if(velha[0][2]==' ' && velha[1][2]==simbC && velha[2][2]==simbC) {velha[0][2]=simbC;}
        else if(velha[0][2]==simbC && velha[1][2]==' ' && velha[2][2]==simbC) {velha[1][2]=simbC;}
        else if(velha[0][2]==simbC && velha[1][2]==simbC && velha[2][2]==' ') {velha[2][2]=simbC;}
        //DIAGONAL PRINCIPAL
        else if(velha[0][0]==' ' && velha[1][1]==simbC && velha[2][2]==simbC) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbC && velha[1][1]==' ' && velha[2][2]==simbC) {velha[1][1]=simbC;}
        else if(velha[0][0]==simbC && velha[1][1]==simbC && velha[2][2]==' ') {velha[2][2]=simbC;}
        //DIAGONAL SECUNDARIA
        else if(velha[0][2]==' ' && velha[1][1]==simbC && velha[2][0]==simbC) {velha[0][2]=simbC;}
        else if(velha[0][2]==simbC && velha[1][1]==' ' && velha[2][0]==simbC) {velha[1][1]=simbC;}
        else if(velha[0][2]==simbC && velha[1][1]==simbC && velha[2][0]==' ') {velha[2][0]=simbC;}

    //===========================================================================================//

    //IMPEDIR A VITORIA
        //LINHA 1
        else if(velha[0][0]==' ' && velha[0][1]==simbP && velha[0][2]==simbP) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbP && velha[0][1]==' ' && velha[0][2]==simbP) {velha[0][1]=simbC;}
        else if(velha[0][0]==simbP && velha[0][1]==simbP && velha[0][2]==' ') {velha[0][2]=simbC;}
        //LINHA 2
        else if(velha[1][0]==' ' && velha[1][1]==simbP && velha[1][2]==simbP) {velha[1][0]=simbC;}
        else if(velha[1][0]==simbP && velha[1][1]==' ' && velha[1][2]==simbP) {velha[1][1]=simbC;}
        else if(velha[1][0]==simbP && velha[1][1]==simbP && velha[1][2]==' ') {velha[1][2]=simbC;}
        //LINHA 3
        else if(velha[2][0]==' ' && velha[2][1]==simbP && velha[2][2]==simbP) {velha[2][0]=simbC;}
        else if(velha[2][0]==simbP && velha[2][1]==' ' && velha[2][2]==simbP) {velha[2][1]=simbC;}
        else if(velha[2][0]==simbP && velha[2][1]==simbP && velha[2][2]==' ') {velha[2][2]=simbC;}
        //COLUNA 1
        else if(velha[0][0]==' ' && velha[1][0]==simbP && velha[2][0]==simbP) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbP && velha[1][0]==' ' && velha[2][0]==simbP) {velha[1][0]=simbC;}
        else if(velha[0][0]==simbP && velha[1][0]==simbP && velha[2][0]==' ') {velha[2][0]=simbC;}
        //COLUNA 2
        else if(velha[0][1]==' ' && velha[1][1]==simbP && velha[2][1]==simbP) {velha[0][1]=simbC;}
        else if(velha[0][1]==simbP && velha[1][1]==' ' && velha[2][1]==simbP) {velha[1][1]=simbC;}
        else if(velha[0][1]==simbP && velha[1][1]==simbP && velha[2][1]==' ') {velha[2][1]=simbC;}
        //COLUNA 3
        else if(velha[0][2]==' ' && velha[1][2]==simbP && velha[2][2]==simbP) {velha[0][2]=simbC;}
        else if(velha[0][2]==simbP && velha[1][2]==' ' && velha[2][2]==simbP) {velha[1][2]=simbC;}
        else if(velha[0][2]==simbP && velha[1][2]==simbP && velha[2][2]==' ') {velha[2][2]=simbC;}
        //DIAGONAL PRINCIPAL
        else if(velha[0][0]==' ' && velha[1][1]==simbP && velha[2][2]==simbP) {velha[0][0]=simbC;}
        else if(velha[0][0]==simbP && velha[1][1]==' ' && velha[2][2]==simbP) {velha[1][1]=simbC;}
        else if(velha[0][0]==simbP && velha[1][1]==simbP && velha[2][2]==' ') {velha[2][2]=simbC;}
        //DIAGONAL SECUNDARIO
        else if(velha[0][2]==' ' && velha[1][1]==simbP && velha[2][0]==simbP) {velha[0][2]=simbC;}
        else if(velha[0][2]==simbP && velha[1][1]==' ' && velha[2][0]==simbP) {velha[1][1]=simbC;}
        else if(velha[0][2]==simbP && velha[1][1]==simbP && velha[2][0]==' ') {velha[2][0]=simbC;}

    //===========================================================================================//

    //PLAYER COMEÇANDO - IMPEDIR TATICAS DO PLAYER

        //TATICA DOS CANTOS
        else if(*jogada==1 && (velha[0][0]==simbP || velha[0][2]==simbP || velha[2][0]==simbP || velha[2][2]==simbP)) {velha[1][1]=simbC;}
        else if(*jogada==3 && (velha[0][0]==simbP || velha[0][2]==simbP || velha[2][0]==simbP || velha[2][2]==simbP) && velha[1][1]==simbC){
            aleat=rand()%4;
            if(aleat==0) {velha[0][1]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
            else if(aleat==2) {velha[2][1]=simbC;}
            else if(aleat==3) {velha[1][0]=simbC;}
        }

        //TATICA DO MEIO
        else if(*jogada==1 && velha[1][1]==simbP){
            aleat=rand()%4;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[2][0]=simbC;}
            else if(aleat==3) {velha[2][2]=simbC;}
        }

        //TATICA DOS CANTOS CENTRAIS
        else if(*jogada==1 && velha[0][1]==simbP){
            aleat=rand()%6;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
            else if(aleat==3) {velha[2][0]=simbC;}
            else if(aleat==4) {velha[2][1]=simbC;}
            else if(aleat==5) {velha[2][2]=simbC;}
        }
        else if(*jogada==1 && velha[1][0]==simbP){
            aleat=rand()%6;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
            else if(aleat==3) {velha[1][2]=simbC;}
            else if(aleat==4) {velha[2][0]=simbC;}
            else if(aleat==5) {velha[2][2]=simbC;}
        }
        else if(*jogada==1 && velha[1][2]==simbP){
            aleat=rand()%6;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[1][0]=simbC;}
            else if(aleat==3) {velha[1][1]=simbC;}
            else if(aleat==4) {velha[2][0]=simbC;}
            else if(aleat==5) {velha[2][2]=simbC;}
        }
        else if(*jogada==1 && velha[2][1]==simbP){
            aleat=rand()%6;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][1]=simbC;}
            else if(aleat==2) {velha[0][2]=simbC;}
            else if(aleat==3) {velha[1][1]=simbC;}
            else if(aleat==4) {velha[2][0]=simbC;}
            else if(aleat==5) {velha[2][2]=simbC;}
        }

    //===========================================================================================//

    //IA COMEÇANDO - CRIAR TATICAS

        //TATICA DOS CANTOS - nao finalizado

            //COMEÇANDO A TATICA
        else if(*jogada==0 && ia_tatica>=0 && ia_tatica<=3){
            aleat=rand()%4;
            if(aleat==0){velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[2][0]=simbC;}
            else if(aleat==3) {velha[2][2]=simbC;}
        }

            //CANTO [0][0]

                //POSSIBILIDADE 1
        else if(*jogada==2 && velha[0][0]==simbC && velha[0][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
            else if(aleat==2) {velha[1][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[0][1]==simbP && velha[2][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[0][1]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[1][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[0][1]==simbP && velha[1][0]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 2
        else if(*jogada==2 && velha[0][0]==simbC && velha[0][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
            else if(aleat==2) {velha[1][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[0][2]==simbP && velha[2][0]==simbC) {velha[2][2]=simbC;}
        else if(*jogada==4 && velha[0][0]==simbC && velha[0][2]==simbP && velha[1][0]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 3
        else if(*jogada==2 && velha[0][0]==simbC && velha[1][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
            else if(aleat==2) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[1][2]==simbP && velha[0][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }

                //POSSIBILIDADE 4
        else if(*jogada==2 && velha[0][0]==simbC && velha[2][2]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[2][2]==simbP && velha[2][0]==simbC) {velha[0][2]=simbC;}
        else if(*jogada==4 && velha[0][0]==simbC && velha[2][2]==simbP && velha[0][2]==simbC) {velha[2][0]=simbC;}

                //POSSIBILIDADE 5
        else if(*jogada==2 && velha[0][0]==simbC && velha[2][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[2][1]==simbP && velha[2][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }

                //POSSIBILIDADE 6
        else if(*jogada==2 && velha[0][0]==simbC && velha[2][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[0][1]=simbC;}
            else if(aleat==2) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[2][0]==simbP && velha[0][2]==simbC) {velha[2][2]=simbC;}
        else if(*jogada==4 && velha[0][0]==simbC && velha[2][0]==simbP && velha[0][1]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDAE 7
        else if(*jogada==2 && velha[0][0]==simbC && velha[1][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
            else if(aleat==2) {velha[0][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[1][0]==simbP && velha[0][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[1][0]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[0][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][0]==simbC && velha[1][0]==simbP && velha[0][1]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 8
        else if(*jogada==2 && velha[0][0]==simbC && velha[1][1]==simbP) {velha[2][2]=simbC;}

            //CANTO [0][2]

                //POSSIBILIDADE 1
        else if(*jogada==2 && velha[0][2]==simbC && velha[0][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
            else if(aleat==2) {velha[1][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[0][1]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[0][1]==simbP && velha[2][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[0][1]==simbP && velha[1][2]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 2
        else if(*jogada==2 && velha[0][2]==simbC && velha[0][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
            else if(aleat==2) {velha[1][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[0][0]==simbP && velha[2][2]==simbC) {velha[2][0]=simbC;}
        else if(*jogada==4 && velha[0][2]==simbC && velha[0][0]==simbP && velha[1][2]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 3
        else if(*jogada==2 && velha[0][2]==simbC && velha[1][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[1][0]==simbP && velha[0][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }

                //POSSIBILIDADE 4
        else if(*jogada==2 && velha[0][2]==simbC && velha[2][0]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[2][0]==simbP && velha[0][0]==simbC) {velha[2][2]=simbC;}
        else if(*jogada==4 && velha[0][2]==simbC && velha[2][0]==simbP && velha[2][2]==simbC) {velha[0][0]=simbC;}

                //POSSIBILIDADE 5
        else if(*jogada==2 && velha[0][2]==simbC && velha[2][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[2][1]==simbP && velha[2][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }

                //POSSIBILIDADE 6
        else if(*jogada==2 && velha[0][2]==simbC && velha[2][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][1]=simbC;}
            else if(aleat==2) {velha[2][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[2][2]==simbP && velha[0][0]==simbC) {velha[2][0]=simbC;}
        else if(*jogada==4 && velha[0][2]==simbC && velha[2][0]==simbP && velha[0][1]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 7
        else if(*jogada==2 && velha[0][2]==simbC && velha[1][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
            else if(aleat==2) {velha[0][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[1][2]==simbP && velha[0][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[1][2]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][1]=simbC;}
        }
        else if(*jogada==4 && velha[0][2]==simbC && velha[1][2]==simbP && velha[0][1]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 8
        else if(*jogada==2 && velha[0][2]==simbC && velha[1][1]==simbP) {velha[2][0]=simbC;}

            //CANTO [2][0]

                //POSSIBILIDADE 1
        else if(*jogada==2 && velha[2][0]==simbC && velha[1][0]==simbP){
            aleat=rand()%3;
            if(aleat==0){velha[2][2]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[1][0]==simbP && velha[2][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[1][0]==simbP && velha[2][1]==simbC) {velha[1][1]=simbC;}
        else if(*jogada==4 && velha[2][0]==simbC && velha[1][0]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[2][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }

                //POSSIBILIDADE 2
        else if(*jogada==2 && velha[2][0]==simbC && velha[0][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
            else if(aleat==2) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[0][0]==simbP && velha[2][1]==simbC) {velha[1][1]=simbC;}
        else if(*jogada==4 && velha[2][0]==simbC && velha[0][0]==simbP && velha[2][2]==simbC) {velha[0][2]=simbC;}

                //POSSIBILIDADE 3
        else if(*jogada==2 && velha[2][0]==simbC && velha[0][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[0][1]==simbP && velha[0][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
        }

                //POSSIBILIDADE 4
        else if(*jogada==2 && velha[2][0]==simbC && velha[0][2]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[2][2]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[0][2]==simbP && velha[2][2]==simbC) {velha[0][0]=simbC;}
        else if(*jogada==4 && velha[2][0]==simbC && velha[0][2]==simbP && velha[0][0]==simbC) {velha[2][2]=simbC;}

                //POSSIBILIDADE 5
        else if(*jogada==2 && velha[2][0]==simbC && velha[1][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[1][2]==simbP && velha[2][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }

                //POSSIBILIDADE 6
        else if(*jogada==2 && velha[2][0]==simbC && velha[2][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[1][0]=simbC;}
            else if(aleat==2) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[2][2]==simbP && velha[0][0]==simbC) {velha[0][2]=simbC;}
        else if(*jogada==4 && velha[2][0]==simbC && velha[2][2]==simbP && velha[1][0]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDEDA 7
        else if(*jogada==2 && velha[2][0]==simbC && velha[2][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[1][0]=simbC;}
            else if(aleat==1) {velha[1][1]=simbC;}
            else if(aleat==2) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[2][1]==simbP && velha[1][0]==simbC) {velha[1][1]=simbC;}
        else if(*jogada==4 && velha[2][0]==simbC && velha[2][1]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[1][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][0]==simbC && velha[2][1]==simbP && velha[0][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }

                //POSSIBILIDADE 8
        else if(*jogada==2 && velha[2][0]==simbC && velha[1][1]==simbP) {velha[0][2]=simbC;}

            //CANTO [2][2]

                //POSSIBILIDADE 1
        else if(*jogada==2 && velha[2][2]==simbC && velha[1][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][2]==simbP && velha[2][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][2]==simbP && velha[2][1]==simbC) {velha[1][1]=simbC;}
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][2]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[2][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }

                //POSSIBILIDADE 2
        else if(*jogada==2 && velha[2][2]==simbC && velha[0][2]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
            else if(aleat==2) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[0][2]==simbP && velha[2][0]==simbC) {velha[0][0]=simbC;}
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][2]==simbP && velha[2][1]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 3
        else if(*jogada==2 && velha[2][2]==simbC && velha[0][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[0][1]==simbP && velha[0][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }

                //POSSIBILIDADE 4
        else if(*jogada==2 && velha[2][2]==simbC && velha[0][0]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[0][0]==simbP && velha[2][0]==simbC) {velha[0][2]=simbC;}
        else if(*jogada==4 && velha[2][2]==simbC && velha[0][0]==simbP && velha[0][2]==simbC) {velha[2][0]=simbC;}

                //POSSIBILIDADE 5
        else if(*jogada==2 && velha[2][2]==simbC && velha[1][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][0]==simbP && velha[2][0]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }

                //POSSIBILIDADE 6
        else if(*jogada==2 && velha[2][2]==simbC && velha[2][0]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
            else if(aleat==2) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[2][0]==simbP && velha[0][2]==simbC) {velha[0][0]=simbC;}
        else if(*jogada==4 && velha[2][2]==simbC && velha[1][0]==simbP && velha[1][2]==simbC) {velha[1][1]=simbC;}

                //POSSIBILIDADE 7
        else if(*jogada==2 && velha[2][2]==simbC && velha[2][1]==simbP){
            aleat=rand()%3;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
            else if(aleat==2) {velha[1][1]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[2][1]==simbP && velha[0][2]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }
        else if(*jogada==4 && velha[2][2]==simbC && velha[2][1]==simbP && velha[1][2]==simbC) {velha[1][1]=simbC;}
        else if(*jogada==4 && velha[2][2]==simbC && velha[2][1]==simbP && velha[1][1]==simbC){
            aleat=rand()%2;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
        }

                //POSSIBILIDADE 8
        else if(*jogada==2 && velha[2][2]==simbC && velha[1][1]==simbP) {velha[0][0]=simbC;}

        //TATICA DO MEIO

            //COMECANDO A TATICA
        else if(*jogada==0 && ia_tatica==4){velha[1][1]=simbC;}

            //POSSIBILIDADE 1
        else if(*jogada==2 && velha[1][1]==simbC && velha[0][1]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada==4 && velha[1][1]==simbC && velha[0][1]==simbP && velha[0][0]==simbC) {velha[2][0]=simbC;}
        else if(*jogada==4 && velha[1][1]==simbC && velha[0][1]==simbP && velha[0][2]==simbC) {velha[2][2]=simbC;}

            //POSSIBILIDADE 2
        else if(*jogada==2 && velha[1][1]==simbC && velha[1][2]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[1][1]==simbC && velha[1][2]==simbP && velha[0][2]==simbC) {velha[0][0]=simbC;}
        else if(*jogada==4 && velha[1][1]==simbC && velha[1][2]==simbP && velha[2][2]==simbC) {velha[2][0]=simbC;}

            //POSSIBILIDADE 3
        else if(*jogada==2 && velha[1][1]==simbC && velha[2][1]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada==4 && velha[1][1]==simbC && velha[2][1]==simbP && velha[2][0]==simbC) {velha[0][0]=simbC;}
        else if(*jogada==4 && velha[1][1]==simbC && velha[2][1]==simbP && velha[2][2]==simbC) {velha[0][2]=simbC;}

            //POSSIVBILIDADE 4
        else if(*jogada==2 && velha[1][1]==simbC && velha[1][0]==simbP){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada==4 && velha[1][1]==simbC && velha[1][0]==simbP && velha[0][0]==simbC) {velha[0][2]=simbC;}
        else if(*jogada==4 && velha[1][1]==simbC && velha[1][0]==simbP && velha[2][0]==simbC) {velha[2][2]=simbC;}

        //TATICA DOS CANTOS CENTRAIS - nao é eficiente

        //TENTAR ENCONTRAR UMA OPORTUNIDADE

            //LINHA 0
        else if(*jogada>=2 && velha[0][0]==simbC && velha[0][1]==' ' && velha[0][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada>=2 && velha[0][1]==simbC && velha[0][0]==' ' && velha[0][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }
        else if(*jogada>=2 && velha[0][2]==simbC && velha[0][1]==' ' && velha[0][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }

            //LINHA 1
        else if(*jogada>=2 && velha[1][0]==simbC && velha[1][1]==' ' && velha[1][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
        }
        else if(*jogada>=2 && velha[1][1]==simbC && velha[1][0]==' ' && velha[1][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][0]=simbC;}
            else if(aleat==1) {velha[1][2]=simbC;}
        }
        else if(*jogada>=2 && velha[1][2]==simbC && velha[1][1]==' ' && velha[1][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[1][0]=simbC;}
        }

            //LINHA 2
        else if(*jogada>=2 && velha[2][0]==simbC && velha[2][1]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[2][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[2][1]==simbC && velha[2][0]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[2][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[2][2]==simbC && velha[2][1]==' ' && velha[2][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[2][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }

            //COLUNA 0
        else if(*jogada>=2 && velha[0][0]==simbC && velha[1][0]==' ' && velha[2][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][0]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada>=2 && velha[1][0]==simbC && velha[0][0]==' ' && velha[2][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada>=2 && velha[2][0]==simbC && velha[1][0]==' ' && velha[0][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][0]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }

            //COLUNA 1
        else if(*jogada>=2 && velha[0][1]==simbC && velha[1][1]==' ' && velha[2][1]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
        }
        else if(*jogada>=2 && velha[1][1]==simbC && velha[0][1]==' ' && velha[2][1]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][1]=simbC;}
            else if(aleat==1) {velha[2][1]=simbC;}
        }
        else if(*jogada>=2 && velha[2][1]==simbC && velha[1][1]==' ' && velha[0][1]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][1]=simbC;}
        }

            //COLUNA 2
        else if(*jogada>=2 && velha[0][2]==simbC && velha[1][2]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][2]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[1][2]==simbC && velha[0][2]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[2][2]==simbC && velha[1][2]==' ' && velha[0][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][2]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }

            //DIAGONAL PRINCIPAL
        else if(*jogada>=2 && velha[0][0]==simbC && velha[1][1]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[1][1]==simbC && velha[0][0]==' ' && velha[2][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][0]=simbC;}
            else if(aleat==1) {velha[2][2]=simbC;}
        }
        else if(*jogada>=2 && velha[2][2]==simbC && velha[1][1]==' ' && velha[0][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][0]=simbC;}
        }

            //DIAGONAL SECUNDARIA
        else if(*jogada>=2 && velha[0][2]==simbC && velha[1][1]==' ' && velha[2][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada>=2 && velha[1][1]==simbC && velha[0][2]==' ' && velha[2][0]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[0][2]=simbC;}
            else if(aleat==1) {velha[2][0]=simbC;}
        }
        else if(*jogada>=2 && velha[2][0]==simbC && velha[1][1]==' ' && velha[0][2]==' '){
            aleat=rand()%2;
            if(aleat==0) {velha[1][1]=simbC;}
            else if(aleat==1) {velha[0][2]=simbC;}
        }

        //NADA A FAZER
        else{
          while('true'){
              aleat=rand()%9;
              if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
              if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
              if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
              if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
              if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
              if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
              if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
              if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
              if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
          }
        }

    //===========================================================================================//

    //JOGADAS RUINS
    }else{

        //LINHA 1
        if(velha[0][0]==' ' && velha[0][1]==simbC && velha[0][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[0][1]==' ' && velha[0][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[0][1]==simbC && velha[0][2]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        //LINHA 2
        else if(velha[1][0]==' ' && velha[1][1]==simbC && velha[1][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[1][0]==simbC && velha[1][1]==' ' && velha[1][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[1][0]==simbC && velha[1][1]==simbC && velha[1][2]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        //LINHA 3
        else if(velha[2][0]==' ' && velha[2][1]==simbC && velha[2][2]==simbC) {
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[2][0]==simbC && velha[2][1]==' ' && velha[2][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[2][0]==simbC && velha[2][1]==simbC && velha[2][2]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
            }
        }
        //COLUNA 1
        else if(velha[0][0]==' ' && velha[1][0]==simbC && velha[2][0]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[1][0]==' ' && velha[2][0]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[1][0]==simbC && velha[2][0]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        //COLUNA 2
        else if(velha[0][1]==' ' && velha[1][1]==simbC && velha[2][1]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][1]==simbC && velha[1][1]==' ' && velha[2][1]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][1]==simbC && velha[1][1]==simbC && velha[2][1]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        //COLUNA 3
        else if(velha[0][2]==' ' && velha[1][2]==simbC && velha[2][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][2]==simbC && velha[1][2]==' ' && velha[2][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][2]==simbC && velha[1][2]==simbC && velha[2][2]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
            }
        }
        //DIAGONAL PRINCIPAL
        else if(velha[0][0]==' ' && velha[1][1]==simbC && velha[2][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[1][1]==' ' && velha[2][2]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][0]==simbC && velha[1][1]==simbC && velha[2][2]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
            }
        }
        //DIAGONAL SECUNDARIA
        else if(velha[0][2]==' ' && velha[1][1]==simbC && velha[2][0]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][2]==simbC && velha[1][1]==' ' && velha[2][0]==simbC){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
        else if(velha[0][2]==simbC && velha[1][1]==simbC && velha[2][0]==' '){
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }

        else{
            while('true'){
                aleat=rand()%9;
                if(aleat==0 && velha[0][0]==' ') {velha[0][0]=simbC; break;}
                if(aleat==1 && velha[0][1]==' ') {velha[0][1]=simbC; break;}
                if(aleat==2 && velha[0][2]==' ') {velha[0][2]=simbC; break;}
                if(aleat==3 && velha[1][0]==' ') {velha[1][0]=simbC; break;}
                if(aleat==4 && velha[1][1]==' ') {velha[1][1]=simbC; break;}
                if(aleat==5 && velha[1][2]==' ') {velha[1][2]=simbC; break;}
                if(aleat==6 && velha[2][0]==' ') {velha[2][0]=simbC; break;}
                if(aleat==7 && velha[2][1]==' ') {velha[2][1]=simbC; break;}
                if(aleat==8 && velha[2][2]==' ') {velha[2][2]=simbC; break;}
            }
        }
    }
}
