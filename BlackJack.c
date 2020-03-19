#include<stdio.h>
#include<stdlib.h>
#include"Shuffle.h"
#include"BlackJack.h"

typedef enum turnTag {
    PLAYERTURN,
    ENEMYTURN,
}Turn;

//プロトタイプ宣言
void Draw();
void SwichTurn();
void TortalOutput();
void DrawPhase();
void Judge();                   

Turn whichTurn = PLAYERTURN;    //現在どちらのターンか
Card playerHand[10];            //プレイヤーの手札
Card enemyHand[10];             //相手
int playerEmptyFirst=0;         //プレイヤーの手札の空いている先頭の番号
int enemyEmptyFirst=0;          //相手
int playerValue=0;              //プレイヤーの手札の合計
int enemyValue=0;               //相手
int upperLimit = UPPER_LIMIT;   //ブラックジャックの上限

///ブラックジャックメメイン
int BlackJackMain(void){
    int hand = FIRST_HAND;          //初期手札の枚数  

    printf("\n ブラックジャック \n");
    printf("---------------------------------\n");
    //お互いにカードを配る
    printf("player : ");
    for(int i=0;i<hand;i++){
        Draw();
    }
    TortalOutput();
    SwichTurn();
    printf("enemy : ");
    for(int i=0;i<hand;i++){
        Draw();
    }
    TortalOutput();
    printf("---------------------------------\n");

    //プレイヤーのターン
    SwichTurn();
    printf("\n プレイヤーのターン\n");
    printf("---------------------------------\n");
    DrawPhase();
    TortalOutput();
    printf("---------------------------------\n");

    //相手のターン
    SwichTurn();
    printf("\n 相手のターン\n");
    printf("---------------------------------\n");
    DrawPhase();
    TortalOutput();
    printf("---------------------------------\n");

    //勝敗判定
    printf("\n 判定\n");
    printf("---------------------------------\n");
    Judge();
    printf("---------------------------------\n");
    printf(" ブラックジャックを終了します\n\n");
    return 0;
}

///ターンを切り替える
void SwichTurn(){
    if(whichTurn==PLAYERTURN){
        whichTurn=ENEMYTURN;
    }
    else{
        whichTurn=PLAYERTURN;
    }
}

///手札の合計を表示
void TortalOutput(){
    if(whichTurn==PLAYERTURN){
        printf("プレイヤーの手札の合計： %d\n",playerValue);
    }
    else{
        printf("相手の手札の合計： %d\n",enemyValue);
    }
}

///山札を引く処理
void Draw(){
    Card hand;
    hand=GetCard();
    printf("%c%d ",hand.mark,hand.number);
    //配られたカードが１０以上だった場合は１０に変換して加算
    if(hand.number>=10){
        hand.number=10;
    }
    //現在のターンに応じて加える場所を変える
    if(whichTurn==PLAYERTURN){
        playerHand[playerEmptyFirst]=hand;
        playerValue+=hand.number;
        playerEmptyFirst++;
    }
    else if(whichTurn==ENEMYTURN){
        enemyHand[enemyEmptyFirst]=hand;
        enemyValue+=hand.number;
        enemyEmptyFirst++;
    }
}

///山札を引くフェイズ
void DrawPhase(){
    int enemyLimit = ENEMY_LIMIT;   //相手が山札を引くと判断する最大数
    int selectNum=0;                //yesかnoを答えるための変数
    int value;

    if(whichTurn==PLAYERTURN){
        value=playerValue;
    }
    else{
        value=enemyValue;
    }

    //手札の合計がupperLimitを超えてしまうまで繰り返す
    while (value<upperLimit)
    {
        //プレイヤーのターンだった場合
        if(whichTurn==PLAYERTURN){
            selectNum = 0;
            TortalOutput();
            printf("^山札を引きますか？\n はい:1　いいえ:2 \n =>");       
            scanf("%d",&selectNum);
            if(selectNum==1){
                printf("加えられたカード ＞ ");
                Draw();
                printf("\n");
                value=playerValue;
                //値が21以上だった場合はターンが終了するため忠告
                if(value==upperLimit)
                    printf("手札の合計が%dなので自分のターンを終了します\n",upperLimit);
                if(value>upperLimit)
                    printf("手札の合計が%dを超えてしまいました 自分のターンを終了します\n",upperLimit);
            }
            else if(selectNum==2){
                printf("引かずに終了\n");
                break;
            }   
            else{
                printf("入力エラー\n");   
            }         
        }
        //相手のターンだった場合
        else if(whichTurn==ENEMYTURN){
            TortalOutput();       
            if(value<=enemyLimit){
                printf("相手は山札を引いた\n");
                printf("加えられたカード ＞ ");
                Draw();
                printf("\n");
                value=enemyValue;
            }
            else if(value>enemyLimit){
                printf("引かずに終了\n");
                break;
            }         
        }
    }
}

///勝敗判定
void Judge(){
    printf("プレイヤー : %d  相手 : %d\n",playerValue,enemyValue);

    if(playerValue==enemyValue || (playerValue>upperLimit && enemyValue>upperLimit)){
        printf("引き分け\n");
    }
    else if((playerValue>upperLimit && enemyValue<upperLimit) || (playerValue<upperLimit && enemyValue<upperLimit && playerValue<enemyValue)){
        printf("プレイヤーの負け\n");
    }
    else {
        printf("プレイヤーの勝ち\n");
    }
}