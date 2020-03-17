#include<stdio.h>
#include<stdlib.h>
#include"Shuffle.h"

int main(void){

    int hand = 2;               //手札の枚数
    int upperLimit = 21;        //ブラックジャックの上限
    Card playerHand[hand];      //プレイヤーの手札
    Card enemyHand[hand];       //相手の手札
    int playerValue=0;          //プレイヤーの手札の合計
    int enemyValue=0;           //相手の手札の合計
    int deckTop=0;              //山札の番号

    //プレイヤーにカードを配る
    printf("player:");
    for(int i=0;i<hand;i++){
        playerHand[deckTop]=GetCard(deckTop);
        printf("%c %d ",playerHand[deckTop].mark,playerHand[deckTop].number);
        playerValue+=playerHand[deckTop].number;
        deckTop++;
    }
    printf("\n");
    printf("%d \n",playerValue);

    //相手にカードを配る
    printf("enemy:");
    for(int i=0;i<hand;i++){
        enemyHand[deckTop]=GetCard(deckTop);
        printf("%c %d ",enemyHand[deckTop].mark,enemyHand[deckTop].number);
        enemyValue+=enemyHand[deckTop].number;
        deckTop++;
    }
    printf("\n");
    printf("%d \n",enemyValue);

    while (playerValue<21)
    {
        printf("\n山札を引きますか？\n y:はい　n:いいえ \n");
        int a;
        a = getch();
        if(a==1){
            printf("%d\n", a);
        }
        else
        {
            printf("sasa");
        }
        
        return 0;
    }
    

    return 0;
}

// ///カードを配る
// void Distribute(Card player[],Card enemy[]){

//     printf("player:");
//     for(int i=0;i<hand;i++){
//         player[deckTop]=GetCard(deckTop);
//         printf("%c %d ",player[deckTop].mark,player[deckTop].number);
//         deckTop++;
//     }
//     printf("\n");

//     printf("enemy:");
//     for(int i=0;i<hand;i++){
//         enemy[deckTop]=GetCard(deckTop);
//         printf("%c %d ",enemy[deckTop].mark,enemy[deckTop].number);
//         deckTop++;
//     }
//     printf("\n");

// }