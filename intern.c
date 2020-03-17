#include<stdio.h>
#include<stdlib.h>
#include"Shuffle.h"

//カードの構造体定義
    typedef struct{
        int number; 
        char mark; 
    }card_rec;

int main(void){

    int hand = 2;
    int upperLimit = 21;
    int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
    int playerValue[2];

    card_rec card[52];


    // for (int i = 0; i < handNumber; i++) {
		
	// 	playerValue[i] = array[i];
	// 	printf("%d ", playerValue[i]);
	// }
	printf("\n");
    

    return 0;
}