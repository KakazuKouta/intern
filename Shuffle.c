#include <stdio.h>
#include <time.h>
#include "Shuffle.h"

///トランプをシャッフル
void Shuffle(int array[], int size) {

	srand((unsigned)time(NULL));
		
	for (int i = 0; i < size; i++) {
		int j = rand() % size;
		int t = array[i];
		array[i] = array[j];
		array[j] = t;
	}
}