#ifndef SHUFFLE_H
#define SHUFFLE_H

struct Card
{
	int number; 
    char mark; 
};
typedef struct Card Card;


Card GetCard(int topNum);


#endif