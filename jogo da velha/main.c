#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "IA.h"

int main(void){
char velha[3][3];//matriz 
char res,res2='s';//variáveis de controle de menu e prosegimento de jogo,respectivamente
int pwin=0,pcwin=0,vlh=0;//,lastwin=0;//vitórias do jogador,vitórias do pc,empates e ultimo a ganhar,respectivamente.
do{//laço principal.
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){   //Deixa a tabela em branco e previne de lixo na memória.
            velha[i][j]=' ';
        }
    }
    int qual,quem,level;// qual simbolo,quem joga primeiro e difulculdade,respectivamente.
    char simbP,simbC;//simbolo do jogador e do pc.
    if(res2=='s'){
        qual=0,quem=0,level=0;
        simbP=' ',simbC=' ';    //menu
        pwin=0,pcwin=0,vlh=0;
        menu(&qual,&quem,&level,&simbP,&simbC);
    }
    int l=0,c=0,num=0;//linha na matriz,coluna na matriz e número de jogadas,respectivamente.
    tabela(velha);//chamada de função.
    //printf("VOC%c:(%c) | PC:(%c)\n[R]einiciar [M]enu\n\n",210,simbP,simbC);
    while(num<9){//laço secundário,que termina com o fim  da partida,ou volta ao menu.

     if(quem==1){ //ordem de jogada com base na seleção de ordem e/ou último a ganhar.
         if(num%2==0){
            player(velha,&qual,&num,&l,&c,simbP,simbC);
            //printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
         }else{
            pc(velha,simbC,simbP,&num,&level);  
            tabela(velha);						         
            num++;
         }
     }else if(quem==2){
         if(num%2==0){ //ordem de jogada com base na seleção de ordem e/ou último a ganhar.
            pc(velha,simbC,simbP,&num,&level);
            tabela(velha);                             
            num++;
         }else{
             player(velha,&qual,&num,&l,&c,simbP,simbC);
            //printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
         }
     }
                            // X win
        //linhas
        if(velha[0][0]=='X' && velha[0][1]=='X' && velha[0][2]=='X'){
            num=10;
        }
        if(velha[1][0]=='X' && velha[1][1]=='X' && velha[1][2]=='X'){
            num=10;
        }
        if(velha[2][0]=='X' && velha[2][1]=='X' && velha[2][2]=='X'){
            num=10;
        }
        //colunas
        if(velha[0][0]=='X' && velha[1][0]=='X' && velha[2][0]=='X'){
            num=10;
        }
        if(velha[0][1]=='X' && velha[1][1]=='X' && velha[2][1]=='X'){
            num=10;
        }
        if(velha[0][2]=='X' && velha[1][2]=='X' && velha[2][2]=='X'){
            num=10;
        }
        //diagonais
        if(velha[0][0]=='X' && velha[1][1]=='X' && velha[2][2]=='X'){
            num=10;
        }
         if(velha[0][2]=='X' && velha[1][1]=='X' && velha[2][0]=='X'){
            num=10;
        }
                            // O win
        //linhas
        if(velha[0][0]=='O' && velha[0][1]=='O' && velha[0][2]=='O'){
            num=11;
        }
        if(velha[1][0]=='O' && velha[1][1]=='O' && velha[1][2]=='O'){
            num=11;
        }
        if(velha[2][0]=='O' && velha[2][1]=='O' && velha[2][2]=='O'){
            num=11;
        }
        //colunas
        if(velha[0][0]=='O' && velha[1][0]=='O' && velha[2][0]=='O'){
            num=11;
        }
        if(velha[0][1]=='O' && velha[1][1]=='O' && velha[2][1]=='O'){
            num=11;
        }
        if(velha[0][2]=='O' && velha[1][2]=='O' && velha[2][2]=='O'){
            num=11;
        }
        //diagonais
        if(velha[0][0]=='O' && velha[1][1]=='O' && velha[2][2]=='O'){
            num=11;
        }
         if(velha[0][2]=='O' && velha[1][1]=='O' && velha[2][0]=='O'){
            num=11;
        }
    }

    if(num==12){//volta ao menu de seleção.
        res2='s';
        res='s';
    }else if(num==13){//reinicia a partida.
        res2='n';
        res='s';
    }else{
        tabela(velha);

        if(num==9){//em caso de empate.
            printf("   VELHA\n");
            vlh++;
        }else if(num==10){//'x' ganhou.
            if(qual==1){//se vc for 'x'.
                printf("   VOC%c GANHOU!\n\n",210);
                pwin++;
                quem=1;
            }else{//se vc for 'o'.
                printf("   VOC%c PERDEU!\n\n\a",210);
                pcwin++;
                quem=2;
        }
        }else if(num==11){//'o'ganhou.
            if(qual==2){//se vc for 'o'.
                printf("   VOC%c GANHOU!\n\n",210);
                pwin++;
                quem=1;
            }else{//se vc for'x'.
                printf("   VOC%c PERDEU!\n\n\a",210);
                pcwin++;
                quem=2;
            }
        }
        placar(pwin,pcwin,vlh);//pontuação.
        printf("voc%c gostaria de jogar novamente?[s ou n]\n",136);
        scanf("%s",&res);
        if(res=='s' || res=='S'){//reinicia a partida.
            res2='n';
        }else if(res!='s' || res!='S'){//volta ao menu ou finaliza a execução jogo.
            system("cls");
            printf("gostaria de voltar ao menu?[s ou n]\n");
            scanf("%s",&res);
            if(res=='s' || res=='S'){
                res2='s';
                res='s';
            }
        }
    }
}while(res=='s');
}

//============================MENU=============================//

//============================================================//

//===========================player===========================//

//============================================================//

//===========================computador=======================//

//============================================================//
