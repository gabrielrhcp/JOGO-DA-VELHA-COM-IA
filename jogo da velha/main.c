#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "IA.h"

int main(void){
char velha[3][3];
char res,res2='s';
int pwin=0,pcwin=0,vlh=0,lastwin=0;
do{
    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){
            velha[i][j]=' ';
        }
    }
    int qual,quem,level;
    char simbP,simbC;
    if(res2=='s'){
        qual=0,quem=0,level=0;
        simbP=' ',simbC=' ';
        pwin=0,pcwin=0,vlh=0;
        menu(&qual,&quem,&level,&simbP,&simbC);
    }
    int l=0,c=0,num=0;
    tabela(velha);
    printf("VOC%c:(%c) | PC:(%c)\n[R]einiciar [M]enu\n\n",210,simbP,simbC);
    while(num<9){

     if(quem==1){
         if(num%2==0){
            player(velha,&qual,&num,&l,&c);
            printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
         }else{
            pc(velha,simbC,simbP,&num,&level);
            tabela(velha);
            printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
            num++;
         }
     }else if(quem==2){
         if(num%2==0){
            pc(velha,simbC,simbP,&num,&level);
            tabela(velha);
            printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
            num++;
         }else{
            player(velha,&qual,&num,&l,&c);
            printf("VOC%c:(%c) | PC:(%c)\n\n",210,simbP,simbC);
         }
     }
                            //player X win
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
                            //player O win
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

    if(num==12){
        res2='s';
        res='s';
    }else if(num==13){
        res2='n';
        res='s';
    }else{
        tabela(velha);

        if(num==9){
            printf("   VELHA\n");
            vlh++;
        }else if(num==10){
            if(qual==1){
                printf("   VOC%c GANHOU!\n\n",210);
                pwin++;
                quem=1;
            }else{
                printf("   VOC%c PERDEU!\n\n\a",210);
                pcwin++;
                quem=2;
        }
        }else{
            if(qual==2){
                printf("   VOC%c GANHOU!\n\n",210);
                pwin++;
                quem=1;
            }else{
                printf("   VOC%c PERDEU!\n\n\a",210);
                pcwin++;
                quem=2;
            }
        }
        placar(pwin,pcwin,vlh);
        printf("voc%c gostaria de jogar novamente?[s ou n]\n",136);
        scanf("%s",&res);
        if(res=='s' || res=='S'){
            res2='n';
        }else if(res!='s' || res!='S'){
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
