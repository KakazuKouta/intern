#include<stdio.h>
#include<stdlib.h>
#include"Shuffle.h"
#include"BlackJack.h"

//プロトタイプ宣言
void Win();
void Lose();
void Dlow();

///指定された山札のカードを配る処理
Card Distribute(int deckTop){
    Card hand;
    hand=GetCard(deckTop);
    printf("%c %d ",hand[deckTop].mark,hand[deckTop].number);
    //配られたカードが１０以上だった場合は１０に変換して加算
    if(hand.number>=10){
        hand.number=10;
    }
    return hand;
}



int BlackJackMain(void){

    int hand = FIRST_HAND;          //手札の枚数
    int upperLimit = UPPER_LIMIT;   //ブラックジャックの上限
    Card playerHand[10];            //プレイヤーの手札
    Card enemyHand[10];             //相手の手札
    int playerValue=0;              //プレイヤーの手札の合計
    int enemyValue=0;               //相手の手札の合計
    int deckTop=0;                  //山札の番号
    int selectNum=0;                //yesかnoを答えるための変数
    int enemyLimit = ENEMY_LIMIT;   //相手が山札を引くと判断する最大数

    printf("\n ブラックジャック \n");
    printf("---------------------------------\n");
    //お互いにカードを配る
    printf("player : ");
    for(int i=0;i<hand;i++){
        playerHand[deckTop]=Distribute(deckTop);
        playerValue+=playerHand[deckTop].number;
        deckTop++;
    }
    printf("\nプレイヤーの手札の合計： %d\n",playerValue);   
    printf("enemy : ");
    for(int i=0;i<hand;i++){
        enemyHand[deckTop]=Distribute(deckTop);
        enemyValue+=enemyHand[deckTop].number;
        deckTop++;
    }
    printf("\n相手の手札の合計 :　%d \n",enemyValue);

    printf("---------------------------------\n");

    //プレイヤーのターン
    printf("\nプレイヤーのターン\n");
    printf("---------------------------------\n");
    while (playerValue<upperLimit)
    {
        selectNum = 0;
        printf("\nプレイヤーの手札の合計： %d\n",playerValue);
        printf("山札を引きますか？\n はい:1　いいえ:2 \n =>");       
        scanf("%d",&selectNum);
        if(selectNum==1){
            playerHand[deckTop]=GetCard(deckTop);
            printf("加えられたカード ＞ %c %d \n",playerHand[deckTop].mark,playerHand[deckTop].number);
            //配られたカードが１０以上だった場合は１０に変換して加算
            if(playerHand[deckTop].number>=10){
                playerHand[deckTop].number=10;
            }
            playerValue+=playerHand[deckTop].number;
            //値が21以上だった場合はターンが終了するため忠告
            if(playerValue==21)
                printf("手札の合計が21なので自分のターンを終了します\n");
            if(playerValue>21)
                printf("手札の合計が21を超えてしまいました 自分のターンを終了します\n");
            deckTop++;
        }
        else if(selectNum==2)
        {
            printf("引かずに終了\n");
            break;
        }   
        else
            printf("入力エラー\n");            
    }
    printf("プレイヤーの手札の合計： %d\n",playerValue);
    printf("---------------------------------\n");

    //相手のターン
    printf("\n相手のターン\n");
    printf("---------------------------------\n");
    while (enemyValue<upperLimit)
    {
        printf("\n相手の手札の合計： %d\n",enemyValue);
        
        if(enemyValue<=enemyLimit){
            printf("相手は山札を引いた\n");
            enemyHand[deckTop]=GetCard(deckTop);
            printf("加えられたカード ＞ %c %d \n",enemyHand[deckTop].mark,enemyHand[deckTop].number);
            //配られたカードが１０以上だった場合は１０に変換して加算
            if(enemyHand[deckTop].number>=10){
                enemyHand[deckTop].number=10;
            }
            enemyValue+=enemyHand[deckTop].number;        
            
            deckTop++;
        }
        else if(enemyValue>enemyLimit){
            printf("引かずに終了\n");
            break;
        }         
    }
    printf("相手の手札の合計： %d\n",enemyValue);
    printf("---------------------------------\n");

    printf("\n判定\n");
    printf("---------------------------------\n");
    printf("プレイヤー : %d  相手 : %d\n",playerValue,enemyValue);

    //勝敗判定
    if(playerValue>21){
        if(enemyValue>21)
            Dlow();
        else
            Lose();
    }
    else{
        if(enemyValue>21)
            Win();
        else{
            if(playerValue==enemyValue)
                Dlow();
            else{
                if(playerValue>enemyValue)
                    Win();
                else
                    Lose();
            }
        }
    }
    printf("---------------------------------\n");
    printf("ブラックジャックを終了します\n");
    return 0;
}

void Win(){
    printf("プレイヤーの勝ち\n");
}

void Lose(){
    printf("プレイヤーの負け\n");
}

void Dlow(){
    printf("引き分け\n");
}