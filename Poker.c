#include<stdio.h>
#include"Shuffle.h"
#include"Poker.h"
#include"Shuffle.h"

typedef enum turnTag{
    player,
}Turn;

//プロトタイプ宣言
void Draw();
void Distribute();
void HnadOutput();
void ChangCard();

///ポーカーメイン
int PokerMain(void){

    Card playerHand[HAND];     //プレイヤーの手札

    Distribute(playerHand);
    HnadOutput(playerHand);
    ChangCard(playerHand);
    HnadOutput(playerHand);

    return 0;
}

///山札を引く
void Draw(Card *hand){
    hand->mark=GetCard().mark;
    hand->number=GetCard().number;
}

///カードをHANDの数まで配る
void Distribute(Card *hand){
    for(int i=0;i<HAND;i++){
        hand[i]=GetCard();
    }
}

//指定された場所のカードを入れ替える処理
void ChangCard(Card *hand){
    int selectNum=0;
    int digit=0;
    
    printf("^入れ替えるカード番号を入力\n =>");
    scanf("%d",&selectNum);
    
    //selectNumの桁数を数える
    while(selectNum!=0){
        selectNum /= 10;
        digit++;
    }

    //番号と同じ場所にあるカードを入れ替え
    for(int i=0;i<digit;i++){
        hand[selectNum%10]=GetCard();
        selectNum/=10;
    }
    
}

///プレイヤーの手札を出力
void HnadOutput(Card *hand){
    printf("プレイヤーの手札\n");
    for(int i=0;i<HAND;i++){
        printf("%c%d ",hand[i].mark,hand[i].number);
    }
    printf("\n▲1 ▲2 ▲3 ▲4 ▲5\n");
}