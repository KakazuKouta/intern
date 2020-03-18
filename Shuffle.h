#ifndef SHUFFLE_H
#define SHUFFLE_H

#define CARD_MAX 52
#define MARK_VALUE 13

struct Card
{
	int number; 
    char mark; 
};
typedef struct Card Card;


Card GetCard(int topNum);


#endif