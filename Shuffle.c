#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
#include"Shuffle.h"

//カードの構造体定義
typedef struct{
	int number; 
	char mark; 
}card_rec;

//関数プロトタイプ宣言
void CardInput(card_rec *card); 
void CardShuffle(card_rec *card); 

int topNum = 0;		//山札の一番上の番号

///カードを取得する topNum:山札の番号
Card GetCard(){

	Card trump;
	card_rec card[CARD_MAX]; //カード構造体を配列で定義

	CardInput(card);	
	CardShuffle(card);	

	trump.number=(card+topNum)->number;
	trump.mark=(card+topNum)->mark;

	topNum++;

	return trump;
}

///カードに数字とマークを代入
void CardInput(card_rec *card){
	int i;
	int markValue=MARK_VALUE;		//柄ごとのカードの枚数 
	int deckValue=CARD_MAX;		//山札の枚数

	for(i=0;i<deckValue;i++){
		
		(card+i)->number=i%markValue+1; 
		
		//マークを代入
		switch(i/markValue){ 
			case 0:
			(card+i)->mark='s';
			break;
			
			case 1:
			(card+i)->mark='q';
			break;
			
			case 2:
			(card+i)->mark='h';
			break;
			
			case 3:
			(card+i)->mark='d';
			break;
		}
	}
}

///カードをシャッフル
void CardShuffle(card_rec *card){
	int i,r,tmpNum; 
	int deckValue=CARD_MAX;		//山札の枚数
	char tmpMark;    
	srand((unsigned)time(NULL)); 

	for(i=0;i<deckValue;i++){

		r=rand()%deckValue; 
		
		/*乱数で得た番号と配列の番号を入れ替え*/
		tmpNum=(card+i)->number;
		(card+i)->number=(card+r)->number;
		(card+r)->number=tmpNum;
		
		/*マークを入れ替え*/
		tmpMark=(card+i)->mark;
		(card+i)->mark=(card+r)->mark;
		(card+r)->mark=tmpMark;
	}
}

///テスト用
void CardOutput(card_rec *card,int hand){
	int i;
	int deckValue=CARD_MAX;		//山札の枚数

	for(i=0;i<deckValue;i++){
		printf("%d %c\n",(card+i)->number,(card+i)->mark); 
	}
}